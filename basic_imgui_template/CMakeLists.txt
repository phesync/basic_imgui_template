# CMakeList.txt : CMake project for basic_imgui_template, include source and define
# project specific logic here.
#

# Add source to this project's executable.


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET basic_imgui_template PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
