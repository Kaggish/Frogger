#pragma once
#include <vector>
#include "raylib.h"
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
	Frog Frog;
	Map Map;
	GUI GUI;
	
	bool gameOn = false;

	std::vector<Cars> Cars;
	std::vector<Logs> Logs;
	std::vector<Goal> Goals;

	Resource asset;

	void AddGoals();

	void AddCars();
	void AddLogs();
	
	void FrogCarCollision();
	void FrogLogCollision();
	void FrogWaterCollision();
	void FrogGoalCollision();

public:
	Game();
	~Game();
	Game(const Game&) = delete;
	Game operator=(const Game&) = delete;
	Game(Game&&) noexcept = delete;
	Game operator=(Game&&) noexcept = delete;

	void ProcessInput();
	void Update();
	void Draw();
};