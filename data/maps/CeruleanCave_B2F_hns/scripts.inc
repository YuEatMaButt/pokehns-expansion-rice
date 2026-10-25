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
	goto_if_unset TRAINER_LEAF_HNS, CeruleanCave3_EventScript_LeafRematch //Also simple, if defeated Leaf will request a rematch.
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
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceAway
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting3, MSGBOX_DEFAULT
	closemessage
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFacePlayer
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting4, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceAway
	delay 20
	msgbox CeruleanCave3_Text_LeafMeeting5, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, Common_Movement_ExclamationMark
	delay 20
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFacePlayer
	msgbox CeruleanCave3_Text_LeafMeeting6, MSGBOX_DEFAULT
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox CeruleanCave3_Text_LeafMeeting7, MSGBOX_DEFAULT
	call CeruleanCave3_EventScript_LeafBattle

CeruleanCave3_Movement_LeafFaceAway:
	face_away_player
	step_end

CeruleanCave3_Movement_LeafFacePlayer:
	face_player
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
	.string "I'm in the same boat!\p"
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
	call CeruleanCave3_EventScript_LeafBeat

CeruleanCave3_Text_LeafDefeat:
	.string "I lost! That was incredible!\p"
	.string "You're something else, {PLAYER}!$"

CeruleanCave3_EventScript_LeafBeat::
	playbgm MUS_RG_SLOW_PALLET, FALSE 
	playse SE_CONTEST_HEART
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_Heart
	delay 30
	msgbox CeruleanCave3_Text_LeafBeat1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, Common_Movement_ExclamationMark
	delay 20
	applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceAway
	msgbox CeruleanCave3_Text_LeafBeat2, MSGBOX_DEFAULT
	closemessage
	delay 20
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFacePlayer
	msgbox CeruleanCave3_Text_LeafBeat3, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_EEVEE, 5, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_WISH, shinyMode=SHINY_MODE_ALWAYS
	playbgm MUS_RG_CAUGHT_INTRO, FALSE
	msgbox CeruleanCave3_Text_EeveeReceived, MSGBOX_DEFAULT
	delay 50
	call CeruleanCave3_EventScript_LeafAfterEevee

CeruleanCave3_Movement_Heart:
	emote_heart
	step_end

CeruleanCave3_Text_LeafBeat1:
	.string "You don't beat around the bush\n"
	.string "do you?\p"
	.string "That was about the most fun\n"
	.string "I've had since losing the\l"
	.string "CHAMPION title!\p"
	.string "Who beat me?$"

CeruleanCave3_Text_LeafBeat2:
	.string "Nope!\p"
	.string "My secret!\p"
	.string "But I can tell you one thing.\p"
	.string "Even if I told you:$"

CeruleanCave3_Text_LeafBeat3:
	.string "You probably toppled them already!\p"
	.string "Here!\p"
	.string "I just hatched this EEVEE,\n"
	.string "but I think you deserve this!$"

CeruleanCave3_Text_EeveeReceived:
	.string "{PLAYER} received EEVEE!$"

CeruleanCave3_EventScript_LeafAfterEevee:: 
	msgbox CeruleanCave3_Text_LeafEevee1, MSGBOX_DEFAULT	
	closemessage
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFaceAway
	delay 30
	msgbox CeruleanCave3_Text_LeafEevee2, MSGBOX_DEFAULT
	closemessage
    applymovement2 LOCALID_CERLUEANCAVE3_LEAF, CeruleanCave3_Movement_LeafFacePlayer
	delay 30
	msgbox CeruleanCave3_Text_LeafEevee3, MSGBOX_DEFAULT
    fadedefaultbgm
	release
	end

CeruleanCave3_Text_LeafEevee1:
	.string "You know.\p"
	.string "I don't think you're just some\n"
	.string "trainer who became KANTO CHAMPION.\p"
	.string "You remind me of those two.\p"
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

CeruleanCave3_Text_LeafEevee2:
	.string "We walk our own paths.\p"
	.string "It can get lonely.\p"
	.string "But not only do we have our\n"
	.string "POKéMON...\p"
	.string "We also have long-lasting\n"
	.string "connections with the people\l"
	.string "we bond with.\p"
	.string "Even if we're apart.$"

CeruleanCave3_Text_LeafEevee3:
	.string "So...\p"
	.string "I'm down for another match\n"
	.string "next time you stop by!$"

CeruleanCave3_EventScript_LeafRematch::
	lock
	playbgm MUS_RG_SLOW_PALLET, FALSE
	faceplayer
	msgbox CeruleanCave3_Text_LeafRematchRequest, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, CeruleanCave3_EventScript_RematchLeafDeclined
	call CeruleanCave3_EventScript_RematchLeafBattle

CeruleanCave3_Text_LeafRematchRequest:
	.string "Hey there, {PLAYER}!\p"
	.string "This cave is a great spot\n"
	.string "for training!\p"
	.string "Up for a rematch? Got something\n"
	.string "nice you could use if you win!$"

CeruleanCave3_EventScript_RematchLeafDeclined:
    closemessage
    fadedefaultbgm
	release
	end

CeruleanCave3_EventScript_RematchLeafBattle::
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox CeruleanCave3_Text_RematchLeafChallengeAccepted, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_LEAF_HNS, CeruleanCave3_Text_LeafDefeat
	msgbox CeruleanCave3_Text_RematchLeafDefeated, MSGBOX_DEFAULT
	giveitem ITEM_MAX_REVIVE, 1
	closemessage
	release
	end

CeruleanCave3_Text_RematchLeafChallengeAccepted:
	.string "This time, I'll win!$"

CeruleanCave3_Text_RematchLeafDefeated:
	.string "Here, as promised!\p"
	.string "Let's battle again soon!$"




