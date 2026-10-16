#include <glad/gl.h>
#include <glfw/glfw3.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

int main()
{
	// OpenGL + window init
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* glfw_window = glfwCreateWindow(500, 500, "App", NULL, NULL);

	glfwMakeContextCurrent(glfw_window);

	gladLoadGL(glfwGetProcAddress);
	//

	// ImGui init
	ImGui::CreateContext();
	ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f); // older style

	ImGui::GetIO().IniFilename = nullptr; // reset imgui data on startup

	ImGui_ImplGlfw_InitForOpenGL(glfw_window, true);
	ImGui_ImplOpenGL3_Init();
	//


	while (!glfwWindowShouldClose(glfw_window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		glClear(GL_COLOR_BUFFER_BIT);

		// IMGUI COMMANDS HERE

		ImGui::NewFrame();

		//ImGui::SetNextWindowPos(ImVec2(0, 0));
		//ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

		if (ImGui::Begin("MainWindow", nullptr)) {
			ImGui::Button("Example button", ImVec2(120, 20));
		};

		ImGui::End();

		ImGui::Render();

		//

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(glfw_window);
	};

	return 0;
}
