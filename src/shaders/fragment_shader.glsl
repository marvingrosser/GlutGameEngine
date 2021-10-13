#version 460 core
out vec4 FragColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
uniform vec3 camPos;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform sampler2D DiffTexture;
void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    FragColor = vec4(diffuse + vec3(0.1f, 0.1f, 0.1f), 1.0f) * texture(DiffTexture, TexCoord);
}
