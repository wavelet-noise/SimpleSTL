#version 330
 
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec4 inColor;
 
smooth out vec4 theColor;
 
uniform mat4 MVP; 
 
void main()
{
	gl_Position = MVP * vec4(inPosition, 1.0);
	theColor = inColor;
}