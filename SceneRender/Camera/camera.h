#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <vector>
namespace scmales
{
	enum CameraMovement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float SPEED = 2.5f;
	const float SENSITIVITY = 0.1f;
	const float ZOOM = 45.0f;

	class Camera
	{

	public:
		float Zoom; //鼠标放大缩小的尺度

		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
		{
			Position = position;
			WorldUp = up;
			Yaw = yaw;
			Pitch = pitch;
			updateCameraVectors();
		}
		// constructor with scalar values
		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
		{
			Position = glm::vec3(posX, posY, posZ);
			WorldUp = glm::vec3(upX, upY, upZ);
			Yaw = yaw;
			Pitch = pitch;
			updateCameraVectors();
		}

		glm::mat4 getViewMatrix();

		void processKeyboard(CameraMovement direction, float deltaTime);

		void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

		void processMouseScroll(float yoffset);

		glm::vec3 getPos();
		glm::vec3 getFront();

	private:
		glm::vec3 Position; //相机位置
		glm::vec3 Front;	//相机前向量（初始设置好）,在相机坐标系中的位置，所以在世界坐标系中用的是 Position + Front
		glm::vec3 Up;		// 相机上向量
		glm::vec3 Right;	// 相机右向量
		glm::vec3 WorldUp;	//世界坐标上向量（初始设置好），用于计算相机坐标系的右向量

		float Yaw;	 //偏航角
		float Pitch; //俯仰角

		float MovementSpeed;	//键盘移动的速度
		float MouseSensitivity; //鼠标移动的敏感程度

		void updateCameraVectors();
	};

} // namespace scmales
#endif