#pragma once
#include "PluginAPI.h"
#include <map>
#include <stdint.h>

class MCBlock
{
public:
	static void InitTranslateMap();
	static void StaticInit();
	static bool IsSolidBlock(int block_id);
	static bool TranslateMCBlock(uint16_t &block_id, uint16_t &block_data);
	static void AddBlockInfoToMap(uint16_t block_id, uint16_t data, uint16_t pe_block_id, uint16_t pe_data);
};