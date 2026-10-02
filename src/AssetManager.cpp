#include "AssetManager.h"

namespace AssetManager {
    Font globalFont;

    void Load() {
        globalFont = LoadFontEx("resources/Montserrat-Medium.ttf", 50, nullptr, 0);
        SetTextureFilter(globalFont.texture, TEXTURE_FILTER_BILINEAR);
    }

    void Unload() {
        UnloadFont(globalFont);
    }
}