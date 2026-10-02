#include "utility.h"
#include <random>

std::mt19937& GetGenerator() {
    static std::random_device RandomDevice;
    static std::mt19937 Generator(RandomDevice());

    return Generator;
}

int RandomInt(int minimum, int maximum) {
    std::uniform_int_distribution<int> Distribution(minimum, maximum);
    return Distribution(GetGenerator());
}

float RandomFloat(float minimum, float maximum) {
    std::uniform_real_distribution<float> Distribution(minimum, maximum);
    return Distribution(GetGenerator());
}