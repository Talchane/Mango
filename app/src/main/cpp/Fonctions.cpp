//
// Created by benfe on 14/09/2024.
//

#include "Fonctions.hpp"

Vector2 rendreUnitaire(Vector2 const& V)
{
    Vector2 result = V;
    float length = sqrtf(result.x * result.x + result.y * result.y);

    // Eviter la division par zéro
    if (length > 0.0f) {
        result.x /= length;
        result.y /= length;
    }
    return result;
}