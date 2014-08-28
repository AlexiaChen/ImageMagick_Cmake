cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_tiff) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)

add_definitions(-D_TIFFLIB_)
add_definitions(-DCHECK_JPEG_YCBCR_SUBSAMPLING)
add_definitions(-DDEFAULT_EXTRASAMPLE_AS_ALPHA)
add_definitions(-DSTRIPCHOP_DEFAULT=TIFF_STRIPCHOP)
add_definitions(-DLOGLUV_SUPPORT)
add_definitions(-DNEXT_SUPPORT)
add_definitions(-DTHUNDER_SUPPORT)
add_definitions(-DLZW_SUPPORT)
add_definitions(-DPACKBITS_SUPPORT)
add_definitions(-DCCITT_SUPPORT)
add_definitions(-DTIF_PLATFORM_CONSOLE)
add_definitions(-DFILLODER_LSB2MSB)


#包含工程所需要的头文件路径
include_directories(${PROJECT_SOURCE_DIR}/libtiff)
include_directories(../zlib)
include_directories(../jpeg)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/libtiff/libtiff.def
${PROJECT_SOURCE_DIR}/libtiff/tif_aux.c
${PROJECT_SOURCE_DIR}/libtiff/tif_close.c
${PROJECT_SOURCE_DIR}/libtiff/tif_codec.c
${PROJECT_SOURCE_DIR}/libtiff/tif_color.c
${PROJECT_SOURCE_DIR}/libtiff/tif_compress.c
${PROJECT_SOURCE_DIR}/libtiff/tif_dir.c
${PROJECT_SOURCE_DIR}/libtiff/tif_dirinfo.c
${PROJECT_SOURCE_DIR}/libtiff/tif_dirread.c
${PROJECT_SOURCE_DIR}/libtiff/tif_dirwrite.c
${PROJECT_SOURCE_DIR}/libtiff/tif_dumpmode.c
${PROJECT_SOURCE_DIR}/libtiff/tif_error.c
${PROJECT_SOURCE_DIR}/libtiff/tif_extension.c
${PROJECT_SOURCE_DIR}/libtiff/tif_fax3.c
${PROJECT_SOURCE_DIR}/libtiff/tif_fax3sm.c
${PROJECT_SOURCE_DIR}/libtiff/tif_flush.c
${PROJECT_SOURCE_DIR}/libtiff/tif_getimage.c
${PROJECT_SOURCE_DIR}/libtiff/tif_jbig.c

${PROJECT_SOURCE_DIR}/libtiff/tif_jpeg.c
${PROJECT_SOURCE_DIR}/libtiff/tif_jpeg_12.c
${PROJECT_SOURCE_DIR}/libtiff/tif_luv.c
${PROJECT_SOURCE_DIR}/libtiff/tif_lzma.c
${PROJECT_SOURCE_DIR}/libtiff/tif_lzw.c
${PROJECT_SOURCE_DIR}/libtiff/tif_next.c
${PROJECT_SOURCE_DIR}/libtiff/tif_ojpeg.c
${PROJECT_SOURCE_DIR}/libtiff/tif_open.c
${PROJECT_SOURCE_DIR}/libtiff/tif_packbits.c
${PROJECT_SOURCE_DIR}/libtiff/tif_pixarlog.c
${PROJECT_SOURCE_DIR}/libtiff/tif_predict.c
${PROJECT_SOURCE_DIR}/libtiff/tif_print.c
${PROJECT_SOURCE_DIR}/libtiff/tif_read.c
${PROJECT_SOURCE_DIR}/libtiff/tif_strip.c
${PROJECT_SOURCE_DIR}/libtiff/tif_swab.c
${PROJECT_SOURCE_DIR}/libtiff/tif_thunder.c
${PROJECT_SOURCE_DIR}/libtiff/tif_tile.c
${PROJECT_SOURCE_DIR}/libtiff/tif_unix.c
${PROJECT_SOURCE_DIR}/libtiff/tif_version.c
${PROJECT_SOURCE_DIR}/libtiff/tif_warning.c
${PROJECT_SOURCE_DIR}/libtiff/tif_write.c
${PROJECT_SOURCE_DIR}/libtiff/tif_zip.c


)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_tiff STATIC ${SRC} )

set_target_properties(CORE_tiff PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_tiff PROPERTIES
        OUTPUT_NAME CORE_tiff
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



INSTALL(TARGETS CORE_tiff
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)
