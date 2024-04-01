#pragma once
#include <vector>
#include "Frog.hpp"
#include "Map.hpp"
#include "Cars.hpp"
#include "Logs.hpp"
#include "GUI.hpp"
#include "Goals.hpp"

class game
{
private:
	Frog m_frog;
	Map m_map;
	GUI m_gui;
	bool m_Onlog;
	int m_goalpoints;
	bool m_gameon;
	Color color;
	Sound m_sound;
	Sound m_frogsound;

	std::vector<Cars> m_cars;
	std::vector<Logs> m_logs;
	std::vector<Goal> m_goals;

	void AddGoals();
	void AddLogs();
	void Addtruck();
	void Addracecar();
	void Addtractor();
	void Addbus();
	void AddSedan();
	void FrogCarCollision();
	void FrogLogCollision();
	void FrogWaterCollision();
	void FrogGoalCollision();
	void DrawCars();
	void UpdateCars();
public:
	game();
	void ProcessInput();
	void Update();
	void Draw();
};