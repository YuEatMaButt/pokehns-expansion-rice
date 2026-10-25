MtMortar_B2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B2F_OnTransition
	.byte 0

MtMortar_B2F_OnTransition::
	goto_if_unset FLAG_VISITED_NEW_SINJOH, MtMortar_B2F_EventScript_HideHeatran
	release
	end

MtMortar_B2F_EventScript_HideHeatran::
	setflag FLAG_HIDE_HEATRAN
	release
	end

MtMortar_B2F_BattleHeatran::
	lock
	faceplayer
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
	msgbox MtMortar_B2F_Text_Heatran
	delay 20
	waitmoncry
	seteventmon SPECIES_HEATRAN, 45
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMortar_B2F_PlayerOrHeatranRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject MtMortar_B2F_Heatran
	setflag FLAG_HIDE_HEATRAN
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtMortar_B2F_PlayerOrHeatranRan::
	release
	end

MtMortar_B2F_Text_Heatran::
	.string "Gwogobo gwobobobo!$"
