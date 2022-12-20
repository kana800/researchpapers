cmake_minimum_required(VERSION 3.8)

set(MakingDataStructuresPersistentTest 1)

if (MakingDataStructuresPersistentTest)
	set(SRCES 
		"MakingDataStructuresPersistentTest//fatnodetest.c"	
	)
endif()

add_executable(MakingDataStructuresPersistentTest ${SRCES})

target_include_directories(MakingDataStructuresPersistentTest
	PRIVATE MakingDataStructuresPersistent check
)

target_link_libraries(MakingDataStructuresPersistentTest
	PRIVATE MakingDataStructuresPersistent check
)
