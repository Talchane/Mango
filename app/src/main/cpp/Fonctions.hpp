//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_FONCTIONS_HPP
#define MANGO_FONCTIONS_HPP

#include <android/log.h>
#include <string>
#include "raylib.h"
#include "cmath"

#define LOG_TAG "MY_APP_TAG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

using namespace std;

Vector2 rendreUnitaire(Vector2 const& V);

float getFloatString(string str, int index);
int getIntString(string str, int index);
void traiterString(string &str);


#endif //MANGO_FONCTIONS_HPP
