#include "AssetManager.h"
#include "HUD.h"
#include "Furnace.h"

#include <vector>

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Industrial Server");
    AssetManager::Load();

	std::vector<Furnace> furnaces(1);
    GameData data;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        float deltaTime = GetFrameTime();

		for (Furnace& furnace : furnaces) {
            furnace.update(deltaTime, data);
            furnace.render();
		}

        DrawHUD(data);
        EndDrawing();
    }

    AssetManager::Unload();
    CloseWindow();
    return 0;
}