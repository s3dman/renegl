#version 410 core

out vec4 FragColor;
uniform float iTime;

void main(){

	FragColor = vec4(sin(iTime), sin(iTime*2/3), sin(iTime/3), 1.0f);
}
