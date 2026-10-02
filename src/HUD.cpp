#include "HUD.h"
#include "AssetManager.h"
#include "GameData.h"
#include "raylib.h"

#include <format>

using AssetManager::globalFont;
using std::format;
using std::string;

void DrawHUD(const GameData& data) {
    string plateText = format("Plates: {}", data.GetIronPlates());
    DrawTextEx(globalFont, plateText.c_str(), Vector2 {1050.0f, 30.0f}, 50, 0.0f, WHITE);
}