cmake_minimum_required(VERSION 3.14)

project(temper_contrl LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /UMBCS /D_UNICODE /DUNICODE")
#thridtooltaoqucik thridtool\taoQucik
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/thridtool/taoQucik_t/cmake)


include(taoVersion)

    add_compile_definitions(TaoCommon_NO_LIB)
    # modbus tcp serialport
   # add_compile_definitions(SAK_IMPORT_MODULE_SERIALBUS)
   # add_compile_definitions(SAK_IMPORT_MODULE_SERIALPORT)

   # add_compile_definitions(SAK_IMPORT_MODULE_UDP_CLIENT)
   # add_compile_definitions(SAK_IMPORT_MODULE_UDP)


    #add_compile_definitions(SAK_IMPORT_MODULE_TCP_SERVER)
   # add_compile_definitions(SAK_IMPORT_MODULE_TCP_CLIENT)
   # add_compile_definitions(SAK_IMPORT_MODULE_TCP)
   # add_compile_definitions(SAK_IMPORT_MODULE_TCP_CLIENT)

   # add_compile_definitions(SAK_IMPORT_MODULE_WEBSOCKET)
   # add_compile_definitions(SAK_IMPORT_MODULE_WEBSOCKET_CLIENT)
   # add_compile_definitions(SAK_IMPORT_MODULE_WEBSOCKET_SERVER)

   # add_compile_definitions(SAK_IMPORT_MODULE_TEST)
   # add_compile_definitions(SAK_IMPORT_MODULE_TESTLIB)

   # add_compile_definitions(SAK_HOST_ADDRESS_ANY=\"\\\"Any\\\"\")
 add_subdirectory(${CMAKE_SOURCE_DIR}/thridtool/taoQucik_t/3rdparty/TaoCommon/src/TaoCommon ${CMAKE_SOURCE_DIR}/build/3rdparty/TaoCommon)

  include(taoQuick)

  #add_definitions(QMAKE_GEN_TAOMACRO)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS      Core gui Quick Qml network printsupport quickcontrols2 serialbus serialport Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core gui Quick Qml network printsupport quickcontrols2 serialbus serialport Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        Res.qrc
        Tao_custom.qrc
        login.qrc
           TaoQuick/TaoQuick.qrc
)

include_directories(
    thridtool/framelesswindow_all
    thridtool/QCustomPlot/qcustomplot
    thridtool/QCustomPlot/qcustomplotapi
 thridtool/QCustomPlot/qcustomplot/Anvedi
  thridtool/QCustomPlot/qcustomplot/Anvedi/qml-lib
   thridtool/Qmodbus/src/modbus/client/
   thridtool/Qmodbus/src/modbus/common/
   thridtool/Qmodbus/src/modbus/server/
  #  thridtool/Qmodbus/src/Qmdcommon/
    )
file(GLOB soucres
    "thridtool/framelesswindow_all/*cpp"
    "thridtool/QCustomPlot/qcustomplot/*cpp"
      "thridtool/QCustomPlot/qcustomplotapi/*cpp"
     "thridtool/QCustomPlot/qcustomplot/Anvedi/*cpp"
      "thridtool/QCustomPlot/qcustomplot/Anvedi/qml-lib/*cpp"

      "thridtool/Qmodbus/src/modbus/client/*cc"
      "thridtool/Qmodbus/src/modbus/common/*cc"
      "thridtool/Qmodbus/src/modbus/server/*cc"
     # "thridtool/Qmodbus/src/Qmdcommon/*cc"
    )



        if (CMAKE_BUILD_TYPE MATCHES "Release")
          #  add_executable(MyApp ${someSource} ${TaoQuickRes})
            add_executable(temper_contrl

                  ${TaoCommonFiles}
                ${PROJECT_SOURCES}
               ${soucres}
               ${framlesssrc}
              #   ${TaoQuickRes}
            )
        else()
#            add_executable(MyApp ${someSource})
             add_executable(temper_contrl
              ${PROJECT_SOURCES}
               ${soucres}
                ${framlesssrc}
                   ${TaoCommonFiles}
            )
        endif()




target_include_directories(temper_contrl PUBLIC . ./Src ${TaoCommonPath})


target_compile_definitions(temper_contrl
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(temper_contrl
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::SerialBus
   Qt${QT_VERSION_MAJOR}::SerialPort
  Qt${QT_VERSION_MAJOR}::Widgets
   Qt${QT_VERSION_MAJOR}::PrintSupport
   Qt${QT_VERSION_MAJOR}::Network
  )
