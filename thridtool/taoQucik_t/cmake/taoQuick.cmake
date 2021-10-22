set(TaoQuickPath ${CMAKE_SOURCE_DIR}/thridtool/taoQucik_t/src)

if (CMAKE_BUILD_TYPE MATCHES "Release")

    set(TaoQuickRes ${TaoQuickPath}/TaoQuick/TaoQuick.qrc CACHE STRING "tao quick res path")

    set(TaoQuickImport "qrc:///" CACHE STRING "tao quick import path")
    set(TaoQuickImage "qrc:/TaoQuick/Images/" CACHE STRING "tao quick image path")

else()
    set(TaoQuickImport "file:///${TaoQuickPath}" CACHE STRING "tao quick import path")
    set(TaoQuickImage "file:///${TaoQuickPath}/TaoQuick/Images/" CACHE STRING "tao quick image path")
endif()

 include_directories(${TaoQuickPath}/TaoQuick/src)
if(WIN32)
    set(glob framlesssrc
       ${TaoQuickPath}/TaoQuick/src/*_win.cpp
        )

else()
    set(glob framlesssrc
       ${TaoQuickPath}/TaoQuick/src/*_unix.cpp
        )
endif()

add_compile_definitions(TaoQuickImport="${TaoQuickImport}")
add_compile_definitions(TaoQuickImage="${TaoQuickImage}")

add_compile_definitions(TaoQuickImportPath="${TaoQuickImport}")
add_compile_definitions(TaoQuickImagePath="${TaoQuickImage}")

add_compile_definitions(QML_IMPORT_PATH="${TaoQuickPath}")
add_compile_definitions(QML2_IMPORT_PATH="${TaoQuickPath}")
add_compile_definitions(QML_DESIGNER_IMPORT_PATH="${TaoQuickPath}")

