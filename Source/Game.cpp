#include "Game.hpp"
#include <string>

game::game(Screen& p_screen) : m_frog(p_screen), m_map(p_screen), m_gui(p_screen)
{
	AddGoals(p_screen);
	Addtruck(p_screen);
	Addracecar(p_screen);
	Addbus(p_screen);
	Addtractor(p_screen);
	AddSedan(p_screen);
	AddLogs(p_screen);
	m_goalpoints = 0;
	m_gameon = true;
	color = { 255, 255, 255, 255 };
	m_sound = p_screen.LoadSound("Assets/Background.ogg"); //Music: https://www.bensound.com
	m_frogsound = p_screen.LoadSound("Assets/Crash.ogg"); //sound: https://mixkit.co/free-sound-effects/crash/
}

game::~game()
{

}

void game::FrogCarCollision(Screen& p_screen)
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		if (m_frog.GetX() <= m_cars[i].GetBoxX() && m_frog.GetBoxX() >= m_cars[i].GetX() &&
			m_frog.GetY() <= m_cars[i].GetBoxY() && m_frog.GetBoxY() >= m_cars[i].GetY())
		{
			m_frog.Setup(p_screen);
			m_gui.DeleteLives(p_screen);
			p_screen.PlaySound(m_frogsound);
		}
	}
}

void game::FrogLogCollision(Screen& p_screen)
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

void game::FrogWaterCollision(Screen& p_screen)
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

void game::FrogGoalCollision(Screen& p_screen)
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

void game::AddLogs(Screen &p_screen)
{
	for (int i = 0; i < 3; i++)
	{
		m_logs.push_back(logs(p_screen, "Assets/Log150.png", 100, 120, 2));
		int Index = (int)m_logs.size() - 1;
		if (i == 1 || i == 2)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 200);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		m_logs.push_back(logs(p_screen, "Assets/Log250.png", 50, 170, -1));
		int Index = (int)m_logs.size() - 1;
		if (i == 1)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 400);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		m_logs.push_back(logs(p_screen, "Assets/Log150.png", 150, 220, 3));
		int Index = (int)m_logs.size() - 1;
		if (i == 1 || i == 2)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 200);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		m_logs.push_back(logs(p_screen, "Assets/Log100.png", 100, 270, -3));
		int Index = (int)m_logs.size() - 1;
		if (i == 1 || i == 2 || i == 3)
		{
			m_logs[Index].SetX(m_logs[(long long)Index - 1].GetX() + 150);
		}
	}
}

void game::Addtruck(Screen& p_screen)
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

void game::Addracecar(Screen& p_screen)
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

void game::AddGoals(Screen& p_screen)
{
	for (int i = 0; i < 5; i++)
	{
		m_goals.push_back(goal(p_screen, 50, 50, 50, 50));
		int Index = (int)m_goals.size() - 1;
		if (i == 1 || i == 2 || i == 3 || i == 4)
		{
			m_goals[Index].SetGoalX(m_goals[(long long)Index - 1].GetX() + 150);
		}
	}
}

void game::Addbus(Screen& p_screen)
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

void game::Addtractor(Screen& p_screen)
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

void game::AddSedan(Screen& p_screen)
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

void game::DrawCars(Screen& p_screen)
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		m_cars[i].Draw(p_screen);
	}
}

void game::UpdateCars(Screen& p_screen)
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		m_cars[i].Update(p_screen);
	}
}

void game::ProcessInput(Screen& p_screen)
{
	m_frog.Input(p_screen);
}

void game::Update(Screen& p_screen)
{
	if (m_gameon == true)
	{
		p_screen.PlaySound(m_sound);
		m_gui.Update(p_screen);
		m_frog.Update(p_screen);
		UpdateCars(p_screen);
		for (int i = 0; i < m_logs.size(); i++)
		{
			m_logs[i].Update(p_screen);
		}
		FrogCarCollision(p_screen);
		FrogLogCollision(p_screen);
		FrogWaterCollision(p_screen);
		FrogGoalCollision(p_screen);
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

void game::Draw(Screen& p_screen)
{
	if (m_gameon == true)
	{
		m_map.Draw(p_screen);
		for (int i = 0; i < m_goals.size(); i++)
		{
			m_goals[i].Draw(p_screen);
		}
		m_gui.Draw(p_screen);
		DrawCars(p_screen);
		for (int i = 0; i < m_logs.size(); i++)
		{
			m_logs[i].Draw(p_screen);
		}
		for (int i = 0; i < m_goals.size(); i++)
		{
			if (m_goals[i].GetTaken() == true)
			{
				m_goals[i].DrawFrog(p_screen);
			}
		}
		m_frog.Draw(p_screen);
	}
	if (m_gameon == false)
	{
		p_screen.DrawText(p_screen.GetWindowWidth() / 2, p_screen.GetWindowHeight() / 2, color, "Score: " + std::to_string(m_gui.GetScore()));
	}
}
