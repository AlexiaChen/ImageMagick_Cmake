cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_jp2) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)








add_definitions(-DJAS_WIN_MSVC_BUILD)
add_definitions(-DEXCLUDE_MIF_SUPPORT)
add_definitions(-DEXCLUDE_PNM_SUPPORT)
add_definitions(-DEXCLUDE_BMP_SUPPORT)
add_definitions(-DEXCLUDE_RAS_SUPPORT)
add_definitions(-DEXCLUDE_JPG_SUPPORT)
add_definitions(-DEXCLUDE_PGX_SUPPORT)

#包含工程所需要的头文件路径



include_directories(${PROJECT_SOURCE_DIR}/src/libjasper/include)
include_directories(${PROJECT_SOURCE_DIR}/src/libjasper/jp2)
include_directories(${PROJECT_SOURCE_DIR}/src/libjasper/jpc)





#set(CONFIG_HDR ../glib/glib/config.h)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_cm.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_debug.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_getopt.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_icc.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_iccdata.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_image.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_init.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_malloc.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_seq.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_stream.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_string.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_tmr.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_tvp.c
${PROJECT_SOURCE_DIR}/src/libjasper/base/jas_version.c

${PROJECT_SOURCE_DIR}/jasper.def
${PROJECT_SOURCE_DIR}/src/libjasper/jp2/jp2_cod.c
${PROJECT_SOURCE_DIR}/src/libjasper/jp2/jp2_dec.c
${PROJECT_SOURCE_DIR}/src/libjasper/jp2/jp2_enc.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_bs.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_cs.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_dec.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_enc.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_math.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_mct.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_mqcod.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_mqdec.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_mqenc.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_qmfb.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_t1cod.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_t1dec.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_t1enc.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_t2cod.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_t2dec.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_t2enc.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_tagtree.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_tsfb.c
${PROJECT_SOURCE_DIR}/src/libjasper/jpc/jpc_util.c




)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_jp2 STATIC ${SRC} )

set_target_properties(CORE_jp2 PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_jp2 PROPERTIES
        OUTPUT_NAME CORE_jp2
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


INSTALL(TARGETS CORE_jp2
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

