cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_cairo) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-DPACKAGE)
add_definitions(-DCAIRO_HAS_SCRIPT_SURFACE)
add_definitions(-DCAIRO_HAS_XML_SURFACE)
add_definitions(-DCAIRO_WIN32_STATIC_BUILD)


#包含工程所需要的头文件路径



include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(../pixman/pixman)
include_directories(../zlib)
include_directories(../png)










#set(CONFIG_HDR ../glib/glib/config.h)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/src/cairo-analysis-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-arc.c
${PROJECT_SOURCE_DIR}/src/cairo-array.c
${PROJECT_SOURCE_DIR}/src/cairo-atomic.c
${PROJECT_SOURCE_DIR}/src/cairo-base64-stream.c
${PROJECT_SOURCE_DIR}/src/cairo-base85-stream.c
${PROJECT_SOURCE_DIR}/src/cairo-bentley-ottmann-rectangular.c
${PROJECT_SOURCE_DIR}/src/cairo-bentley-ottmann-rectilinear.c
${PROJECT_SOURCE_DIR}/src/cairo-bentley-ottmann.c
${PROJECT_SOURCE_DIR}/src/cairo-botor-scan-converter.c
${PROJECT_SOURCE_DIR}/src/cairo-boxes-intersect.c
${PROJECT_SOURCE_DIR}/src/cairo-boxes.c
${PROJECT_SOURCE_DIR}/src/cairo-cache.c
${PROJECT_SOURCE_DIR}/src/cairo-cff-subset.c
${PROJECT_SOURCE_DIR}/src/cairo-clip-boxes.c
${PROJECT_SOURCE_DIR}/src/cairo-clip-polygon.c
${PROJECT_SOURCE_DIR}/src/cairo-clip-region.c
${PROJECT_SOURCE_DIR}/src/cairo-clip-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-clip-tor-scan-converter.c
${PROJECT_SOURCE_DIR}/src/cairo-clip.c
${PROJECT_SOURCE_DIR}/src/cairo-color.c
${PROJECT_SOURCE_DIR}/src/cairo-composite-rectangles.c
${PROJECT_SOURCE_DIR}/src/cairo-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-contour.c
${PROJECT_SOURCE_DIR}/src/cairo-damage.c
${PROJECT_SOURCE_DIR}/src/cairo-debug.c
${PROJECT_SOURCE_DIR}/src/cairo-default-context.c
${PROJECT_SOURCE_DIR}/src/cairo-deflate-stream.c
${PROJECT_SOURCE_DIR}/src/cairo-device.c
${PROJECT_SOURCE_DIR}/src/cairo-error.c
${PROJECT_SOURCE_DIR}/src/cairo-fallback-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-font-face-twin-data.c
${PROJECT_SOURCE_DIR}/src/cairo-font-face-twin.c
${PROJECT_SOURCE_DIR}/src/cairo-font-face.c
${PROJECT_SOURCE_DIR}/src/cairo-font-options.c
${PROJECT_SOURCE_DIR}/src/cairo-freelist.c
${PROJECT_SOURCE_DIR}/src/cairo-gstate.c
${PROJECT_SOURCE_DIR}/src/cairo-hash.c
${PROJECT_SOURCE_DIR}/src/cairo-hull.c
${PROJECT_SOURCE_DIR}/src/cairo-image-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-image-info.c
${PROJECT_SOURCE_DIR}/src/cairo-image-source.c
${PROJECT_SOURCE_DIR}/src/cairo-image-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-lzw.c
${PROJECT_SOURCE_DIR}/src/cairo-mask-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-matrix.c
${PROJECT_SOURCE_DIR}/src/cairo-mempool.c
${PROJECT_SOURCE_DIR}/src/cairo-mesh-pattern-rasterizer.c
${PROJECT_SOURCE_DIR}/src/cairo-misc.c
${PROJECT_SOURCE_DIR}/src/cairo-mono-scan-converter.c
${PROJECT_SOURCE_DIR}/src/cairo-mutex.c
${PROJECT_SOURCE_DIR}/src/cairo-no-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-observer.c
${PROJECT_SOURCE_DIR}/src/cairo-output-stream.c
${PROJECT_SOURCE_DIR}/src/cairo-paginated-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-path-bounds.c
${PROJECT_SOURCE_DIR}/src/cairo-path-fill.c
${PROJECT_SOURCE_DIR}/src/cairo-path-fixed.c
${PROJECT_SOURCE_DIR}/src/cairo-path-in-fill.c
${PROJECT_SOURCE_DIR}/src/cairo-path-stroke-boxes.c
${PROJECT_SOURCE_DIR}/src/cairo-path-stroke-polygon.c
${PROJECT_SOURCE_DIR}/src/cairo-path-stroke-traps.c
${PROJECT_SOURCE_DIR}/src/cairo-path-stroke-tristrip.c
${PROJECT_SOURCE_DIR}/src/cairo-path-stroke.c
${PROJECT_SOURCE_DIR}/src/cairo-path.c
${PROJECT_SOURCE_DIR}/src/cairo-pattern.c
${PROJECT_SOURCE_DIR}/src/cairo-pdf-operators.c
${PROJECT_SOURCE_DIR}/src/cairo-pdf-shading.c
${PROJECT_SOURCE_DIR}/src/cairo-pdf-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-pen.c
${PROJECT_SOURCE_DIR}/src/cairo-png.c
${PROJECT_SOURCE_DIR}/src/cairo-polygon-intersect.c
${PROJECT_SOURCE_DIR}/src/cairo-polygon-reduce.c
${PROJECT_SOURCE_DIR}/src/cairo-polygon.c
${PROJECT_SOURCE_DIR}/src/cairo-ps-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-raster-source-pattern.c
${PROJECT_SOURCE_DIR}/src/cairo-recording-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-rectangle.c
${PROJECT_SOURCE_DIR}/src/cairo-rectangular-scan-converter.c
${PROJECT_SOURCE_DIR}/src/cairo-region.c
${PROJECT_SOURCE_DIR}/src/cairo-rtree.c
${PROJECT_SOURCE_DIR}/src/cairo-scaled-font-subsets.c
${PROJECT_SOURCE_DIR}/src/cairo-scaled-font.c
${PROJECT_SOURCE_DIR}/src/cairo-script-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-shape-mask-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-slope.c
${PROJECT_SOURCE_DIR}/src/cairo-spans-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-spans.c
${PROJECT_SOURCE_DIR}/src/cairo-spline.c
${PROJECT_SOURCE_DIR}/src/cairo-stroke-dash.c
${PROJECT_SOURCE_DIR}/src/cairo-stroke-style.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-clipper.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-fallback.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-observer.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-offset.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-snapshot.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-subsurface.c
${PROJECT_SOURCE_DIR}/src/cairo-surface-wrapper.c
${PROJECT_SOURCE_DIR}/src/cairo-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-svg-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-time.c
${PROJECT_SOURCE_DIR}/src/cairo-tor-scan-converter.c
${PROJECT_SOURCE_DIR}/src/cairo-tor22-scan-converter.c
${PROJECT_SOURCE_DIR}/src/cairo-toy-font-face.c
${PROJECT_SOURCE_DIR}/src/cairo-traps-compositor.c
${PROJECT_SOURCE_DIR}/src/cairo-traps.c
${PROJECT_SOURCE_DIR}/src/cairo-tristrip.c
${PROJECT_SOURCE_DIR}/src/cairo-truetype-subset.c
${PROJECT_SOURCE_DIR}/src/cairo-type1-fallback.c
${PROJECT_SOURCE_DIR}/src/cairo-type1-glyph-names.c
${PROJECT_SOURCE_DIR}/src/cairo-type1-subset.c
${PROJECT_SOURCE_DIR}/src/cairo-type3-glyph-surface.c
${PROJECT_SOURCE_DIR}/src/cairo-unicode.c
${PROJECT_SOURCE_DIR}/src/cairo-user-font.c
${PROJECT_SOURCE_DIR}/src/cairo-version.c
${PROJECT_SOURCE_DIR}/src/cairo-wideint.c


${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-debug.c
${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-device.c
${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-display-surface.c
${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-font.c
${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-gdi-compositor.c
${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-printing-surface.c
${PROJECT_SOURCE_DIR}/src/win32/cairo-win32-surface.c


${PROJECT_SOURCE_DIR}/src/cairo-xml-surface.c
${PROJECT_SOURCE_DIR}/src/cairo.c
${PROJECT_SOURCE_DIR}/src/check-link.c
${PROJECT_SOURCE_DIR}/src/test-base-compositor-surface.c
${PROJECT_SOURCE_DIR}/src/test-compositor-surface.c
${PROJECT_SOURCE_DIR}/src/test-null-compositor-surface.c
${PROJECT_SOURCE_DIR}/src/test-paginated-surface.c






)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_cairo STATIC ${SRC} )

set_target_properties(CORE_cairo PROPERTIES COMPILE_FLAGS "/EHsc /GF")
set_target_properties(CORE_cairo PROPERTIES
        OUTPUT_NAME CORE_cairo
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

INSTALL(TARGETS CORE_cairo
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)




