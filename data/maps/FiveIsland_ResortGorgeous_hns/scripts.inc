FiveIsland_ResortGorgeous_hns_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
	.string "With these hands, I will create\n"
	.string "my victory!$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
	.string "The shame of this…\n"
	.string "I'm red-faced…$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
	.string "Uh-oh, my paint tubes have\n"
	.string "scattered everywhere!$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
	.string "Excuse me!\n"
	.string "I'm trying to paint.\l"
	.string "Please keep out of my sight!$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
	.string "This loss…\n"
	.string "I feel like I'm whiting out…$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
	.string "GILLIAN?\n"
	.string "Please tilt your head slightly…\l"
	.string "There! That's the look I want!$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
	.string "Hmm…\n"
	.string "The angle, it is not quite there…$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
	.string "Oh…\n"
	.string "My feelings, they are blue…$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
	.string "The sky and the sea…\n"
	.string "They are so fickle.\p"
	.string "Their changing expressions make\n"
	.string "them difficult to capture.$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
	.string "I am visiting my friend's retreat,\n"
	.string "if you must know.$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "Oh, my, so strong.$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
	.string "I find it pleasurable to leisurely\n"
	.string "battle in the gentle sea breeze.$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
	.string "I'm thinking of having a pool\n"
	.string "made specially for POKéMON.$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
	.string "Oh, my goodness gracious!$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
	.string "A pool would be nice, but I must\n"
	.string "say, a sun-room may be sublime.$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
	.string "I'm a good runner.\n"
	.string "I'm really fast!$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
	.string "Oops!\n"
	.string "I rushed things!$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
	.string "When I run with the wind, it feels\n"
	.string "like I could fly!$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
	.string "I say, this marine life here at\n"
	.string "this resort agrees with me.$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
	.string "That's a shocker!\n"
	.string "You must be joking.$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
	.string "Getting so serious over this…\n"
	.string "How nonsensical.$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "SELPHY: Thank you.\p"
	.string "You may go now.$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
	.string "SELPHY'S HOUSE$"

FiveIsland_ResortGorgeous_EventScript_Daisy::
	trainerbattle_single TRAINER_PAINTER_DAISY, FiveIsland_ResortGorgeous_Text_DaisyIntro, FiveIsland_ResortGorgeous_Text_DaisyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_DaisyRematch
	msgbox FiveIsland_ResortGorgeous_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_DaisyRematch::
	trainerbattle_rematch TRAINER_PAINTER_DAISY, FiveIsland_ResortGorgeous_Text_DaisyRematchIntro, FiveIsland_ResortGorgeous_Text_DaisyDefeat
	msgbox FiveIsland_ResortGorgeous_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_Celina::
	trainerbattle_single TRAINER_PAINTER_CELINA, FiveIsland_ResortGorgeous_Text_CelinaIntro, FiveIsland_ResortGorgeous_Text_CelinaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_CelinaRematch
	msgbox FiveIsland_ResortGorgeous_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_CelinaRematch::
	trainerbattle_rematch TRAINER_PAINTER_CELINA, FiveIsland_ResortGorgeous_Text_CelinaRematchIntro, FiveIsland_ResortGorgeous_Text_CelinaDefeat
	msgbox FiveIsland_ResortGorgeous_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_Rayna::
	trainerbattle_single TRAINER_PAINTER_RAYNA, FiveIsland_ResortGorgeous_Text_RaynaIntro, FiveIsland_ResortGorgeous_Text_RaynaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_RaynaRematch
	msgbox FiveIsland_ResortGorgeous_Text_RaynaPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_RaynaRematch::
	trainerbattle_rematch TRAINER_PAINTER_RAYNA, FiveIsland_ResortGorgeous_Text_RaynaRematchIntro, FiveIsland_ResortGorgeous_Text_RaynaDefeat
	msgbox FiveIsland_ResortGorgeous_Text_RaynaPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_Jacki::
	trainerbattle_single TRAINER_LADY_JACKI, FiveIsland_ResortGorgeous_Text_JackiIntro, FiveIsland_ResortGorgeous_Text_JackiDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_JackiRematch
	msgbox FiveIsland_ResortGorgeous_Text_JackiPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_JackiRematch::
	trainerbattle_rematch TRAINER_LADY_JACKI, FiveIsland_ResortGorgeous_Text_JackiRematchIntro, FiveIsland_ResortGorgeous_Text_JackiDefeat
	msgbox FiveIsland_ResortGorgeous_Text_JackiPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_Gillian::
	trainerbattle_single TRAINER_LADY_GILLIAN, FiveIsland_ResortGorgeous_Text_GillianIntro, FiveIsland_ResortGorgeous_Text_GillianDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_GillianRematch
	msgbox FiveIsland_ResortGorgeous_Text_GillianPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_GillianRematch::
	trainerbattle_rematch TRAINER_LADY_GILLIAN, FiveIsland_ResortGorgeous_Text_GillianRematchIntro, FiveIsland_ResortGorgeous_Text_GillianDefeat
	msgbox FiveIsland_ResortGorgeous_Text_GillianPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_Destin::
	trainerbattle_single TRAINER_YOUNGSTER_DESTIN, FiveIsland_ResortGorgeous_Text_DestinIntro, FiveIsland_ResortGorgeous_Text_DestinDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_DestinRematch
	msgbox FiveIsland_ResortGorgeous_Text_DestinPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_DestinRematch::
	trainerbattle_rematch TRAINER_YOUNGSTER_DESTIN, FiveIsland_ResortGorgeous_Text_DestinRematchIntro, FiveIsland_ResortGorgeous_Text_DestinDefeat
	msgbox FiveIsland_ResortGorgeous_Text_DestinPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_Toby::
	trainerbattle_single TRAINER_SWIMMER_MALE_TOBY, FiveIsland_ResortGorgeous_Text_TobyIntro, FiveIsland_ResortGorgeous_Text_TobyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_EventScript_TobyRematch
	msgbox FiveIsland_ResortGorgeous_Text_TobyPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_EventScript_TobyRematch::
	trainerbattle_rematch TRAINER_SWIMMER_MALE_TOBY, FiveIsland_ResortGorgeous_Text_TobyRematchIntro, FiveIsland_ResortGorgeous_Text_TobyDefeat
	msgbox FiveIsland_ResortGorgeous_Text_TobyPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_ResortGorgeous_Text_DaisyRematchIntro::
	.string "With these hands, I will create\n"
	.string "my victory today.$"

FiveIsland_ResortGorgeous_Text_CelinaRematchIntro::
	.string "Must I repeat myself?\n"
	.string "I'm trying to paint.\l"
	.string "Please keep out of my sight!$"

FiveIsland_ResortGorgeous_Text_RaynaRematchIntro::
	.string "I haven't made any progress…\n"
	.string "I still can't get the right angle…$"

FiveIsland_ResortGorgeous_Text_JackiRematchIntro::
	.string "Oh, you will give me another\n"
	.string "opportunity to match wits with you?$"

FiveIsland_ResortGorgeous_Text_GillianRematchIntro::
	.string "They're almost finished making the\n"
	.string "pool for my POKéMON.\p"
	.string "You must drop in for a visit.$"

FiveIsland_ResortGorgeous_Text_DestinRematchIntro::
	.string "I'm a good runner.\n"
	.string "I've gotten even faster!$"

FiveIsland_ResortGorgeous_Text_TobyRematchIntro::
	.string "I say, friend!\n"
	.string "Let us enjoy our time together!$"
