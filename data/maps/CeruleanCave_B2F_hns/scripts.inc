CeruleanCave_B2F_hns_MapScripts::
	.byte 0

CeruleanCave3_EventScript_MewtwoNew::
	lock
	faceplayer
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_MEWTWO, 80
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave3_EventScript_MewtwoRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEANCAVE_MEWTWO
	setflag FLAG_HIDE_MEWTWO
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

CeruleanCave3_EventScript_MewtwoRan::
	release
	end

CeruleanCave3_EventScript_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

CeruleanCave3_EventScript_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

CeruleanCave3_EventScript_LeafStatus::
    goto_if_not_defeated TRAINER_LEAF_HNS, CeruleanCave3_EventScript_Leaf //Pretty simple, if undefeated Leaf will introduce herself.
	goto_if_unset TRAINER_LEAF_HNS, CeruleanCave3_EventScript_LeafBeat
    end //If the above are NOT true, do nothing.

CeruleanCave3_EventScript_Leaf::
    lock
    playbgm MUS_RG_ROCKET_HIDEOUT, FALSE 
    delay 20
	faceplayer
	playse SE_BALL_THROW
	fadescreen FADE_TO_BLACK
	delay 10
	playse SE_M_DOUBLE_SLAP
	msgbox CeruleanCave3_Text_LeafMeeting1, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_FROM_BLACK
	delay 30	
	playse SE_PIN
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, Common_Movement_ExclamationMark
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting2, MSGBOX_DEFAULT
	closemessage
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceUp
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting3, MSGBOX_DEFAULT
	closemessage
	faceplayer
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting4, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceUp
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting5, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox CeruleanCave3_Text_LeafMeeting6, MSGBOX_DEFAULT
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox CeruleanCave3_Text_LeafMeeting7, MSGBOX_DEFAULT
	call CeruleanCave3_EventScript_LeafBattle

CeruleanCave3_Movement_LeafFaceUp:
	face_up
	step_end

CeruleanCave3_Text_LeafMeeting1:
	.string "Ow!\p"
	.string "You were hit by a\n"
	.string "low-flying POKé BALL!$"

CeruleanCave3_Text_LeafMeeting2:
	.string "???: Oh, whoops!\p"
	.string "Sorry, I thought you\n"
	.string "were a POKéMON!\p"
	.string "Man, it's so dark in here...!$"

CeruleanCave3_Text_LeafMeeting3:
	.string "Oh, uhm...$"

CeruleanCave3_Text_LeafMeeting4:
	.string "I'm LEAF!\p"
	.string "And you're...\p"
	.string "Okay! Hi, {PLAYER}!\p"
	.string "Say, if you're here...\p"
	.string "That must mean you're\n"
	.string "KANTO CHAMPION now!\p"
	.string "Yeah, that's awesome!\n"
	.string "I'm on the same boat!\p"
	.string "Or at least I was until\n"
	.string "I lost the title.$"

CeruleanCave3_Text_LeafMeeting5:
	.string "How long has that been...\n"
	.string "since leaving PALLET TOWN\l"
	.string "with those two.$"

CeruleanCave3_Text_LeafMeeting6:
	.string "Hey! Let's battle!\p"
	.string "It's been awhile since\n"
	.string "I came across a trainer\l"
	.string "like you, {PLAYER}!\p"
	.string "I'm warning you though:$"

CeruleanCave3_Text_LeafMeeting7:
	.string "I'm very strong!$"

CeruleanCave3_EventScript_LeafBattle::
    trainerbattle_no_intro TRAINER_LEAF_HNS, CeruleanCave3_Text_LeafDefeat
	end

CeruleanCave3_Text_LeafDefeat:
	.string "I lost! That was incredible!\p"
	.string "You're something else, {PLAYER}!$"

CeruleanCave3_EventScript_LeafBeat::
	playbgm MUS_RG_SLOW_PALLET, FALSE 
	playse SE_CONTEST_HEART
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_Heart
	delay 20
	msgbox CeruleanCave3_Text_LeafBeat1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, Common_Movement_ExclamationMark
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceUp
	delay 20
	msgbox CeruleanCave3_Text_LeafBeat2, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	msgbox CeruleanCave3_Text_LeafBeat3, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveegg SPECIES_EEVEE, isShiny
	call CeruleanCave3_EventScript_LeafAfterEgg

CeruleanCave3_EventScript_LeafAfterEgg::
	msgbox CeruleanCave3_Text_LeafEgg1, MSGBOX_DEFAULT	
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceUp
	delay 30
	msgbox CeruleanCave3_Text_LeafEgg2, MSGBOX_DEFAULT
	msgbox CeruleanCave3_Text_LeafEgg3, MSGBOX_DEFAULT
    fadedefaultbgm
	release
	end

CeruleanCave3_Movement_Heart:
	emote_heart
	step_end

CeruleanCave3_Text_LeafBeat1:
	.string "You don't beat around the bush\n"
	.string "do you?\p"
	.string "That was about as much fun\n"
	.string "I ever had since losing the\l"
	.string "CHAMPION title!\p"
	.string "Who beat me?$"

CeruleanCave3_Text_LeafBeat2:
	.string "Nope!\p"
	.string "My secret!\p"
	.string "But I can tell you one thing:\n"
	.string "Even if I told you, you probably\l"
	.string "toppled them already!$"

CeruleanCave3_Text_LeafBeat3:
	.string "Here!\p"
	.string "You deserve this!$"

CeruleanCave3_Text_LeafEgg1:
	.string "You know.\p"
	.string "It's not just being the\n"
	.string "KANTO CHAMPION that I'm seeing.\p"
	.string "You're kind of like those two.\p"
	.string "They were always neck-and-neck\n"
	.string "with each other, trying to see\l"
	.string "who's the better trainer.\p"
	.string "Their rivalry came to a head at\n"
	.string "the POKéMON LEAGUE.\p"
	.string "They had rematches afterward,\n"
	.string "but each battle made them\l"
	.string "better friends over time.\p"
	.string "You probably knew someone like\n"
	.string "that in your journey, right?$"

CeruleanCave3_Text_LeafEgg2:
	.string "We walk our own paths.\p"
	.string "It can get lonely.\p"
	.string "But not only do we have our\l"
	.string "POKéMON...\p"
	.string "We also have long-lasting\n"
	.string "connections with the people\l"
	.string "we bond with.\p"
	.string "Even if we're apart.$"

CeruleanCave3_Text_LeafEgg3:
	.string "So...\p"
	.string "I'm down for another match\n"
	.string "next time you stop by!$"



