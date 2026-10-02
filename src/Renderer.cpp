#include "Renderer.h"
#include "AssetManager.h"
#include "raylib.h"

#include <format>
#include <algorithm>

// UI
constexpr int FONT_SIZE = 30;
constexpr int BAR_WIDTH = 130;

using std::string;
using std::format;

namespace Renderer {
    void RenderFurnace(const Furnace& furnace) {
        float posX = furnace.posX;
        float posY = furnace.posY;

        const int BOTTOM = posY + 105;

        DrawRectangle(posX, posY, 100, 100, GRAY);

        // Text
        Font& globalFont = AssetManager::globalFont;
        std::string oreText = std::format("Iron ore: {}", furnace.ironOre);
        
        DrawTextEx(globalFont, oreText.c_str(), Vector2 {
            static_cast<float>(posX - 10),
            static_cast<float>(BOTTOM)
        }, FONT_SIZE, 0.0f, WHITE);
        DrawTextEx(globalFont, "Furnace", Vector2 {static_cast<float>(posX), static_cast<float>(posY) - 35.0f}, FONT_SIZE, 0.0f, WHITE);

        DrawRectangle(posX - 12, BOTTOM + 37, BAR_WIDTH, 30, GRAY);
        DrawRectangle(posX - 12, BOTTOM + 37, (furnace.tickProgress / TICK_DELAY_SECS) * BAR_WIDTH, 30, GREEN);
    }
}