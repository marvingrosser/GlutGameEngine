#version 460 core
out vec4 FragColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
uniform sampler2D DiffTexture;
void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(3.0f,4.0f,8.0f) - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(1.0f,1.0f,1.0f);
    FragColor = vec4(diffuse + vec3(0.1f, 0.1f, 0.1f), 1.0f) * texture(DiffTexture, TexCoord);
}
