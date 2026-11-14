cmake_minimum_required(VERSION 3.20)
project(ZombieTreasureHunt LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_path(ASSIMP_INCLUDE_DIR assimp/Importer.hpp REQUIRED)
find_library(ASSIMP_LIBRARY NAMES assimp REQUIRED)

add_executable(ZombieTreasureHunt
    src/main.cpp
    src/Game.cpp
    src/Shader.cpp
    src/Model.cpp
    src/WaveManager.cpp
)
target_include_directories(ZombieTreasureHunt PRIVATE third_party ${ASSIMP_INCLUDE_DIR})
target_link_libraries(ZombieTreasureHunt PRIVATE OpenGL::GL glfw GLEW::GLEW glm::glm ${ASSIMP_LIBRARY})

include(CTest)
if(BUILD_TESTING)
    add_test(NAME gameplay_logic COMMAND ZombieTreasureHunt --self-test)
    add_test(NAME asset_import COMMAND ZombieTreasureHunt --asset-test)
    set_tests_properties(gameplay_logic asset_import PROPERTIES WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif()
