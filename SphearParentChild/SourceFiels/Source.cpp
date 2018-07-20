#include <GL/glew.h>
#include <GLFW/glfw3.h> 

#include "..\Includes\Shader.h"
#include <iostream>
#include "../Includes/Shapes/Grid.h"
#include "../Includes/3D/Camera.h"
#include "../Includes/Maths/Transform.h"
#include "../Includes/Shapes/Sphere.h"
#include "../Includes/Shapes/Circle.h"

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

	float colorVertices[] = {
		// front
		-0.2, -0.1, -0.5,
		0.1, -0.2, -0.35,
		0.21,  0.23, -0.5,
		-0.2,  0.2, -0.5,

		-0.2, -0.2,  0.5 ,
		0.2, -0.2,  0.5 ,
		0.2,  0.2,  0.5 ,
		-0.2,  0.2,  0.5
	};

	float vertices[] = {
		// front
		-0.2, -0.2, -0.2,   0.0, 0.0, 1.0f,		   //(0)
		 0.2, -0.2, -0.2,   0.0, 0.0, 1.0f,		   //(1)
		 0.2,  0.2, -0.2,   0.0, 0.0, 1.0f,		   //(2)
		-0.2,  0.2, -0.2,   0.0, 0.0, 1.0f,		   //(3)


												   //back									   
		-0.2,  -0.2,  0.2 ,  0.0, 0.0, -1.0f,	   //(4)
		 0.2,  -0.2,  0.2 ,  0.0, 0.0, -1.0f,	   //(5)
		 0.2,   0.2,  0.2 ,  0.0, 0.0, -1.0f,	   //(6)
		-0.2,   0.2,  0.2,   0.0, 0.0, -1.0f,	   //(7)

	  //left									   
		-0.2, -0.2, -0.2,   1.0, 0.0, 0.0f,		   //(8)
		-0.2,  -0.2, 0.2,   1.0, 0.0, 0.0f,		   //(9)
		-0.2,   0.2, 0.2,	1.0, 0.0, 0.0f,		   //(10)
		-0.2,  0.2, -0.2,	1.0, 0.0, 0.0f,		   //(11)

	//right								   
		 0.2,  -0.2, -0.2,  -1.0, 0.0, 0.0f,	   //(12)
		 0.2,   0.2, -0.2,  -1.0, 0.0, 0.0f,	   //(13)
		 0.2,   0.2,  0.2,  -1.0, 0.0, 0.0f,	   //(14)
		 0.2,  -0.2,  0.2,  -1.0, 0.0, 0.0f,	   //(15)

	  //top								   
	    -0.2,  0.2, -0.2,  0.0, 1.0, 0.0f,		   //(16)
	     0.2,  0.2, -0.2,  0.0, 1.0, 0.0f,		   //(17)
	     0.2,  0.2,  0.2,  0.0, 1.0, 0.0f,		   //(18)
	    -0.2,  0.2,  0.2,  0.0, 1.0, 0.0f,		   //(19)

	// bottom
	    -0.2, -0.2, -0.2,  0.0,-1.0, 0.0f,        //(20)
	    -0.2, -0.2,  0.2,  0.0,-1.0, 0.0f,        //(21)
	     0.2, -0.2,  0.2,  0.0,-1.0, 0.0f,        //(22)
	     0.2, -0.2, -0.2,  0.0,-1.0, 0.0f,        //(23)
	};

	unsigned int indices[] = {
		//front
		0,1,2,
		0,2,3,

		//right face
		12,14,13,
		12,15,14,

		//bottom face
		20,21,22,
		20,22,23,

		//top face
		16,17,18,
		16,18,19,

		//left face

		8,10,9,
		8,11,10,

		//back face
		4,6,5,
		4,7,6

	};


	unsigned int VBO, VAO, EBO;
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

	glBindVertexArray(0);

	//Grid grid()

	//Transform trans(Vector3(0, 0, 0),Vector3(0,0,0),Vector3(1,1,1));

	Grid grid(20,
			  "D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/VertexShader.vs",
			  "D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/FragmentShader.fs",
			  Vector3(0,0,0),
			  nullptr
			  );

	/*Sphere sphere(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/VertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/FragmentShader.fs",
		Vector3(0,0,0),
		10,
		20
	);*/

	Sphere sphere(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(-2, 0, 0),
		5,
		30,
		nullptr
	);
	Sphere sphere1(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(6, 0, 0),
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

	//sphere.transform.Rotate(Vector3(1,0,0),90);
	/*Circle circle(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/VertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/FragmentShader.fs",
		Vector3(0, 0, 0),
		10,
		24,
		nullptr
	);*/


	

	Vector3 v=grid.transform.position;
	Camera camera(Vector3(0,0,-50), sphere.transform.position, 500, .005f, 60);
	float angle=0;
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		angle+=.1f/10.0f;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//grid.Render(camera);
		sphere.Render(camera);
		sphere1.Render(camera);
		sphere2.Render(camera);
		//sphere.transform.Rotate(Vector3(0, 1, 0), 0.2f);
		sphere2.transform.Rotate(Vector3(0, 1, 0), 1);
		//sphere1.transform.Translate(Vector3(0,cos(angle)*0.2f, 0));
	//sphere2.transform.Translate(Vector3(0,sin(angle)*0.2f,0));
		//circle.Render(camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	grid.DeleteDrawingData();

	
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