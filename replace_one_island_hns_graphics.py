import re
import shutil
from pathlib import Path

MAPS = [
    "OneIsland_hns",
    "OneIsland_Harbor_hns",
    "OneIsland_House1_hns",
    "OneIsland_House2_hns",
    "OneIsland_KindleRoad_hns",
    "OneIsland_TreasureBeach_hns",
    "OneIsland_KindleRoad_EmberSpa_hns",
    "OneIsland_PokemonCenter_1F_hns",
    "OneIsland_PokemonCenter_2F_hns",
]

# Only replacements with an obvious HnS equivalent.
REPLACEMENTS = {
    "OBJ_EVENT_GFX_BILL": "OBJ_EVENT_GFX_BILL_HNS",
    "OBJ_EVENT_GFX_OLD_MAN_1": "OBJ_EVENT_GFX_OLD_MAN_HNS",
    "OBJ_EVENT_GFX_BALDING_MAN": "OBJ_EVENT_GFX_BALDING_MAN_HNS",
    "OBJ_EVENT_GFX_SAILOR_FRLG": "OBJ_EVENT_GFX_SAILOR_HNS",
    "OBJ_EVENT_GFX_OLD_WOMAN_FRLG": "OBJ_EVENT_GFX_OLD_WOMAN_HNS",
    "OBJ_EVENT_GFX_LASS_FRLG": "OBJ_EVENT_GFX_LASS_HNS",
    "OBJ_EVENT_GFX_SWIMMER_F_WATER": "OBJ_EVENT_GFX_SWIMMER_F_HNS",
    "OBJ_EVENT_GFX_SWIMMER_F_LAND": "OBJ_EVENT_GFX_SWIMMER_F_LAND_HNS",
    "OBJ_EVENT_GFX_SWIMMER_M_WATER": "OBJ_EVENT_GFX_SWIMMER_M_HNS",
    "OBJ_EVENT_GFX_SWIMMER_M_LAND": "OBJ_EVENT_GFX_SWIMMER_M_HNS",
    "OBJ_EVENT_GFX_FISHER": "OBJ_EVENT_GFX_FISHERMAN_HNS",
    "OBJ_EVENT_GFX_BATTLE_GIRL": "OBJ_EVENT_GFX_BATTLE_GIRL_HNS",
    "OBJ_EVENT_GFX_CAMPER_FRLG": "OBJ_EVENT_GFX_CAMPER_HNS",
    "OBJ_EVENT_GFX_PICNICKER_FRLG": "OBJ_EVENT_GFX_PICNICKER_HNS",
    "OBJ_EVENT_GFX_BREAKABLE_ROCK_FRLG": "OBJ_EVENT_GFX_BREAKABLE_ROCK_HNS",
    "OBJ_EVENT_GFX_ITEM_BALL": "OBJ_EVENT_GFX_ITEM_BALL_HNS",
    "OBJ_EVENT_GFX_NURSE_FRLG": "OBJ_EVENT_GFX_NURSE_HNS",
    "OBJ_EVENT_GFX_LITTLE_BOY_FRLG": "OBJ_EVENT_GFX_LITTLE_BOY_HNS",
    "OBJ_EVENT_GFX_HIKER_FRLG": "OBJ_EVENT_GFX_HIKER_HNS",
}

# Verify every replacement symbol is actually defined.
header = Path("include/constants/event_objects.h").read_text()
defined = set(re.findall(
    r'^\s*#define\s+(OBJ_EVENT_GFX_[A-Z0-9_]+)\b',
    header,
    re.MULTILINE
))

invalid = {
    old: new for old, new in REPLACEMENTS.items()
    if new not in defined
}
if invalid:
    print("ERROR: These replacement IDs were not found:")
    for old, new in invalid.items():
        print(f"  {old} -> {new}")
    raise SystemExit("No files changed. Check the graphics IDs first.")

total = 0

for map_name in MAPS:
    path = Path("data/maps") / map_name / "map.json"

    if not path.exists():
        print(f"SKIP: {path} not found")
        continue

    original = path.read_text()
    updated = original
    changes = []

    for old, new in REPLACEMENTS.items():
        # Match only graphics_id fields, not warp or other map references.
        pattern = (
            r'("graphics_id"\s*:\s*")'
            + re.escape(old)
            + r'(")'
        )
        updated, count = re.subn(
            pattern,
            lambda m: m.group(1) + new + m.group(2),
            updated
        )
        if count:
            changes.append((old, new, count))
            total += count

    if updated != original:
        backup = path.with_suffix(".map.json.bak")
        if not backup.exists():
            shutil.copy2(path, backup)
        path.write_text(updated)

    print(f"\n{map_name}:")
    if changes:
        for old, new, count in changes:
            print(f"  {old} -> {new} ({count})")
    else:
        print("  No matching graphics IDs needed replacement.")

print(f"\nFinished. Total object graphics replacements: {total}")
print("Original JSON files backed up as *.map.json.bak")
