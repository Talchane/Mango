#ifndef MANGO_GAME_HPP
#define MANGO_GAME_HPP

#include "raylib.h"
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

class Game {
public:
    Game(Vector2 const& ScreenDims);

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout

    bool inGame;

private:
    Bouton startButton;
    Bouton colorButtons[3];
    void checkSpawn();	// Vérifie l'apparition de nouveaux ennemis
    void checkCollisionsTirs();	// Check les collisions entre les tirs et les ennemis

    Personnage player;
    vector<Ennemy> ennemies;
    Niveau level;
    Clock clockLevel;

    TextureLoader textures;
    map<string, Color> correspondances;
};

#endif // GAME_HPP
