#version 330 core
out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
    FragColor = vec4(1.0f, 0f, 0.2f, 1.0f);
	//FragColor=vec4(lightColor*objectColor,1.0);
} 