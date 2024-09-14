//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_STATS_HPP
#define MANGO_STATS_HPP

#include <tuple>
#include <string>
#include <map>
#include <sstream>
#include "Fonctions.hpp"
#include "raylib.h"

using namespace std;

struct Stats
{
    Stats();

    string type;
    float life;
    float speed;
    float speedAttack;
    float damages;

    tuple<float, float, float> resistances; // Résistance aux différents types de balles
};

map<string, Stats> LoadAllMobStats();

#endif //MANGO_STATS_HPP
