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
#include "Pause_menu.hpp"


class Ingame
{
public:

    Ingame(Vector2 const& ScreenDims, TextureLoader * pttextures, string * ptstate);

    Bouton colorButtons[3];

    TextureLoader * textures_ptr;
    Personnage player;
    vector<Ennemy> ennemies;
    Niveau level;
    Clock clockLevel;
    Clock clockInfini;
    int numLevel = 0;

    string * state_ptr;

    map<string, Color> correspondances;
    PauseMenu pauseMenu;

    Bouton pauseButton;

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout
    void Start();
    void checkSpawn();	// Vérifie l'apparition de nouveaux ennemis
    void checkCollisionsTirs();	// Check les collisions entre les tirs et les ennemis

};


#endif //MANGO_INGAME_H
