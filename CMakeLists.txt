# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (basic_imgui_template)

add_executable (basic_imgui_template)

file(GLOB_RECURSE SOURCES
    "basic_imgui_template/src/*.cpp"
    "basic_imgui_template/src/*.c"
)

file(GLOB_RECURSE HEADERS
    "basic_imgui_template/src/*.h"
)

target_sources (basic_imgui_template PRIVATE ${SOURCES} ${HEADERS})

target_include_directories(basic_imgui_template PRIVATE
    "basic_imgui_template/src/include"
)

# Include sub-projects.
add_subdirectory("basic_imgui_template")
add_subdirectory("external")

target_link_libraries(basic_imgui_template PRIVATE glfw)
target_link_libraries(basic_imgui_template PRIVATE GLAD)
target_link_libraries(basic_imgui_template PRIVATE IMGUI)

target_include_directories(basic_imgui_template PRIVATE
"external/glad/include"
"external/glfw/include",
"external/imgui",
"external/imgui/backends"
)