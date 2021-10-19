#version 460 core
struct PointLight{
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    vec3 position;
    float c;
    float l;
    float q;
};
out vec4 FragColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
in vec3 normalBaseOne;
in vec3 normalBaseTwo;
uniform PointLight light;
uniform vec3 camPos;
uniform sampler2D diffusemap;
uniform sampler2D specularmap;
uniform sampler2D normalmap; //normalmapping include
void main()
{
    mat3 base = mat3(-normalBaseTwo,-normalBaseOne,Normal);
    //vec3 norm = normalize(Normal);
    vec3 normalMapRGB = texture(normalmap,TexCoord).rgb * 2.0f - 1.0f;
    vec3 norm = base*normalMapRGB*2.0f;
    vec3 lightVec = light.position - FragPos;
    float lightDistance = length(lightVec);
    float attenuation = 1.0 / (light.c + light.l * lightDistance + light.q * (lightDistance * lightDistance));
    vec3 lightDir = normalize(lightVec);
    
    vec3 viewDir = normalize(camPos - FragPos);
    
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = attenuation* spec * light.specular * vec3(texture(specularmap,TexCoord));
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = attenuation * diff * light.diffuse;
    FragColor = vec4(diffuse + attenuation* light.ambient + specular, 1.0f) * texture(diffusemap, TexCoord);
}
