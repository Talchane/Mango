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

template <typename T>
void removeElement(vector<T*> &vec, size_t index)
{
    // Vérifier que l'index est valide
    if (index < vec.size()) {
        // Libérer la mémoire pointée avant de supprimer le pointeur
        delete vec[index];

        // Remplacer l'élément à l'index par le dernier élément
        std::swap(vec[index], vec.back());

        // Supprimer le dernier élément (pointeur)
        vec.pop_back();
    }
    else
    {
        LOGE("ERROR Fonctions.cpp : delete inexistant element index : %d", index);
        exit(1);
    }
}

Vector2 rendreUnitaire(Vector2 const& V);

float getFloatString(string str, int index);
int getIntString(string str, int index);
void traiterString(string &str);
float distance(const Vector2 A, const Vector2 B);



#endif //MANGO_FONCTIONS_HPP