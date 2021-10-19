#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
out vec3 normalBaseOne;
out vec3 normalBaseTwo;
//mat2 turn90 = mat2(0.0, 1.0,-1.0,0.0);
void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    TexCoord = aTexCoord;
    Normal = normalize(mat3(transpose(inverse(model))) * aNormal); //pls do it at processor
    normalBaseOne = vec3(-Normal.y, Normal.x,0.0);
    normalBaseTwo = cross(Normal, normalBaseOne);
    FragPos = vec3(model * vec4(aPos, 1.0f));
}
