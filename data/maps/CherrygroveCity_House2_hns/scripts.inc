CherrygroveCity_House2_hns_MapScripts::
        .byte 0

CherrygroveCity_House2_EventScript_GuideGent::
        lock
        faceplayer
        goto_if_set FLAG_DEXNAV_GET, CherrygroveCity_House2_EventScript_GuideGent_AlreadyHasDexNav
        showmoneybox 0, 0
        msgbox CherrygroveCity_GuideHouse_Text_DexNavOffer, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, CherrygroveCity_House2_EventScript_GuideGent_DeclinePurchase
        checkmoney 15000
        goto_if_eq VAR_RESULT, FALSE, CherrygroveCity_House2_EventScript_GuideGent_NotEnoughMoney
        removemoney 15000
        playse SE_SHOP
        updatemoneybox
        setflag FLAG_DEXNAV_GET
        msgbox CherrygroveCity_GuideHouse_Text_DexNavPurchased, MSGBOX_DEFAULT
        hidemoneybox
        release
        end

CherrygroveCity_House2_EventScript_GuideGent_DeclinePurchase::
        msgbox CherrygroveCity_GuideHouse_Text_DexNavDeclined, MSGBOX_DEFAULT
        hidemoneybox
        release
        end

CherrygroveCity_House2_EventScript_GuideGent_NotEnoughMoney::
        msgbox CherrygroveCity_GuideHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
        hidemoneybox
        release
        end

CherrygroveCity_House2_EventScript_GuideGent_AlreadyHasDexNav::
        msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
        release
        end

CherrygroveCity_GuideHouse_Text_DexNavOffer:
        .string "I have a DEX NAV I can part with.\p"
        .string "I'll sell it to you for ¥15,000.\n"
        .string "Interested?$"

CherrygroveCity_GuideHouse_Text_DexNavPurchased:
        .string "Excellent! It's all yours!\p"
        .string "The DEX NAV is now available!\p"
        .string "You can access it from the\n"
        .string "START menu.$"

CherrygroveCity_GuideHouse_Text_DexNavDeclined:
        .string "No problem. Let me know if\n"
        .string "you change your mind.$"

CherrygroveCity_GuideHouse_Text_NotEnoughMoney:
        .string "You don't have enough money!$"

CherrygroveCity_GuideHouse_Text_GuideGent:
        .string "When I was a wee lad, I was a\n"
        .string "hotshot trainer!\p"
        .string "Here's a word of advice:\n"
        .string "Catch lots of POKéMON!\p"
        .string "Treat them all with kindness!$"
