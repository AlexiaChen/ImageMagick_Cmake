cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_pixman) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-DPACKAGE)

#包含工程所需要的头文件路径
include_directories(${PROJECT_SOURCE_DIR}/pixman)
include_directories(../librsvg/gdk-pixbuf/gdk-pixbuf)










#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/pixman/pixman-access-accessors.c
${PROJECT_SOURCE_DIR}/pixman/pixman-access.c
${PROJECT_SOURCE_DIR}/pixman/pixman-arm-neon.c
${PROJECT_SOURCE_DIR}/pixman/pixman-arm-simd.c
${PROJECT_SOURCE_DIR}/pixman/pixman-arm.c
${PROJECT_SOURCE_DIR}/pixman/pixman-bits-image.c
${PROJECT_SOURCE_DIR}/pixman/pixman-combine-float.c
${PROJECT_SOURCE_DIR}/pixman/pixman-combine32.c
${PROJECT_SOURCE_DIR}/pixman/pixman-conical-gradient.c
${PROJECT_SOURCE_DIR}/pixman/pixman-edge-accessors.c
${PROJECT_SOURCE_DIR}/pixman/pixman-edge.c
${PROJECT_SOURCE_DIR}/pixman/pixman-fast-path.c
${PROJECT_SOURCE_DIR}/pixman/pixman-filter.c
${PROJECT_SOURCE_DIR}/pixman/pixman-general.c
${PROJECT_SOURCE_DIR}/pixman/pixman-glyph.c
${PROJECT_SOURCE_DIR}/pixman/pixman-gradient-walker.c
${PROJECT_SOURCE_DIR}/pixman/pixman-image.c
${PROJECT_SOURCE_DIR}/pixman/pixman-implementation.c
${PROJECT_SOURCE_DIR}/pixman/pixman-linear-gradient.c
${PROJECT_SOURCE_DIR}/pixman/pixman-matrix.c
${PROJECT_SOURCE_DIR}/pixman/pixman-mips.c
${PROJECT_SOURCE_DIR}/pixman/pixman-mmx.c
${PROJECT_SOURCE_DIR}/pixman/pixman-noop.c
${PROJECT_SOURCE_DIR}/pixman/pixman-ppc.c
${PROJECT_SOURCE_DIR}/pixman/pixman-radial-gradient.c
${PROJECT_SOURCE_DIR}/pixman/pixman-region16.c
${PROJECT_SOURCE_DIR}/pixman/pixman-region32.c
${PROJECT_SOURCE_DIR}/pixman/pixman-solid-fill.c
${PROJECT_SOURCE_DIR}/pixman/pixman-sse2.c
${PROJECT_SOURCE_DIR}/pixman/pixman-timer.c
${PROJECT_SOURCE_DIR}/pixman/pixman-trap.c
${PROJECT_SOURCE_DIR}/pixman/pixman-utils.c
${PROJECT_SOURCE_DIR}/pixman/pixman-x86.c
${PROJECT_SOURCE_DIR}/pixman/pixman.c


)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_pixman STATIC ${SRC} )

set_target_properties(CORE_pixman PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_pixman PROPERTIES
        OUTPUT_NAME CORE_pixman
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


INSTALL(TARGETS CORE_pixman
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

