#include <GL/glew.h>
#include <GLFW/glfw3.h> 

#include "..\Includes\Shader.h"
#include <iostream>
#include "../Includes/Shapes/Grid.h"
#include "../Includes/3D/Camera.h"
#include "../Includes/Maths/Transform.h"
#include "../Includes/Shapes/Sphere.h"
#include "../Includes/Shapes/Circle.h"
#include "Shapes/Cube.h"
#include "Shapes/Torus.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;


int main(int argc, char* argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glewInit();

	Shader ourShader("D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs", "D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs");

	//Shader ourShader("D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/LightVertexShader.vs", "D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/LightFragmentShader.fs");
	glEnable(GL_DEPTH_TEST);

	
	
	

	/*unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);*/

	
	


	Sphere sphere(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(-15, 0, 0),
		5,
		30,
		nullptr
	);

	Sphere sphere1(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(10, 0, 0),
		2,
		30,
		&sphere
	);

	Sphere sphere2(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(6.5, 0, 0),
		2,
		30,
		&sphere1
	);


	Cube cube(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(6.5, 0, 0),
		5,
		nullptr
	);

	Torus torus(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(6.5, 0, 0),
		10,
		5,
		20,
		20,
		nullptr
	);
	
	Camera camera(Vector3(0,0,-50), Vector3(0,0,0), 500, .005f, 60);
	float angle=0;

	//sphere.transform.Rotate(Vector3(0, 1, 0), 45);
	//sphere.transform.Translate(Vector3(-15, 0, 0));
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		angle+=.1f/10.0f;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//grid.Render(camera);
		/*sphere.Render(camera);
		sphere1.Render(camera);
		sphere2.Render(camera);
		sphere.transform.Rotate(Vector3(0, 1, 0), 1.f);
		sphere1.transform.Rotate(Vector3(0, 1, 0), 1);
	*/
		//cube.Render(camera);
		torus.Render(camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	sphere.DeleteDrawingData();
	sphere1.DeleteDrawingData();
	sphere2.DeleteDrawingData();
//	grid.DeleteDrawingData();

	
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that gridSize and 
	// cellCount will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}