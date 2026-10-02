#pragma once

#include <iostream>
#include <random>

std::mt19937& GetGenerator();
int RandomInt(int minimum, int maximum);
float RandomFloat(float minimum, float maximum);

template <typename... Args>
void println(Args &&...values)
{
    (std::cout << ... << values) << '\n';
}