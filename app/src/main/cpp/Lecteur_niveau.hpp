//
// Created by benfe on 13/09/2024.
//

#ifndef MANGO_LECTEUR_NIVEAU_HPP
#define MANGO_LECTEUR_NIVEAU_HPP

#include "raylib.h"
#include <sstream>
#include <utility>
#include <tuple>
#include <iostream>
#include "Fonctions.hpp"
#include <android/log.h>

using namespace std;

vector<tuple<float, int, string>> readLevel(int numLevel);


#endif //MANGO_LECTEUR_NIVEAU_HPP
