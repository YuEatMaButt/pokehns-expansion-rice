NationalPark_Meadow_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Meadow_EventScript_GracideaCheck
	.byte 0

NationalPark_Meadow_EventScript_GracideaCheck::
	checkitem ITEM_GRACIDEA
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Meadow_EventScript_NoGracidea
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Meadow_EventScript_PlayerOrShayminRan
	release
	end

NationalPark_Meadow_EventScript_Shaymin::
	lock
	faceplayer
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
	msgbox NationalPark_Meadow_Text_Shaymin
	delay 20
	waitmoncry
	seteventmon SPECIES_SHAYMIN, 30
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NationalPark_Meadow_EventScript_PlayerOrShayminRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_NATIONALPARKMEADOW_SHAYMIN
	setflag FLAG_HIDE_SHAYMIN
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

NationalPark_Meadow_EventScript_PlayerOrShayminRan::
	release
	end

NationalPark_Meadow_EventScript_NoGracidea::
	removeobject LOCALID_NATIONALPARKMEADOW_SHAYMIN
	setflag FLAG_HIDE_SHAYMIN
	release
	end

NationalPark_Meadow_Text_Shaymin::
	.string "Kyuu uuhn.$"
