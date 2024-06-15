#include "Game.hpp"

Game::Game()
{
	AddGoals();
}

Game::~Game()
{
	Goals.clear();
	Logs.clear();
	Cars.clear();
}

void Game::FrogCarCollision()
{
	//for (int i = 0; i < Cars.size(); i++)
	//{
	//	/*if (m_frog.GetX() <= m_cars[i].GetBoxX() && m_frog.GetBoxX() >= m_cars[i].GetX() &&
	//		m_frog.GetY() <= m_cars[i].GetBoxY() && m_frog.GetBoxY() >= m_cars[i].GetY())
	//	{
	//		m_frog.Setup();
	//		m_gui.DeleteLives();
	//		p_screen.PlaySound(m_frogsound);
	//	}*/
	//}
}

void Game::FrogLogCollision()
{
	//for (int i = 0; i < Logs.size(); i++)
	//{
	//	/*if (m_frog.GetX() <= m_logs[i].GetBoxX() && m_frog.GetBoxX() >= m_logs[i].GetX() &&
	//		m_frog.GetY() <= m_logs[i].GetBoxY() && m_frog.GetBoxY() >= m_logs[i].GetY())
	//	{
	//		m_Onlog = true;
	//		if (m_frog.GetJump() == false && m_Onlog == true)
	//		{
	//			m_frog.SetSpeed(m_logs[i].GetSpeed());
	//		}
	//	}*/
	//}
}

void Game::FrogWaterCollision()
{
	//for (int i = 0; i < Logs.size(); i++)
	//{
	//	/*if (m_frog.GetX() <= m_map.GetBoxX() && m_frog.GetBoxX() >= m_map.GetWaterX() &&
	//		m_frog.GetY() <= m_map.GetBoxY() && m_frog.GetBoxY() >= m_map.GetWaterY())
	//	{
	//		if (m_Onlog == false && m_frog.GetJump() == false)
	//		{
	//			m_frog.Setup(p_screen);
	//			m_gui.DeleteLives(p_screen);
	//		}
	//	}*/
	//}
}

void Game::FrogGoalCollision()
{
	//for (int i = 0; i < Goals.size(); i++)
	//{
	//	/*if (m_frog.GetX() <= m_goals[i].GetBoxX() && m_frog.GetBoxX() >= m_goals[i].GetX() &&
	//		m_frog.GetY() <= m_goals[i].GetBoxY() && m_frog.GetBoxY() >= m_goals[i].GetY())
	//	{
	//		m_gui.AddScore();
	//		m_frog.Setup(p_screen);
	//		m_goals[i].SetTaken(true);
	//		m_goalpoints++;
	//	}*/
	//}
}

void Game::AddLogs()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	/*m_logs.push_back(Logs(p_screen, "Assets/Log150.png", 100, 120, 2));*/
	//	/*int Index = (int)Logs.size() - 1;*/
	//	if (i == 1 || i == 2)
	//	{
	//		Logs[i].SetX(Logs[(long long)i - 1].GetX() + 200);
	//	}
	//}
	//for (int i = 0; i < 2; i++)
	//{
	//	/*m_logs.push_back(Logs(p_screen, "Assets/Log250.png", 50, 170, -1));*/
	//	/*int Index = (int)Logs.size() - 1;*/
	//	if (i == 1)
	//	{
	//		Logs[i].SetX(Logs[(long long)i - 1].GetX() + 400);
	//	}
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	/*m_logs.push_back(Logs(p_screen, "Assets/Log150.png", 150, 220, 3));*/
	//	/*int Index = (int)Logs.size() - 1;*/
	//	if (i == 1 || i == 2)
	//	{
	//		Logs[i].SetX(Logs[(long long)i - 1].GetX() + 200);
	//	}
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	/*m_logs.push_back(Logs(p_screen, "Assets/Log100.png", 100, 270, -3));*/
	//	/*int Index = (int)Logs.size() - 1;*/
	//	if (i == 1 || i == 2 || i == 3)
	//	{
	//		Logs[i].SetX(Logs[(long long)i - 1].GetX() + 150);
	//	}
	//}
}

void Game::Addtruck()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	/*m_cars.push_back(Cars(p_screen,"Assets/Truck.png", 150, (float)p_screen.GetWindowHeight() / 2 + 75, -3));*/
	//	/*int Index = (int)Cars.size() - 1;*/
	//	if (i == 1 || i == 2)
	//	{
	//		/*Cars[Index].SetX(Cars[(long long)Index - 1].GetX() + 250);*/
	//	}
	//}
}

void Game::Addracecar()
{
	//for (int i = 0; i < 2; i++)
	//{
	//	/*m_cars.push_back(Cars(p_screen, "Assets/Racecar.png", 250, (float)p_screen.GetWindowHeight() / 2 + 125, 4));*/
	//	/*int Index = (int)Cars.size() - 1;*/
	//	if (i == 1)
	//	{
	//		/*m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);*/
	//	}
	//}
}

void Game::AddGoals()
{
	for (int i = 0; i < 5; ++i)
	{
		//TODO; Make this into a for loop, I want to use emplace_back and add a position in it, does not seem to work, have done it in another project, but does net seem to work here
		Goals.emplace_back();

		switch (i)
		{
			case 0:
				Goals[i].SetPos({ 20.0f, 20.0f });
				break;

			case 1:
				Goals[i].SetPos({ 80.0f, 20.0f });
				break;

			case 2:
				Goals[i].SetPos({ 140.0f, 20.0f });
				break;

			case 3:
				Goals[i].SetPos({ 200.0f, 20.0f });
				break;

			case 4:
				Goals[i].SetPos({ 260.0f, 20.0f });
				break;
		}
	}
}

void Game::Addbus()
{
	//for (int i = 0; i < 3;i++)
	//{
	//	/*m_cars.push_back(Cars(p_screen,"Assets/Bus.png", 200, (float)p_screen.GetWindowHeight() / 2 + 175, -3));*/
	//	/*int Index = (int)Cars.size() - 1;*/
	//	if (i == 1 || i == 2)
	//	{
	//		/*m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);*/
	//	}
	//}
}

void Game::Addtractor()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	/*m_cars.push_back(Cars(p_screen,"Assets/Tractor.png", 150, (float)p_screen.GetWindowHeight() / 2 + 225, 2));*/
	//	/*int Index = (int)Cars.size() - 1;*/
	//	if (i == 1 || i == 2 || i == 3)
	//	{
	//		/*m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);*/
	//	}
	//}
}

void Game::AddSedan()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	/*m_cars.push_back(Cars(p_screen,"Assets/Sedan.png", 300, (float)p_screen.GetWindowHeight() / 2 + 275, -3));*/
	//	/*int Index = (int)Cars.size() - 1;*/
	//	if (i == 1 || i == 2)
	//	{
	//		/*m_cars[Index].SetX(m_cars[(long long)Index - 1].GetX() + 250);*/
	//	}
	//}
}

void Game::DrawCars()
{
	//for (int i = 0; i < Cars.size(); i++)
	//{
	//	/*Cars[i].Draw();*/
	//}
}

void Game::UpdateCars()
{
	/*for (int i = 0; i < Cars.size(); i++)
	{
		Cars[i].Update();
	}*/
}

void Game::ProcessInput()
{
	Frog.Input();
}

void Game::Update()
{
	Frog.Update();
}

void Game::Draw()
{
	Map.Draw(asset.WaterTexture.m_texture, asset.GrassTexture.m_texture, asset.RoadTexture.m_texture, asset.SafeZoneTexture.m_texture);
	Frog.Draw(asset.FrogTexture.m_texture);
	
	for (int i = 0; i < Goals.size(); ++i)
	{
		DrawRectangle(static_cast<int>(Goals[i].HitBox().x), static_cast<int>(Goals[i].HitBox().y), static_cast<int>(Goals[i].HitBox().width), static_cast<int>(Goals[i].HitBox().height), RED);
	}
}
