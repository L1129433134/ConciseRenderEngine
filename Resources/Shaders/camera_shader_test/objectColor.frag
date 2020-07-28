#version 330 core
out vec4 FragColor;
in vec3 Normal;
in vec3 FragPos;

struct Material{ //定义模型的材质
    vec3 ambient; 
    vec3 diffuse;  
    vec3 specular;
    float shininess; //反光度影响镜面高光的半径
};

struct Light{     //定义光照属性，因为每种光对物体的颜色显示有不同作用
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform Material material;
uniform Light light;

uniform vec3 viewPos;
//uniform vec3 objectColor;


void main()
{
    //环境光
    vec3 ambient = material.ambient * light.ambient;

    //漫反射
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    //高光
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);  

    //vec3 result = (ambient + diffuse + specular) * objectColor;
    vec3 result = ambient + diffuse + specular;
    
    FragColor = vec4(result, 1.0);
}