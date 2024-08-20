#include "Game.hpp"

Game::Game()
{
	AddGoals();
	AddLogs();
	AddCars();
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

void Game::AddCars()
{
	for (int i = 0; i < 3; i++)
	{
		int ID = 0;
		Vector2 Pos = { 0.0f + (200.0f * i), 450.0f };
		float SPEED = 4.0f;
		Cars.emplace_back(Pos, SPEED, ID);
	}

	for (int i = 0; i < 3; i++)
	{
		int ID = 1;
		Vector2 Pos = { 0.0f + (200.0f * i), 500.0f };
		float SPEED = -1.0f;
		Cars.emplace_back(Pos, SPEED, ID);
	}

	for (int i = 0; i < 2; i++)
	{
		int ID = 2;
		Vector2 Pos = { 0.0f + (200.0f * i), 550.0f };
		float SPEED = 5.0f;
		Cars.emplace_back(Pos, SPEED, ID);
	}

	for (int i = 0; i < 3; i++)
	{
		int ID = 3;
		Vector2 Pos = { 0.0f + (200.0f * i), 600.0f };
		float SPEED = -3.0f;
		Cars.emplace_back(Pos, SPEED, ID);
	}

	for (int i = 0; i < 4; i++)
	{
		int ID = 4;
		Vector2 Pos = { 0.0f + (200.0f * i), 650.0f };
		float SPEED = 2.0f;
		Cars.emplace_back(Pos, SPEED, ID);
	}
}

void Game::AddLogs()
{
	for (int i = 0; i < 3; i++)
	{
		Vector2 Pos = { 0.0f + (200.0f * i), 150.0f };
		float SPEED = 4.0f;
		Logs.emplace_back(Pos, SPEED);
	}

	for (int i = 0; i < 3; i++)
	{
		Vector2 Pos = { 0.0f + (200.0f * i), 200.0f };
		float SPEED = -1.0f;
		Logs.emplace_back(Pos, SPEED);
	}

	for (int i = 0; i < 2; i++)
	{
		Vector2 Pos = { 0.0f + (200.0f * i), 250.0f };
		float SPEED = 5.0f;
		Logs.emplace_back(Pos, SPEED);
	}

	for (int i = 0; i < 3; i++)
	{
		Vector2 Pos = { 0.0f + (200.0f * i), 300.0f };
		float SPEED = -3.0f;
		Logs.emplace_back(Pos, SPEED);
	}

	for (int i = 0; i < 4; i++)
	{
		Vector2 Pos = { 0.0f + (200.0f * i), 350.0f };
		float SPEED = 2.0f;
		Logs.emplace_back(Pos, SPEED);
	}
}

void Game::AddGoals()
{
	for (int i = 0; i < 5; ++i)
	{
		Vector2 Pos = { 50.0f + (50.0f * 3.0f * i), 50.0f };
		Goals.emplace_back(Pos);
	}
}

void Game::ProcessInput()
{
	Frog.Input();
}

void Game::Update()
{
	Frog.Update();

	for (int i = 0; i < Logs.size(); i++)
	{
		Logs[i].Update(asset.LogTextures[0].m_texture);
	}

	for (int i = 0; i < Cars.size(); i++)
	{
		Cars[i].Update();
	}
}

void Game::Draw()
{
	Map.Draw(asset.WaterTexture.m_texture, asset.GrassTexture.m_texture, asset.RoadTexture.m_texture, asset.SafeZoneTexture.m_texture);
	Frog.Draw(asset.FrogTexture.m_texture);
	
	for (int i = 0; i < Logs.size(); i++)
	{
		Logs[i].Draw(asset.LogTextures[0].m_texture);
	}
	
	for (int i = 0; i < Cars.size(); i++)
	{
		switch (Cars[i].ID)
		{
			case 0:
				Cars[i].Draw(asset.CarTextures[Cars[i].ID].m_texture);
			break;
			case 1:
				Cars[i].Draw(asset.CarTextures[Cars[i].ID].m_texture);
				break;
			case 2:
				Cars[i].Draw(asset.CarTextures[Cars[i].ID].m_texture);
				break;
			case 3:
				Cars[i].Draw(asset.CarTextures[Cars[i].ID].m_texture);
				break;
			case 4:
				Cars[i].Draw(asset.CarTextures[Cars[i].ID].m_texture);
				break;
		}
	}
}
