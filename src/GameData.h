#pragma once

class GameData {
    public:
        int GetIronPlates() const;
        void SetIronPlates(const int newAmount);
    private:
        int ironPlates = 0;
};