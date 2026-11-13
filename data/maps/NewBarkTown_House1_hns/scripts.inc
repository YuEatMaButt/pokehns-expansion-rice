NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
    lock
    faceplayer
    checkitem ITEM_MEGA_RING
    goto_if_eq VAR_RESULT, TRUE, NewBarkTown_House1_EventScript_AlreadyHasMegaRing

    msgbox NewBarkTown_House1_Text_MegaGift, MSGBOX_DEFAULT

    giveitem ITEM_MEGA_RING
    giveitem ITEM_MEGANIUMITE
    giveitem ITEM_FERALIGITE  

    msgbox NewBarkTown_House1_Text_MegaGiftComplete, MSGBOX_DEFAULT
    closemessage
    release
    end

NewBarkTown_House1_EventScript_AlreadyHasMegaRing::
    msgbox NewBarkTown_House1_Text_AlreadyHasMegaRing, MSGBOX_DEFAULT
    closemessage
    release
    end
 


NewBarkTown_House1_Text_Neighbor:
	.string "My daughter is adamant about\n"
	.string "the wonders of Mega Evolution.\p"
	.string "She thinks everyone should!\p"
	.string "But then, so do I!$"

NewBarkTown_House1_Text_MegaGift:
    .string "I have something special for you.\p"
    .string "This MEGA RING will allow your POKéMON\l"
    .string "to Mega Evolve!\p"
    .string "I'm want you to have these Mega Stones\l"
    .string "I am rooting for you!$"

NewBarkTown_House1_Text_MegaGiftComplete:
    .string "Take good care of those Mega Stones!\p"
    .string "Now your POKéMON can Mega Evolve!$"

NewBarkTown_House1_Text_AlreadyHasMegaRing:
    .string "You already have a Mega Ring!\p"
    .string "I hope you're enjoying Mega Evolution!$"
