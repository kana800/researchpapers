cmake_minimum_required(VERSION 3.8)

set(MakingDataStructuresPersistentTest 0)
set(RTree 1)

if (MakingDataStructuresPersistentTest)
	set(SRCES 
		"MakingDataStructuresPersistentTest/fatnodetest.c"	
	)
	add_executable(
		MakingDataStructuresPersistentTest 
		${SRCES})
	target_include_directories(
		MakingDataStructuresPersistentTest
		PRIVATE MakingDataStructuresPersistent check
	)

	target_link_libraries(
		MakingDataStructuresPersistentTest
		PRIVATE MakingDataStructuresPersistent check
	)
endif()

if (RTree)
	set(RTREE_SRCES
		"RTree/rtreetest.c"	
	)
	add_executable(
		RTreeTest ${RTREE_SRCES})

	target_include_directories(RTreeTest
		PRIVATE RTree check
	)

	target_link_libraries(RTreeTest
		PRIVATE RTree check
	)
endif()
