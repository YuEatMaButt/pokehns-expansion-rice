AbandonedHouse_Bedroom_hns_MapScripts::
	.byte 0

AbandonedHouse_Bedroom_CheckBed_LeftSide::
	msgbox AbandonedHouse_Bedroom_Text_CheckBed, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, AbandonedHouse_Bedroom_CancelWarp
	case YES, AbandonedHouse_Bedroom_Nightmare_Warp
	case MULTI_B_PRESSED, AbandonedHouse_Bedroom_CancelWarp

AbandonedHouse_Bedroom_CheckBed_RightSide::
	msgbox AbandonedHouse_Bedroom_Text_CheckBed, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, AbandonedHouse_Bedroom_CancelWarp
	case YES, AbandonedHouse_Bedroom_Dream_Warp
	case MULTI_B_PRESSED, AbandonedHouse_Bedroom_CancelWarp

AbandonedHouse_Bedroom_Nightmare_Warp::
	warp MAP_ABANDONED_HOUSE_NIGHTMARE_HNS, 10, 16
	waitstate
	end

AbandonedHouse_Bedroom_Dream_Warp::
	warp MAP_ABANDONED_HOUSE_DREAM_HNS, 8, 18
	waitstate
	end

AbandonedHouse_Bedroom_CancelWarp::
	release
	end

AbandonedHouse_Bedroom_Text_CheckBed::
	.string "You suddenly feel sleepy.\n"
	.string "Rest your eyes?$"
