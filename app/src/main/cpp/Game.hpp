#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Personnage.hpp"
#include "Ennemy.hpp"
#include "Bouton.hpp"

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
    std::vector<Ennemy*> ennemies;
};

#endif // GAME_HPP
