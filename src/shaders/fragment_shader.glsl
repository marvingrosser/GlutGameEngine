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
in vec2 texCoord;
in vec3 Normal;
in vec3 FragPos;
in mat3 TBN;
uniform PointLight light;
uniform vec3 camPos;
uniform sampler2D diffusemap;
uniform sampler2D specularmap;
uniform sampler2D normalmap; //normalmapping include
uniform sampler2D heightmap;

float heightscale = 0.1f;

vec2 heightmapping(vec2 texcoord, vec3 viewdir);
void main()
{

    //vec3 norm = normalize(Normal);
    vec3 viewDir = TBN * normalize( camPos - FragPos);
    vec2 TexCoord = heightmapping(texCoord,viewDir);
    //if(texCoord.x > 1.0 || texCoord.y > 1.0 || texCoord.x < 0.0 || texCoord.y < 0.0 ) discard;
    //vec2 TexCoord = texCoord;
    vec3 normalMapRGB = texture(normalmap,TexCoord).rgb * 2.0f - 1.0f;
    vec3 norm = normalMapRGB ;
    vec3 lightVec = light.position - FragPos;
    float lightDistance = length(lightVec);
    float attenuation = 1.0 / (light.c + light.l * lightDistance + light.q * (lightDistance * lightDistance));
    vec3 lightDir = TBN*normalize(lightVec);
    
    
    
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = attenuation* spec * light.specular * vec3(texture(specularmap,TexCoord));
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = attenuation * diff * light.diffuse;
    FragColor = vec4(diffuse + attenuation* light.ambient * 0.5f + specular, 1.0f) * texture(diffusemap, TexCoord);
}

vec2 heightmapping(vec2 texcoord, vec3 viewdir){
    //viewdir = TBN * viewdir;
    const float minLayers = 4.0;
    const float maxLayers = 16.0;
    float layerNum = mix(maxLayers, minLayers, max(dot(vec3(0.0, 0.0, -1.0), viewdir), 0.0));

    float layerDepth = 1.0 / layerNum;
    float currentDepth = 0.0;
    vec2 p = viewdir.xy * heightscale;
    vec2 deltaTexCoord = p / layerNum;

    vec2 currentTexCoord = texcoord;
    float currentDepthMapValue = 1.0f - texture(heightmap, currentTexCoord).r;
    while(currentDepth < currentDepthMapValue){
        currentTexCoord -= deltaTexCoord;
        currentDepthMapValue = 1.0f - texture(heightmap, currentTexCoord).r;
        currentDepth += layerDepth;
    }

    vec2 texcoordPrev = currentTexCoord + deltaTexCoord;

    float afterDepth = currentDepthMapValue - currentDepth;
    float beforeDepth = texture(heightmap, texcoordPrev).r - currentDepth + layerDepth;

    float weight = afterDepth / (afterDepth - beforeDepth);
    vec2 finalTexCoord = texcoordPrev * weight + currentTexCoord * (1.0 - weight);

    return finalTexCoord;

}
