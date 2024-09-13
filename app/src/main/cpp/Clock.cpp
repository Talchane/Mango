#include "Clock.hpp"

Clock::Clock() : startTime(std::chrono::high_resolution_clock::now())
{}

double Clock::getElapsedTime() const
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - startTime;
    return elapsed.count();
}

double Clock::restart()
{
    double elapsed = getElapsedTime();
    startTime = std::chrono::high_resolution_clock::now();
    return elapsed;
}