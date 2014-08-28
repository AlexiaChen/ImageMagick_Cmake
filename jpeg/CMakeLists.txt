cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_jpeg) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)

add_definitions(-DWITH_SIMD)

#包含工程所需要的头文件路径



include_directories(${PROJECT_SOURCE_DIR})



#set(CONFIG_HDR ../glib/glib/config.h)

# Detect whether compiler is 64-bit
if(MSVC AND CMAKE_CL_64)
  set(SIMD_X86_64 1)
  set(64BIT 1)
elseif(CMAKE_SIZEOF_VOID_P MATCHES 8)
  set(SIMD_X86_64 1)
  set(64BIT 1)
endif()







#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/jaricom.c
${PROJECT_SOURCE_DIR}/jcapimin.c
${PROJECT_SOURCE_DIR}/jcapistd.c
${PROJECT_SOURCE_DIR}/jcarith.c
${PROJECT_SOURCE_DIR}/jccoefct.c
${PROJECT_SOURCE_DIR}/jccolor.c
${PROJECT_SOURCE_DIR}/jcdctmgr.c
${PROJECT_SOURCE_DIR}/jchuff.c
${PROJECT_SOURCE_DIR}/jcinit.c
${PROJECT_SOURCE_DIR}/jcmainct.c
${PROJECT_SOURCE_DIR}/jcmarker.c
${PROJECT_SOURCE_DIR}/jcmaster.c
${PROJECT_SOURCE_DIR}/jcomapi.c
${PROJECT_SOURCE_DIR}/jcparam.c
${PROJECT_SOURCE_DIR}/jcphuff.c
${PROJECT_SOURCE_DIR}/jcprepct.c
${PROJECT_SOURCE_DIR}/jcsample.c
${PROJECT_SOURCE_DIR}/jctrans.c
${PROJECT_SOURCE_DIR}/jdapimin.c
${PROJECT_SOURCE_DIR}/jdapistd.c
${PROJECT_SOURCE_DIR}/jdarith.c
${PROJECT_SOURCE_DIR}/jdatadst-tj.c
${PROJECT_SOURCE_DIR}/jdatadst.c
${PROJECT_SOURCE_DIR}/jdatasrc-tj.c
${PROJECT_SOURCE_DIR}/jdatasrc.c
${PROJECT_SOURCE_DIR}/jdcoefct.c
${PROJECT_SOURCE_DIR}/jdcolor.c
${PROJECT_SOURCE_DIR}/jddctmgr.c
${PROJECT_SOURCE_DIR}/jdhuff.c
${PROJECT_SOURCE_DIR}/jdinput.c
${PROJECT_SOURCE_DIR}/jdmainct.c
${PROJECT_SOURCE_DIR}/jdmarker.c
${PROJECT_SOURCE_DIR}/jdmaster.c
${PROJECT_SOURCE_DIR}/jdmerge.c
${PROJECT_SOURCE_DIR}/jdphuff.c
${PROJECT_SOURCE_DIR}/jdpostct.c
${PROJECT_SOURCE_DIR}/jdsample.c
${PROJECT_SOURCE_DIR}/jdtrans.c
${PROJECT_SOURCE_DIR}/jerror.c
${PROJECT_SOURCE_DIR}/jfdctflt.c
${PROJECT_SOURCE_DIR}/jfdctfst.c
${PROJECT_SOURCE_DIR}/jfdctint.c
${PROJECT_SOURCE_DIR}/jidctflt.c
${PROJECT_SOURCE_DIR}/jidctfst.c
${PROJECT_SOURCE_DIR}/jidctint.c
${PROJECT_SOURCE_DIR}/jidctred.c
${PROJECT_SOURCE_DIR}/jmemmgr.c
${PROJECT_SOURCE_DIR}/jmemnobs.c
${PROJECT_SOURCE_DIR}/jquant1.c
${PROJECT_SOURCE_DIR}/jquant2.c
#${PROJECT_SOURCE_DIR}/simd/jsimd_x86_64.c
${PROJECT_SOURCE_DIR}/jsimd_none.c
${PROJECT_SOURCE_DIR}/jutils.c
${PROJECT_SOURCE_DIR}/tjutil.c
${PROJECT_SOURCE_DIR}/transupp.c
${PROJECT_SOURCE_DIR}/turbojpeg.c


#NASM Source File
#${PROJECT_SOURCE_DIR}/simd/jccolss2-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jcgrass2-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jcqnts2f-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jcqnts2i-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jcsamss2-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jdcolss2-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jdmerss2-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jdsamss2-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jfss2fst-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jfss2int-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jfsseflt-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jiss2flt-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jiss2fst-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jiss2int-64.nasm
#${PROJECT_SOURCE_DIR}/simd/jiss2red-64.nasm



)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_jpeg STATIC ${SRC} )

set_target_properties(CORE_jpeg PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_jpeg PROPERTIES
        OUTPUT_NAME CORE_jpeg
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



INSTALL(TARGETS CORE_jpeg
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)
