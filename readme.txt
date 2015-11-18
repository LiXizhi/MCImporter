Author: LiPeng, LiXizhi
Date: 2015.11

---++ Introduction
	added /mcimport command to import minecraft world directory. Please note, it does not import at once, instead it uses the ChunkGenerator interface to load the world dynamically according to current player position. 

---++ Install
	- copy MCImporter.dll to paracraft root directory. (currently only 32bits version is built)
	- copy MCImporter.zip to ./Mod folder and enable the importer plugin. 

---++ How to use
	- type /mcimport and select a valid minecraft world directory. 
	- a new world with the same name will be created locally, one may need to teleport the player to correct position to see the world load progressively as the player moves. 

---++ reference
	source code is based on mapcrafter-master
	https://github.com/m0r13/mapcrafter (all files in /mc folder)
	require boost zlib 

---++ build
	the only thing that I modified in mapcrafter is in nbt.cpp file line 252
	if(length>0)
	{
		stream.read(&payload[0], length);
	}
	VC compiler does not support 0 length array.  gcc has it. 
