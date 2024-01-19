#pragma once

class frog
{
protected:
	float m_scale;
	bool m_jumping;
	float m_jumptimer;
	bool m_onlog;
	Sprite m_sprite;
	Sound m_sound;
	virtual void Movement();

public:
	frog();
	void Setup();
	void WorldBlock();
	void Input();
	virtual void Update();
	virtual void Draw();
	float GetBoxX();
	float GetBoxY();
	float GetWidth();
	float GetHeight();
	float GetX();
	float GetY();
	bool GetOnLog();
	bool GetJump();
	void SetJump(bool p_jump);
	void SetSpeed(float p_speed);
	void SetOnLog(bool p_onlog);
};
