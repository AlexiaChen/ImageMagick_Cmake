cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_lcms) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)


add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)

add_definitions(-DCMS_NO_HALF_SUPPORT)
add_definitions(-D_LCMSLIB_)
add_definitions(-D__CONSOLE__)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)

#包含工程所需要的头文件路径



include_directories(${PROJECT_SOURCE_DIR}/include)



#set(CONFIG_HDR ../glib/glib/config.h)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/src/cmscam02.c
${PROJECT_SOURCE_DIR}/src/cmscgats.c
${PROJECT_SOURCE_DIR}/src/cmscnvrt.c
${PROJECT_SOURCE_DIR}/src/cmserr.c
${PROJECT_SOURCE_DIR}/src/cmsgamma.c
${PROJECT_SOURCE_DIR}/src/cmsgmt.c
${PROJECT_SOURCE_DIR}/src/cmshalf.c
${PROJECT_SOURCE_DIR}/src/cmsintrp.c
${PROJECT_SOURCE_DIR}/src/cmsio0.c
${PROJECT_SOURCE_DIR}/src/cmsio1.c
${PROJECT_SOURCE_DIR}/src/cmslut.c
${PROJECT_SOURCE_DIR}/src/cmsmd5.c
${PROJECT_SOURCE_DIR}/src/cmsmtrx.c
${PROJECT_SOURCE_DIR}/src/cmsnamed.c
${PROJECT_SOURCE_DIR}/src/cmsopt.c
${PROJECT_SOURCE_DIR}/src/cmspack.c
${PROJECT_SOURCE_DIR}/src/cmspcs.c
${PROJECT_SOURCE_DIR}/src/cmsplugin.c
${PROJECT_SOURCE_DIR}/src/cmsps2.c
${PROJECT_SOURCE_DIR}/src/cmssamp.c
${PROJECT_SOURCE_DIR}/src/cmssm.c
${PROJECT_SOURCE_DIR}/src/cmstypes.c
${PROJECT_SOURCE_DIR}/src/cmsvirt.c
${PROJECT_SOURCE_DIR}/src/cmswtpnt.c
${PROJECT_SOURCE_DIR}/src/cmsxform.c
${PROJECT_SOURCE_DIR}/src/lcms2.def




)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_lcms STATIC ${SRC} )

set_target_properties(CORE_lcms PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_lcms PROPERTIES
        OUTPUT_NAME CORE_lcms
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


INSTALL(TARGETS CORE_lcms
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

