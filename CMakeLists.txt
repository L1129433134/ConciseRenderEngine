cmake_minimum_required(VERSION 3.16)
project(ConciseRenderEngine)

# 附加包含目录
include_directories(ConciseRenderEngine/Model)
include_directories(ConciseRenderEngine/Mathematics)
include_directories(ConciseRenderEngine/Utils)

include_directories(SceneRender/Camera)
include_directories(SceneRender/Shader)
include_directories(SceneRender/Model)
include_directories(SceneRender/ThirdParty/include)

# 编译入口
add_subdirectory (Tests/SceneRender/assimpTest)
add_subdirectory (Tests/SceneRender/BlendTest)
add_subdirectory (Tests/SceneRender/CameraShaderTest)
add_subdirectory (Tests/SceneRender/LightingMapTest)
add_subdirectory (Tests/SceneRender/MultiLightTest)
add_subdirectory (Tests/SceneRender/FrameTest)
add_subdirectory (Tests/SceneRender/DeferredRenderTest)
add_subdirectory (Tests/SceneRender/ShadowMapTest)
add_subdirectory (Tests/SceneRender/CubeMapTest)
add_subdirectory (Tests/ConciseRenderEngine/Mathematics)


# 链接器附加库目录
find_library(GLFW_LIB libglfw3dll.a HINTS SceneRender/ThirdParty/lib)
find_library(GLAD_LIB libglad.a HINTS SceneRender/ThirdParty/lib)
find_library(ASSIMP_LIB libassimp.dll.a HINTS SceneRender/ThirdParty/lib)


set(CMAKE_CXX_STANDARD 14)

