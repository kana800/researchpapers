cmake_minimum_required(VERSION 3.8)

set(MakingDataStructuresPersistent 0)
set(RTree 0)
set(BTree 1)

if (MakingDataStructuresPersistent)
	set(SRCES 
		"MakingDataStructuresPersistent/fatnode.c"	
	)

	set(HEADERS
		"MakingDataStructuresPersistent/fatnode.h"	
		"MakingDataStructuresPersistent/nodecopying.h"
	)

	add_library(
		MakingDataStructuresPersistent 
		${SRCES} ${HEADERS})

	set_target_properties(
		MakingDataStructuresPersistent PROPERTIES 
		LINKER_LANGUAGE C
	)
endif()

if (RTree) 
	set(RTree_SRCES 
		"RTree/rtree.c"
	)

	set(RTree_HEADERS
		"RTree/rtree.h"
	)
	add_library(
		RTree 
		${RTree_SRCES} ${RTree_HEADERS})

	set_target_properties(
		RTree PROPERTIES 
		LINKER_LANGUAGE C
)
endif()


if (BTree)
	set(BTree_SRCES 
		"BTree/btree.c"
	)

	set(BTree_HEADERS
		"BTree/btree.h"
	)
	add_library(
		BTree 
		${BTree_SRCES} ${BTree_HEADERS})

	set_target_properties(
		BTree PROPERTIES 
		LINKER_LANGUAGE C
	)
endif()


