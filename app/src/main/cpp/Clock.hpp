#ifndef MANGO_CLOCK_HPP
#define MANGO_CLOCK_HPP

#include <chrono>

class Clock {
public:
    Clock();
    double getElapsedTime() const;
    double restart();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};


#endif //MANGO_CLOCK_HPP
