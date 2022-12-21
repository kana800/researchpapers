cmake_minimum_required(VERSION 3.8)

set(MakingDataStructuresPersistent 1)

if (MakingDataStructuresPersistent)
	set(SRCES 
		"MakingDataStructuresPersistent//fatnode.c"	
	)

	set(HEADERS
		"MakingDataStructuresPersistent//fatnode.h"	
	 "MakingDataStructuresPersistent/nodecopying.h")
endif()

add_library(MakingDataStructuresPersistent ${SRCES} ${HEADERS})

set_target_properties(
	MakingDataStructuresPersistent PROPERTIES 
	LINKER_LANGUAGE C
)
