AbandonedHouse_Nightmare_hns_MapScripts::
	.byte 0

AbandonedHouse_Nightmare_EventScript_Darkrai::
	lock
	faceplayer
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	msgbox AbandonedHouse_Nightmare_Text_Darkrai
	delay 20
	waitmoncry
	seteventmon SPECIES_DARKRAI, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AbandonedHouse_Nightmare_EventScript_PlayerOrDarkraiRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ABANDONEDHOUSE_NIGHTMARE_DARKRAI
	setflag FLAG_HIDE_DARKRAI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

AbandonedHouse_Nightmare_EventScript_PlayerOrDarkraiRan::
	release
	end

AbandonedHouse_Nightmare_Text_Darkrai::
	.string "...$"
