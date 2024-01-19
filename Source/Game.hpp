#pragma once
#include <vector>
#include "Frog.h"
#include "Map.h"
#include "Cars.h"
#include "Logs.h"
#include "GUI.h"
#include "Goals.h"

class game
{
private:
	frog m_frog;
	map m_map;
	gui m_gui;
	bool m_Onlog;
	int m_goalpoints;
	bool m_gameon;
	Color color;
	Sound m_sound;
	Sound m_frogsound;

	std::vector<cars> m_cars;
	std::vector<logs> m_logs;
	std::vector<goal> m_goals;

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