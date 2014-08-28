cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_librsvg) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)



add_definitions(-DGDK_PIXBUF_ENABLE_BACKEND)
add_definitions(-DRSVG_COMPILATION)

#包含工程所需要的头文件路径



include_directories(${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf)
include_directories(${PROJECT_SOURCE_DIR}/gdk-pixbuf)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(../glib/glib)
include_directories(../glib/gobject)
include_directories(../glib/gmodule)
include_directories(../glib)
include_directories(../libxml/include/libxml)
include_directories(../cairo/src)
include_directories(../libxml/include)
include_directories(../pango)
include_directories(../tiff/libtiff)
include_directories(../png)
include_directories(../jpeg)
include_directories(../jp2/src/libjasper/include)
include_directories(../croco/src)


#set(CONFIG_HDR ../glib/glib/config.h)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdiplus.def
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-animation.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-data.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-enum-types.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-io.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-loader.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-scale.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-scaled-anim.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-simple-anim.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf-util.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixbuf.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk-pixdata.c

${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/gdk_pixbuf.def
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-ani-animation.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-ani.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-bmp.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-gif-animation.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-gif.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-icns.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-ico.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-jasper.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-jpeg.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-pcx.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-pixdata.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-png.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-pnm.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-qtif.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-ras.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf-loader/io-svg.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-tga.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-tiff.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-wbmp.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-xbm.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/io-xpm.c


${PROJECT_SOURCE_DIR}/librsvg-enum-types.c
${PROJECT_SOURCE_DIR}/librsvg-features.c
${PROJECT_SOURCE_DIR}/gdk-pixbuf/gdk-pixbuf/pixops/pixops.c
${PROJECT_SOURCE_DIR}/rsvg-base-file-util.c
${PROJECT_SOURCE_DIR}/rsvg-base.c
${PROJECT_SOURCE_DIR}/rsvg-cairo-clip.c
${PROJECT_SOURCE_DIR}/rsvg-cairo-draw.c
${PROJECT_SOURCE_DIR}/rsvg-cairo-render.c
${PROJECT_SOURCE_DIR}/rsvg-cond.c
${PROJECT_SOURCE_DIR}/rsvg-css.c
${PROJECT_SOURCE_DIR}/rsvg-defs.c
${PROJECT_SOURCE_DIR}/rsvg-filter.c
${PROJECT_SOURCE_DIR}/rsvg-gobject.c
${PROJECT_SOURCE_DIR}/rsvg-image.c
${PROJECT_SOURCE_DIR}/rsvg-io.c
${PROJECT_SOURCE_DIR}/rsvg-marker.c
${PROJECT_SOURCE_DIR}/rsvg-mask.c
${PROJECT_SOURCE_DIR}/rsvg-paint-server.c
${PROJECT_SOURCE_DIR}/rsvg-path.c
${PROJECT_SOURCE_DIR}/rsvg-shapes.c
${PROJECT_SOURCE_DIR}/rsvg-size-callback.c
${PROJECT_SOURCE_DIR}/rsvg-structure.c
${PROJECT_SOURCE_DIR}/rsvg-styles.c
${PROJECT_SOURCE_DIR}/rsvg-text.c
${PROJECT_SOURCE_DIR}/rsvg-xml.c
${PROJECT_SOURCE_DIR}/rsvg.c



)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_librsvg STATIC ${SRC} )

set_target_properties(CORE_librsvg PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_librsvg PROPERTIES
        OUTPUT_NAME CORE_librsvg
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


INSTALL(TARGETS CORE_librsvg
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

