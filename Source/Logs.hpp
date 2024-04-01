#pragma once
#include "GameObject.h"
#include <string>

class Logs
{
	Sprite m_sprite;
	bool isonlog;
	virtual void Movement();
public:
	Logs(std::string path, float p_logX, float p_logY, float p_logSpeed);
	void Wrapping();
	virtual void Update();
	virtual void Draw();
	float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	float GetWidth();
	float GetHeight();
	float GetSpeed();
	bool GetOnLog();
	void SetX(float p_logPosX);
	void SetOnlog(bool p_onlog);
};
