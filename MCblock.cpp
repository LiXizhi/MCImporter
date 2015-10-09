#include "PluginAPI.h"
#include "MCBlock.h"


struct MCBlockInfo
{
	uint16_t block_id;
	uint16_t data;
	uint16_t pe_block_id;
	uint16_t pe_data;
};

std::map<uint16_t, MCBlockInfo*> MCBlockMaps;

void MCBlock::AddBlockInfoToMap(uint16_t block_id, uint16_t data,uint16_t pe_block_id, uint16_t pe_data)
{
	MCBlockInfo* info = new MCBlockInfo;
	info->block_id = block_id;
	info->data = data;
	info->pe_block_id = pe_block_id;
	info->pe_data = pe_data;
	//MCBlockMaps.insert()
	/*char s[16];
	sprintf(s,"%d,%d,%d", block_id, data, sec_block_id);*/
	//std::string block_tag(s);
	MCBlockMaps[block_id*100 + data] = info;
}

void MCBlock::InitTranslateMap()
{
	/*
	 * fill the mc_to_pe TranslateMap
	 * params:mc_block_id,mc_block_data or sec_mc_block_id,pe_block_id,pe_block_data
	 */
	// air
	AddBlockInfoToMap(0, 0, 0, 0);
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
	AddBlockInfoToMap(8, 75, 123, 0);

	// water
	AddBlockInfoToMap(9, 75, 123, 0);

	// flowing_lava
	AddBlockInfoToMap(10, 0, 123, 0);

	// lava
	AddBlockInfoToMap(11, 0, 123, 0);

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

	// sponge
	AddBlockInfoToMap(19, 0, 174, 0);
	AddBlockInfoToMap(19, 1, 174, 0);

	// glass
	AddBlockInfoToMap(20, 0, 95, 0);

	// lapis_ore
	AddBlockInfoToMap(21, 0, 130, 0);

	// lapis_block
	AddBlockInfoToMap(22, 0, 131, 0);

	// lapis_block 
	AddBlockInfoToMap(24, 0, 4, 0);
	AddBlockInfoToMap(24, 1, 4, 0);
	AddBlockInfoToMap(24, 2, 4, 0);

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

	// gold_block
	AddBlockInfoToMap(41, 0, 142, 0);

	// iron_block 
	AddBlockInfoToMap(42, 0, 143, 0);

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
	AddBlockInfoToMap(45, 0, 176, 0);

	// tnt
	AddBlockInfoToMap(46, 0, 176, 0);

	// bookshelf
	AddBlockInfoToMap(47, 0, 176, 0);

	// the mossy_cobblestone block in mc
	AddBlockInfoToMap(48, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(49, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(50, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(51, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(52, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(53, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(54, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(55, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(56, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(57, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(58, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(59, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(60, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(61, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(62, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(63, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(64, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(65, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(66, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(67, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(68, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(69, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(70, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(71, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(70, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(73, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(74, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(75, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(76, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(77, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(78, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(79, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(80, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(81, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(82, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(83, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(84, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(85, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(86, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(87, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(88, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(89, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(90, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(91, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(92, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(93, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(94, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(95, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(96, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(97, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(98, 0, 176, 0);

	// the obsidian block in mc
	AddBlockInfoToMap(99, 0, 176, 0);

	// the obsidian block in mc
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

bool MCBlock::TranslateMCBlock(uint16_t &block_id, uint16_t &block_data)
{
	uint16_t block_tag = block_id * 100 + block_data;
	if (MCBlockMaps[block_tag])
	{
		
		MCBlockInfo *info = MCBlockMaps[block_tag];
		if (info->pe_block_id == 0)
			return false;
		block_id = info->pe_block_id;
		block_data = info->pe_data;
		return true;
	}
	return false;
}

