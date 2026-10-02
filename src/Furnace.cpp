#include "AssetManager.h"
#include "raylib.h"
#include "Furnace.h"

#include <format>
#include <cmath>

// UI
constexpr int FONT_SIZE = 30;
constexpr int BAR_WIDTH = 130;

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

void Furnace::render() const {
    const int BOTTOM = posY + 105;

    DrawRectangle(posX, posY, 100, 100, GRAY);

    // Text
    Font& globalFont = AssetManager::globalFont;
    std::string oreText = std::format("Iron ore: {}", ironOre);
    
    DrawTextEx(globalFont, oreText.c_str(), Vector2 {
        static_cast<float>(posX - 10),
        static_cast<float>(BOTTOM)
    }, FONT_SIZE, 0.0f, WHITE);
    DrawTextEx(globalFont, "Furnace", Vector2 {static_cast<float>(posX), static_cast<float>(posY) - 35.0f}, FONT_SIZE, 0.0f, WHITE);

    DrawRectangle(posX - 12, BOTTOM + 37, BAR_WIDTH, 30, GRAY);
    DrawRectangle(posX - 12, BOTTOM + 37, (tickProgress / TICK_DELAY_SECS) * BAR_WIDTH, 30, GREEN);
}