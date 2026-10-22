from pathlib import Path
import shutil
import sys

target = Path("src/field_control_avatar.c")

old = """    else if (IsOverworldWildEncounter(&gObjectEvents[objectEventId], OWE_ANY))
        script = GetOverworlWildEncounterScript(objectEventId);"""

new = """    else if (IsOverworldWildEncounter(&gObjectEvents[objectEventId], OWE_GENERATED))
        return NULL;
    else if (IsOverworldWildEncounter(&gObjectEvents[objectEventId], OWE_ANY))
        script = GetOverworlWildEncounterScript(objectEventId);"""

if not target.is_file():
    sys.exit(f"ERROR: Cannot find {target}")

content = target.read_text()

if content.count(old) != 1:
    sys.exit("ERROR: Expected code was not found exactly once. No changes made.")

backup = target.with_suffix(".c.bak")

if backup.exists():
    sys.exit(f"ERROR: Backup already exists: {backup}")

shutil.copy2(target, backup)
target.write_text(content.replace(old, new, 1))

print("SUCCESS: Updated A-button interaction handler.")
print(f"Backup: {backup}")
