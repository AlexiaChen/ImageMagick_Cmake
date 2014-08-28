cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_wmf) 


add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)
add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-DHAVE_CONFIG_H)

#包含工程所需要的头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)	#shang add
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(../ttf/include)
include_directories(../zlib)
include_directories(${PROJECT_SOURCE_DIR})


#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
#set(SRC ${PROJECT_SOURCE_DIR}/

#file(GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c)
file(GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/api.c src/bbuf.c src/eps.c src/font.c src/meta.c src/player.c src/recorder.c src/stream.c src/wmf.c)
source_group("src" FILES ${SRC})

source_group("resource" FILES "")

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h wmfconfig.h)
source_group("include" FILES ${HDR})


ADD_LIBRARY(CORE_wmf STATIC ${SRC} ${HDR} )

set_target_properties(CORE_wmf PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_wmf PROPERTIES
        OUTPUT_NAME CORE_wmf
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



INSTALL(TARGETS CORE_wmf
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)
