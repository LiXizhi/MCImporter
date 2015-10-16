#include "PluginAPI.h"
#include "MCBlock.h"


struct MCBlockInfo
{
	uint16_t block_id;
	uint16_t data;
	uint16_t state;
	uint16_t pe_block_id;
	uint16_t pe_data;
	uint16_t pe_side;
};

std::map<uint32_t, MCBlockInfo*> MCBlockMaps;

void MCBlock::AddBlockInfoToMap(uint16_t block_id, uint16_t data, uint16_t pe_block_id, uint16_t pe_data, uint16_t state, uint16_t pe_side)
{
	MCBlockInfo* info = new MCBlockInfo;
	info->block_id = block_id;
	info->data = data;
	info->state = state;
	info->pe_block_id = pe_block_id;
	info->pe_data = pe_data;
	info->pe_side = pe_side;
	//MCBlockMaps.insert()
	/*char s[16];
	sprintf(s,"%d,%d,%d", block_id, data, sec_block_id);*/
	//std::string block_tag(s);
	uint32_t id_32 = block_id;
	id_32 = id_32 << 16;
	uint32_t data_32 = data;
	data_32 = data_32 << 8;
	uint32_t state_32 = state;
	uint32_t block_tag = id_32 + data_32 + state_32;
	//uint32_t block_tag = (uint32_t)block_id << 6 + data << 3 + state;
	MCBlockMaps[block_tag] = info;
}

void MCBlock::InitTranslateMap()
{
	/*
	 * fill the mc_to_pe TranslateMap
	 * params:mc_block_id,mc_block_data or sec_mc_block_id,pe_block_id,pe_block_data
	 */
	// air
	//AddBlockInfoToMap(0, 0, 0, 0);
	// stone
	AddBlockInfoToMap(1, 0, 56, 0);
	AddBlockInfoToMap(1, 1, 56, 0);
	AddBlockInfoToMap(1, 2, 56, 0);
	AddBlockInfoToMap(1, 3, 56, 0);
	AddBlockInfoToMap(1, 4, 56, 0);
	AddBlockInfoToMap(1, 5, 56, 0);
	AddBlockInfoToMap(1, 6, 56, 0);

	// grass
	AddBlockInfoToMap(2, 0, 62, 0);

	// dirt
	AddBlockInfoToMap(3, 0, 55, 0);
	AddBlockInfoToMap(3, 1, 55, 0);
	AddBlockInfoToMap(3, 2, 55, 0);

	// cobblestone
	AddBlockInfoToMap(4, 0, 58, 0);

	// planks
	AddBlockInfoToMap(5, 0, 81, 0);
	AddBlockInfoToMap(5, 1, 81, 0);
	AddBlockInfoToMap(5, 2, 81, 0);
	AddBlockInfoToMap(5, 3, 81, 0);
	AddBlockInfoToMap(5, 4, 81, 0);
	AddBlockInfoToMap(5, 5, 81, 0);

	// sapling
	AddBlockInfoToMap(6, 0, 119, 0);
	AddBlockInfoToMap(6, 1, 120, 0);
	AddBlockInfoToMap(6, 2, 121, 0);
	AddBlockInfoToMap(6, 3, 122, 0);
	AddBlockInfoToMap(6, 4, 120, 0);
	AddBlockInfoToMap(6, 5, 119, 0);

	// bedrock
	AddBlockInfoToMap(7, 0, 123, 0);

	// flowing_water
	AddBlockInfoToMap(8, 0, 75, 0);

	// water
	AddBlockInfoToMap(9, 0, 75, 0);
	AddBlockInfoToMap(9, 1, 75, 0);
	AddBlockInfoToMap(9, 2, 75, 0);
	AddBlockInfoToMap(9, 3, 75, 0);
	AddBlockInfoToMap(9, 4, 75, 0);
	AddBlockInfoToMap(9, 5, 75, 0);
	AddBlockInfoToMap(9, 6, 75, 0);
	AddBlockInfoToMap(9, 7, 75, 0);

	// flowing_lava
	AddBlockInfoToMap(10, 0, 82, 0);

	// lava
	AddBlockInfoToMap(11, 0, 82, 0);
	AddBlockInfoToMap(11, 2, 82, 0);
	AddBlockInfoToMap(11, 4, 82, 0);
	AddBlockInfoToMap(11, 6, 82, 0);

	// sand
	AddBlockInfoToMap(12, 0, 51, 0);
	AddBlockInfoToMap(12, 0, 51, 0);

	// gravel
	AddBlockInfoToMap(13, 0, 12, 0);

	// gold_ore
	AddBlockInfoToMap(14, 0, 18, 0);

	// iron_ore 
	AddBlockInfoToMap(15, 0, 124, 0);

	// coal_ore
	AddBlockInfoToMap(16, 0, 125, 0);

	// log 
	AddBlockInfoToMap(17, 0, 98, 0);
	AddBlockInfoToMap(17, 1, 98, 0);
	AddBlockInfoToMap(17, 2, 98, 0);
	AddBlockInfoToMap(17, 3, 98, 0);

	// leaves 
	AddBlockInfoToMap(18, 0, 86, 0);
	AddBlockInfoToMap(18, 1, 91, 0);
	AddBlockInfoToMap(18, 2, 129, 0);
	AddBlockInfoToMap(18, 3, 85, 0);

	// sponge
	AddBlockInfoToMap(19, 0, 174, 0);
	AddBlockInfoToMap(19, 1, 174, 0);

	// glass
	AddBlockInfoToMap(20, 0, 95, 0);

	// lapis_ore
	AddBlockInfoToMap(21, 0, 130, 0);

	// lapis_block
	AddBlockInfoToMap(22, 0, 131, 0);

	// dispenser (can not find the replace block in paracraft)
	//AddBlockInfoToMap(23, 0, 0, 0);

	// lapis_block 
	AddBlockInfoToMap(24, 0, 4, 0);
	AddBlockInfoToMap(24, 1, 4, 0);
	AddBlockInfoToMap(24, 2, 4, 0);

	// noteblock
	AddBlockInfoToMap(25, 0, 216, 0);

	// bed (can not find the replace block in paracraft)
	//AddBlockInfoToMap(26, 0, 0, 0);

	// golden_rail
	AddBlockInfoToMap(27, 0, 250, 2); //flat and around z 
	AddBlockInfoToMap(27, 1, 250, 1); //flat and around x  
	AddBlockInfoToMap(27, 2, 250, 7);//from low to high and around x
	AddBlockInfoToMap(27, 3, 250, 9);//from high to low and around x
	AddBlockInfoToMap(27, 4, 250, 10);//from high to low and around z
	AddBlockInfoToMap(27, 5, 250, 8);//from low to high and around z


	// detector_rail
	AddBlockInfoToMap(28, 0, 251, 2); //flat and around z 
	AddBlockInfoToMap(28, 1, 251, 1); //flat and around x  
	AddBlockInfoToMap(28, 2, 251, 7);//from low to high and around x
	AddBlockInfoToMap(28, 3, 251, 9);//from high to low and around x
	AddBlockInfoToMap(28, 4, 251, 10);//from high to low and around z
	AddBlockInfoToMap(28, 5, 251, 8);//from low to high and around z

	// sticky_piston
	AddBlockInfoToMap(29, 2, 202, 2);  // side£ºz-   state£ºoff
	AddBlockInfoToMap(29, 3, 202, 3);  // side£ºz+   state£ºoff
	AddBlockInfoToMap(29, 4, 202, 0);  // side£ºx-   state£ºoff
	AddBlockInfoToMap(29, 5, 202, 1);  // side£ºx+   state£ºoff
	AddBlockInfoToMap(29, 10, 202, 10); // side£ºz-   state£ºon
	AddBlockInfoToMap(29, 11, 202, 11); // side£ºz+   state£ºon
	AddBlockInfoToMap(29, 12, 202, 8); // side£ºx-   state£ºon
	AddBlockInfoToMap(29, 13, 202, 9); // side£ºx+   state£ºon

	// web
	AddBlockInfoToMap(30, 0, 118, 0);

	// tallgrass
	AddBlockInfoToMap(31, 1, 113, 0);
	AddBlockInfoToMap(31, 2, 114, 0);

	// deadbush
	AddBlockInfoToMap(32, 0, 132, 0);

	// piston
	AddBlockInfoToMap(33, 2, 203, 2);  // side£ºz-   state£ºoff
	AddBlockInfoToMap(33, 3, 203, 3);  // side£ºz+   state£ºoff
	AddBlockInfoToMap(33, 4, 203, 0);  // side£ºx-   state£ºoff
	AddBlockInfoToMap(33, 5, 203, 1);  // side£ºx+   state£ºoff
	AddBlockInfoToMap(33, 10, 203, 10); // side£ºz-   state£ºon
	AddBlockInfoToMap(33, 11, 203, 11); // side£ºz+   state£ºon
	AddBlockInfoToMap(33, 12, 203, 8); // side£ºx-   state£ºon
	AddBlockInfoToMap(33, 13, 203, 9); // side£ºx+   state£ºon

	// piston_head
	AddBlockInfoToMap(34, 2, 204, 10);  // side£ºz-  piston_head
	AddBlockInfoToMap(34, 3, 204, 11);  // side£ºz+  piston_head
	AddBlockInfoToMap(34, 4, 204, 8);  // side£ºx-  piston_head
	AddBlockInfoToMap(34, 5, 204, 9);  // side£ºx+  piston_head
	AddBlockInfoToMap(34, 10, 204, 10); // side£ºz-  sticky_piston 
	AddBlockInfoToMap(34, 11, 204, 11); // side£ºz+  sticky_piston
	AddBlockInfoToMap(34, 12, 204, 8); // side£ºx-  sticky_piston
	AddBlockInfoToMap(34, 13, 204, 9); // side£ºx+  sticky_piston

	// wool 
	AddBlockInfoToMap(35, 0, 133, 0);
	AddBlockInfoToMap(35, 1, 94, 0);
	AddBlockInfoToMap(35, 2, 25, 0);
	AddBlockInfoToMap(35, 3, 21, 0);
	AddBlockInfoToMap(35, 4, 27, 0);
	AddBlockInfoToMap(35, 5, 93, 0);
	AddBlockInfoToMap(35, 6, 96, 0);
	AddBlockInfoToMap(35, 7, 134, 0);
	AddBlockInfoToMap(35, 8, 135, 0);
	AddBlockInfoToMap(35, 9, 20, 0);
	AddBlockInfoToMap(35, 10, 24, 0);
	AddBlockInfoToMap(35, 11, 19, 0);
	AddBlockInfoToMap(35, 12, 136, 0);
	AddBlockInfoToMap(35, 13, 137, 0);
	AddBlockInfoToMap(35, 14, 23, 0);
	AddBlockInfoToMap(35, 15, 71, 0);

	// piston_extension (can find this block in version 1.8.8 mc,replace it with 34<piston_head>) 
	//AddBlockInfoToMap(36, 0, 0, 0);

	// yellow_flower
	AddBlockInfoToMap(37, 0, 116, 0);

	// red_flower
	AddBlockInfoToMap(38, 0, 115, 0);
	AddBlockInfoToMap(38, 1, 115, 0);
	AddBlockInfoToMap(38, 2, 115, 0);
	AddBlockInfoToMap(38, 3, 115, 0);
	AddBlockInfoToMap(38, 4, 115, 0);
	AddBlockInfoToMap(38, 5, 115, 0);
	AddBlockInfoToMap(38, 6, 115, 0);
	AddBlockInfoToMap(38, 7, 115, 0);
	AddBlockInfoToMap(38, 8, 115, 0);

	// brown_mushroom
	AddBlockInfoToMap(39, 0, 141, 0);

	// red_mushroom
	AddBlockInfoToMap(40, 0, 117, 0);

	// gold_block
	AddBlockInfoToMap(41, 0, 142, 0);

	// iron_block 
	AddBlockInfoToMap(42, 0, 143, 0);

	// double_stone_slab (can find this block in version 1.8.8 mc)
	//AddBlockInfoToMap(43, 0, 0, 0);

	// stone_slab
	AddBlockInfoToMap(44, 0, 176, 0);
	AddBlockInfoToMap(44, 1, 177, 0);
	// 44/2 block doesn't exist
	//AddBlockInfoToMap(44, 2, 178, 0);
	AddBlockInfoToMap(44, 3, 178, 0);
	AddBlockInfoToMap(44, 4, 179, 0);
	AddBlockInfoToMap(44, 5, 180, 0);
	AddBlockInfoToMap(44, 6, 181, 0);
	AddBlockInfoToMap(44, 7, 182, 0);

	// brick_block
	AddBlockInfoToMap(45, 0, 70, 0);

	// tnt
	AddBlockInfoToMap(46, 0, 23, 0);

	// bookshelf
	AddBlockInfoToMap(47, 0, 144, 0);

	// mossy_cobblestone
	AddBlockInfoToMap(48, 0, 145, 0);

	// obsidian
	AddBlockInfoToMap(49, 0, 146, 0);

	// torch
	AddBlockInfoToMap(50, 0, 100, 0);

	// fire (can not find the replace block in paracraft)
	AddBlockInfoToMap(51, 0, 0, 0);

	// mob_spawner (can not find the replace block in paracraft)
	//AddBlockInfoToMap(52, 0, 0, 0);

	// oak_stairs
	// face x-
	AddBlockInfoToMap(53, 0, 112, 5, 0); // state:outter 
	AddBlockInfoToMap(53, 0, 112, 8, 1); // state:outter 
	AddBlockInfoToMap(53, 0, 112, 18, 2);// state:inner
	AddBlockInfoToMap(53, 0, 112, 21, 3);// state:inner
	AddBlockInfoToMap(53, 0, 112, 1, 7); // state:normal
	// face x+
	AddBlockInfoToMap(53, 1, 112, 6, 0); // state:outter
	AddBlockInfoToMap(53, 1, 112, 7, 1); // state:outter
	AddBlockInfoToMap(53, 1, 112, 19, 2);// state:inner
	AddBlockInfoToMap(53, 1, 112, 20, 3);// state:inner
	AddBlockInfoToMap(53, 1, 112, 2, 7); // state:normal
	// face z-
	AddBlockInfoToMap(53, 2, 112, 5, 0); // state:outter
	AddBlockInfoToMap(53, 2, 112, 8, 1); // state:outter
	AddBlockInfoToMap(53, 2, 112, 18, 2);// state:inner
	AddBlockInfoToMap(53, 2, 112, 21, 3);// state:inner
	AddBlockInfoToMap(53, 2, 112, 4, 7); // state:normal
	// face z-
	AddBlockInfoToMap(53, 3, 112, 6, 0); // state:outter
	AddBlockInfoToMap(53, 3, 112, 7, 1); // state:outter
	AddBlockInfoToMap(53, 3, 112, 19, 2);// state:inner
	AddBlockInfoToMap(53, 3, 112, 20, 3);// state:inner
	AddBlockInfoToMap(53, 3, 112, 3, 7); // state:normal

	// chest
	// face z-
	AddBlockInfoToMap(54, 2, 176, 0, 0, 2);
	// face z+
	AddBlockInfoToMap(54, 3, 176, 0, 0, 3);
	// face x-
	AddBlockInfoToMap(54, 4, 176, 0, 0, 0);
	// face x+
	AddBlockInfoToMap(54, 5, 176, 0, 0, 1);

	// redstone_wire (can find this block in version 1.8.8 mc)
	//AddBlockInfoToMap(55, 0, 189, 0);

	// diamond_ore
	AddBlockInfoToMap(56, 0, 147, 0);

	// diamond_block
	AddBlockInfoToMap(57, 0, 148, 0);

	// crafting_table (can not find the replace block in paracraft)
	//AddBlockInfoToMap(58, 0, 176, 0);

	// wheat
	AddBlockInfoToMap(59, 0, 176, 3);
	AddBlockInfoToMap(59, 1, 176, 3);
	AddBlockInfoToMap(59, 2, 176, 2);
	AddBlockInfoToMap(59, 3, 176, 2);
	AddBlockInfoToMap(59, 4, 176, 1);
	AddBlockInfoToMap(59, 5, 176, 1);
	AddBlockInfoToMap(59, 6, 176, 0);
	AddBlockInfoToMap(59, 7, 176, 0);

	// farmland
	AddBlockInfoToMap(60, 0, 13, 0); //dry
	AddBlockInfoToMap(60, 7, 13, 0); //moist

	// furnace (can not find the replace block in paracraft)
	//// face z-
	//AddBlockInfoToMap(61, 2, 0, 0);
	//// face z+			   
	//AddBlockInfoToMap(61, 3, 0, 0);
	//// face x-			   
	//AddBlockInfoToMap(61, 4, 0, 0);
	//// face x+			   
	//AddBlockInfoToMap(61, 5, 0, 0);

	// lit_furnace (can not find the replace block in paracraft)
	//AddBlockInfoToMap(62, 0, 176, 0);

	// standing_sign
	// face z+
	AddBlockInfoToMap(63, 0, 211, 2);
	// face x-
	AddBlockInfoToMap(63, 4, 211, 1);
	// face z-
	AddBlockInfoToMap(63, 8, 211, 3);
	// face x+
	AddBlockInfoToMap(63, 11, 211, 0); //slope
	AddBlockInfoToMap(63, 12, 211, 0); //front
	AddBlockInfoToMap(63, 13, 211, 0); //slope

	// obsidian block in mc
	AddBlockInfoToMap(64, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(65, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(66, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(67, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(68, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(69, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(70, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(71, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(70, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(73, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(74, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(75, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(76, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(77, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(78, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(79, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(80, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(81, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(82, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(83, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(84, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(85, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(86, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(87, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(88, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(89, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(90, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(91, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(92, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(93, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(94, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(95, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(96, 0, 176, 0);

	// obsidian block in mc
	AddBlockInfoToMap(97, 0, 176, 0);

	// obsidian
	AddBlockInfoToMap(98, 0, 176, 0);

	// obsidian
	AddBlockInfoToMap(99, 0, 176, 0);

	// obsidian
	AddBlockInfoToMap(100, 0, 176, 0);

}

int block_maps[512];

void MCBlock::StaticInit()
{
	for(int i=0; i < 512; ++i)
	{
		block_maps[i] = 1;
	}
	block_maps[0] = 0;
	block_maps[6] = 0;
	block_maps[18] = 0;
	block_maps[19] = 0;

	block_maps[30] = 0;
	block_maps[31] = 0;
	block_maps[32] = 0;
	block_maps[37] = 0;
	block_maps[38] = 0;
	block_maps[39] = 0;
	block_maps[40] = 0;
	block_maps[59] = 0;

	block_maps[65] = 0;
	block_maps[66] = 0;
	block_maps[81] = 0;
	block_maps[83] = 0;
	block_maps[85] = 0;

	block_maps[50] = 0; // torch
	block_maps[51] = 0; 
	block_maps[52] = 0; 
	block_maps[53] = 0; 
	block_maps[67] = 0; 
	block_maps[69] = 0; 
	block_maps[85] = 0; 
	block_maps[20] = 0;  // glass
	block_maps[65] = 0;  
	block_maps[66] = 0;  
	block_maps[63] = 0;  
	block_maps[64] = 0;  
	block_maps[67] = 0;  
	block_maps[68] = 0;  
	block_maps[69] = 0;  

	block_maps[71] = 0;  
	block_maps[75] = 0;  
	block_maps[76] = 0;  
	block_maps[79] = 0;  

	block_maps[101] = 0;  
	block_maps[102] = 0;  
	block_maps[106] = 0;  
	block_maps[107] = 0;  
	block_maps[108] = 0;  
	block_maps[109] = 0;  

	block_maps[113] = 0; 
	block_maps[114] = 0; 
	block_maps[127] = 0;
	block_maps[128] = 0;

	block_maps[134] = 0; 
	block_maps[135] = 0; 
	block_maps[136] = 0; 
	block_maps[138] = 0; 
	block_maps[156] = 0; 
	block_maps[157] = 0; 

	InitTranslateMap();
}


bool MCBlock::IsSolidBlock( int block_id )
{
	if(block_id >=0 && block_id<256)
		return (block_maps[block_id] == 1);
	else
		return true;
}

bool MCBlock::TranslateMCBlock(uint16_t &block_id, uint16_t &block_data, uint16_t block_state, uint16_t& block_side)
{
	uint32_t id_32 = block_id;
	id_32 = id_32 << 16;
	uint32_t data_32 = block_data;
	data_32 = data_32 << 8;
	uint32_t state_32 = block_state;
	uint32_t block_tag = id_32 + data_32 + state_32;
	if (MCBlockMaps[block_tag])
	{
		
		MCBlockInfo *info = MCBlockMaps[block_tag];
		if (info->pe_block_id == 0)
			return false;
		block_id = info->pe_block_id;
		block_data = info->pe_data;
		block_side = info->pe_side;
		return true;
	}
	block_id = 0;
	block_data = 0;
	block_side = 0;
	return false;
}

