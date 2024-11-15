#include "config.h"
#include "constants/global.h"
#include "constants/apprentice.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/day_night.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/roulette.h"
#include "constants/seagallop.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_tower.h"
#include "constants/trainers.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.include "data/script_cmd_table.inc"

gSpecialVars::
	.4byte gSpecialVar_0x8000
	.4byte gSpecialVar_0x8001
	.4byte gSpecialVar_0x8002
	.4byte gSpecialVar_0x8003
	.4byte gSpecialVar_0x8004
	.4byte gSpecialVar_0x8005
	.4byte gSpecialVar_0x8006
	.4byte gSpecialVar_0x8007
	.4byte gSpecialVar_0x8008
	.4byte gSpecialVar_0x8009
	.4byte gSpecialVar_0x800A
	.4byte gSpecialVar_0x800B
	.4byte gSpecialVar_Facing
	.4byte gSpecialVar_Result
	.4byte gSpecialVar_ItemId
	.4byte gSpecialVar_LastTalked
	.4byte gSpecialVar_ContestRank
	.4byte gSpecialVar_ContestCategory
	.4byte gSpecialVar_MonBoxId
	.4byte gSpecialVar_MonBoxPos
	.4byte gSpecialVar_TextColor
	.4byte gTrainerBattleOpponent_A

	.include "data/specials.inc"

gStdScripts::
	.4byte Std_ObtainItem              @ STD_OBTAIN_ITEM
	.4byte Std_FindItem                @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC               @ MSGBOX_NPC
	.4byte Std_MsgboxSign              @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault           @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo             @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose         @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration        @ STD_OBTAIN_DECORATION
	.4byte Std_RegisteredInMatchCall   @ STD_REGISTER_MATCH_CALL
	.4byte Std_MsgboxGetPoints         @ MSGBOX_GETPOINTS
	.4byte Std_MsgboxPokenav           @ MSGBOX_POKENAV
    .4byte Std_ReceivedItem            @ STD_RECEIVED_ITEM
    .4byte Std_PutItemAway             @ STD_PUT_ITEM_AWAY
gStdScripts_End::

    .include "data/maps/TradeCenter/scripts.inc"
    .include "data/maps/RecordCorner/scripts.inc"
    .include "data/maps/BattleColosseum_2P/scripts.inc"
    .include "data/maps/BattleColosseum_4P/scripts.inc"
    .include "data/maps/UnionRoom/scripts.inc"
    .include "data/maps/ViridianForest/scripts.inc"
    .include "data/maps/MtMoon_1F/scripts.inc"
    .include "data/maps/MtMoon_B1F/scripts.inc"
    .include "data/maps/MtMoon_B2F/scripts.inc"
    .include "data/maps/SSAnne_Exterior/scripts.inc"
    .include "data/maps/SSAnne_1F_Corridor/scripts.inc"
    .include "data/maps/SSAnne_2F_Corridor/scripts.inc"
    .include "data/maps/SSAnne_3F_Corridor/scripts.inc"
    .include "data/maps/SSAnne_B1F_Corridor/scripts.inc"
    .include "data/maps/SSAnne_Deck/scripts.inc"
    .include "data/maps/SSAnne_Kitchen/scripts.inc"
    .include "data/maps/SSAnne_CaptainsOffice/scripts.inc"
    .include "data/maps/SSAnne_1F_Room1/scripts.inc"
    .include "data/maps/SSAnne_1F_Room2/scripts.inc"
    .include "data/maps/SSAnne_1F_Room3/scripts.inc"
    .include "data/maps/SSAnne_1F_Room4/scripts.inc"
    .include "data/maps/SSAnne_1F_Room5/scripts.inc"
    .include "data/maps/SSAnne_1F_Room6/scripts.inc"
    .include "data/maps/SSAnne_1F_Room7/scripts.inc"
    .include "data/maps/SSAnne_2F_Room1/scripts.inc"
    .include "data/maps/SSAnne_2F_Room2/scripts.inc"
    .include "data/maps/SSAnne_2F_Room3/scripts.inc"
    .include "data/maps/SSAnne_2F_Room4/scripts.inc"
    .include "data/maps/SSAnne_2F_Room5/scripts.inc"
    .include "data/maps/SSAnne_2F_Room6/scripts.inc"
    .include "data/maps/SSAnne_B1F_Room1/scripts.inc"
    .include "data/maps/SSAnne_B1F_Room2/scripts.inc"
    .include "data/maps/SSAnne_B1F_Room3/scripts.inc"
    .include "data/maps/SSAnne_B1F_Room4/scripts.inc"
    .include "data/maps/SSAnne_B1F_Room5/scripts.inc"
    .include "data/maps/DiglettsCave_NorthEntrance/scripts.inc"
    .include "data/maps/DiglettsCave_B1F/scripts.inc"
    .include "data/maps/DiglettsCave_SouthEntrance/scripts.inc"
    .include "data/maps/RockTunnel_1F/scripts.inc"
    .include "data/maps/RockTunnel_B1F/scripts.inc"
    .include "data/maps/PokemonTower_1F/scripts.inc"
    .include "data/maps/PokemonTower_2F/scripts.inc"
    .include "data/maps/PokemonTower_3F/scripts.inc"
    .include "data/maps/PokemonTower_4F/scripts.inc"
    .include "data/maps/PokemonTower_5F/scripts.inc"
    .include "data/maps/PokemonTower_6F/scripts.inc"
    .include "data/maps/PokemonTower_7F/scripts.inc"
    .include "data/maps/UndergroundPath_NorthEntrance/scripts.inc"
    .include "data/maps/UndergroundPath_NorthSouthTunnel/scripts.inc"
    .include "data/maps/UndergroundPath_SouthEntrance/scripts.inc"
    .include "data/maps/UndergroundPath_WestEntrance/scripts.inc"
    .include "data/maps/UndergroundPath_EastWestTunnel/scripts.inc"
    .include "data/maps/UndergroundPath_EastEntrance/scripts.inc"
    .include "data/maps/RocketHideout_B1F/scripts.inc"
    .include "data/maps/RocketHideout_B2F/scripts.inc"
    .include "data/maps/RocketHideout_B3F/scripts.inc"
    .include "data/maps/RocketHideout_B4F/scripts.inc"
    .include "data/maps/RocketHideout_Elevator/scripts.inc"
    .include "data/maps/SilphCo_1F/scripts.inc"
    .include "data/maps/SilphCo_2F/scripts.inc"
    .include "data/maps/SilphCo_3F/scripts.inc"
    .include "data/maps/SilphCo_4F/scripts.inc"
    .include "data/maps/SilphCo_5F/scripts.inc"
    .include "data/maps/SilphCo_6F/scripts.inc"
    .include "data/maps/SilphCo_7F/scripts.inc"
    .include "data/maps/SilphCo_8F/scripts.inc"
    .include "data/maps/SilphCo_9F/scripts.inc"
    .include "data/maps/SilphCo_10F/scripts.inc"
    .include "data/maps/SilphCo_11F/scripts.inc"
    .include "data/maps/SilphCo_Elevator/scripts.inc"
    .include "data/maps/SeafoamIslands_1F/scripts.inc"
    .include "data/maps/SeafoamIslands_B1F/scripts.inc"
    .include "data/maps/SeafoamIslands_B2F/scripts.inc"
    .include "data/maps/SeafoamIslands_B3F/scripts.inc"
    .include "data/maps/SeafoamIslands_B4F/scripts.inc"
    .include "data/maps/PowerPlant/scripts.inc"
    .include "data/maps/PokemonMansion_1F/scripts.inc"
    .include "data/maps/PokemonMansion_2F/scripts.inc"
    .include "data/maps/PokemonMansion_3F/scripts.inc"
    .include "data/maps/PokemonMansion_B1F/scripts.inc"
    .include "data/maps/VictoryRoad_1F/scripts.inc"
    .include "data/maps/VictoryRoad_2F/scripts.inc"
    .include "data/maps/VictoryRoad_3F/scripts.inc"
    .include "data/maps/CeruleanCave_1F/scripts.inc"
    .include "data/maps/CeruleanCave_2F/scripts.inc"
    .include "data/maps/CeruleanCave_B1F/scripts.inc"
    .include "data/maps/MtEmber_Exterior/scripts.inc"
    .include "data/maps/MtEmber_SummitPath_1F/scripts.inc"
    .include "data/maps/MtEmber_SummitPath_2F/scripts.inc"
    .include "data/maps/MtEmber_SummitPath_3F/scripts.inc"
    .include "data/maps/MtEmber_Summit/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_1F/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B1F/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B2F/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B4F/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B3F/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B5F/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B1F_Stairs/scripts.inc"
    .include "data/maps/MtEmber_RubyPath_B2F_Stairs/scripts.inc"
    .include "data/maps/BerryForest/scripts.inc"
    .include "data/maps/IcefallCave_Entrance/scripts.inc"
    .include "data/maps/IcefallCave_1F/scripts.inc"
    .include "data/maps/IcefallCave_B1F/scripts.inc"
    .include "data/maps/IcefallCave_Back/scripts.inc"
    .include "data/maps/RocketWarehouse/scripts.inc"
    .include "data/maps/LostCave_Entrance/scripts.inc"
    .include "data/maps/LostCave_Room1/scripts.inc"
    .include "data/maps/LostCave_Room2/scripts.inc"
    .include "data/maps/LostCave_Room3/scripts.inc"
    .include "data/maps/LostCave_Room4/scripts.inc"
    .include "data/maps/LostCave_Room5/scripts.inc"
    .include "data/maps/LostCave_Room6/scripts.inc"
    .include "data/maps/LostCave_Room7/scripts.inc"
    .include "data/maps/LostCave_Room8/scripts.inc"
    .include "data/maps/LostCave_Room9/scripts.inc"
    .include "data/maps/LostCave_Room10/scripts.inc"
    .include "data/maps/LostCave_Room11/scripts.inc"
    .include "data/maps/LostCave_Room12/scripts.inc"
    .include "data/maps/LostCave_Room13/scripts.inc"
    .include "data/maps/LostCave_Room14/scripts.inc"
    .include "data/maps/DottedHole_1F/scripts.inc"
    .include "data/maps/DottedHole_B1F/scripts.inc"
    .include "data/maps/DottedHole_B2F/scripts.inc"
    .include "data/maps/DottedHole_B3F/scripts.inc"
    .include "data/maps/DottedHole_B4F/scripts.inc"
    .include "data/maps/DottedHole_SapphireRoom/scripts.inc"
    .include "data/maps/PatternBush/scripts.inc"
    .include "data/maps/AlteringCave/scripts.inc"
    .include "data/maps/SevaultCanyon_TanobyKey/scripts.inc"
    .include "data/maps/TanobyRuins_MoneanChamber/scripts.inc"
    .include "data/maps/TanobyRuins_LiptooChamber/scripts.inc"
    .include "data/maps/TanobyRuins_WeepthChamber/scripts.inc"
    .include "data/maps/TanobyRuins_DilfordChamber/scripts.inc"
    .include "data/maps/TanobyRuins_ScufibChamber/scripts.inc"
    .include "data/maps/TanobyRuins_RixyChamber/scripts.inc"
    .include "data/maps/TanobyRuins_ViapoisChamber/scripts.inc"
    .include "data/maps/SafariZone_Center/scripts.inc"
    .include "data/maps/SafariZone_East/scripts.inc"
    .include "data/maps/SafariZone_North/scripts.inc"
    .include "data/maps/SafariZone_West/scripts.inc"
    .include "data/maps/SafariZone_Center_RestHouse/scripts.inc"
    .include "data/maps/SafariZone_East_RestHouse/scripts.inc"
    .include "data/maps/SafariZone_North_RestHouse/scripts.inc"
    .include "data/maps/SafariZone_West_RestHouse/scripts.inc"
    .include "data/maps/SafariZone_SecretHouse/scripts.inc"
    .include "data/maps/TrainerTower_Lobby/scripts.inc"
    .include "data/maps/TrainerTower_1F/scripts.inc"
    .include "data/maps/TrainerTower_2F/scripts.inc"
    .include "data/maps/TrainerTower_3F/scripts.inc"
    .include "data/maps/TrainerTower_4F/scripts.inc"
    .include "data/maps/TrainerTower_Roof/scripts.inc"
    .include "data/maps/TrainerTower_Elevator/scripts.inc"
    .include "data/maps/BattleFrontier_OutsideWest/scripts.inc"
    .include "data/maps/BattleFrontier_OutsideEast/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerElevator/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerCorridor/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.inc"
    .include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattleDomeLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattleDomeCorridor/scripts.inc"
    .include "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc"
    .include "data/maps/BattlePyramidSquare01/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePyramidTop/scripts.inc"
    .include "data/maps/BattleFrontier_BattleArenaLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc"
    .include "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePikeLobby/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.inc"
    .include "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge1/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge2/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge3/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge4/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge5/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge6/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge7/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge8/scripts.inc"
    .include "data/maps/BattleFrontier_Lounge9/scripts.inc"
    .include "data/maps/BattleFrontier_ReceptionGate/scripts.inc"
    .include "data/maps/BattleFrontier_ScottsHouse/scripts.inc"
    .include "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc"
    .include "data/maps/BattleFrontier_RankingHall/scripts.inc"
    .include "data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc"
    .include "data/maps/BattleFrontier_PokemonCenter_2F/scripts.inc"
    .include "data/maps/BattleFrontier_Mart/scripts.inc"
    .include "data/maps/ArtisanCave_B1F/scripts.inc"
    .include "data/maps/ArtisanCave_1F/scripts.inc"
    .include "data/maps/FarawayIsland_Entrance/scripts.inc"
    .include "data/maps/FarawayIsland_Interior/scripts.inc"
    .include "data/maps/CeruleanCity_BattleTentLobby/scripts.inc"
    .include "data/maps/CeruleanCity_BattleTentCorridor/scripts.inc"
    .include "data/maps/CeruleanCity_BattleTentBattleRoom/scripts.inc"
    .include "data/maps/FuchsiaCity_BattleTentLobby/scripts.inc"
    .include "data/maps/FuchsiaCity_BattleTentCorridor/scripts.inc"
    .include "data/maps/FuchsiaCity_BattleTentBattleRoom/scripts.inc"
    .include "data/maps/SaffronCity_BattleTentLobby/scripts.inc"
    .include "data/maps/SaffronCity_BattleTentCorridor/scripts.inc"
    .include "data/maps/SaffronCity_BattleTentBattleRoom/scripts.inc"
    .include "data/maps/CeladonCity_ContestLobby/scripts.inc"
    .include "data/maps/CeladonCity_ContestHall/scripts.inc"
    .include "data/maps/ContestHall/scripts.inc"
    .include "data/maps/TrickHouseEntrance/scripts.inc"
    .include "data/maps/TrickHouseEnd/scripts.inc"
    .include "data/maps/TrickHouseCorridor/scripts.inc"
    .include "data/maps/TrickHousePuzzle1/scripts.inc"
    .include "data/maps/TrickHousePuzzle2/scripts.inc"
    .include "data/maps/TrickHousePuzzle3/scripts.inc"
    .include "data/maps/TrickHousePuzzle4/scripts.inc"
    .include "data/maps/TrickHousePuzzle5/scripts.inc"
    .include "data/maps/TrickHousePuzzle6/scripts.inc"
    .include "data/maps/TrickHousePuzzle7/scripts.inc"
    .include "data/maps/TrickHousePuzzle8/scripts.inc"
    .include "data/maps/PalletTown/scripts.inc"
    .include "data/maps/ViridianCity/scripts.inc"
    .include "data/maps/PewterCity/scripts.inc"
    .include "data/maps/CeruleanCity/scripts.inc"
    .include "data/maps/VermilionCity/scripts.inc"
    .include "data/maps/LavenderTown/scripts.inc"
    .include "data/maps/CeladonCity/scripts.inc"
    .include "data/maps/FuchsiaCity/scripts.inc"
    .include "data/maps/SaffronCity/scripts.inc"
    .include "data/maps/CinnabarIsland/scripts.inc"
    .include "data/maps/IndigoPlateau/scripts.inc"
    .include "data/maps/OneIsland/scripts.inc"
    .include "data/maps/TwoIsland/scripts.inc"
    .include "data/maps/ThreeIsland/scripts.inc"
    .include "data/maps/FourIsland/scripts.inc"
    .include "data/maps/FiveIsland/scripts.inc"
    .include "data/maps/SixIsland/scripts.inc"
    .include "data/maps/SevenIsland/scripts.inc"
    .include "data/maps/Route1/scripts.inc"
    .include "data/maps/Route2/scripts.inc"
    .include "data/maps/Route3/scripts.inc"
    .include "data/maps/Route4/scripts.inc"
    .include "data/maps/Route5/scripts.inc"
    .include "data/maps/Route6/scripts.inc"
    .include "data/maps/Route7/scripts.inc"
    .include "data/maps/Route8/scripts.inc"
    .include "data/maps/Route9/scripts.inc"
    .include "data/maps/Route10/scripts.inc"
    .include "data/maps/Route11/scripts.inc"
    .include "data/maps/Route12/scripts.inc"
    .include "data/maps/Route13/scripts.inc"
    .include "data/maps/Route14/scripts.inc"
    .include "data/maps/Route15/scripts.inc"
    .include "data/maps/Route16/scripts.inc"
    .include "data/maps/Route17/scripts.inc"
    .include "data/maps/Route18/scripts.inc"
    .include "data/maps/Route19/scripts.inc"
    .include "data/maps/Route20/scripts.inc"
    .include "data/maps/Route21/scripts.inc"
    .include "data/maps/Route22/scripts.inc"
    .include "data/maps/Route23/scripts.inc"
    .include "data/maps/Route24/scripts.inc"
    .include "data/maps/Route25/scripts.inc"
    .include "data/maps/TreasureBeach/scripts.inc"
    .include "data/maps/KindleRoad/scripts.inc"
    .include "data/maps/KindleRoad_EmberSpa/scripts.inc"
    .include "data/maps/CapeBrink/scripts.inc"
    .include "data/maps/ThreeIsland_Port/scripts.inc"
    .include "data/maps/ThreeIsland_Path/scripts.inc"
    .include "data/maps/BondBridge/scripts.inc"
    .include "data/maps/FiveIsland_Meadow/scripts.inc"
    .include "data/maps/MemorialPillar/scripts.inc"
    .include "data/maps/WaterLabyrinth/scripts.inc"
    .include "data/maps/ResortGorgeous/scripts.inc"
    .include "data/maps/WaterPath/scripts.inc"
    .include "data/maps/RuinValley/scripts.inc"
    .include "data/maps/GreenPath/scripts.inc"
    .include "data/maps/OutcastIsland/scripts.inc"
    .include "data/maps/TrainerTower_Exterior/scripts.inc"
    .include "data/maps/SevaultCanyon_Entrance/scripts.inc"
    .include "data/maps/SevaultCanyon/scripts.inc"
    .include "data/maps/TanobyRuins/scripts.inc"
    .include "data/maps/PlayersHouse_1F/scripts.inc"
    .include "data/maps/PlayersHouse_2F/scripts.inc"
    .include "data/maps/RivalsHouse/scripts.inc"
    .include "data/maps/ProfessorOaksLab/scripts.inc"
    .include "data/maps/ViridianCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/ViridianCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/ViridianCity_Mart/scripts.inc"
    .include "data/maps/ViridianCity_Gym/scripts.inc"
    .include "data/maps/ViridianCity_House1/scripts.inc"
    .include "data/maps/ViridianCity_House2/scripts.inc"
    .include "data/maps/PewterCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/PewterCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/PewterCity_Mart/scripts.inc"
    .include "data/maps/PewterCity_Gym/scripts.inc"
    .include "data/maps/PewterCity_Museum_1F/scripts.inc"
    .include "data/maps/PewterCity_Museum_2F/scripts.inc"
    .include "data/maps/PewterCity_House1/scripts.inc"
    .include "data/maps/PewterCity_House2/scripts.inc"
    .include "data/maps/CeruleanCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/CeruleanCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/CeruleanCity_Mart/scripts.inc"
    .include "data/maps/CeruleanCity_Gym/scripts.inc"
    .include "data/maps/CeruleanCity_BikeShop/scripts.inc"
    .include "data/maps/CeruleanCity_House1/scripts.inc"
    .include "data/maps/CeruleanCity_House2/scripts.inc"
    .include "data/maps/CeruleanCity_House3/scripts.inc"
    .include "data/maps/CeruleanCity_House4/scripts.inc"
    .include "data/maps/VermilionCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/VermilionCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/VermilionCity_Mart/scripts.inc"
    .include "data/maps/VermilionCity_Gym/scripts.inc"
    .include "data/maps/VermilionCity_PokemonFanClub/scripts.inc"
    .include "data/maps/VermilionCity_House1/scripts.inc"
    .include "data/maps/VermilionCity_House2/scripts.inc"
    .include "data/maps/VermilionCity_House3/scripts.inc"
    .include "data/maps/LavenderTown_PokemonCenter_1F/scripts.inc"
    .include "data/maps/LavenderTown_PokemonCenter_2F/scripts.inc"
    .include "data/maps/LavenderTown_Mart/scripts.inc"
    .include "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.inc"
    .include "data/maps/LavenderTown_House1/scripts.inc"
    .include "data/maps/LavenderTown_House2/scripts.inc"
    .include "data/maps/CeladonCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/CeladonCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStore_1F/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStore_2F/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStore_3F/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStore_4F/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStore_5F/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStoreRooftop/scripts.inc"
    .include "data/maps/CeladonCity_DepartmentStoreElevator/scripts.inc"
    .include "data/maps/CeladonCity_Gym/scripts.inc"
    .include "data/maps/CeladonCity_GameCorner/scripts.inc"
    .include "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.inc"
    .include "data/maps/CeladonCity_Restaurant/scripts.inc"
    .include "data/maps/CeladonCity_Hotel/scripts.inc"
    .include "data/maps/CeladonCity_Condominiums_1F/scripts.inc"
    .include "data/maps/CeladonCity_Condominiums_2F/scripts.inc"
    .include "data/maps/CeladonCity_Condominiums_3F/scripts.inc"
    .include "data/maps/CeladonCity_Condominiums_Roof/scripts.inc"
    .include "data/maps/CeladonCity_Condominiums_RoofRoom/scripts.inc"
    .include "data/maps/CeladonCity_House1/scripts.inc"
    .include "data/maps/FuchsiaCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/FuchsiaCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/FuchsiaCity_Mart/scripts.inc"
    .include "data/maps/FuchsiaCity_Gym/scripts.inc"
    .include "data/maps/FuchsiaCity_SafariZone_Entrance/scripts.inc"
    .include "data/maps/FuchsiaCity_SafariZone_Office/scripts.inc"
    .include "data/maps/FuchsiaCity_WardensHouse/scripts.inc"
    .include "data/maps/FuchsiaCity_House1/scripts.inc"
    .include "data/maps/FuchsiaCity_House2/scripts.inc"
    .include "data/maps/FuchsiaCity_House3/scripts.inc"
    .include "data/maps/SaffronCity_PokemonCenter_1F/scripts.inc"
    .include "data/maps/SaffronCity_PokemonCenter_2F/scripts.inc"
    .include "data/maps/SaffronCity_Mart/scripts.inc"
    .include "data/maps/SaffronCity_Gym/scripts.inc"
    .include "data/maps/SaffronCity_Dojo/scripts.inc"
    .include "data/maps/SaffronCity_PokemonTrainerFanClub/scripts.inc"
    .include "data/maps/SaffronCity_CopycatsHouse_1F/scripts.inc"
    .include "data/maps/SaffronCity_CopycatsHouse_2F/scripts.inc"
    .include "data/maps/SaffronCity_MrPsychicsHouse/scripts.inc"
    .include "data/maps/SaffronCity_House1/scripts.inc"
    .include "data/maps/CinnabarIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/CinnabarIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/CinnabarIsland_Mart/scripts.inc"
    .include "data/maps/CinnabarIsland_Gym/scripts.inc"
    .include "data/maps/PokemonLab_Entrance/scripts.inc"
    .include "data/maps/PokemonLab_Lounge/scripts.inc"
    .include "data/maps/PokemonLab_ResearchRoom/scripts.inc"
    .include "data/maps/PokemonLab_ExperimentRoom/scripts.inc"
    .include "data/maps/IndigoPlateau_PokemonCenter_1F/scripts.inc"
    .include "data/maps/IndigoPlateau_PokemonCenter_2F/scripts.inc"
    .include "data/maps/PokemonLeague_LoreleisRoom/scripts.inc"
    .include "data/maps/PokemonLeague_BrunosRoom/scripts.inc"
    .include "data/maps/PokemonLeague_AgathasRoom/scripts.inc"
    .include "data/maps/PokemonLeague_LancesRoom/scripts.inc"
    .include "data/maps/PokemonLeague_ChampionsRoom/scripts.inc"
    .include "data/maps/PokemonLeague_HallOfFame/scripts.inc"
    .include "data/maps/OneIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/OneIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/OneIsland_Harbor/scripts.inc"
    .include "data/maps/OneIsland_House1/scripts.inc"
    .include "data/maps/OneIsland_House2/scripts.inc"
    .include "data/maps/TwoIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/TwoIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/TwoIsland_Harbor/scripts.inc"
    .include "data/maps/TwoIsland_GameCorner/scripts.inc"
    .include "data/maps/TwoIsland_House/scripts.inc"
    .include "data/maps/ThreeIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/ThreeIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/ThreeIsland_Mart/scripts.inc"
    .include "data/maps/ThreeIsland_House1/scripts.inc"
    .include "data/maps/ThreeIsland_House2/scripts.inc"
    .include "data/maps/ThreeIsland_House3/scripts.inc"
    .include "data/maps/ThreeIsland_House4/scripts.inc"
    .include "data/maps/ThreeIsland_House5/scripts.inc"
    .include "data/maps/FourIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/FourIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/FourIsland_Mart/scripts.inc"
    .include "data/maps/FourIsland_Harbor/scripts.inc"
    .include "data/maps/FourIsland_PokemonDayCare/scripts.inc"
    .include "data/maps/FourIsland_LoreleisHouse/scripts.inc"
    .include "data/maps/FourIsland_House1/scripts.inc"
    .include "data/maps/FourIsland_House2/scripts.inc"
    .include "data/maps/FiveIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/FiveIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/FiveIsland_Harbor/scripts.inc"
    .include "data/maps/FiveIsland_House1/scripts.inc"
    .include "data/maps/FiveIsland_House2/scripts.inc"
    .include "data/maps/SixIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/SixIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/SixIsland_Mart/scripts.inc"
    .include "data/maps/SixIsland_Harbor/scripts.inc"
    .include "data/maps/SixIsland_House/scripts.inc"
    .include "data/maps/SevenIsland_PokemonCenter_1F/scripts.inc"
    .include "data/maps/SevenIsland_PokemonCenter_2F/scripts.inc"
    .include "data/maps/SevenIsland_Mart/scripts.inc"
    .include "data/maps/SevenIsland_Harbor/scripts.inc"
    .include "data/maps/SevenIsland_House_Room1/scripts.inc"
    .include "data/maps/SevenIsland_House_Room2/scripts.inc"
    .include "data/maps/ViridianForest_NorthEntrance/scripts.inc"
    .include "data/maps/ViridianForest_SouthEntrance/scripts.inc"
    .include "data/maps/Route2_EastBuilding/scripts.inc"
    .include "data/maps/Route2_House1/scripts.inc"
	.include "data/maps/PrettyPetalFlowerShop/scripts.inc"
    .include "data/maps/Route4_PokemonCenter_1F/scripts.inc"
    .include "data/maps/Route4_PokemonCenter_2F/scripts.inc"
    .include "data/maps/Route5_PokemonDayCare/scripts.inc"
    .include "data/maps/Route5_SouthEntrance/scripts.inc"
    .include "data/maps/Route6_NorthEntrance/scripts.inc"
    .include "data/maps/Route7_EastEntrance/scripts.inc"
    .include "data/maps/Route8_WestEntrance/scripts.inc"
    .include "data/maps/Route10_PokemonCenter_1F/scripts.inc"
    .include "data/maps/Route10_PokemonCenter_2F/scripts.inc"
    .include "data/maps/Route11_EastEntrance_1F/scripts.inc"
    .include "data/maps/Route11_EastEntrance_2F/scripts.inc"
    .include "data/maps/Route12_NorthEntrance_1F/scripts.inc"
    .include "data/maps/Route12_NorthEntrance_2F/scripts.inc"
    .include "data/maps/Route12_FishingHouse/scripts.inc"
    .include "data/maps/Route15_WestEntrance_1F/scripts.inc"
    .include "data/maps/Route15_WestEntrance_2F/scripts.inc"
    .include "data/maps/Route16_NorthEntrance_1F/scripts.inc"
    .include "data/maps/Route16_NorthEntrance_2F/scripts.inc"
    .include "data/maps/Route16_House1/scripts.inc"
    .include "data/maps/Route18_EastEntrance_1F/scripts.inc"
    .include "data/maps/Route18_EastEntrance_2F/scripts.inc"
    .include "data/maps/Route22_NorthEntrance/scripts.inc"
    .include "data/maps/SeaCottage/scripts.inc"
    .include "data/maps/CapeBrink_House/scripts.inc"
    .include "data/maps/ThreeIsland_Harbor/scripts.inc"
    .include "data/maps/ResortGorgeous_House/scripts.inc"
    .include "data/maps/WaterPath_House1/scripts.inc"
    .include "data/maps/WaterPath_House2/scripts.inc"
    .include "data/maps/SevaultCanyon_House/scripts.inc"

    .include "data/scripts/shared_secret_base.inc"
	.include "data/scripts/std_msgbox.inc"
	.include "data/scripts/trainer_battle.inc"
	.include "data/scripts/new_game.inc"
	.include "data/scripts/hall_of_fame.inc"

EventScript_WhiteOut::
	call EventScript_ResetEliteFour
	goto EventScript_ResetMrBriney
	end

EventScript_ResetMrBriney::
	goto_if_eq VAR_BRINEY_LOCATION, 1, EventScript_MoveMrBrineyToHouse
	goto_if_eq VAR_BRINEY_LOCATION, 2, EventScript_MoveMrBrineyToDewford
	goto_if_eq VAR_BRINEY_LOCATION, 3, EventScript_MoveMrBrineyToRoute109
	end

EventScript_MoveMrBrineyToHouse::
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	end

EventScript_MoveMrBrineyToDewford::
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	end

EventScript_MoveMrBrineyToRoute109::
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	end

EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_LORELEI
	clearflag FLAG_DEFEATED_BRUNO
	clearflag FLAG_DEFEATED_AGATHA
	clearflag FLAG_DEFEATED_LANCE
	clearflag FLAG_DEFEATED_CHAMP
	cleartrainerflag TRAINER_CHAMPION_FIRST_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_FIRST_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_FIRST_CHARMANDER
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 0
	return

Common_EventScript_UpdateBrineyLocation::
	goto_if_unset FLAG_RECEIVED_POKENAV, Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_KOGA, Common_EventScript_NopReturn
	goto_if_unset FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT, EventScript_SetBrineyLocation_House
	goto_if_unset FLAG_HIDE_ROUTE_109_MR_BRINEY, EventScript_SetBrineyLocation_Route109
	return

EventScript_SetBrineyLocation_House::
	setvar VAR_BRINEY_LOCATION, 1
	return

EventScript_SetBrineyLocation_Dewford::
	setvar VAR_BRINEY_LOCATION, 2
	return

EventScript_SetBrineyLocation_Route109::
	setvar VAR_BRINEY_LOCATION, 3
	return

	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/record_mix.inc"
	.include "data/scripts/pc.inc"

Common_ShowEasyChatScreen::
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

Common_EventScript_ReadyPetalburgGymForBattle::
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_PETALBURG_MART_EXPANDED_ITEMS
	return

Common_EventScript_BufferTrendyPhrase::
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

EventScript_BackupMrBrineyLocation::
	copyvar VAR_0x8008, VAR_BRINEY_LOCATION
	setvar VAR_BRINEY_LOCATION, 0
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/rival_graphics.inc"
	.include "data/scripts/set_gym_trainers.inc"

Common_EventScript_ShowBagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

Common_EventScript_ShowNoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetAbnormalWeather::
	setweather WEATHER_ABNORMAL
	return

Common_EventScript_PlayGymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_RG_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

EventScript_RegionMap::
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special FieldShowRegionMap
	waitstate
	releaseall
	end

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "Kanto region map.$"

Common_EventScript_PlayBrineysBoatMusic::
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, FALSE
	return

Common_EventScript_StopBrineysBoatMusic::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	return

EventScript_GetElevatorFloor::
    special SetDeptStoreFloor
    return

@ Below could be split as ferry.inc aside from the Rusturf tunnel script
Common_EventScript_FerryDepart::
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EventScript_HideMrBriney::
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 0
	return

RusturfTunnel_EventScript_SetRusturfTunnelOpen::
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	return

EventScript_UnusedBoardFerry::
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Movement_UnusedBoardFerry
	waitmovement 0
	delay 30
	return

Movement_UnusedBoardFerry:
	walk_up
	step_end

Ferry_EventScript_DepartIslandSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Ferry_Movement_DepartIslandBoardSouth
	waitmovement 0
	return

Ferry_EventScript_DepartIslandWest::
	applymovement OBJ_EVENT_ID_PLAYER, Ferry_Movement_DepartIslandBoardWest
	waitmovement 0
	return

Ferry_Movement_DepartIslandBoardSouth:
	walk_down
	step_end

Ferry_Movement_DepartIslandBoardWest:
	walk_left
	walk_in_place_faster_down
	step_end

Common_EventScript_FerryDepartIsland::
	call_if_eq VAR_FACING, DIR_SOUTH, Ferry_EventScript_DepartIslandSouth
	call_if_eq VAR_FACING, DIR_WEST, Ferry_EventScript_DepartIslandWest
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	call Common_EventScript_FerryDepart
	return

Common_EventScript_NameReceivedPartyMon::
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	waitstate
	return

Common_EventScript_PlayerHandedOverTheItem::
	bufferitemname STR_VAR_1, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	message gText_PlayerHandedOverTheItem
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

    .include "data/scripts/pokemon_league.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/check_furniture.inc"
	.include "data/text/record_mix.inc"
	.include "data/text/pc.inc"
	.include "data/text/pkmn_center_nurse.inc"
	.include "data/text/mart_clerk.inc"
	.include "data/text/obtain_item.inc"

@ The below and surf.inc could be split into some text/notices.inc
gText_PokemartSign::
	.string "“Selected items for your convenience!”\n"
	.string "Pokémon Mart$"

gText_PokemonCenterSign::
	.string "“Rejuvenate your tired partners!”\n"
	.string "Pokémon Center$"

gText_MomOrDadMightLikeThisProgram::
	.string "{STR_VAR_1} might like this program.\n"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Better get going!$"

gText_WantWhichFloor::
    .string "Which floor do you want?$"

gText_SandstormIsVicious::
	.string "The sandstorm is vicious.\n"
	.string "It's impossible to keep going.$"

gText_SelectWithoutRegisteredItem::
	.string "An item in the Bag can be\n"
	.string "registered to Select for easy use.$"

gText_PokemonTrainerSchoolEmail::
	.string "There's an e-mail from Pokémon Trainer\n"
	.string "School.\p"
	.string "… … … … … …\p"
	.string "A Pokémon may learn up to four moves.\p"
	.string "A Trainer's expertise is tested on the\n"
	.string "move sets chosen for Pokémon.\p"
	.string "… … … … … …$"

gText_PlayerHouseBootPC::
	.string "{PLAYER} booted up the PC.$"

gText_PokeblockLinkCanceled::
	.string "The link was cancelled.$"

gText_UnusedNicknameReceivedPokemon::
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_2} you received?$"

gText_PlayerWhitedOut::
	.string "{PLAYER} is out of usable\n"
	.string "Pokémon!\p{PLAYER} whited out!$"

gText_RegisteredTrainerinPokeNav::
	.string "Registered {STR_VAR_1} {STR_VAR_2}\n"
	.string "in the Pokénav.$"

gText_ComeBackWithSecretPower::
	.string "Do you know the TM Secret Power?\p"
	.string "Our group, we love the TM Secret\n"
	.string "Power.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"

gText_PokerusExplanation::
	.string "Your Pokémon may be infected with\n"
	.string "Pokérus.\p"
	.string "Little is known about the Pokérus\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to Pokémon.\p"
	.string "While infected, Pokémon are said to\n"
	.string "grow exceptionally well.$"

	.include "data/text/surf.inc"

gText_DoorOpenedFarAway::
	.string "It sounded as if a door opened\n"
	.string "somewhere far away.$"

gText_BigHoleInTheWall::
	.string "There is a big hole in the wall.$"

gText_SorryWirelessClubAdjustments::
	.string "I'm terribly sorry.\n"
	.string "The Pokémon Wireless Club is\l"
	.string "undergoing adjustments now.$"

gText_UndergoingAdjustments::
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

@ Unused
gText_SorryTradeCenterInspections::
	.string "I'm terribly sorry. The Trade Center\n"
	.string "is undergoing inspections.$"

@ Unused
gText_SorryRecordCornerPreparation::
	.string "I'm terribly sorry. The Record Corner\n"
	.string "is under preparation.$"

gText_PlayerHandedOverTheItem::
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

gText_ThankYouForAccessingMysteryGift::
	.string "Thank you for accessing the\n"
	.string "Mystery Gift System.$"

gText_PlayerFoundOneTMHM::
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_CardKeyOpenedDoor::
    .string "Bingo!\n"
    .string "The Card Key opened the door!$"

gText_ItNeedsCardKey::
    .string "No!\n"
    .string "It needs a Card Key!$"

gText_TheDoorIsOpen::
    .string "The door is open…$"

gText_LegendaryFlewAway::
	.string "The {STR_VAR_1} flew away!$"

gText_Gyaoo::
    .string "Gyaoo!$"

gText_SnorlaxWokeUp::
    .string "Snorlax woke up!\p"
    .string "It attacked in a grumpy rage!$"

gText_SnorlaxReturnedToMountains::
    .string "Snorlax calmed down.\n"
    .string "It gave a huge yawn…\l"
    .string "And returned to the mountains.$"

gText_WantToUsePokeFlute::
    .string "Want to use the Poké Flute?$"

gText_PlayedPokeFlute::
    .string "{PLAYER} played the Poké Flute.$"

gText_VoiceRangOutDontRunAway::
    .string "Someone's voice rang out,\n"
    .string "“Don't run away!”$"

	.include "data/text/pc_transfer.inc"
	.include "data/text/questionnaire.inc"

EventScript_SelectWithoutRegisteredItem::
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

	.include "data/scripts/field_poison.inc"

Common_EventScript_NopReturn::
	return

@ Unused
EventScript_CableClub_SetVarResult1::
	setvar VAR_RESULT, 1
	return

EventScript_CableClub_SetVarResult0::
	setvar VAR_RESULT, 0
	return

EventScript_SetExitingCyclingRoad::
	lockall
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_MAP_SCENE_ROUTE16, 0
	releaseall
	end

EventScript_SetEnteringCyclingRoad::
	lockall
	setvar VAR_MAP_SCENE_ROUTE16, 1
	releaseall
	end

EventScript_GetInGameTradeSpeciesInfo::
    copyvar VAR_0x8004, VAR_0x8008
    specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
    copyvar VAR_0x8009, VAR_RESULT
    return

EventScript_ChooseMonForInGameTrade::
    special ChoosePartyMon
    waitstate
    lock
    faceplayer
    copyvar VAR_0x800A, VAR_0x8004
    return

EventScript_GetInGameTradeSpecies::
    copyvar VAR_0x8005, VAR_0x800A
    specialvar VAR_RESULT, GetTradeSpecies
    copyvar VAR_0x800B, VAR_RESULT
    return

EventScript_DoInGameTrade::
    copyvar VAR_0x8004, VAR_0x8008
    copyvar VAR_0x8005, VAR_0x800A
    special CreateInGameTradePokemon
    special DoInGameTradeScene
    waitstate
    lock
    faceplayer
    return

Common_EventScript_UnionRoomAttendant::
	call CableClub_EventScript_UnionRoomAttendant
	end

Common_EventScript_WirelessClubAttendant::
	call CableClub_EventScript_WirelessClubAttendant
	end

Common_EventScript_DirectCornerAttendant::
	call CableClub_EventScript_DirectCornerAttendant
	end

Common_EventScript_RemoveStaticPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Common_EventScript_LegendaryFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

Common_EventScript_AwakenSnorlax::
    message gText_PlayedPokeFlute
    waitmessage
    playfanfare MUS_RG_POKE_FLUTE
    waitfanfare
    msgbox gText_SnorlaxWokeUp
    return

EventScript_TryDarkenRuins::
	goto_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, Common_EventScript_NopReturn
	setweather WEATHER_SHADE
	doweather
	return

	.include "data/scripts/silphco_doors.inc"
	.include "data/scripts/pc_transfer.inc"
	.include "data/scripts/questionnaire.inc"
	.include "data/scripts/trainer_script.inc"
	.include "data/scripts/berry_tree.inc"
	.include "data/scripts/secret_base.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/text/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/text/contest_strings.inc"
	.include "data/text/contest_link.inc"
	.include "data/text/contest_painting.inc"
	.include "data/text/trick_house_mechadolls.inc"
	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"
	.include "data/scripts/interview.inc"
	.include "data/scripts/gabby_and_ty.inc"
	.include "data/text/pokemon_news.inc"
	.include "data/scripts/mauville_man.inc"
	.include "data/scripts/field_move_scripts.inc"
	.include "data/scripts/item_ball_scripts.inc"
	.include "data/scripts/profile_man.inc"
	.include "data/scripts/day_care.inc"
	.include "data/scripts/flash.inc"
	.include "data/scripts/berry_blender.inc"
	.include "data/text/mauville_man.inc"
	.include "data/text/trainers.inc"
	.include "data/scripts/repel.inc"
	.include "data/scripts/safari_zone.inc"
	.include "data/scripts/roulette.inc"
    .include "data/scripts/pokedex_rating.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/braille.inc"
	.include "data/text/berries.inc"
	.include "data/text/shoal_cave.inc"
	.include "data/text/check_furniture.inc"
	.include "data/scripts/cave_hole.inc"
	.include "data/scripts/lilycove_lady.inc"
	.include "data/text/match_call.inc"
	.include "data/scripts/apprentice.inc"
	.include "data/text/apprentice.inc"
	.include "data/text/battle_dome.inc"
	.include "data/scripts/battle_pike.inc"
	.include "data/text/blend_master.inc"
	.include "data/text/battle_tent.inc"
	.include "data/text/event_ticket_2.inc"
	.include "data/text/move_tutors.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_tower.inc"
	.include "data/scripts/test_signpost.inc"
	.include "data/text/frontier_brain.inc"
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"
    .include "data/scripts/aide.inc"
    .include "data/text/aide.inc"
    .include "data/text/ingame_trade.inc"
	.include "data/scripts/pokemon_mansion.inc"
    .include "data/scripts/route23.inc"
    .include "data/text/route23.inc"
	.include "data/text/new_game_intro.inc"
	.include "data/scripts/seagallop.inc"
	.include "data/text/seagallop.inc"
