#include "GameData.h"
#include <cmath>

int GameData::GetIronPlates() const {
    return ironPlates;
}

void GameData::SetIronPlates(const int newAmount) {
    ironPlates = std::max(0, newAmount);
}