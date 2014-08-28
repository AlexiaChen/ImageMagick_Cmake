cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_bzlib) 

#message(STATUS "second is :${PROJECT_BINARY_DIR}")


add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-DBZ_EXPORT)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)


file(GLOB BZLIB_SRC  blocksort.c bzlib.c compress.c crctable.c decompress.c huffman.c randtable.c )
file(GLOB BZLIB_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)


#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_bzlib STATIC ${BZLIB_SRC} ${BZLIB_HDR})

set_target_properties(CORE_bzlib PROPERTIES  COMPILE_FLAGS "/EHsc /GF")
set_target_properties(CORE_bzlib PROPERTIES
        OUTPUT_NAME CORE_bzlib
        DEBUG_POSTFIX "d"
    )


message(STATUS dawdwada:${CMAKE_BINARY_DIR})
#set_target_properties(ZLib PROPERTIES COMPILE_FLAGS "/GF")  #VERY IMPORTANT: can not use twice.

#set_source_files_properties(${ZLIB_SRC} PROPERTIES COMPILE_FLAGS "/EHsc")   #every file compile option.

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  string(REPLACE "/Ob0" "" ${CompilerFlag} "${${CompilerFlag}}")
  string(REPLACE "/TC" "" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()



INSTALL(TARGETS CORE_bzlib
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)
