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
    giveitem ITEM_VENUSAURITE
    giveitem ITEM_CHARIZARDITE_X
    giveitem ITEM_CHARIZARDITE_Y
    giveitem ITEM_BLASTOISINITE
    giveitem ITEM_BEEDRILLITE
    giveitem ITEM_PIDGEOTITE
    giveitem ITEM_ALAKAZITE
    giveitem ITEM_SLOWBRONITE
    giveitem ITEM_GENGARITE
    giveitem ITEM_KANGASKHANITE
    giveitem ITEM_PINSIRITE
    giveitem ITEM_GYARADOSITE
    giveitem ITEM_AERODACTYLITE
    giveitem ITEM_MEWTWONITE_X
    giveitem ITEM_MEWTWONITE_Y
    giveitem ITEM_AMPHAROSITE
    giveitem ITEM_STEELIXITE
    giveitem ITEM_SCIZORITE
    giveitem ITEM_HERACRONITE
    giveitem ITEM_HOUNDOOMINITE
    giveitem ITEM_TYRANITARITE
    giveitem ITEM_SCEPTILITE
    giveitem ITEM_BLAZIKENITE
    giveitem ITEM_SWAMPERTITE
    giveitem ITEM_GARDEVOIRITE
    giveitem ITEM_SABLENITE
    giveitem ITEM_MAWILITE
    giveitem ITEM_AGGRONITE
    giveitem ITEM_MEDICHAMITE
    giveitem ITEM_MANECTITE
    giveitem ITEM_SHARPEDONITE
    giveitem ITEM_CAMERUPTITE
    giveitem ITEM_ALTARIANITE
    giveitem ITEM_BANETTITE
    giveitem ITEM_ABSOLITE
    giveitem ITEM_GLALITITE
    giveitem ITEM_SALAMENCITE
    giveitem ITEM_METAGROSSITE
    giveitem ITEM_LATIASITE
    giveitem ITEM_LATIOSITE
    giveitem ITEM_LOPUNNITE
    giveitem ITEM_GARCHOMPITE
    giveitem ITEM_LUCARIONITE
    giveitem ITEM_ABOMASITE
    giveitem ITEM_GALLADITE
    giveitem ITEM_AUDINITE
    giveitem ITEM_DIANCITE

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
	.string "becoming PROF.ELM's assistant.\p"
	.string "She really loves POKéMON!\p"
	.string "But then, so do I!$"

NewBarkTown_House1_Text_MegaGift:
    .string "I have something special for you.\p"
    .string "This MEGA RING will allow your POKéMON\l"
    .string "to Mega Evolve!\p"
    .string "I'm also giving you every MEGA STONE\l"
    .string "you'll need.$"

NewBarkTown_House1_Text_MegaGiftComplete:
    .string "Take good care of those MEGA STONES!\p"
    .string "Now your POKéMON can Mega Evolve!$"

NewBarkTown_House1_Text_AlreadyHasMegaRing:
    .string "You already have a MEGA RING!\p"
    .string "I hope you're enjoying Mega Evolution!$"
