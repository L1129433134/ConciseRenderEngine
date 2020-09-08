#### GLFW编译
下载glfw源码，cd到目录下<br>
创建build目录保存cmake结果，使用cmake选择GCC makefile编译，configure、generate <br>
切换到build目录，mingw32-make <br>
得到需要的glfw3.dll、libglfw3dll.a文件
glfw3.dll需要放到可执行文件目录, libglfw3dll.a在cmake时链接


#### GLAD编译
在线平台编译选择OpenGL3.3 <br>
cd到目录下,把glad编译成一个静态库
```
gcc .\src\glad.c -c -I.\include\
ar -rc libglad.a glad.o
```
得到需要的libglad.a文件,在cmake时链接

#### ASSIMP编译
使用assimp4.1.0版本（最新的5.0.0版本读取mtl会出错）
新建build目录用于安装，使用cmke(UI)工具选择GCC makefile编译，configure、generate，注意configure完选择安装路径
切换到build目录下，mingw32-make，注意要安放一下revision.h的位置，源码的问题
mingw32-make install
得到需要的libassimp.dll.a和libassimp.dll