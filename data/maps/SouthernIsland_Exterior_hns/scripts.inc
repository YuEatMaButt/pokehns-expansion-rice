SouthernIsland_Exterior_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Exterior_hns_OnTransition
	.byte 0

SouthernIsland_Exterior_hns_OnTransition:
	setflag FLAG_VISITED_CERULEAN_CITY
	end

SouthernIsland_Exterior_hns_EventScript_Sailor::
	lock
	faceplayer
	msgbox EventTicket_Text_SouthernIslandSailBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Exterior_hns_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_SAILOR, MAP_SOUTHERN_ISLAND_EXTERIOR_HNS
	setvar VAR_0x8004, LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

SouthernIsland_Exterior_hns_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

SouthernIsland_Exterior_hns_EventScript_Sign::
	msgbox SouthernIsland_Exterior_Text_Sign, MSGBOX_SIGN
	end

SouthernIsland_Exterior_hns_EventScript_BrendanStatus::
    goto_if_not_defeated TRAINER_BRENDAN_HNS, SouthernIsland_Exterior_hns_EventScript_Brendan //Pretty simple, if undefeated Brendan will introduce himself.
	goto_if_unset TRAINER_BRENDAN_HNS, SouthernIsland_Exterior_hns_EventScript_BrendanRematch //Also simple, if defeated Brendan will request a rematch.
    end //If the above are NOT true, do nothing.

SouthernIsland_Exterior_hns_EventScript_Brendan::
	lock
	faceplayer
	playbgm MUS_DUMMY, FALSE
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, Common_Movement_ExclamationMark
	delay 20
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting2, MSGBOX_DEFAULT
	closemessage
	playse SE_M_DOUBLE_SLAP
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_X
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceRight
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting4, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting5, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceDown
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting6, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting7, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceUp
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting8, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanMeeting9, MSGBOX_DEFAULT
	call SouthernIsland_Exterior_hns_EventScript_BrendanBattle


SouthernIsland_Exterior_hns_Text_BrendanMeeting1:
	.string ".........................\n"
	.string ".........................$"

SouthernIsland_Exterior_hns_Text_BrendanMeeting2:
	.string "???: Hey...! I know you!\n"
	.string "You're the new KANTO CHAMPION\l"
	.string "I keep hearing about!\p"
	.string "Yeah, news like that even spreads\n"
	.string "around HOENN too.\p"
	.string "I'm BRENDAN, by the way.$"

SouthernIsland_Exterior_hns_Movement_X:
	emote_x
	step_end

SouthernIsland_Exterior_hns_Text_BrendanMeeting3:
	.string "Man, why did it take so long\n"
	.string "for us to meet?!$"

SouthernIsland_Exterior_hns_Movement_BrendanFaceRight:
	face_right
	step_end

SouthernIsland_Exterior_hns_Text_BrendanMeeting4:
	.string "Ever since becoming\n"
	.string "HOENN CHAMPION and collecting the\l"
	.string "symbols at the BATTLE FRONTIER,\l"
	.string "there really isn't much\l"
	.string "left to challenge.$"

SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft:
	face_left
	step_end

SouthernIsland_Exterior_hns_Text_BrendanMeeting5:
	.string "I can't even get a good\n"
	.string "fight these days.$"

SouthernIsland_Exterior_hns_Movement_BrendanFaceDown:
	face_down
	step_end

SouthernIsland_Exterior_hns_Text_BrendanMeeting6:
	.string "I win too easily for the\n"
	.string "POKéMON LEAGUE and GYM LEADERS\l"
	.string "to be worth training with.\p"
	.string "STEVEN is out doing his own thing.\p"
	.string "WALLY is off training at some\n"
	.string "place called the BATTLE MAISON.\p"
	.string "And MAY...\p"
	.string "Well, she's nice and I like her.\p"
	.string "She got stronger recently, but\n"
	.string "her thing is helping PROF. BIRCH\l"
	.string "with his POKéMON research.$"

SouthernIsland_Exterior_hns_Text_BrendanMeeting7:
	.string "Get what I'm saying?\p"
	.string "Don't get me wrong, I'll always\n"
	.string "be proud of the journey that led me\l"
	.string "to this point and the POKéMON that\l"
	.string "followed me all the way through.$"

SouthernIsland_Exterior_hns_Movement_BrendanFaceUp:
	face_up
	step_end

SouthernIsland_Exterior_hns_Text_BrendanMeeting8:
	.string "But it's not easy staying at the top,\n"
	.string "even if there's no one rising to\l"
	.string "challenge me.\p"
	.string "Then I heard about you.\p"
	.string "Conquering the POKéMON LEAGUE\n"
	.string "of two regions!\p"
	.string "I promise you, that is a feat\n"
	.string "not many people achieve.$"

SouthernIsland_Exterior_hns_Text_BrendanMeeting9:
	.string "With that said, I'm done waiting!\p"
	.string "{PLAYER}, right?\p"
	.string "You came to this island for a reason.\p"
	.string "And here I was just considering\n"
	.string "looking for you myself.\p"
	.string "Then get ready, {PLAYER}!\p"
	.string "Show me the strength you used to\n"
	.string "conquer the JOHTO and KANTO LEAGUE!$"

SouthernIsland_Exterior_hns_EventScript_BrendanBattle::
    trainerbattle_no_intro TRAINER_BRENDAN_HNS, SouthernIsland_Exterior_hns_Text_BrendanDefeat
	call SouthernIsland_Exterior_hns_EventScript_BrendanBeat

SouthernIsland_Exterior_hns_Text_BrendanDefeat:
	.string "...!\p"
	.string "I was ready for a challenge...\p"
	.string "But to lose?$"

SouthernIsland_Exterior_hns_EventScript_BrendanBeat::
	playbgm MUS_CREDITS, FALSE
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceRight
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceDown
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat4, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat5, MSGBOX_DEFAULT
	giveitem ITEM_CATCHING_CHARM
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat6, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceRight
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat7, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat8, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceUp
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat9, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SOUTHERN_ISLAND_EXTERIOR_HNS_BRENDAN, SouthernIsland_Exterior_hns_Movement_BrendanFaceLeft
	delay 20
	msgbox SouthernIsland_Exterior_hns_Text_BrendanBeat10, MSGBOX_DEFAULT
    fadedefaultbgm
    release
    end

SouthernIsland_Exterior_hns_Text_BrendanBeat1:
	.string "...\p"
	.string ".........................\n"
	.string ".........................$"

SouthernIsland_Exterior_hns_Text_BrendanBeat2:
	.string "Gosh... I wasn't expecting that.\p"
	.string "I'm frustrated that I lost, but\n"
	.string "at the same time...$"

SouthernIsland_Exterior_hns_Text_BrendanBeat3:
	.string "I'm relieved.\p"
	.string "Relieved that I'm not the\n"
	.string "only one standing at the top.\p"
	.string "I can tell everyone in their\n"
	.string "POKé BALLS are just as happy.$"

SouthernIsland_Exterior_hns_Text_BrendanBeat4:
	.string "It just feels so weird to be given\n"
	.string "such a reality check.$"

SouthernIsland_Exterior_hns_Text_BrendanBeat5:
	.string "Uhm... here.\p"
	.string "You did great, so...\n"
	.string "you should have this.$"

SouthernIsland_Exterior_hns_Text_BrendanBeat6:
	.string "That should make it a bit easier to\n"
	.string "catch whatever POKéMON you're trying\l"
	.string "to find.\p"
	.string "As for me...$"

SouthernIsland_Exterior_hns_Text_BrendanBeat7:
	.string "I think I should explore what\n"
	.string "the rest of the world has to offer.\p"
	.string "Not just to get stronger.\p"
	.string "But to find what's more to life than\n"
	.string "just battles and contests.$"

SouthernIsland_Exterior_hns_Text_BrendanBeat8:
	.string "I know you beat me not\n"
	.string "from strength alone.\p"
	.string "You took extra steps beyond\n"
	.string "becoming CHAMPION.$"

SouthernIsland_Exterior_hns_Text_BrendanBeat9:
	.string "Maybe I could learn more from you\n"
	.string "while I'm here...\p"
	.string "It would be a blast if\n"
	.string "we have a rematch.\p"
	.string "But still...$"

SouthernIsland_Exterior_hns_Text_BrendanBeat10:
	.string "Thanks, {PLAYER}.$"

SouthernIsland_Exterior_hns_EventScript_BrendanRematch::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	faceplayer
	msgbox SouthernIsland_Exterior_hns_Text_BrendanRematchRequest, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, SouthernIsland_Exterior_hns_EventScript_RematchBrendanDeclined
	call SouthernIsland_Exterior_hns_EventScript_RematchBrendanBattle

SouthernIsland_Exterior_hns_Text_BrendanRematchRequest:
	.string "BRENDAN: {PLAYER}!\p"
	.string "How have you been holding up?\p"
	.string "Well, we could do away with\n"
	.string "the small talk if a rematch\l"
	.string "is what you're here for.\p"
	.string "How about it? I got plenty\n"
	.string "of berries to give if you win.$"

SouthernIsland_Exterior_hns_EventScript_RematchBrendanDeclined:
    closemessage
    fadedefaultbgm
	release
	end

SouthernIsland_Exterior_hns_EventScript_RematchBrendanBattle::
    trainerbattle_no_intro TRAINER_BRENDAN_HNS, SouthernIsland_Exterior_hns_Text_BrendanDefeat
	msgbox SouthernIsland_Exterior_hns_Text_RematchBrendanDefeated, MSGBOX_DEFAULT
	giveitem ITEM_ENIGMA_BERRY, 5
	giveitem ITEM_MICLE_BERRY, 5
	giveitem ITEM_CUSTAP_BERRY, 5
	giveitem ITEM_JABOCA_BERRY, 5
	giveitem ITEM_ROWAP_BERRY, 5
	closemessage
	release
	end

SouthernIsland_Exterior_hns_Text_RematchBrendanDefeated:
	.string "Lost again...\p"
	.string "Well, you earned this one.\p"
	.string "Have fun with these!$"





