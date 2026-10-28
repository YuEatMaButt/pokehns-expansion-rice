#!/usr/bin/env python3
import copy
import json
import os
import re
import shutil
import sys
import tempfile
from pathlib import Path

ROOT = Path.cwd()
MAPS = ROOT / "data/maps"
LAYOUTS_FILE = ROOT / "data/layouts/layouts.json"

# source map folder, target map folder, target map ID,
# target layout ID, target layout directory
MAP_SPECS = [
    ("ThreeIsland_Frlg", "ThreeIsland_hns",
     "MAP_THREE_ISLAND_HNS", "LAYOUT_THREE_ISLAND_HNS",
     "ThreeIsland_hns"),
    ("ThreeIsland_Port_Frlg", "ThreeIsland_Port_hns",
     "MAP_THREE_ISLAND_PORT_hns", "LAYOUT_THREE_ISLAND_PORT_HNS",
     "ThreeIsland_Port_hns"),
    ("ThreeIsland_BondBridge_Frlg", "ThreeIsland_BondBridge_hns",
     "MAP_THREE_ISLAND_BOND_BRIDGE_hns",
     "LAYOUT_THREE_ISLAND_BOND_BRIDGE_HNS",
     "ThreeIsland_BondBridge_hns"),
    ("ThreeIsland_BerryForest_Frlg", "ThreeIsland_BerryForest_hns",
     "MAP_THREE_ISLAND_BERRY_FOREST_hns",
     "LAYOUT_THREE_ISLAND_BERRY_FOREST_HNS",
     "ThreeIsland_BerryForest_hns"),
    ("ThreeIsland_DunsparceTunnel_Frlg",
     "ThreeIsland_DunsparceTunnel_hns",
     "MAP_THREE_ISLAND_DUNSPARCE_TUNNEL_hns",
     "LAYOUT_THREE_ISLAND_DUNSPARCE_TUNNEL_HNS",
     "ThreeIsland_DunsparceTunnel_hns"),
    ("ThreeIsland_House1_Frlg", "ThreeIsland_House1_hns",
     "MAP_THREE_ISLAND_HOUSE1_hns",
     "LAYOUT_THREE_ISLAND_HOUSE1_HNS",
     "ThreeIsland_House1_hns"),
    ("ThreeIsland_House2_Frlg", "ThreeIsland_House2_hns",
     "MAP_THREE_ISLAND_HOUSE2_hns",
     "LAYOUT_THREE_ISLAND_HOUSES_2_5_HNS",
     "ThreeIsland_Houses_2_5_hns"),
    ("ThreeIsland_House3_Frlg", "ThreeIsland_House3_hns",
     "MAP_THREE_ISLAND_HOUSE3_hns",
     "LAYOUT_THREE_ISLAND_HOUSES_2_5_HNS",
     "ThreeIsland_Houses_2_5_hns"),
    ("ThreeIsland_House4_Frlg", "ThreeIsland_House4_hns",
     "MAP_THREE_ISLAND_HOUSE4_hns",
     "LAYOUT_THREE_ISLAND_HOUSES_2_5_HNS",
     "ThreeIsland_Houses_2_5_hns"),
    ("ThreeIsland_House5_Frlg", "ThreeIsland_House5_hns",
     "MAP_THREE_ISLAND_HOUSE5_hns",
     "LAYOUT_THREE_ISLAND_HOUSES_2_5_HNS",
     "ThreeIsland_Houses_2_5_hns"),
    ("ThreeIsland_Mart_Frlg", "ThreeIsland_Mart_hns",
     "MAP_THREE_ISLAND_MART_hns", "LAYOUT_THREE_ISLAND_MART_HNS",
     "ThreeIsland_Mart_hns"),
    ("ThreeIsland_PokemonCenter_1F_Frlg",
     "ThreeIsland_PokemonCenter_1F_hns",
     "MAP_THREE_ISLAND_POKEMON_CENTER_1F_hns",
     "LAYOUT_THREE_ISLAND_POKEMON_CENTER_1F_HNS",
     "ThreeIsland_PokemonCenter_1F_hns"),
    ("ThreeIsland_PokemonCenter_2F_Frlg",
     "ThreeIsland_PokemonCenter_2F_hns",
     "MAP_THREE_ISLAND_POKEMON_CENTER_2F_hns",
     "LAYOUT_THREE_ISLAND_POKEMON_CENTER_2F_HNS",
     "ThreeIsland_PokemonCenter_2F_hns"),
]

# The Harbor is intentionally not copied or overwritten.
HARBOR_SOURCE_ID = "MAP_THREE_ISLAND_HARBOR"
HARBOR_TARGET_ID = "MAP_THREE_ISLAND_HARBOR_HNS"
HARBOR_TARGET_LAYOUT = "LAYOUT_THREE_ISLAND_HARBOR_HNS"

def fail(message):
    print(f"ERROR: {message}", file=sys.stderr)
    sys.exit(1)

def read_json(path):
    try:
        return json.loads(path.read_text())
    except Exception as exc:
        fail(f"Cannot read JSON {path.relative_to(ROOT)}: {exc}")

def walk_replace(value, replacements):
    if isinstance(value, dict):
        return {k: walk_replace(v, replacements) for k, v in value.items()}
    if isinstance(value, list):
        return [walk_replace(v, replacements) for v in value]
    if isinstance(value, str):
        return replacements.get(value, value)
    return value

def strings_in(value):
    if isinstance(value, dict):
        for child in value.values():
            yield from strings_in(child)
    elif isinstance(value, list):
        for child in value:
            yield from strings_in(child)
    elif isinstance(value, str):
        yield value

def write_json(path, data):
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n")

if not LAYOUTS_FILE.is_file():
    fail("data/layouts/layouts.json does not exist")

layouts_data = read_json(LAYOUTS_FILE)
if not isinstance(layouts_data, dict) or not isinstance(layouts_data.get("layouts"), list):
    fail("Expected layouts.json to contain a top-level 'layouts' array")

layout_entries = layouts_data["layouts"]
layout_by_id = {
    item.get("id"): item
    for item in layout_entries
    if isinstance(item, dict) and item.get("id")
}

# Load every source map and verify all destinations before writing.
loaded = []
map_id_replacements = {}
planned_map_dirs = set()
planned_layout_ids = {}
planned_layout_dirs = {}

for source_name, target_name, target_id, target_layout_id, target_layout_dir in MAP_SPECS:
    source_dir = MAPS / source_name
    target_dir = MAPS / target_name
    source_json = source_dir / "map.json"

    if not source_json.is_file():
        fail(f"Missing source map: {source_json.relative_to(ROOT)}")
    if target_dir.exists():
        fail(f"Target map directory already exists; refusing to overwrite: {target_dir.relative_to(ROOT)}")

    source_map = read_json(source_json)
    source_id = source_map.get("id")
    source_layout_id = source_map.get("layout")

    if not source_id or not source_layout_id:
        fail(f"Missing map ID or layout ID in {source_json.relative_to(ROOT)}")
    if source_layout_id not in layout_by_id:
        fail(f"Layout {source_layout_id} referenced by {source_name} was not found in layouts.json")

    map_id_replacements[source_id] = target_id
    planned_map_dirs.add(target_dir)

    if target_layout_id in planned_layout_ids:
        previous = planned_layout_ids[target_layout_id]
        # Reuse is allowed only for Houses 2–5, which intentionally share
        # the same original layout and target directory.
        if not (
            target_layout_id == "LAYOUT_THREE_ISLAND_HOUSES_2_5_HNS"
            and source_layout_id == previous["source_layout_id"]
            and target_layout_dir == previous["target_layout_dir"]
        ):
            fail(f"Unexpected duplicate planned layout ID: {target_layout_id}")
    else:
        if target_layout_id in layout_by_id:
            fail(f"Layout ID already exists in layouts.json: {target_layout_id}")
        planned_layout_ids[target_layout_id] = {
            "source_layout_id": source_layout_id,
            "target_layout_dir": target_layout_dir,
        }

    loaded.append({
        "source_name": source_name,
        "target_name": target_name,
        "target_id": target_id,
        "target_layout_id": target_layout_id,
        "target_layout_dir": target_layout_dir,
        "source_map": source_map,
        "source_layout_id": source_layout_id,
    })

# Remap Harbor references to the already-existing HnS Harbor, without
# touching its map folder or layout files.
map_id_replacements[HARBOR_SOURCE_ID] = HARBOR_TARGET_ID

for target_layout_dir in planned_layout_dirs.values():
    pass

# Validate source layout binary paths and target layout destinations.
layout_sources = {}
for target_layout_id, info in planned_layout_ids.items():
    source_layout = layout_by_id[info["source_layout_id"]]
    paths = list(strings_in(source_layout))
    map_paths = [
        value for value in paths
        if re.fullmatch(r"data/layouts/.+/map\.bin", value)
    ]
    border_paths = [
        value for value in paths
        if re.fullmatch(r"data/layouts/.+/border\.bin", value)
    ]

    if not map_paths or not border_paths:
        fail(f"Could not find map.bin and border.bin paths for {info['source_layout_id']}")

    source_map_bin = ROOT / map_paths[0]
    source_border_bin = ROOT / border_paths[0]
    if not source_map_bin.is_file() or not source_border_bin.is_file():
        fail(f"Missing source layout binaries for {info['source_layout_id']}")

    source_layout_dir = source_map_bin.parent
    if source_border_bin.parent != source_layout_dir:
        fail(f"map.bin and border.bin are in different directories for {info['source_layout_id']}")

    target_layout_path = ROOT / "data/layouts" / info["target_layout_dir"]
    if target_layout_path.exists():
        fail(f"Target layout directory already exists; refusing to overwrite: {target_layout_path.relative_to(ROOT)}")

    layout_sources[target_layout_id] = {
        "entry": copy.deepcopy(source_layout),
        "source_dir": source_layout_dir,
        "target_dir": target_layout_path,
    }

# Check all planned target directories for collisions, including shared layout.
if len(planned_map_dirs) != len(MAP_SPECS):
    fail("Duplicate target map directories detected")

print("Preflight passed.")
print(f"Maps to create: {len(loaded)}")
print(f"Unique HnS layouts to create: {len(planned_layout_ids)}")
print("Original _Frlg maps and the existing Harbor will be left untouched.")

# Stage all files first. Nothing is installed into the repo until staging succeeds.
stage_root = Path(tempfile.mkdtemp(prefix=".three_island_hns_stage_", dir=ROOT))
try:
    staged_maps = []
    staged_layouts = []

    # Copy map folders and update their map.json files.
    for item in loaded:
        staged_dir = stage_root / "maps" / item["target_name"]
        staged_dir.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(MAPS / item["source_name"], staged_dir)

        map_json_path = staged_dir / "map.json"
        map_data = read_json(map_json_path)
        map_data = walk_replace(map_data, map_id_replacements)
        map_data["id"] = item["target_id"]
        map_data["name"] = item["target_name"]
        map_data["layout"] = item["target_layout_id"]
        map_data["game_version"] = "hns"
        write_json(map_json_path, map_data)
        staged_maps.append((staged_dir, MAPS / item["target_name"]))

    # Create each unique layout once, including the shared Houses 2–5 layout.
    new_layout_entries = []
    for target_layout_id, info in planned_layout_ids.items():
        details = layout_sources[target_layout_id]
        staged_dir = stage_root / "layouts" / info["target_layout_dir"]
        staged_dir.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(details["source_dir"], staged_dir)

        entry = details["entry"]
        source_dir_string = str(details["source_dir"].relative_to(ROOT)).replace("\\", "/")
        target_dir_string = (
            Path("data/layouts") / info["target_layout_dir"]
        ).as_posix()

        def replace_layout_paths(value):
            if isinstance(value, dict):
                return {k: replace_layout_paths(v) for k, v in value.items()}
            if isinstance(value, list):
                return [replace_layout_paths(v) for v in value]
            if isinstance(value, str):
                return value.replace(source_dir_string, target_dir_string)
            return value

        entry = replace_layout_paths(entry)
        entry["id"] = target_layout_id
        entry["game_version"] = "hns"
        entry["layout_version"] = "frlg"
        if "name" in entry:
            entry["name"] = info["target_layout_dir"]

        new_layout_entries.append(entry)
        staged_layouts.append((staged_dir, details["target_dir"]))

    updated_layouts = copy.deepcopy(layouts_data)
    updated_layouts["layouts"].extend(new_layout_entries)
    staged_layouts_json = stage_root / "layouts.json"
    write_json(staged_layouts_json, updated_layouts)

    # Final collision check before installing staged output.
    for _, destination in staged_maps + staged_layouts:
        if destination.exists():
            fail(f"Destination appeared during staging; refusing to overwrite: {destination.relative_to(ROOT)}")

    # Install the staged directories.
    installed = []
    try:
        for staged, destination in staged_maps + staged_layouts:
            destination.parent.mkdir(parents=True, exist_ok=True)
            os.rename(staged, destination)
            installed.append(destination)

        backup = LAYOUTS_FILE.with_suffix(".json.before_three_island_hns")
        if backup.exists():
            fail(f"Backup already exists; refusing to overwrite: {backup.name}")
        shutil.copy2(LAYOUTS_FILE, backup)
        os.replace(staged_layouts_json, LAYOUTS_FILE)
    except Exception:
        for destination in reversed(installed):
            if destination.is_dir():
                shutil.rmtree(destination)
        raise

    print("\nSUCCESS")
    print(f"Created {len(loaded)} HnS map folders.")
    print(f"Created {len(new_layout_entries)} unique HnS layout registrations.")
    print(f"Backup: {backup.relative_to(ROOT)}")
    print("ThreeIsland_Harbor_hns was not copied or overwritten.")
    print("Original _Frlg map folders and layout binaries were not modified.")

finally:
    shutil.rmtree(stage_root, ignore_errors=True)
