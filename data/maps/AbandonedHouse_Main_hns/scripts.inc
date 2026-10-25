AbandonedHouse_Main_hns_MapScripts::
	.byte 0

AbandonedHouse_Main_ReadBook::
	msgbox AbandonedHouse_Main_Text_Book, MSGBOX_SIGN
	end

AbandonedHouse_Main_Ceruledge::
	lock
	msgbox AbandonedHouse_Main_Text_Ceruledge, MSGBOX_DEFAULT
	closemessage
	release
	end

AbandonedHouse_Main_Text_Book::
	.string "This is not for you.$"

AbandonedHouse_Main_Text_Ceruledge::
	.string "A suit of armor that looks\n"
	.string "like a POKéMON.$"
