#include "GameData.h"
#include <algorithm>

int GameData::GetIronPlates() const {
    return ironPlates;
}

void GameData::SetIronPlates(const int newAmount) {
    ironPlates = std::max(0, newAmount);
}