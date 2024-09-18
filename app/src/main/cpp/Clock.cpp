#include "Clock.hpp"

Clock::Clock()
        : startTime(std::chrono::high_resolution_clock::now()),
          pausedDuration(std::chrono::duration<double>::zero()),
          isPaused(false)
{}

// Retourne le temps écoulé en tenant compte de la pause
double Clock::getElapsedTime() const
{
    if (isPaused) {
        // Si le chrono est en pause, on retourne le temps écoulé jusqu'à la pause
        return std::chrono::duration<double>(pauseStartTime - startTime - pausedDuration).count();
    } else {
        // Sinon, on retourne le temps écoulé jusqu'à maintenant moins la durée des pauses
        return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime - pausedDuration).count();
    }
}

// Redémarre le chrono et retourne le temps écoulé
double Clock::restart()
{
    double elapsed = getElapsedTime(); // Temps écoulé avant restart
    startTime = std::chrono::high_resolution_clock::now(); // Réinitialise le chrono
    pausedDuration = std::chrono::duration<double>::zero(); // Réinitialise la durée des pauses
    isPaused = false; // Relance le chrono
    return elapsed;
}

// Met en pause le chrono
void Clock::pause()
{
    if (!isPaused) {
        pauseStartTime = std::chrono::high_resolution_clock::now(); // Enregistre l'heure de la pause
        isPaused = true;
    }
}

// Reprend le chrono après une pause
void Clock::play()
{
    if (isPaused) {
        pausedDuration += std::chrono::high_resolution_clock::now() - pauseStartTime; // Ajoute la durée de la pause
        isPaused = false;
    }
}