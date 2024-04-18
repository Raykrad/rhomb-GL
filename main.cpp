#include <GLFW/glfw3.h>
#include <imgui.h>
#include <iostream>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
void renderRhomb(float rotation, float scale, float posX, float posY) 
//создание ромба
{
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0, 800, 0, 600, -1, 1);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glPushMatrix();
 glTranslatef(posX, posY, 0.0f);
 glRotatef(rotation, 0.0f, 0.0f, 1.0f);
 glScalef(scale, scale, 1.0f);
 glColor3f(0.0f, 1.0f, 0.0f);
 glBegin(GL_POLYGON);
 glVertex2f(100, 0);
 glVertex2f(0, 100);
 glVertex2f(-100, 0);
 glVertex2f(0, -100);
 glEnd();
 glPopMatrix();
}
int main()
{
 // Инициализация GLFW и ImGUI
 glfwInit();
 GLFWwindow* window = glfwCreateWindow(1024, 768, "Rhomb", 
NULL, NULL);
 if (window == NULL)
 {
 std::cout<< "Failed to create GLFW window" << std::endl;
 glfwTerminate();
 return -1;
 }
 glfwMakeContextCurrent(window);
 ImGui::CreateContext();
 ImGuiIO& io = ImGui::GetIO();
 ImGui_ImplGlfw_InitForOpenGL(window, true);
 ImGui_ImplOpenGL3_Init("#version 130");
 float initialRotation = 0.0f;
 float initialScale = 1.0f;
 float initialPosX = 400.0f;
 float initialPosY = 300.0f;
 float rotation = initialRotation;
 float scale = initialScale;
 float posX = initialPosX;
 float posY = initialPosY;
 while (!glfwWindowShouldClose(window))
 {
 glfwPollEvents();
 ImGui_ImplOpenGL3_NewFrame();
 ImGui_ImplGlfw_NewFrame();
 ImGui::NewFrame();
 ImGui::Begin("Interaction Panel");
 ImGui::SliderFloat("Rotation", &rotation, 0.0f, 360.0f);
 ImGui::SliderFloat("Scale", &scale, 0.1f, 3.0f);
 ImGui::SliderFloat("The X-axis", &posX, 0.0f, 800.0f);
 ImGui::SliderFloat("The Y-axis", &posY, 0.0f, 600.0f);
 if (ImGui::Button("Reset"))
 {
 rotation = initialRotation;
 scale = initialScale;
 posX = initialPosX;
 posY = initialPosY;
 }
 ImGui::End();
 renderRhomb(rotation, scale, posX, posY);
 ImGui::Render();
 ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
 glfwSwapBuffers(window);
 }
 ImGui_ImplOpenGL3_Shutdown();
 ImGui_ImplGlfw_Shutdown();
 ImGui::DestroyContext();
 glfwDestroyWindow(window);
 glfwTerminate();
 return 0;
}
