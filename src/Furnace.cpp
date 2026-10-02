#include "Furnace.h"
#include <algorithm>

void Furnace::update(const float deltaTime, GameData& data) {
    if (ironOre <= 0) {
        tickProgress = 0.0f;
        return;
    }

    tickProgress += deltaTime;
    if (tickProgress < TICK_DELAY_SECS) return;
    tickProgress -= TICK_DELAY_SECS;

    data.SetIronPlates(data.GetIronPlates() + PLATE_PER_ORE);
    ironOre = std::max(0, ironOre - 1);
}