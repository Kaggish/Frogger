#pragma once
#include <vector>
#include "Frog.hpp"
#include "Map.hpp"
#include "Cars.hpp"
#include "Logs.hpp"
#include "GUI.hpp"
#include "Goals.hpp"
#include "AssetManager.hpp"

class Game
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

	Resource asset;

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
	void ProcessInput();
	void Update();
	void Draw();
};