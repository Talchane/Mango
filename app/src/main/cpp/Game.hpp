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
#include "Ennemies/Ether/Ether_black.hpp"
#include "Ennemies/Ether/Ether_blue.hpp"
#include "Ennemies/Ether/Ether_gold.hpp"

class Game {
public:
    Game(Vector2 const& ScreenDims);

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout

    bool inGame;

private:
    Bouton startButton;
    void checkSpawn();	// Vérifie l'apparition de nouveaux ennemis
    void checkCollisionsTirs();	// Check les collisions entre les tirs et les ennemis

    Personnage player;
    vector<Ennemy*> ennemies;
    Niveau level;
    Clock clockLevel;

    TextureLoader textures;
    map<string, Stats> statsMobs;
};

#endif // GAME_HPP
