Author: LiXizhi
Company: ParaEngine Co.
Date: 2013.5.6
---++ reference
	source code is based on mapcrafter-master
	https://github.com/m0r13/mapcrafter (all files in /mc folder)
	require boost zlib 
---++ Install
	the only thing that I modified in mapcrafter is in nbt.cpp file line 252
	if(length>0)
	{
		stream.read(&payload[0], length);
	}
	VC compiler does not support 0 length array.  gcc has it. 

---++ Guide
	import mcr file to game engine



