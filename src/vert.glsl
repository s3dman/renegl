#version 410 core

layout (location = 0) in vec3 aPos;
uniform float iTime;

void main(){
	gl_Position = vec4(cos(iTime)*aPos.x, aPos.y, aPos.z, 1.0);
}
