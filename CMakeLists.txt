cmake_minimum_required(VERSION 3.14)

project(AimmyV2_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set the CMAKE_PREFIX_PATH to the Qt installation directory
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/mingw_64")

# Manually set ONNX Runtime paths
set(ONNXRUNTIME_INCLUDE_DIRS "C:/Amm/onnxruntime-win-x64-1.18.1/include")
set(ONNXRUNTIME_LIBRARIES "C:/Amm/onnxruntime-win-x64-1.18.1/lib/onnxruntime.lib")

include_directories(${ONNXRUNTIME_INCLUDE_DIRS})

# Manually set TinyXML2 paths
set(TINYXML2_INCLUDE_DIRS "C:/Amm/tinyxml2-10.0.0")
set(TINYXML2_LIBRARIES "C:/Amm/tinyxml2-10.0.0/build/libtinyxml2.a")

include_directories(${TINYXML2_INCLUDE_DIRS})

# Include directory for custom headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find Qt6
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(include)

# Add the .ui files
set(UI_FILES
    src/OverlayWindow.ui
    src/SecondaryWindow.ui
    src/MainWindow.ui
)

# Add the header files
set(HEADERS
    include/MainWindow.h
    include/OverlayWindow.h
    include/SecondaryWindow.h
    include/Visualization.h
    include/Configs.h
    include/Fonts.h
    include/Settings.h
    include/AIModel.h
    include/PredictionManager.h
    include/InputBindingManager.h
    include/RequirementsManager.h
    include/UserController.h
    include/KeybindEventFilter.h
    include/PredictAheadTarget.h  # Include the new prediction method header
    predictions/LeadTargetPrediction.h  # Include the LeadTargetPrediction header
)

# Set the source files variable
set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/OverlayWindow.cpp
    src/SecondaryWindow.cpp
    src/Visualization.cpp
    src/Configs.cpp
    src/Fonts.cpp
    src/Settings.cpp
    src/AIModel.cpp
    src/PredictionManager.cpp
    src/InputBindingManager.cpp
    src/RequirementsManager.cpp
    src/UserController.cpp
    src/KeybindEventFilter.cpp
    src/PredictAheadTarget.cpp  # Include the new prediction method source
    predictions/LeadTargetPrediction.cpp  # Include the LeadTargetPrediction source
    ${UI_FILES}
)

# Add the executable target
add_executable(AimmyV2_CPP ${SOURCES} ${HEADERS})

# Link the required libraries
target_link_libraries(AimmyV2_CPP
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    ${ONNXRUNTIME_LIBRARIES}
    ${TINYXML2_LIBRARIES}
)
