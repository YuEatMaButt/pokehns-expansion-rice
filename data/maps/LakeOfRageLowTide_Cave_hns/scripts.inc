LakeOfRageLowTide_Cave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRageLowTide_Cave_OnTransition
	.byte 0

LakeOfRageLowTide_Cave_OnTransition::
	goto_if_unset FLAG_VISITED_NEW_SINJOH, LakeOfRageLowTide_Cave_EventScript_HideLakeTrio
	release
	end

LakeOfRageLowTide_Cave_EventScript_HideLakeTrio::
	setflag FLAG_HIDE_UXIE
	setflag FLAG_HIDE_MESPRIT
	setflag FLAG_HIDE_AZELF
	release
	end

LakeOfRageLowTide_Cave_EventScript_Uxie::
	lock
	faceplayer
	playmoncry SPECIES_UXIE, CRY_MODE_ENCOUNTER
	msgbox LakeOfRageLowTide_Cave_Text_Uxie
	delay 20
	waitmoncry
	seteventmon SPECIES_UXIE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRageLowTide_Cave_EventScript_PlayerOrLakeTrioRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_UXIE
	setflag FLAG_HIDE_UXIE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LakeOfRageLowTide_Cave_EventScript_Mesprit::
	lock
	faceplayer
	playmoncry SPECIES_MESPRIT, CRY_MODE_ENCOUNTER
	msgbox LakeOfRageLowTide_Cave_Text_Mesprit
	delay 20
	waitmoncry
	seteventmon SPECIES_MESPRIT, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRageLowTide_Cave_EventScript_PlayerOrLakeTrioRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_MESPRIT
	setflag FLAG_HIDE_MESPRIT
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LakeOfRageLowTide_Cave_EventScript_Azelf::
	lock
	faceplayer
	playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
	msgbox LakeOfRageLowTide_Cave_Text_Azelf
	delay 20
	waitmoncry
	seteventmon SPECIES_AZELF, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRageLowTide_Cave_EventScript_PlayerOrLakeTrioRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_AZELF
	setflag FLAG_HIDE_AZELF
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LakeOfRageLowTide_Cave_EventScript_PlayerOrLakeTrioRan::
	release
	end

LakeOfRageLowTide_Cave_Text_Uxie::
	.string "Kyouuuun!$"

LakeOfRageLowTide_Cave_Text_Mesprit::
	.string "Kyauun.$"

LakeOfRageLowTide_Cave_Text_Azelf::
	.string "Kyuuun...$"
