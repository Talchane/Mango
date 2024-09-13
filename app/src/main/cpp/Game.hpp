#ifndef MANGO_GAME_HPP
#define MANGO_GAME_HPP

#include "raylib.h"
#include <vector>
#include <tuple>
#include "Personnage.hpp"
#include "Ennemy.hpp"
#include "Bouton.hpp"
#include "Lecteur_niveau.hpp"
#include "Ennemies/Ether/Ether_black.hpp"

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
    vector<tuple<float, int, string>> levelData;
    Clock clockLevel;
    int indexSpawn;     // Index pour savoir quel est le prochain mob à spawn

    Texture2D texEtherBlack;
};

#endif // GAME_HPP
