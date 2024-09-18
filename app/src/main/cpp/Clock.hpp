#ifndef MANGO_CLOCK_HPP
#define MANGO_CLOCK_HPP

#include <chrono>

using namespace std;

class Clock {
public:
    Clock();

    double getElapsedTime() const;
    double restart();
    void pause();
    void play();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> pauseStartTime;
    std::chrono::duration<double> pausedDuration;
    bool isPaused;
};

#endif //MANGO_CLOCK_HPP
