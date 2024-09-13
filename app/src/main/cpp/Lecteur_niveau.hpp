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
#include <android/log.h>

#define LOG_TAG "MY_APP_TAG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

using namespace std;

float getFloatString(string str, int index);
int getIntString(string str, int index);
vector<tuple<float, int, string>> readLevel(int numLevel);


#endif //MANGO_LECTEUR_NIVEAU_HPP
