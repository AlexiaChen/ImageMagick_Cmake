cmake_minimum_required(VERSION 2.8)

PROJECT(CORE_glib) 

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LIB)

add_definitions(-D_VISUALC_)
add_definitions(-DNeedFunctionPrototypes)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)


add_definitions(-DFFI_BUILDING)
add_definitions(-DGIO_COMPILATION)
add_definitions(-DGLIB_COMPILATION)
add_definitions(-DGOBJECT_COMPILATION)
add_definitions(-DHAVE_CONFIG_H)
add_definitions(-DLINK_SIZE=2)
add_definitions(-DMATCH_LIMIT=10000000)
add_definitions(-DMATCH_LIMIT_RECURSION=10000000)
add_definitions(-DMAX_NAME_SIZE=32)
add_definitions(-DMAX_NAME_COUNT=10000)
add_definitions(-DMAX_DUPLENGTH=30000)
add_definitions(-DNEWLINE=-1)
add_definitions(-DPCRE_STATIC)
add_definitions(-DPOSIX_MALLOC_THRESHOLD=10)
add_definitions(-DSUPPORT_UCP)
add_definitions(-DSUPPORT_UTF8)

















#包含工程所需要的头文件路径



include_directories(${PROJECT_SOURCE_DIR}/glib)
include_directories(${PROJECT_SOURCE_DIR}/glib/gnulib)
include_directories(${PROJECT_SOURCE_DIR}/gio/win32)
include_directories(${PROJECT_SOURCE_DIR}/gmodule)
include_directories(${PROJECT_SOURCE_DIR}/gio)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(../zlib)
include_directories(../ffi/include)








#set(CONFIG_HDR ../glib/glib/config.h)








#add_subdirectory(src)

#设置源文件的相对路径和文件名
#PROJECT_SOURCE_DIR变量为最顶层Cmakelists.txt的路径
set(SRC ${PROJECT_SOURCE_DIR}/glib/gnulib/asnprintf.c
${PROJECT_SOURCE_DIR}/glib/docs.c
${PROJECT_SOURCE_DIR}/gio/gaction.c
${PROJECT_SOURCE_DIR}/gio/gactiongroup.c
${PROJECT_SOURCE_DIR}/gio/gactiongroupexporter.c


${PROJECT_SOURCE_DIR}/gio/gactionmap.c
${PROJECT_SOURCE_DIR}/gio/gappinfo.c
${PROJECT_SOURCE_DIR}/gio/gapplication.c
${PROJECT_SOURCE_DIR}/gio/gapplicationcommandline.c
${PROJECT_SOURCE_DIR}/gio/gapplicationimpl-dbus.c
${PROJECT_SOURCE_DIR}/glib/garray.c
${PROJECT_SOURCE_DIR}/gio/gasynchelper.c
${PROJECT_SOURCE_DIR}/gio/gasyncinitable.c
${PROJECT_SOURCE_DIR}/glib/gasyncqueue.c
${PROJECT_SOURCE_DIR}/gio/gasyncresult.c
${PROJECT_SOURCE_DIR}/glib/gatomic.c
${PROJECT_SOURCE_DIR}/gobject/gatomicarray.c
${PROJECT_SOURCE_DIR}/glib/gbacktrace.c
${PROJECT_SOURCE_DIR}/glib/gbase64.c
${PROJECT_SOURCE_DIR}/gobject/gbinding.c
${PROJECT_SOURCE_DIR}/glib/gbitlock.c
${PROJECT_SOURCE_DIR}/glib/gbookmarkfile.c
${PROJECT_SOURCE_DIR}/gobject/gboxed.c
${PROJECT_SOURCE_DIR}/gio/gbufferedinputstream.c
${PROJECT_SOURCE_DIR}/gio/gbufferedoutputstream.c
${PROJECT_SOURCE_DIR}/glib/gbytes.c
${PROJECT_SOURCE_DIR}/gio/gbytesicon.c
${PROJECT_SOURCE_DIR}/gio/gcancellable.c
${PROJECT_SOURCE_DIR}/glib/gcharset.c
${PROJECT_SOURCE_DIR}/gio/gcharsetconverter.c
${PROJECT_SOURCE_DIR}/glib/gchecksum.c
${PROJECT_SOURCE_DIR}/gobject/gclosure.c
${PROJECT_SOURCE_DIR}/gio/gcontenttype-win32.c
${PROJECT_SOURCE_DIR}/glib/gconvert.c
${PROJECT_SOURCE_DIR}/gio/gconverter.c
${PROJECT_SOURCE_DIR}/gio/gconverterinputstream.c
${PROJECT_SOURCE_DIR}/gio/gconverteroutputstream.c
${PROJECT_SOURCE_DIR}/gio/gcredentials.c
${PROJECT_SOURCE_DIR}/gio/gdatainputstream.c
${PROJECT_SOURCE_DIR}/gio/gdataoutputstream.c
${PROJECT_SOURCE_DIR}/glib/gdataset.c
${PROJECT_SOURCE_DIR}/glib/gdate.c
${PROJECT_SOURCE_DIR}/glib/gdatetime.c
${PROJECT_SOURCE_DIR}/gio/gdbus-daemon-generated.c
${PROJECT_SOURCE_DIR}/gio/gdbusactiongroup.c
${PROJECT_SOURCE_DIR}/gio/gdbusaddress.c
${PROJECT_SOURCE_DIR}/gio/gdbusauth.c
${PROJECT_SOURCE_DIR}/gio/gdbusauthmechanism.c
${PROJECT_SOURCE_DIR}/gio/gdbusauthmechanismanon.c
${PROJECT_SOURCE_DIR}/gio/gdbusauthmechanismexternal.c
${PROJECT_SOURCE_DIR}/gio/gdbusauthmechanismsha1.c
${PROJECT_SOURCE_DIR}/gio/gdbusauthobserver.c
${PROJECT_SOURCE_DIR}/gio/gdbusconnection.c
${PROJECT_SOURCE_DIR}/gio/gdbusdaemon.c
${PROJECT_SOURCE_DIR}/gio/gdbuserror.c
${PROJECT_SOURCE_DIR}/gio/gdbusinterface.c
${PROJECT_SOURCE_DIR}/gio/gdbusinterfaceskeleton.c
${PROJECT_SOURCE_DIR}/gio/gdbusintrospection.c
${PROJECT_SOURCE_DIR}/gio/gdbusmenumodel.c
${PROJECT_SOURCE_DIR}/gio/gdbusmessage.c
${PROJECT_SOURCE_DIR}/gio/gdbusmethodinvocation.c
${PROJECT_SOURCE_DIR}/gio/gdbusnameowning.c
${PROJECT_SOURCE_DIR}/gio/gdbusnamewatching.c
${PROJECT_SOURCE_DIR}/gio/gdbusobject.c
${PROJECT_SOURCE_DIR}/gio/gdbusobjectmanager.c
${PROJECT_SOURCE_DIR}/gio/gdbusobjectmanagerclient.c
${PROJECT_SOURCE_DIR}/gio/gdbusobjectmanagerserver.c
${PROJECT_SOURCE_DIR}/gio/gdbusobjectproxy.c
${PROJECT_SOURCE_DIR}/gio/gdbusobjectskeleton.c
${PROJECT_SOURCE_DIR}/gio/gdbusprivate.c
${PROJECT_SOURCE_DIR}/gio/gdbusproxy.c
${PROJECT_SOURCE_DIR}/gio/gdbusserver.c
${PROJECT_SOURCE_DIR}/gio/gdbusutils.c
${PROJECT_SOURCE_DIR}/gio/gdelayedsettingsbackend.c
${PROJECT_SOURCE_DIR}/glib/gdir.c
${PROJECT_SOURCE_DIR}/gio/gdrive.c
${PROJECT_SOURCE_DIR}/gio/gdummyfile.c
${PROJECT_SOURCE_DIR}/gio/gdummyproxyresolver.c
${PROJECT_SOURCE_DIR}/gio/gdummytlsbackend.c
${PROJECT_SOURCE_DIR}/gio/gemblem.c
${PROJECT_SOURCE_DIR}/gio/gemblemedicon.c
${PROJECT_SOURCE_DIR}/gobject/genums.c
${PROJECT_SOURCE_DIR}/glib/genviron.c
${PROJECT_SOURCE_DIR}/glib/gerror.c
${PROJECT_SOURCE_DIR}/gio/gfile.c
${PROJECT_SOURCE_DIR}/gio/gfileattribute.c
${PROJECT_SOURCE_DIR}/gio/gfiledescriptorbased.c
${PROJECT_SOURCE_DIR}/gio/gfileenumerator.c
${PROJECT_SOURCE_DIR}/gio/gfileicon.c
${PROJECT_SOURCE_DIR}/gio/gfileinfo.c
${PROJECT_SOURCE_DIR}/gio/gfileinputstream.c
${PROJECT_SOURCE_DIR}/gio/gfileiostream.c
${PROJECT_SOURCE_DIR}/gio/gfilemonitor.c
${PROJECT_SOURCE_DIR}/gio/gfilenamecompleter.c
${PROJECT_SOURCE_DIR}/gio/gfileoutputstream.c
${PROJECT_SOURCE_DIR}/glib/gfileutils.c
${PROJECT_SOURCE_DIR}/gio/gfilterinputstream.c
${PROJECT_SOURCE_DIR}/gio/gfilteroutputstream.c
${PROJECT_SOURCE_DIR}/glib/ggettext.c
${PROJECT_SOURCE_DIR}/glib/ghash.c
${PROJECT_SOURCE_DIR}/glib/ghmac.c
${PROJECT_SOURCE_DIR}/glib/ghook.c
${PROJECT_SOURCE_DIR}/glib/ghostutils.c
${PROJECT_SOURCE_DIR}/gio/gicon.c
${PROJECT_SOURCE_DIR}/gio/ginetaddress.c
${PROJECT_SOURCE_DIR}/gio/ginetaddressmask.c
${PROJECT_SOURCE_DIR}/gio/ginetsocketaddress.c
${PROJECT_SOURCE_DIR}/gio/ginitable.c
${PROJECT_SOURCE_DIR}/gio/ginputstream.c
${PROJECT_SOURCE_DIR}/gio/gio-querymodules.c
${PROJECT_SOURCE_DIR}/glib/giochannel.c
${PROJECT_SOURCE_DIR}/gio/gioenumtypes.c
${PROJECT_SOURCE_DIR}/gio/gioerror.c
${PROJECT_SOURCE_DIR}/gio/giomodule.c
${PROJECT_SOURCE_DIR}/gio/gioscheduler.c
${PROJECT_SOURCE_DIR}/gio/giostream.c
${PROJECT_SOURCE_DIR}/glib/giowin32.c
${PROJECT_SOURCE_DIR}/glib/gkeyfile.c
${PROJECT_SOURCE_DIR}/gio/gkeyfilesettingsbackend.c
${PROJECT_SOURCE_DIR}/glib/glib-init.c
${PROJECT_SOURCE_DIR}/glib/glib-private.c
${PROJECT_SOURCE_DIR}/glib/glist.c
${PROJECT_SOURCE_DIR}/gio/gloadableicon.c
${PROJECT_SOURCE_DIR}/gio/glocaldirectorymonitor.c
${PROJECT_SOURCE_DIR}/gio/glocalfile.c
${PROJECT_SOURCE_DIR}/gio/glocalfileenumerator.c
${PROJECT_SOURCE_DIR}/gio/glocalfileinfo.c
${PROJECT_SOURCE_DIR}/gio/glocalfileinputstream.c
${PROJECT_SOURCE_DIR}/gio/glocalfileiostream.c
${PROJECT_SOURCE_DIR}/gio/glocalfilemonitor.c
${PROJECT_SOURCE_DIR}/gio/glocalfileoutputstream.c
${PROJECT_SOURCE_DIR}/gio/glocalvfs.c
${PROJECT_SOURCE_DIR}/glib/gmain.c
${PROJECT_SOURCE_DIR}/glib/gmappedfile.c
${PROJECT_SOURCE_DIR}/glib/gmarkup.c
${PROJECT_SOURCE_DIR}/gobject/gmarshal.c
${PROJECT_SOURCE_DIR}/glib/gmem.c
${PROJECT_SOURCE_DIR}/gio/gmemoryinputstream.c
${PROJECT_SOURCE_DIR}/gio/gmemoryoutputstream.c
${PROJECT_SOURCE_DIR}/gio/gmemorysettingsbackend.c
${PROJECT_SOURCE_DIR}/gio/gmenu.c
${PROJECT_SOURCE_DIR}/gio/gmenuexporter.c
${PROJECT_SOURCE_DIR}/gio/gmenumodel.c
${PROJECT_SOURCE_DIR}/glib/gmessages.c
${PROJECT_SOURCE_DIR}/gmodule/gmodule.c
${PROJECT_SOURCE_DIR}/gio/gmount.c
${PROJECT_SOURCE_DIR}/gio/gmountoperation.c
${PROJECT_SOURCE_DIR}/gio/gnativevolumemonitor.c
${PROJECT_SOURCE_DIR}/gio/gnetworkaddress.c
${PROJECT_SOURCE_DIR}/gio/gnetworking.c
${PROJECT_SOURCE_DIR}/gio/gnetworkmonitor.c
${PROJECT_SOURCE_DIR}/gio/gnetworkmonitorbase.c
${PROJECT_SOURCE_DIR}/gio/gnetworkservice.c
${PROJECT_SOURCE_DIR}/glib/gnode.c
${PROJECT_SOURCE_DIR}/gio/gnullsettingsbackend.c
${PROJECT_SOURCE_DIR}/gobject/gobject.c
${PROJECT_SOURCE_DIR}/gobject/gobjectnotifyqueue.c
${PROJECT_SOURCE_DIR}/glib/goption.c
${PROJECT_SOURCE_DIR}/gio/goutputstream.c
${PROJECT_SOURCE_DIR}/gobject/gparam.c
${PROJECT_SOURCE_DIR}/gobject/gparamspecs.c
${PROJECT_SOURCE_DIR}/glib/gpattern.c
${PROJECT_SOURCE_DIR}/gio/gpermission.c
${PROJECT_SOURCE_DIR}/glib/gpoll.c
${PROJECT_SOURCE_DIR}/gio/gpollableinputstream.c
${PROJECT_SOURCE_DIR}/gio/gpollableoutputstream.c
${PROJECT_SOURCE_DIR}/gio/gpollableutils.c
${PROJECT_SOURCE_DIR}/gio/gpollfilemonitor.c
${PROJECT_SOURCE_DIR}/glib/gprimes.c
${PROJECT_SOURCE_DIR}/glib/gprintf.c
${PROJECT_SOURCE_DIR}/gio/gpropertyaction.c
${PROJECT_SOURCE_DIR}/gio/gproxy.c
${PROJECT_SOURCE_DIR}/gio/gproxyaddress.c
${PROJECT_SOURCE_DIR}/gio/gproxyaddressenumerator.c
${PROJECT_SOURCE_DIR}/gio/gproxyresolver.c
${PROJECT_SOURCE_DIR}/glib/gqsort.c
${PROJECT_SOURCE_DIR}/glib/gquark.c
${PROJECT_SOURCE_DIR}/glib/gqueue.c
${PROJECT_SOURCE_DIR}/glib/grand.c
${PROJECT_SOURCE_DIR}/glib/gregex.c
${PROJECT_SOURCE_DIR}/gio/gregistrysettingsbackend.c
${PROJECT_SOURCE_DIR}/gio/gremoteactiongroup.c
${PROJECT_SOURCE_DIR}/gio/gresolver.c
${PROJECT_SOURCE_DIR}/gio/gresource.c
${PROJECT_SOURCE_DIR}/gio/gresourcefile.c
${PROJECT_SOURCE_DIR}/glib/gscanner.c
${PROJECT_SOURCE_DIR}/gio/gseekable.c
${PROJECT_SOURCE_DIR}/glib/gsequence.c
${PROJECT_SOURCE_DIR}/gio/gsettings-mapping.c
${PROJECT_SOURCE_DIR}/gio/gsettings.c
${PROJECT_SOURCE_DIR}/gio/gsettingsbackend.c
${PROJECT_SOURCE_DIR}/gio/gsettingsschema.c
${PROJECT_SOURCE_DIR}/glib/gshell.c
${PROJECT_SOURCE_DIR}/gobject/gsignal.c
${PROJECT_SOURCE_DIR}/gio/gsimpleaction.c
${PROJECT_SOURCE_DIR}/gio/gsimpleactiongroup.c
${PROJECT_SOURCE_DIR}/gio/gsimpleasyncresult.c
${PROJECT_SOURCE_DIR}/gio/gsimplepermission.c
${PROJECT_SOURCE_DIR}/gio/gsimpleproxyresolver.c
${PROJECT_SOURCE_DIR}/glib/gslice.c
${PROJECT_SOURCE_DIR}/glib/gslist.c
${PROJECT_SOURCE_DIR}/gio/gsocket.c
${PROJECT_SOURCE_DIR}/gio/gsocketaddress.c
${PROJECT_SOURCE_DIR}/gio/gsocketaddressenumerator.c
${PROJECT_SOURCE_DIR}/gio/gsocketclient.c
${PROJECT_SOURCE_DIR}/gio/gsocketconnectable.c
${PROJECT_SOURCE_DIR}/gio/gsocketconnection.c
${PROJECT_SOURCE_DIR}/gio/gsocketcontrolmessage.c
${PROJECT_SOURCE_DIR}/gio/gsocketinputstream.c
${PROJECT_SOURCE_DIR}/gio/gsocketlistener.c
${PROJECT_SOURCE_DIR}/gio/gsocketoutputstream.c
${PROJECT_SOURCE_DIR}/gio/gsocketservice.c
${PROJECT_SOURCE_DIR}/gio/gsocks4aproxy.c
${PROJECT_SOURCE_DIR}/gio/gsocks4proxy.c
${PROJECT_SOURCE_DIR}/gio/gsocks5proxy.c
${PROJECT_SOURCE_DIR}/gobject/gsourceclosure.c
${PROJECT_SOURCE_DIR}/glib/gspawn-win32.c
${PROJECT_SOURCE_DIR}/gio/gsrvtarget.c
${PROJECT_SOURCE_DIR}/glib/gstdio.c
${PROJECT_SOURCE_DIR}/glib/gstrfuncs.c
${PROJECT_SOURCE_DIR}/glib/gstring.c
${PROJECT_SOURCE_DIR}/glib/gstringchunk.c
${PROJECT_SOURCE_DIR}/gio/gtask.c
${PROJECT_SOURCE_DIR}/gio/gtcpconnection.c
${PROJECT_SOURCE_DIR}/gio/gtcpwrapperconnection.c
${PROJECT_SOURCE_DIR}/gio/gtestdbus.c
${PROJECT_SOURCE_DIR}/glib/gtestutils.c
${PROJECT_SOURCE_DIR}/gio/gthemedicon.c
${PROJECT_SOURCE_DIR}/glib/gthread-win32.c
${PROJECT_SOURCE_DIR}/glib/gthread.c
${PROJECT_SOURCE_DIR}/gio/gthreadedresolver.c
${PROJECT_SOURCE_DIR}/gio/gthreadedsocketservice.c
${PROJECT_SOURCE_DIR}/glib/gthreadpool.c
${PROJECT_SOURCE_DIR}/glib/gtimer.c
${PROJECT_SOURCE_DIR}/glib/gtimezone.c
${PROJECT_SOURCE_DIR}/gio/gtlsbackend.c
${PROJECT_SOURCE_DIR}/gio/gtlscertificate.c
${PROJECT_SOURCE_DIR}/gio/gtlsclientconnection.c
${PROJECT_SOURCE_DIR}/gio/gtlsconnection.c
${PROJECT_SOURCE_DIR}/gio/gtlsdatabase.c
${PROJECT_SOURCE_DIR}/gio/gtlsfiledatabase.c
${PROJECT_SOURCE_DIR}/gio/gtlsinteraction.c
${PROJECT_SOURCE_DIR}/gio/gtlspassword.c
${PROJECT_SOURCE_DIR}/gio/gtlsserverconnection.c
${PROJECT_SOURCE_DIR}/glib/gtrashstack.c
${PROJECT_SOURCE_DIR}/glib/gtree.c
${PROJECT_SOURCE_DIR}/gobject/gtype.c
${PROJECT_SOURCE_DIR}/gobject/gtypemodule.c
${PROJECT_SOURCE_DIR}/gobject/gtypeplugin.c
${PROJECT_SOURCE_DIR}/glib/gunibreak.c
${PROJECT_SOURCE_DIR}/glib/gunicollate.c
${PROJECT_SOURCE_DIR}/glib/gunidecomp.c
${PROJECT_SOURCE_DIR}/gio/gunionvolumemonitor.c
${PROJECT_SOURCE_DIR}/glib/guniprop.c
${PROJECT_SOURCE_DIR}/glib/gurifuncs.c
${PROJECT_SOURCE_DIR}/glib/gutf8.c
${PROJECT_SOURCE_DIR}/glib/gutils.c
${PROJECT_SOURCE_DIR}/gobject/gvalue.c
${PROJECT_SOURCE_DIR}/gobject/gvaluearray.c
${PROJECT_SOURCE_DIR}/gobject/gvaluetransform.c
${PROJECT_SOURCE_DIR}/gobject/gvaluetypes.c
${PROJECT_SOURCE_DIR}/glib/gvariant-core.c
${PROJECT_SOURCE_DIR}/glib/gvariant-parser.c
${PROJECT_SOURCE_DIR}/glib/gvariant-serialiser.c
${PROJECT_SOURCE_DIR}/glib/gvariant.c
${PROJECT_SOURCE_DIR}/glib/gvarianttype.c
${PROJECT_SOURCE_DIR}/glib/gvarianttypeinfo.c
${PROJECT_SOURCE_DIR}/gio/gvdb/gvdb-builder.c
${PROJECT_SOURCE_DIR}/gio/gvdb/gvdb-reader.c
${PROJECT_SOURCE_DIR}/glib/gversion.c
${PROJECT_SOURCE_DIR}/gio/gvfs.c
${PROJECT_SOURCE_DIR}/gio/gvolume.c
${PROJECT_SOURCE_DIR}/gio/gvolumemonitor.c
${PROJECT_SOURCE_DIR}/glib/gwakeup.c
${PROJECT_SOURCE_DIR}/glib/gwin32.c
${PROJECT_SOURCE_DIR}/gio/gwin32appinfo.c
${PROJECT_SOURCE_DIR}/gio/win32/gwin32directorymonitor.c
${PROJECT_SOURCE_DIR}/gio/gwin32inputstream.c
${PROJECT_SOURCE_DIR}/gio/gwin32mount.c
${PROJECT_SOURCE_DIR}/gio/gwin32outputstream.c
${PROJECT_SOURCE_DIR}/gio/gwin32volumemonitor.c
${PROJECT_SOURCE_DIR}/gio/win32/gwinhttpfile.c
${PROJECT_SOURCE_DIR}/gio/win32/gwinhttpfileinputstream.c
${PROJECT_SOURCE_DIR}/gio/win32/gwinhttpfileoutputstream.c
${PROJECT_SOURCE_DIR}/gio/win32/gwinhttpvfs.c
${PROJECT_SOURCE_DIR}/gio/gzlibcompressor.c
${PROJECT_SOURCE_DIR}/gio/gzlibdecompressor.c
${PROJECT_SOURCE_DIR}/glib/libcharset/localcharset.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_byte_order.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_chartables.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_compile.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_config.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_dfa_exec.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_exec.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_fullinfo.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_get.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_globals.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_jit_compile.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_newline.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_ord2utf8.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_string_utils.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_study.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_tables.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_valid_utf8.c
${PROJECT_SOURCE_DIR}/glib/pcre/pcre_xclass.c
${PROJECT_SOURCE_DIR}/glib/gnulib/printf-args.c
${PROJECT_SOURCE_DIR}/glib/gnulib/printf-parse.c
${PROJECT_SOURCE_DIR}/glib/gnulib/printf.c
${PROJECT_SOURCE_DIR}/gio/strinfo.c
${PROJECT_SOURCE_DIR}/glib/gnulib/vasnprintf.c




)







#file(GLOB FFI_SRC  blocksort.c bzilb.c compress.c crctable.c decompress.c huffman.c rendtable.c )
#file(GLOB FFI_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

#source_group("Header Files" FILES ${ZLIB_HDR})
ADD_LIBRARY(CORE_glib STATIC ${SRC} )

set_target_properties(CORE_glib PROPERTIES COMPILE_FLAGS "/EHsc /GF")

set_target_properties(CORE_glib PROPERTIES
        OUTPUT_NAME CORE_glib
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


INSTALL(TARGETS CORE_glib
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)

