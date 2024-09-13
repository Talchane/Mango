#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Personnage.hpp"
#include "Ennemy.hpp"

class Game {
public:
    Game();

    void actualize();	// Actualise tout
    void Draw();		// Affiche tout

    bool inGame;

private:
    void checkSpawn();	// Vérifie l'apparition de nouveaux ennemis
    void checkCollisionsTirs();	// Check les collisions entre les tirs et les ennemis

    Personnage player;
    std::vector<Ennemy*> ennemies;
};

#endif // GAME_HPP
