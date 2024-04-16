cmake_minimum_required(VERSION 3.5)

project(algosi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        algorithms.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(algosi
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        algorithms.cpp README.md
        .gitignore algorithms.cpp CMakeLists.txt main.cpp mainwindow.cpp mainwindow.h mainwindow.ui README.md sad.png
        algorithms/Insertion.cpp
        algorithms/Selection.cpp
        algorithms/Bubble.cpp
        algorithms/Gnome.cpp
        algorithms/Cocktail.cpp
        algorithms/Heap.cpp
        algorithms/Quick.cpp
        algorithms/Merge.cpp
        algorithms/Tree.cpp
        algorithms/Comb.cpp
        algorithms/Shell.cpp
        algorithms/Bucket.cpp
        algorithms/Pancake.cpp
        algorithms/PSRS.cpp
        algorithms/Patience.cpp
        algorithms/Smooth.cpp
        algorithms/Tim.cpp
        algorithms/Radix.cpp
        algorithms/Sleep.cpp
        algorithms/Stalin.cpp
        algorithms/Bitonic.cpp
    )

find_package(Qt6 REQUIRED COMPONENTS Charts)
target_link_libraries(algosi PRIVATE Qt6::Charts)

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET algosi APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(algosi SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(algosi
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(algosi PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.algosi)
endif()
set_target_properties(algosi PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS algosi
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(algosi)
endif()
