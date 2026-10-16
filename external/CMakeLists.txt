project(GLAD) # GLAD

add_library(GLAD)

target_sources(GLAD PRIVATE "glad/src/gl.c")

target_include_directories(GLAD PRIVATE
"glad/include"
)

add_subdirectory("glfw") # glfw

project(IMGUI) # IMGUI

add_library(IMGUI)

target_sources(IMGUI PRIVATE
"imgui/imgui.cpp"
"imgui/imgui_draw.cpp"
"imgui/imgui_tables.cpp"
"imgui/imgui_widgets.cpp"
"imgui/backends/imgui_impl_opengl3.cpp"
"imgui/backends/imgui_impl_glfw.cpp"
)

target_include_directories(IMGUI PRIVATE
"glfw/include"
"imgui"
)