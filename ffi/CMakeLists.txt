cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_ffi) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)




add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)

#包含工程所需要的头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/x86)

#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/src/closures.c 
${PROJECT_SOURCE_DIR}/src/debug.c 
${PROJECT_SOURCE_DIR}/src/prep_cif.c 
${PROJECT_SOURCE_DIR}/src/raw_api.c 
${PROJECT_SOURCE_DIR}/src/types.c 
${PROJECT_SOURCE_DIR}/src/x86/ffi.c 
${PROJECT_SOURCE_DIR}/src/x86/ffi64.c 
)

if(CMAKE_CL_64)
	ENABLE_LANGUAGE(ASM_MASM)
	list(APPEND SRC ${PROJECT_SOURCE_DIR}/src/x86/win64.asm )
else()
	ENABLE_LANGUAGE(ASM_MASM)
	list(APPEND SRC ${PROJECT_SOURCE_DIR}/src/x86/win32.asm )
endif(CMAKE_CL_64)





#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_ffi STATIC ${SRC} )

set_target_properties(CORE_ffi PROPERTIES COMPILE_FLAGS "/EHsc /GF")
set_target_properties(CORE_ffi PROPERTIES
        OUTPUT_NAME CORE_ffi
        DEBUG_POSTFIX "d"
    )
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


INSTALL(TARGETS CORE_ffi
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

