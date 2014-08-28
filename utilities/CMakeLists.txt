cmake_minimum_required(VERSION 2.8)

#set(CMAKE_C_COMPILER "D:\VS2008Release\VC\bin\amd64")
#set(CMAKE_CXX_COMPILER "D:\VS2008Release\VC\bin\amd64")

PROJECT(CONVERT) 

add_definitions(-D_CONSOLE)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)

include_directories(../)


#shang LINK_DIRECTORIES(../../build/lib)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)



set(SRC ${PROJECT_SOURCE_DIR}/convert.c)


add_executable(convert ${SRC})

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(IMAGEMAGICK_LIB CORE_wandd CORE_magickd CORE_wmfd CORE_pixmand CORE_ffid CORE_crocod CORE_cairod CORE_webpd CORE_ttfd CORE_tiffd CORE_pngd CORE_pangod CORE_lqrd  CORE_libxmld CORE_librsvgd CORE_lcmsd CORE_jp2d CORE_jbigd CORE_glibd CORE_filtersd CORE_codersd CORE_jpegd CORE_bzlibd CORE_zLibd)
else()
  set(IMAGEMAGICK_LIB CORE_wand CORE_magick CORE_wmf CORE_pixman CORE_ffi CORE_croco CORE_cairo CORE_webp CORE_ttf CORE_tiff CORE_png CORE_pango CORE_lqr  CORE_libxml CORE_librsvg CORE_lcms CORE_jp2 CORE_jbig CORE_glib CORE_filters CORE_coders CORE_jpeg.lib CORE_bzlib CORE_zLib)
endif()

target_link_libraries(convert ${IMAGEMAGICK_LIB} urlmon.lib)

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





