#include "Frog.hpp"

frog::frog()
{
	m_jumping = false;
	m_onlog = false;
	m_jumptimer = 0;
	m_width = 25;
	m_height = 25;
	m_scale = 50;
	m_speed = { 0, 0 };
	m_sprite = p_screen.LoadSprite("Assets/Frog.png");
	m_sprite.position.x = (float)p_screen.GetWindowWidth() / 2;
	m_sprite.position.y = (float)p_screen.GetWindowHeight() - 25;
	m_sprite.origin = { 12.5, 12.5 };
}

void frog::WorldBlock(Screen &p_screen)
{
	if (m_sprite.position.x - 25 <= 0)
	{
		m_sprite.position.x = 25;
	}
	if (m_sprite.position.x + 25 >= p_screen.GetWindowWidth())
	{
		m_sprite.position.x = (float)p_screen.GetWindowWidth() - 25;
	}
	if (m_sprite.position.y - 25 <= 50)
	{
		m_sprite.position.y = 75;
	}
	if (m_sprite.position.y + 25 >= p_screen.GetWindowHeight())
	{
		m_sprite.position.y = (float)p_screen.GetWindowHeight() - 25;
	}
}

void frog::Input(Screen& p_screen)
{
	if (p_screen.IsKeyDown(Key::W) && m_jumping == false)
	{
		m_speed = { 0, -7 };
		m_jumping = true;
		m_sprite.angle = 0;
	}
	if (p_screen.IsKeyDown(Key::A) && m_jumping == false)
	{
		m_speed = { -7, 0 };
		m_jumping = true;
		m_sprite.angle = 270;
	}
	if (p_screen.IsKeyDown(Key::S) && m_jumping == false)
	{
		m_speed = { 0, 7 };
		m_jumping = true;
		m_sprite.angle = 180;
	}
	if (p_screen.IsKeyDown(Key::D) && m_jumping == false)
	{
		m_speed = { 7, 0 };
		m_jumping = true;
		m_sprite.angle = 90;
	}
}

void frog::Movement()
{
	m_sprite.position.x += (m_speed.x);
	m_sprite.position.y += (m_speed.y);
}

void frog::Update(Screen& p_screen)
{
	if (m_jumping == true)
	{
		m_jumptimer++;
	}
	if (m_jumptimer == 8)
	{
		SetJump(false);
		m_speed = { 0, 0 };
		m_jumptimer = 0;
	}
	Movement();
	WorldBlock(p_screen);
}

void frog::Draw(Screen& p_screen)
{
	p_screen.DrawSprite(m_sprite);
}

float frog::GetBoxX()
{
	return m_sprite.position.x + GetWidth();
}

float frog::GetBoxY()
{
	return m_sprite.position.y + GetHeight();
}

float frog::GetWidth()
{
	return (float)m_sprite.texture.width;
}

float frog::GetHeight()
{
	return (float)m_sprite.texture.height;
}

float frog::GetX()
{
	return m_sprite.position.x;
}

float frog::GetY()
{
	return m_sprite.position.y;
}

bool frog::GetOnLog()
{
	return m_onlog;
}

bool frog::GetJump()
{
	return m_jumping;
}

void frog::SetJump(bool p_jump)
{
	m_jumping = p_jump;
}

void frog::SetSpeed(float p_speed)
{
	m_speed.x = p_speed;
}

void frog::SetOnLog(bool p_onlog)
{
	m_onlog = p_onlog;
}
