cmake_minimum_required(VERSION 2.8)

#set(CMAKE_C_COMPILER "D:\VS2008Release\VC\bin\amd64")
#set(CMAKE_CXX_COMPILER "D:\VS2008Release\VC\bin\amd64")

PROJECT(VisualStaticMT) 

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
#set(ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Lib")
#message(STATUS ${CMAKE_BINARY_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(SHARE_LIBS_DIR ${CMAKE_BINARY_DIR}/Lib)

add_subdirectory(bzlib) 
add_subdirectory(cairo)
add_subdirectory(coders)
add_subdirectory(croco)
add_subdirectory(ffi)
add_subdirectory(filters)
add_subdirectory(glib)
add_subdirectory(jbig)
add_subdirectory(jp2)
add_subdirectory(jpeg)
add_subdirectory(lcms)
add_subdirectory(librsvg)
add_subdirectory(libxml)
add_subdirectory(lqr)
add_subdirectory(magick)
add_subdirectory(Magick++)
add_subdirectory(pango)
add_subdirectory(pixman)
add_subdirectory(png)
add_subdirectory(tiff)
add_subdirectory(ttf)
add_subdirectory(wand)
add_subdirectory(webp)
add_subdirectory(wmf)
add_subdirectory(zlib)



#convert.exe工具编译
add_subdirectory(utilities)

#头文件输出
file(COPY  "${CMAKE_CURRENT_SOURCE_DIR}/Magick++/lib/Magick++.h"  
DESTINATION  "${CMAKE_BINARY_DIR}/include"  )
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Magick++/lib/Magick++.h"
    DESTINATION "include"
    )

#wand文件夹

file(GLOB wand_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/wand/*.h")
file(COPY  ${wand_hdrs}  
DESTINATION  "${CMAKE_BINARY_DIR}/include/wand"  )

install(FILES ${wand_hdrs}
    DESTINATION "include/wand"
    )


file(COPY  "${CMAKE_CURRENT_SOURCE_DIR}/VisualMagick/wand/wand-config.h.in"  
DESTINATION  "${CMAKE_BINARY_DIR}/include/wand"  )
#文件重命名
file(RENAME "${CMAKE_BINARY_DIR}/include/wand/wand-config.h.in" "${CMAKE_BINARY_DIR}/include/wand/wand-config.h")


install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/VisualMagick/wand/wand-config.h.in"
    DESTINATION "include/wand"
      RENAME "wand-config.h")

#Magick++文件夹
file(GLOB Magick_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/Magick++/lib/Magick++/*.h")
file(COPY  ${Magick_hdrs}  
DESTINATION  "${CMAKE_BINARY_DIR}/include/Magick++"  )

install(FILES ${Magick_hdrs}
    DESTINATION "include/Magick++"
   )

#magick文件夹
file(GLOB magick_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/magick/*.h")
file(COPY ${magick_hdrs}
DESTINATION  "${CMAKE_BINARY_DIR}/include/magick"  
)
install(FILES ${magick_hdrs}
    DESTINATION "include/magick"
   )

#wand
#add_subdirectory(cairo)





