FourIsland_House1_hns_MapScripts::
	.byte 0

FourIsland_House1_EventScript_BodySlamTutor::
	lock
	faceplayer
	msgbox Text_BodySlamTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FourIsland_House1_EventScript_BodySlamDeclined
	msgbox Text_BodySlamWhichMon
	setvar VAR_0x8005, MOVE_BODY_SLAM
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_RESULT, FALSE, FourIsland_House1_EventScript_BodySlamDeclined
	msgbox Text_BodySlamTaught
	release
	end

FourIsland_House1_EventScript_BodySlamDeclined::
	msgbox Text_BodySlamDeclined
	release
	end

FourIsland_House1_EventScript_FatMan::
	msgbox FourIsland_House1_Text_YoureAwfullyHeavy, MSGBOX_NPC
	end

FourIsland_House1_Text_YoureAwfullyHeavy::
	.string "There! Boing!\n"
	.string "You're awfully heavy!$"
