#pragma once
#include "GameData.h"

// Configuration
constexpr float TICK_DELAY_SECS = 2.0f;
constexpr int PLATE_PER_ORE = 1;

class Furnace {
	public:
		// Data
        int posX = 30;
        int posY = 60;
        int ironOre = 10;
		float tickProgress = 0.0f;

    	void update(const float deltaTime, GameData& data);
};