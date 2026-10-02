#include "HUD.h"
#include "AssetManager.h"
#include "raylib.h"

#include <format>

using AssetManager::globalFont;

void DrawHUD(const GameData& data) {
    std::string plateText = std::format("Plates: {}", data.GetIronPlates());
    DrawTextEx(globalFont, plateText.c_str(), Vector2 {1050.0f, 30.0f}, 50, 0.0f, WHITE);
}