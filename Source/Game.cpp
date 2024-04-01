#include "Game.hpp"
#include <string>

game::game()
{
	AddGoals();
	Addtruck();
	Addracecar();
	Addbus();
	AddSedan();
	AddLogs();
	m_goalpoints = 0;
	m_gameon = true;
	color = { 255, 255, 255, 255 };
	m_sound = p_screen.LoadSound("Assets/Background.ogg"); //Music: https://www.bensound.com
	m_frogsound = p_screen.LoadSound("Assets/Crash.ogg"); //sound: https://mixkit.co/free-sound-effects/crash/
}

game::~game()
{

}

void game::FrogCarCollision()
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		if (m_frog.GetX() <= m_cars[i].GetBoxX() && m_frog.GetBoxX() >= m_cars[i].GetX() &&
			m_frog.GetY() <= m_cars[i].GetBoxY() && m_frog.GetBoxY() >= m_cars[i].GetY())
		{
			m_frog.Setup();
			m_gui.DeleteLives();
			p_screen.PlaySound(m_frogsound);
		}
	}
}

void game::FrogLogCollision()
{
	m_Onlog = false;
	for (int i = 0; i < m_logs.size(); i++)
	{
		if (m_frog.GetX() <= m_logs[i].GetBoxX() && m_frog.GetBoxX() >= m_logs[i].GetX() &&
			m_frog.GetY() <= m_logs[i].GetBoxY() && m_frog.GetBoxY() >= m_logs[i].GetY())
		{
			m_Onlog = true;
			if (m_frog.GetJump() == false && m_Onlog == true)
			{
				m_frog.SetSpeed(m_logs[i].GetSpeed());
			}
		}
	}
}

void game::FrogWaterCollision()
{
	for (int i = 0; i < m_logs.size(); i++)
	{
		if (m_frog.GetX() <= m_map.GetBoxX() && m_frog.GetBoxX() >= m_map.GetWaterX() &&
			m_frog.GetY() <= m_map.GetBoxY() && m_frog.GetBoxY() >= m_map.GetWaterY())
		{
			if (m_Onlog == false && m_frog.GetJump() == false)
			{
				m_frog.Setup(p_screen);
				m_gui.DeleteLives(p_screen);
			}
		}
	}
}

void game::FrogGoalCollision()
{
	for (int i = 0; i < m_goals.size(); i++)
	{
		if (m_frog.GetX() <= m_goals[i].GetBoxX() && m_frog.GetBoxX() >= m_goals[i].GetX() &&
			m_frog.GetY() <= m_goals[i].GetBoxY() && m_frog.GetBoxY() >= m_goals[i].GetY())
		{
			m_gui.AddScore();
			m_frog.Setup(p_screen);
			m_goals[i].SetTaken(true);
			m_goalpoints++;
		}
	}
}

void game::AddLogs()
{
	for (int i = 0; i < 3; i++)
	{
		m_logs.push_back(Logs(p_screen, "Assets/Log150.png", 100, 120, 2));
		int Index = (int)m_logs.size() - 1;
		if (i == 1 || i == 2)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 200);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		m_logs.push_back(Logs(p_screen, "Assets/Log250.png", 50, 170, -1));
		int Index = (int)m_logs.size() - 1;
		if (i == 1)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 400);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		m_logs.push_back(Logs(p_screen, "Assets/Log150.png", 150, 220, 3));
		int Index = (int)m_logs.size() - 1;
		if (i == 1 || i == 2)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 200);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		m_logs.push_back(Logs(p_screen, "Assets/Log100.png", 100, 270, -3));
		int Index = (int)m_logs.size() - 1;
		if (i == 1 || i == 2 || i == 3)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 150);
		}
	}
}

void game::Addtruck()
{
	for (int i = 0; i < 3; i++)
	{
		m_cars.push_back(Cars(p_screen,"Assets/Truck.png", 150, (float)p_screen.GetWindowHeight() / 2 + 75, -3));
		int Index = (int)m_cars.size() - 1;
		if (i == 1 || i == 2)
		{
			m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);
		}
	}
}

void game::Addracecar()
{
	for (int i = 0; i < 2; i++)
	{
		m_cars.push_back(Cars(p_screen, "Assets/Racecar.png", 250, (float)p_screen.GetWindowHeight() / 2 + 125, 4));
		int Index = (int)m_cars.size() - 1;
		if (i == 1)
		{
			m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);
		}
	}
}

void game::AddGoals()
{
	for (int i = 0; i < 5; i++)
	{
		m_goals.push_back(Goal(p_screen, 50, 50, 50, 50));
		int Index = (int)m_goals.size() - 1;
		if (i == 1 || i == 2 || i == 3 || i == 4)
		{
			m_goals[Index].SetGoalX(m_goals[(long long)Index - 1].GetX() + 150);
		}
	}
}

void game::Addbus()
{
	for (int i = 0; i < 3;i++)
	{
		m_cars.push_back(Cars(p_screen,"Assets/Bus.png", 200, (float)p_screen.GetWindowHeight() / 2 + 175, -3));
		int Index = (int)m_cars.size() - 1;
		if (i == 1 || i == 2)
		{
			m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);
		}
	}
}

void game::Addtractor()
{
	for (int i = 0; i < 3; i++)
	{
		m_cars.push_back(Cars(p_screen,"Assets/Tractor.png", 150, (float)p_screen.GetWindowHeight() / 2 + 225, 2));
		int Index = (int)m_cars.size() - 1;
		if (i == 1 || i == 2 || i == 3)
		{
			m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);
		}
	}
}

void game::AddSedan()
{
	for (int i = 0; i < 3; i++)
	{
		m_cars.push_back(Cars(p_screen,"Assets/Sedan.png", 300, (float)p_screen.GetWindowHeight() / 2 + 275, -3));
		int Index = (int)m_cars.size() - 1;
		if (i == 1 || i == 2)
		{
			m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);
		}
	}
}

void game::DrawCars()
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		m_cars[i].Draw();
	}
}

void game::UpdateCars()
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		m_cars[i].Update();
	}
}

void game::ProcessInput()
{
	m_frog.Input();
}

void game::Update()
{
	if (m_gameon == true)
	{
		p_screen.PlaySound(m_sound);
		m_gui.Update();
		m_frog.Update();
		UpdateCars();
		for (int i = 0; i < m_logs.size(); i++)
		{
			m_logs[i].Update();
		}
		FrogCarCollision();
		FrogLogCollision();
		FrogWaterCollision();
		FrogGoalCollision();
		for (int i = 0; i < m_goals.size(); i++)
		{
			if (m_goalpoints == 5)
			{
				m_goals[i].SetTaken(false);
			}
		}
		if (m_gui.GetLives() == 0)
		{
			m_gameon = false;
		}
	}
}

void game::Draw()
{
	if (m_gameon == true)
	{
		m_map.Draw();
		for (int i = 0; i < m_goals.size(); i++)
		{
			m_goals[i].Draw();
		}
		m_gui.Draw();
		DrawCars();
		for (int i = 0; i < m_logs.size(); i++)
		{
			m_logs[i].Draw();
		}
		for (int i = 0; i < m_goals.size(); i++)
		{
			if (m_goals[i].GetTaken() == true)
			{
				m_goals[i].DrawFrog();
			}
		}
		m_frog.Draw();
	}
	if (m_gameon == false)
	{
		p_screen.DrawText(p_screen.GetWindowWidth() / 2, p_screen.GetWindowHeight() / 2, color, "Score: " + std::to_string(m_gui.GetScore()));
	}
}
