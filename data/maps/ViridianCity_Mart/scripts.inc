ViridianCity_Mart_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, ViridianCity_Mart_OnLoad
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_Mart_OnFrame
    .byte 0

ViridianCity_Mart_OnLoad:
    goto_if_unset FLAG_SYS_POKEDEX_GET, ViridianCity_Mart_EventScript_HideQuestionnaire
    end

ViridianCity_Mart_EventScript_HideQuestionnaire::
    setmetatile 1, 3, METATILE_Mart_CounterMid_Top, 1
    setmetatile 1, 4, METATILE_Mart_CounterMid_Bottom, 1
    end

ViridianCity_Mart_OnFrame:
    map_script_2 VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 0, ViridianCity_Mart_EventScript_ParcelScene
    .2byte 0

ViridianCity_Mart_EventScript_ParcelScene::
    lockall
    applymovement LOCALID_VIRIDIAN_MART_CLERK, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    msgbox ViridianCity_Mart_Text_YouCameFromPallet, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_VIRIDIAN_MART_CLERK, ViridianCity_Mart_Movement_FacePlayer
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Mart_Movement_ApproachCounter
    waitmovement 0
    msgbox ViridianCity_Mart_Text_TakeThisToProfOak
    setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1
    giveitem_msg ViridianCity_Mart_Text_ReceivedOaksParcelFromClerk, ITEM_OAKS_PARCEL, 1, MUS_RG_OBTAIN_KEY_ITEM
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 5
    releaseall
    end

ViridianCity_Mart_Movement_ApproachCounter::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_in_place_faster_left
    step_end

ViridianCity_Mart_Movement_FacePlayer::
    delay_16
    delay_16
    delay_16
    delay_16
    walk_in_place_faster_right
    step_end

ViridianCity_Mart_EventScript_Clerk::
    lock
    faceplayer
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1
    goto_if_eq ViridianCity_Mart_EventScript_SayHiToOak
    message gText_HowMayIServeYou
    waitmessage
    pokemart ViridianCity_Mart_Items
    msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
    release
    end

    .align 2
ViridianCity_Mart_Items::
    .2byte ITEM_POKE_BALL
    .2byte ITEM_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_NONE
    release
    end

ViridianCity_Mart_EventScript_SayHiToOak::
    msgbox ViridianCity_Mart_Text_SayHiToOakForMe, MSGBOX_DEFAULT
    release
    end

ViridianCity_Mart_EventScript_Woman::
    msgbox ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes, MSGBOX_NPC
    end

ViridianCity_Mart_EventScript_Youngster::
    msgbox ViridianCity_Mart_Text_GotToBuySomePotions, MSGBOX_NPC
    end

ViridianCity_Mart_Text_YouCameFromPallet::
    .string "Hey!\n"
    .string "You came from Pallet Town?$"

ViridianCity_Mart_Text_TakeThisToProfOak::
    .string "You know Prof. Oak, right?\p"
    .string "His order came in.\n"
    .string "Can I get you to take it to him?$"

ViridianCity_Mart_Text_ReceivedOaksParcelFromClerk::
    .string "{PLAYER} received Oak's Parcel\n"
    .string "from the Pokémon Mart clerk.$"

ViridianCity_Mart_Text_SayHiToOakForMe::
    .string "Okay, thanks! Please say hi to\n"
    .string "Prof. Oak for me, too.$"

ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes::
    .string "This shop does good business in\n"
    .string "Antidotes, I've heard.$"

ViridianCity_Mart_Text_GotToBuySomePotions::
    .string "I've got to buy some Potions.\p"
    .string "You never know when your Pokémon\n"
    .string "will need quick healing.$"
