#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out mat3 TBN;
out vec2 texCoord;
out vec3 Normal;
out vec3 FragPos;
//mat2 turn90 = mat2(0.0, 1.0,-1.0,0.0);
void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    texCoord = aTexCoord;
    Normal = normalize(mat3(transpose(inverse(model))) * aNormal); //pls do it at processor
    vec3 T = normalize(vec3(model * vec4(aTangent,0.0f))) ;
    vec3 B = normalize(vec3(model * vec4(aBitangent,0.0f)));
    vec3 N = normalize(vec3(model * vec4(Normal,0.0f))) ;
    TBN = transpose(mat3(T,B,N));
    FragPos = vec3(model * vec4(aPos, 1.0f));
}

