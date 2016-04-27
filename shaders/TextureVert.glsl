#version 430

layout (location = 0) in vec3 inVert;
layout (location = 1) in vec2 inUv;
layout (location = 2) in vec3 inNormal;

out vec2 vertUV;
out vec3 normal;



void main()
{
  gl_Position = vec4(inVert, 1.0);
  vertUV = inUv;
  normal = inNormal;
}
