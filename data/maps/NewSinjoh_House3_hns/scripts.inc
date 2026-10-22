NewSinjoh_House3_hns_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, NewSinjoh_House3_OnFrame
    map_script MAP_SCRIPT_ON_LOAD, NewSinjoh_House3_OnTransition
    .byte 0


NewSinjoh_House3_OnTransition::
    call_if_ge VAR_NOBLE_TYPHLOSION, 2, NewSinjoh_House3_AddStairs
    end

NewSinjoh_House3_AddStairs::
    setmetatile 38, 13, 0x015, TRUE
	setmetatile 38, 14, 0x005, TRUE
	setmetatile 38, 15, 0x00D, TRUE
	setmetatile 39, 14, 0x006, TRUE
	setmetatile 39, 15, 0x00E, TRUE
	setmetatile 40, 14, 0x007, FALSE
	setmetatile 40, 15, 0x00F, FALSE
    return

NewSinjoh_House3_OnFrame:
    map_script_2 VAR_TEMP_0, 0, NewSinjoh_HauntedHouse_EventScript_Enter
    map_script_2 VAR_SINJOH_STORYLINE, 13, NewSinjoh_HauntedHouse_EventScript_CynthiaStatus //This gives you more control over which script is going to run. All this does is see if Cynthia was defeated and if the Master Ball was acquired from her. Underneathe both of these, you could insert the normal dialogue she would say after battle and Master Ball scripts are done.
	.2byte 0

NewSinjoh_HauntedHouse_EventScript_Enter::
    setvar VAR_TEMP_0, 1
    goto_if_eq VAR_NOBLE_TYPHLOSION, 1, NewSinjoh_HauntedHouse_EventScript_StartScary
    goto_if_eq VAR_NOBLE_TYPHLOSION, 0, NewSinjoh_HauntedHouse_EventScript_TooEarly
    end

NewSinjoh_HauntedHouse_EventScript_TooEarly::
    msgbox NewSinjoh_HauntedHouse_Text_TooEarlyNoReaction, MSGBOX_AUTOCLOSE
    release
    end

NewSinjoh_HauntedHouse_Text_TooEarlyNoReaction:
    .string "You sense an odd presence...\p"
    .string "But there is no reaction.$"

NewSinjoh_HauntedHouse_EventScript_StartScary::
    msgbox NewSinjoh_HauntedHouse_Text_StartScary, MSGBOX_AUTOCLOSE
    playse SE_M_DETECT
    getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
    playse SE_PIN
    applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_PLAYER
    msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
    closemessage
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
    playbgm MUS_DP_AZURE_FLUTE, FALSE
    delay 200
    fadedefaultbgm    
    special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, NewSinjoh_House3_Movement_CameraPanLeft
    waitmovement 0
    setvar VAR_0x8004, 2  @ vertical pan
    setvar VAR_0x8005, 2  @ horizontal pan
    setvar VAR_0x8006, 20  @ num shakes
    setvar VAR_0x8007, 4  @ shake delay
    special ShakeCamera
    waitstate
    call NewSinjoh_House3_AddStairs
    special DrawWholeMapView
    playse SE_CLICK
    applymovement2 OBJ_EVENT_ID_CAMERA, NewSinjoh_House3_Movement_CameraPanRight
    waitmovement 0
    special RemoveCameraObject
    addobject LOCALID_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
    clearflag FLAG_HIDE_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
    setvar VAR_NOBLE_TYPHLOSION, 2
    release
    end

NewSinjoh_House3_EventScript_NobleTyphlosion::
	lock
	faceplayer
	playmoncry SPECIES_TYPHLOSION_HISUI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_TYPHLOSION_HISUI, level=80, item=ITEM_SPOOKY_PLATE, move1_1=MOVE_INFERNAL_PARADE, move1_2=MOVE_LAVA_PLUME, move1_3=MOVE_CONFUSE_RAY move1_4=MOVE_SOLAR_BEAM
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 1, 2, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewSinjoh_House3_EventScript_NobleTyphlosionRan
    bufferspeciesname STR_VAR_1, SPECIES_TYPHLOSION_HISUI
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_SPOOKY_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
	setflag FLAG_HIDE_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

NewSinjoh_House3_EventScript_NobleTyphlosionRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

NewSinjoh_House3_Movement_CameraPanLeft:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

NewSinjoh_House3_Movement_CameraPanRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

NewSinjoh_HauntedHouse_Text_StartScary:
    .string "You sense an odd presence...\p"
    .string "Are you being watched?$"

NewSinjoh_HauntedHouse_EventScript_Log1::
    msgbox NewSinjoh_HauntedHouse_Text_Log1, MSGBOX_SIGN
    end

NewSinjoh_HauntedHouse_EventScript_Log2::
    msgbox NewSinjoh_HauntedHouse_Text_Log2, MSGBOX_SIGN
    end

NewSinjoh_HauntedHouse_EventScript_Log3::
    msgbox NewSinjoh_HauntedHouse_Text_Log3, MSGBOX_SIGN
    end

NewSinjoh_HauntedHouse_Text_Log1:
  	.string "Research Log 9:  September 20, 1975\p"
	.string "The days are getting shorter now\n"
	.string "and the wind is becoming harsh.\p"
    .string "The villagers were quite welcoming.\p"
    .string "They are allowing me to stay here\n"
    .string "in this cabin for the winter.\p"
	.string "It seems a family used to live here.\n"
	.string "I often think about my family.\p"
	.string "Maybe I will have the courage to\n"
    .string "return to them in the spring.$"

NewSinjoh_HauntedHouse_Text_Log2:
    .string "Research Log 10: October 20, 1975\p"
    .string "My thoughts have turned dark.\p"
    .string "Perhaps it is the changing of the\n"
    .string "seasons.\p"
    .string "The villagers continue to treat me\n"
    .string "as one of their own.\p"
    .string "But the guilt I carry prevents me from\n"
    .string "returning the sentiment.\p"
    .string "I rarely leave the cabin now.\p"
    .string "And when I think of my family...\n"
    .string "Their faces have changed...\l"
    .string "I only see the faces of the POKéMON\l"
    .string "that were lost at the ruins...\p"
    .string "Sometimes I think the POKéMON are\n"
    .string "here with me. I see them in\l"
    .string "reflections, I feel their gaze.\p"
    .string "Things will be better in the spring.$"

NewSinjoh_HauntedHouse_Text_Log3:
    .string "Research Log 10: November 1, 1975\p"
    .string "I am not alone here.\n"
    .string "Maybe I never was.\p"
    .string "The POKéMON are with me...\p"
    .string "They are angry with me, I think.\p"
    .string "Objects are thrown, doors slam.\p"
    .string "Heavy boxes block the front door.\p"
    .string "But truthfully, I could leave\n"
    .string "if I wanted to.\p"
    .string "There is nothing else for me now.\p"
    .string "I've written of a family before,\n"
    .string "but the POKéMON are the only family\l"
    .string "I can remember...\p"
    .string "I am running out of food, but my\n"
    .string "guilt outpaces my hunger.\p"
    .string "I think I will stay here a while...$"

NewSinjoh_HauntedHouse_EventScript_CynthiaStatus::
    goto_if_not_defeated TRAINER_CYNTHIA_HNS, NewSinjoh_HauntedHouse_EventScript_Cynthia //Pretty simple, if undefeated Cynthia will introduce herself.
    goto_if_unset FLAG_CYNTHIA_MASTERBALL, NewSinjoh_HauntedHouse_EventScript_CynthiaBeat //If the above is NOT true, and the Master Ball was not given, go to the script that gives the Master Ball.
    goto_if_ge VAR_SINJOH_STORYLINE, 14, NewSinjoh_HauntedHouse_EventScript_CynthiaRematch
    end //If the above are NOT true, do nothing.

NewSinjoh_HauntedHouse_EventScript_Cynthia::
    lock
    playbgm MUS_DP_ENCOUNTER_CHAMPION, FALSE
    playse SE_PIN
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, Common_Movement_ExclamationMark
    delay 30
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaMeeting1, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaWalkDown
    delay 30
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaMeeting2, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaFaceRight
    delay 20
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaMeeting3, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaFaceDown
    delay 20
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaMeeting4, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, NewSinjoh_HauntedHouse_EventScript_ChallengeCynthia_Declined
    call NewSinjoh_HauntedHouse_EventScript_CynthiaBattle

NewSinjoh_HauntedHouse_Text_CynthiaMeeting1:
   	.string "???: What's this?$"

NewSinjoh_HauntedHouse_Movement_CynthiaWalkDown:
	walk_down
	walk_down
    step_end

NewSinjoh_HauntedHouse_Text_CynthiaMeeting2:
	.string "Such determined eyes...\n"
	.string "What's your name?\p"
    .string "...\p"
    .string "Yes, I'll remember that!\n"
    .string "{PLAYER}, it's nice to meet you.\p"
	.string "My name's CYNTHIA.\n"
    .string "Like you, I'm a POKéMON trainer.\p"
	.string "I have an insatiable curiosity\n"
	.string "for researching POKéMON myths.$"

NewSinjoh_HauntedHouse_Movement_CynthiaFaceRight:
    face_right
    step_end

NewSinjoh_HauntedHouse_Text_CynthiaMeeting3:
	.string "You must be the one who helped\n"
    .string "STEVEN in SINJOH RUINS, right?\p"
	.string "Actually, he called me here\n"
    .string "to help investigate.\p"
    .string "Though it looks like that is\n"
    .string "no longer necessary.$"

NewSinjoh_HauntedHouse_Movement_CynthiaFaceDown:
    face_down
    step_end

NewSinjoh_HauntedHouse_Text_CynthiaMeeting4:
    .string "And yet... I've become\n"
    .string "rather curious.\p"
    .string "I would like for our\n"
    .string "POKéMON to have a match.\p"
	.string "Would you care to be my opponent?$"

NewSinjoh_HauntedHouse_EventScript_ChallengeCynthia_Declined:
	closemessage
	delay 30
    warp MAP_NEW_SINJOH_HNS, 2
	waitstate
	release
	end

NewSinjoh_HauntedHouse_EventScript_CynthiaBattle::
    msgbox NewSinjoh_HauntedHouse_Text_ChallengeCynthia, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_CYNTHIA_HNS, NewSinjoh_HauntedHouse_Text_CynthiaDefeat
    end

NewSinjoh_HauntedHouse_Text_ChallengeCynthia:
    .string "It's fascinating...\p"
    .string "My heart suddenly\n"
    .string "started to race.\p"
    .string "Everyone in their POKé BALLS\n"
    .string "are radiating in excitement...!\p"
    .string "Are you the reason?\n"
    .string "What are you?$"

NewSinjoh_HauntedHouse_EventScript_CynthiaBeat::
    playbgm MUS_DP_ENCOUNTER_CHAMPION, FALSE
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterBattle, MSGBOX_DEFAULT
    giveitem ITEM_MASTER_BALL
    setflag FLAG_CYNTHIA_MASTERBALL //This needs to be defined or she will give out infinite Master Balls.
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterItem1, MSGBOX_DEFAULT
    closemessage
    playse SE_PIN
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, Common_Movement_ExclamationMark
    delay 30
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterItem2, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaFaceRight
    delay 20
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterItem3, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaFaceDown
    delay 20
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterItem4, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaMoveUp
    delay 30
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterItem5, MSGBOX_DEFAULT
    closemessage
    applymovement2 LOCALID_NEWSINJOH_HOUSE3_CYNTHIA, NewSinjoh_HauntedHouse_Movement_CynthiaFaceDown
    delay 20
    msgbox NewSinjoh_HauntedHouse_Text_CynthiaAfterItem6, MSGBOX_DEFAULT
    setvar VAR_SINJOH_STORYLINE, 14
    fadedefaultbgm
    release
    end

NewSinjoh_HauntedHouse_Text_CynthiaDefeat:
    .string "My heart was pounding!\n"
    .string "What an amazing match!$"

NewSinjoh_HauntedHouse_Text_CynthiaAfterBattle:
    .string "This battle just went\n"
    .string "beyond expectations!\p"
    .string "How exceptional!\p"
    .string "You must have this!$"

NewSinjoh_HauntedHouse_Text_CynthiaAfterItem1:
    .string "To think you have faced\n"
    .string "the God of all POKéMON...$"

NewSinjoh_HauntedHouse_Text_CynthiaAfterItem2:
    .string "Oh! Pardon me. I was just\n"
    .string "thinking out loud.$"

NewSinjoh_HauntedHouse_Text_CynthiaAfterItem3:
    .string "No... to be honest, I am\n"
    .string "familiar with the\l"
    .string "KIMONO GIRLS of NEW SINJOH.$"

NewSinjoh_HauntedHouse_Text_CynthiaAfterItem4:
    .string "I've heard how STEVEN and\n"
    .string "DEVON CORP were not going\l"
    .string "to be able to handle the\l"
    .string "disaster coming in this small\l"
    .string "but beautiful town.\p"
    .string "I have to agree.\p"
    .string "As much as I wanted to help,\n"
    .string "I figured this situation was\l"
    .string "going to take more than the\l"
    .string "joined forces of an archeologist\l"
    .string "and a geologist.\p"
    .string "I know this from experience.\p"
    .string "Fortunately, you were the\n"
    .string "significant force that helped.$"

NewSinjoh_HauntedHouse_Movement_CynthiaMoveUp:
    walk_up
    walk_up
    step_end

NewSinjoh_HauntedHouse_Text_CynthiaAfterItem5:
    .string "I will be staying here for\n"
    .string "a while to study the\l"
    .string "SINJOH RUINS for any piece of\l"
    .string "information that may have\l"
    .string "been missed.$"

NewSinjoh_HauntedHouse_Text_CynthiaAfterItem6:
    .string "You have proven yourself\n"
    .string "to be a great trainer and\l"
    .string "I can tell you have\l"
    .string "experienced so much\l"
    .string "before coming here.\p"
    .string "It would make me happy\n"
    .string "if I were to see you again.$"

NewSinjoh_HauntedHouse_EventScript_CynthiaRematch::
    lock
    playbgm MUS_DP_ENCOUNTER_CHAMPION, FALSE
    faceplayer
    msgbox NewSinjoh_HauntedHouse_Text_RematchCynthiaRequest, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, NewSinjoh_HauntedHouse_EventScript_RematchCynthiaDeclined
    call NewSinjoh_HauntedHouse_EventScript_CynthiaRematchBattle

NewSinjoh_HauntedHouse_Text_RematchCynthiaRequest:
    .string "CYNTHIA: Hello, {PLAYER}!\p"
    .string "This house is certainly an\n"
    .string "interesting place to stay\l"
    .string "all things considered.\p"
    .string "Fufufufu...\p"
    .string "Do you wanna live it\n"
    .string "up with a rematch?$"

NewSinjoh_HauntedHouse_EventScript_RematchCynthiaDeclined:
    closemessage
    fadedefaultbgm
	release
	end

NewSinjoh_HauntedHouse_EventScript_CynthiaRematchBattle::
    trainerbattle_no_intro TRAINER_CYNTHIA_HNS, NewSinjoh_HauntedHouse_Text_CynthiaDefeat
	givebp 50
    msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
    closemessage
	release
	end

