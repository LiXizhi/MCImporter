# Author: LiXizhi
# Company: ParaEngine.com
# Date: 2013.5.5
# Desc: minecraft real time file importer
# Note: 

cmake_minimum_required(VERSION 2.6)

project (MCImporter)


SET(MCImporter_SRCS
	MCImporter.h
	MCImporter.cpp
	MCblock.h
	MCblock.cpp
	endian.h
	util.h
	util.cpp
	MCImporter.def
	readme.txt
)


##############################  
# web files
file (GLOB MC_FILES RELATIVE ${PROJECT_SOURCE_DIR}
    mc/*.cpp
	mc/*.h
    )
SOURCE_GROUP("mc" FILES ${MC_FILES})    
list(APPEND MCImporter_SRCS ${MC_FILES})

# add the binary tree to the search path for include files
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${ParaEngineClient_SOURCE_DIR}")
include_directories("${ParaEngineClient_SOURCE_DIR}/Core")
include_directories("${Boost_INCLUDE_DIRS}")

IF(MSVC)
	# statically link MSVC to reduce dependancies
	foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
	 	if(${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
	 	endif(${flag_var} MATCHES "/MD")
	 	if(${flag_var} MATCHES "/MDd")
	 		string(REGEX REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
		endif(${flag_var} MATCHES "/MDd")
	endforeach(flag_var)
	
	# /GR- Remove RTTI to miminize the executable size
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /GR-")
	SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Zi")
ENDIF()


IF(MSVC)
	# generate program database (PDB symbol files even in release build)
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
	SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Zi")
ENDIF(MSVC)

SET(CMAKE_DEBUG_POSTFIX "_d")



# add the executable
add_library(MCImporter SHARED ${MCImporter_SRCS})

target_link_libraries(MCImporter
	Ws2_32.lib
	${Boost_LIBRARIES_static_runtime}
)

IF(WIN32)
	ADD_DEFINITIONS(-DWNT)
ENDIF(WIN32)

if(MSVC)
	get_target_property(DEBUG_EXE_PATH MCImporter DEBUG_LOCATION)
	STRING(REGEX REPLACE "^.*[/\\]([^/\\]+)$" "\\1" DEBUG_EXE_NAME "${DEBUG_EXE_PATH}" )

	get_target_property(RELEASE_EXE_PATH MCImporter RELEASE_LOCATION)
	STRING(REGEX REPLACE "^.*[/\\]([^/\\]+)$" "\\1" RELEASE_EXE_NAME "${RELEASE_EXE_PATH}" )

	if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
		set( PARAWORLD_BIN_DIR "${CLIENT_SOURCE_DIR}/../../ParaWorld/bin64/" )
	else()
		set( PARAWORLD_BIN_DIR "${CLIENT_SOURCE_DIR}/../../ParaWorld/" )
	endif()

	ADD_CUSTOM_COMMAND(
	   TARGET MCImporter
	   POST_BUILD
	   COMMAND ${CMAKE_COMMAND} -E copy ${DEBUG_EXE_PATH} ${PARAWORLD_BIN_DIR}${DEBUG_EXE_NAME}
	   COMMAND ${CMAKE_COMMAND} -E copy ${RELEASE_EXE_PATH} ${PARAWORLD_BIN_DIR}${RELEASE_EXE_NAME}
	)
endif(MSVC)