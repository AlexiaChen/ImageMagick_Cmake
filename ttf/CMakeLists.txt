cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_ttf) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-DFT2_BUILD_LIBRARY)
add_definitions(-D_MBCS)
add_definitions(-D_TTFLIB_)


#包含工程所需要的头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/config)
include_directories(${PROJECT_SOURCE_DIR}/include/freetype)
include_directories(${PROJECT_SOURCE_DIR}/include/internal)
include_directories(${PROJECT_SOURCE_DIR}/include/freetype/internal)
include_directories(${PROJECT_SOURCE_DIR}/include/freetype/internal/services)
include_directories(${PROJECT_SOURCE_DIR}/include/internal/services)
include_directories(${PROJECT_SOURCE_DIR}/include/freetype/cache)
include_directories(${PROJECT_SOURCE_DIR}/include/freetype/config)







#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/src/autofit/autofit.c
${PROJECT_SOURCE_DIR}/src/bdf/bdf.c
${PROJECT_SOURCE_DIR}/src/cff/cff.c
${PROJECT_SOURCE_DIR}/src/base/ftbase.c
${PROJECT_SOURCE_DIR}/src/base/ftbbox.c
${PROJECT_SOURCE_DIR}/src/base/ftbitmap.c
${PROJECT_SOURCE_DIR}/src/cache/ftcache.c
${PROJECT_SOURCE_DIR}/src/base/ftdebug.c
${PROJECT_SOURCE_DIR}/builds/windows/ftdebug.c
${PROJECT_SOURCE_DIR}/src/base/ftfstype.c
${PROJECT_SOURCE_DIR}/src/base/ftgasp.c
${PROJECT_SOURCE_DIR}/src/base/ftglyph.c
${PROJECT_SOURCE_DIR}/src/base/ftgxval.c
${PROJECT_SOURCE_DIR}/src/gzip/ftgzip.c
${PROJECT_SOURCE_DIR}/src/base/ftinit.c




${PROJECT_SOURCE_DIR}/src/base/ftlcdfil.c
${PROJECT_SOURCE_DIR}/src/lzw/ftlzw.c
${PROJECT_SOURCE_DIR}/src/base/ftmm.c
${PROJECT_SOURCE_DIR}/src/base/ftotval.c
${PROJECT_SOURCE_DIR}/src/base/ftpatent.c
${PROJECT_SOURCE_DIR}/src/base/ftpfr.c
${PROJECT_SOURCE_DIR}/src/base/ftstroke.c
${PROJECT_SOURCE_DIR}/src/base/ftsynth.c
${PROJECT_SOURCE_DIR}/src/base/ftsystem.c
${PROJECT_SOURCE_DIR}/src/base/fttype1.c


${PROJECT_SOURCE_DIR}/src/base/ftwinfnt.c
${PROJECT_SOURCE_DIR}/src/base/ftxf86.c
${PROJECT_SOURCE_DIR}/src/pcf/pcf.c

${PROJECT_SOURCE_DIR}/src/pfr/pfr.c
${PROJECT_SOURCE_DIR}/src/psaux/psaux.c
${PROJECT_SOURCE_DIR}/src/pshinter/pshinter.c
${PROJECT_SOURCE_DIR}/src/psnames/psmodule.c
${PROJECT_SOURCE_DIR}/src/raster/raster.c
${PROJECT_SOURCE_DIR}/src/sfnt/sfnt.c
${PROJECT_SOURCE_DIR}/src/smooth/smooth.c

${PROJECT_SOURCE_DIR}/src/truetype/truetype.c
${PROJECT_SOURCE_DIR}/src/type1/type1.c
${PROJECT_SOURCE_DIR}/src/cid/type1cid.c

${PROJECT_SOURCE_DIR}/src/type42/type42.c
${PROJECT_SOURCE_DIR}/src/winfonts/winfnt.c



)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_ttf STATIC ${SRC} )

set_target_properties(CORE_ttf PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_ttf PROPERTIES
        OUTPUT_NAME CORE_ttf
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



INSTALL(TARGETS CORE_ttf
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)
