WhirlIslands_Descent_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WhirlIslands_Descent_OnTransition
	.byte 0

WhirlIslands_Descent_OnTransition::
	goto_if_unset FLAG_VISITED_NEW_SINJOH, WhirlIslands_Descent_EventScript_HideManaphy
	release
	end

WhirlIslands_Descent_EventScript_HideManaphy::
	setflag FLAG_HIDE_MANAPHY
	release
	end

WhirlIslands_Descent_BattleManaphy::
	lock
	faceplayer
	playmoncry SPECIES_MANAPHY, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	seteventmon SPECIES_MANAPHY, 45
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslands_Descent_PlayerOrManaphyRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject WhirlIslands_Descent_Manaphy
	setflag FLAG_HIDE_MANAPHY
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

WhirlIslands_Descent_PlayerOrManaphyRan::
	release
	end

WhirlIslands_Descent_EventScript_Item_Max_Revive::
	finditem ITEM_MAX_REVIVE
	end

WhirlIslands_Descent_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end

WhirlIslands_Descent_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end

WhirlIslands_B2F_Trigger_Fog::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end
