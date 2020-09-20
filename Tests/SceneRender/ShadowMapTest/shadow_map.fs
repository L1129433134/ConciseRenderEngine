#version 330 core
out vec4 FragColor;
in VS_OUT{
    vec3 FragPos; //顶点的世界坐标
    vec3 Normal;  //顶点的世界法线
    vec2 TexCoords; //顶点对应的纹理坐标
    vec4 FragPosLightSpace; //顶点在光照坐标系下的坐标
}fs_in;
uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;

uniform vec3 lightPos;
uniform vec3 viewPos;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    //透视除法
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    //变换到0-1范围
    projCoords = projCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;
    float shadow = currentDepth > closestDepth ? 1.0:0.0;
    return shadow;

}
void main()
{
    vec3 color = texture(diffuseTexture, fs_in.TexCoords).rgb;
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightColor = vec3(0.3);
    //ambient
    vec3 ambient = 0.3 * color;
    //diffuse
    vec3 lightDir = normalize(viewPos - fs_in.FragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
    //specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);
    spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    vec3 specular = spec * lightColor;
    float shadow = ShadowCalculation(fs_in.FragPosLightSpace);

    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * color;
    FragColor = vec4(lighting, 1.0);
}