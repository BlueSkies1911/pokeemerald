.set LOCALID_RUBY, 1

MtEmber_RubyPath_B5F_MapScripts::
	.byte 0

MtEmber_RubyPath_B5F_EventScript_Ruby::
    lock
    faceplayer
    setflag FLAG_GOT_RUBY
    removeobject LOCALID_RUBY
    giveitem_msg MtEmber_RubyPath_B5F_Text_FoundARuby, ITEM_RUBY, 1, MUS_RG_OBTAIN_KEY_ITEM
    release
    end

MtEmber_RubyPath_B5F_EventScript_BrailleMessage::
    lockall
    setvar VAR_0x8005, 130
    braillemsgbox Braille_Text_Everything
    braillemsgbox Braille_Text_HasMeaning1
    braillemsgbox Braille_Text_Existence
    braillemsgbox Braille_Text_HasMeaning2
    braillemsgbox Braille_Text_BeingAlive
    braillemsgbox Braille_Text_HasMeaning3
    braillemsgbox Braille_Text_HaveDreams
    braillemsgbox Braille_Text_UsePower
    releaseall
    end

MtEmber_RubyPath_B5F_Text_FoundARuby::
    .string "{PLAYER} found a Ruby!$"
