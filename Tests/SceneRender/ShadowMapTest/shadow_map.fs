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

uniform bool shadows;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    //透视除法
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    //变换到0-1范围
    projCoords = projCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    //计算偏移值
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);

    //PCF,简单从纹理像素四周对深度贴图采样，然后把结果平均起来
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;
        }
    }
    shadow /= 9.0;

    //超出视锥体的深度都设为没有阴影
    if(currentDepth > 1.0)
        shadow = 0.0;
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