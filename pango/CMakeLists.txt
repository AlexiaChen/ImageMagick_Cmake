cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_pango) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)

add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)




add_definitions(-DPANGO_COMPILATION)
add_definitions(-DPANGO_ENABLE_BACKEND)
add_definitions(-DPANGO_ENABLE_ENGINE)
add_definitions(-DHAVE_CAIRO_WIN32)

#包含工程所需要的头文件路径
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/pango)

include_directories(${PROJECT_SOURCE_DIR}/pango/mini-fribidi)
include_directories(../cairo/src)


include_directories(../glib/glib)
include_directories(../glib)
include_directories(../glib/gmodule)


include_directories(../librsvg/gdk-pixbuf/gdk-pixbuf)
#set(CONFIG_HDR ../glib/glib/config.h)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/modules/arabic/arabic-lang.c
${PROJECT_SOURCE_DIR}/modules/basic/basic-win32.c
${PROJECT_SOURCE_DIR}/pango/break.c

${PROJECT_SOURCE_DIR}/pango/check.defs
${PROJECT_SOURCE_DIR}/pango/ellipsize.c
${PROJECT_SOURCE_DIR}/pango/fonts.c
${PROJECT_SOURCE_DIR}/pango/mini-fribidi/fribidi.c
${PROJECT_SOURCE_DIR}/pango/mini-fribidi/fribidi_char_type.c
${PROJECT_SOURCE_DIR}/pango/mini-fribidi/fribidi_types.c
${PROJECT_SOURCE_DIR}/pango/glyphstring.c
${PROJECT_SOURCE_DIR}/modules/indic/indic-lang.c
${PROJECT_SOURCE_DIR}/pango/module-defs-coretext.c
${PROJECT_SOURCE_DIR}/pango/module-defs-fc.c
${PROJECT_SOURCE_DIR}/pango/module-defs-lang.c
${PROJECT_SOURCE_DIR}/pango/module-defs-win32.c

${PROJECT_SOURCE_DIR}/modules/module.def
${PROJECT_SOURCE_DIR}/pango/modules.c
${PROJECT_SOURCE_DIR}/pango/pango-attributes.c
${PROJECT_SOURCE_DIR}/pango/pango-bidi-type.c
${PROJECT_SOURCE_DIR}/pango/pango-color.c
${PROJECT_SOURCE_DIR}/pango/pango-context.c
${PROJECT_SOURCE_DIR}/pango/pango-coverage.c
${PROJECT_SOURCE_DIR}/pango/pango-engine.c
${PROJECT_SOURCE_DIR}/pango/pango-enum-types.c
${PROJECT_SOURCE_DIR}/pango/pango-fontmap.c
${PROJECT_SOURCE_DIR}/pango/pango-fontset.c
${PROJECT_SOURCE_DIR}/pango/pango-glyph-item.c
${PROJECT_SOURCE_DIR}/pango/pango-gravity.c
${PROJECT_SOURCE_DIR}/pango/pango-item.c
${PROJECT_SOURCE_DIR}/pango/pango-language.c
${PROJECT_SOURCE_DIR}/pango/pango-layout.c
${PROJECT_SOURCE_DIR}/pango/pango-markup.c
${PROJECT_SOURCE_DIR}/pango/pango-matrix.c
${PROJECT_SOURCE_DIR}/pango/pango-renderer.c
${PROJECT_SOURCE_DIR}/pango/pango-script.c
${PROJECT_SOURCE_DIR}/pango/pango-tabs.c
${PROJECT_SOURCE_DIR}/pango/pango-utils.c
${PROJECT_SOURCE_DIR}/pango/pango.def
${PROJECT_SOURCE_DIR}/pango/pangocairo-context.c
${PROJECT_SOURCE_DIR}/pango/pangocairo-font.c
${PROJECT_SOURCE_DIR}/pango/pangocairo-fontmap.c
${PROJECT_SOURCE_DIR}/pango/pangocairo-render.c
${PROJECT_SOURCE_DIR}/pango/pangocairo-win32font.c
${PROJECT_SOURCE_DIR}/pango/pangocairo-win32fontmap.c
${PROJECT_SOURCE_DIR}/pango/pangocairo.def
${PROJECT_SOURCE_DIR}/pango/pangoft2.def
${PROJECT_SOURCE_DIR}/pango/pangowin32-fontcache.c
${PROJECT_SOURCE_DIR}/pango/pangowin32-fontmap.c
${PROJECT_SOURCE_DIR}/pango/pangowin32.c
${PROJECT_SOURCE_DIR}/pango/pangowin32.def
${PROJECT_SOURCE_DIR}/pango/pangoxft.def
${PROJECT_SOURCE_DIR}/pango/reorder-items.c
${PROJECT_SOURCE_DIR}/pango/shape.c

)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_pango STATIC ${SRC} )

set_target_properties(CORE_pango PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_pango PROPERTIES
        OUTPUT_NAME CORE_pango
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


INSTALL(TARGETS CORE_pango
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

