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

float getFloatString(string str, int index)
{
    string tmp = "";
    while (isdigit(str[index]) || str[index] == '.')
    {
        tmp += str[index];
        index++;
    }
    return stof(tmp);
}


int getIntString(string str, int index)
{
    string tmp = "";
    while (isdigit(str[index]))
    {
        tmp += str[index];
        index++;
    }
    return stoi(tmp);
}

void traiterString(string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
}