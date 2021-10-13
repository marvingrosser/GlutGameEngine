#version 460 core
out vec4 FragColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
uniform vec3 camPos;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform sampler2D DiffTexture;
float spec_strength = 1.0f;
vec3 ambient = vec3(0.1f, 0.1f, 0.1f);
void main()
{
    
    vec3 norm = normalize(Normal);
    
    vec3 lightDir = normalize(lightPos - FragPos);
    
    vec3 viewDir = normalize(camPos - FragPos);
    
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = spec_strength * spec * lightColor;
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    FragColor = vec4(diffuse + ambient + specular, 1.0f) * texture(DiffTexture, TexCoord);
}
