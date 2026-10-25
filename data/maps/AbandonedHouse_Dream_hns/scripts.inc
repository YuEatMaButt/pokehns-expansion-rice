AbandonedHouse_Dream_hns_MapScripts::
	.byte 0

AbandonedHouse_Dream_EventScript_Cresselia::
	lock
	faceplayer
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	seteventmon SPECIES_CRESSELIA, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AbandonedHouse_Dream_EventScript_PlayerOrCresseliaRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ABANDONEDHOUSE_DREAM_CRESSELIA
	setflag FLAG_HIDE_CRESSELIA
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

AbandonedHouse_Dream_EventScript_PlayerOrCresseliaRan::
	release
	end
