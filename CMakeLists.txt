cmake_minimum_required(VERSION 3.22)
project(ImguiPractice)
set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(UNICODE _UNICODE)
file(GLOB_RECURSE IMGUI ${PROJECT_SOURCE_DIR}/imgui/*.cpp)
file(GLOB_RECURSE BACKEND ${PROJECT_SOURCE_DIR}/backend/*.cpp)
file(GLOB_RECURSE UTILS ${PROJECT_SOURCE_DIR}/utils/*.cpp)
file(GLOB_RECURSE WINDOWS ${PROJECT_SOURCE_DIR}/windows/*.cpp)
file(GLOB_RECURSE COMPONENTS ${PROJECT_SOURCE_DIR}/components/*.cpp)
file(GLOB_RECURSE D3D11StructureArchiveProxy ${PROJECT_SOURCE_DIR}/D3D11StructureArchiveProxy/*.cpp)
file(GLOB_RECURSE Triangle ${PROJECT_SOURCE_DIR}/triangle/*.cpp)
file(GLOB_RECURSE MAIN ${PROJECT_SOURCE_DIR}/main/*.cpp)


include_directories(${PROJECT_SOURCE_DIR}/imgui)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(ImguiPractice main.cpp ${IMGUI} ${BACKEND} ${UTILS} ${WINDOWS} ${COMPONENTS} ${D3D11StructureArchiveProxy} ${Triangle})

add_executable(BasicDraw start.cpp ${MAIN} ${Triangle})

add_executable(outTestCereal test/outCerealTest.cpp)
add_executable(inTestCereal test/inCerealTest.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE d3d11.lib)
target_link_libraries(BasicDraw PRIVATE d3d11.lib D3DCompiler.lib d2d1.lib)
