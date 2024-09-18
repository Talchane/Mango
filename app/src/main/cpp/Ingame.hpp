#ifndef MANGO_INGAME_H
#define MANGO_INGAME_H

#include "raylib.h"
#include <string>
#include <vector>
#include <tuple>
#include "Personnage.hpp"
#include "Ennemy.hpp"
#include "Bouton.hpp"
#include "Niveau.hpp"
#include "Lecteur_niveau.hpp"
#include "Texture_loader.hpp"
#include "Stats.hpp"
#include "Circle.hpp"
#include "Fonctions.hpp"


class Ingame{
public:

    Ingame(Vector2 const& ScreenDims, TextureLoader * pttextures, string * ptstate);

    Bouton colorButtons[3];

    Personnage player;
    vector<Ennemy> ennemies;
    Niveau level;
    Clock clockLevel;
    Clock clockInfini;
    int numLevel = 0;

    TextureLoader * textures_ptr;
    string * state_ptr;

    map<string, Color> correspondances;

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout
    void Start();
    void checkSpawn();	// Vérifie l'apparition de nouveaux ennemis
    void checkCollisionsTirs();	// Check les collisions entre les tirs et les ennemis

};


#endif //MANGO_INGAME_H
