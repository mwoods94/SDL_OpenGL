//#version 430
#version 330 core

layout (location = 0) out vec4 outColor;
in vec2 uv;

//in vec2 vertUV;
//in vec3 normal;

//out vec4 outColour;

uniform sampler2D tex;

void main()
{
   outColor = texture(tex, uv);
  //outColour = vec4(1.0, 1.0, 1.0, 1.0); //white
}
