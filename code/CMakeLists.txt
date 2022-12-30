cmake_minimum_required(VERSION 3.8)

set(MakingDataStructuresPersistent 1)
set(RTree 1)

if (MakingDataStructuresPersistent)
	set(SRCES 
		"MakingDataStructuresPersistent/fatnode.c"	
	)

	set(HEADERS
		"MakingDataStructuresPersistent/fatnode.h"	
		"MakingDataStructuresPersistent/nodecopying.h"
	)
endif()


if (RTree) 
	set(SRCES 
	)

	set(HEADERS
	)
endif()


add_library(MakingDataStructuresPersistent ${SRCES} ${HEADERS})

set_target_properties(
	MakingDataStructuresPersistent PROPERTIES 
	LINKER_LANGUAGE C
)