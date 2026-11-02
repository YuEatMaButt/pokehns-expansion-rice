FiveIsland_PokemonCenter_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FiveIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FIVE_ISLAND
	end

FiveIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FiveIsland_PokemonCenter_1F_EventScript_Chef::
	msgbox FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal, MSGBOX_NPC
	end

FiveIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon, MSGBOX_NPC
	end

FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal::
	.string "I'm on my way to prepare a meal\n"
	.string "for a certain high-society person.$"

FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon::
	.string "You're on a quest to catch every\n"
	.string "single kind of POKéMON?\p"
	.string "…How incredible. Please tell me if\n"
	.string "you catch a strong one!$"

FiveIsland_PokemonCenter_1F_EventScript_PokemonJournal::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PokemonJournal_Text_SpecialFeatureLorelei
	release
	end

PokemonJournal_Text_SpecialFeatureLorelei::
	.string "POKéMON JOURNAL\p"
	.string "Special Feature:\n"
	.string "ELITE FOUR's LORELEI!\p"
	.string "Known for her logical, calculated,\n"
	.string "and cool battling style, LORELEI\l"
	.string "has a surprising secret!$"
