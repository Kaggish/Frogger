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
	
	int goalPoints;
	bool gameOn;
	
	Color color;

	std::vector<Cars> Cars;
	std::vector<Logs> Logs;
	std::vector<Goal> Goals;

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