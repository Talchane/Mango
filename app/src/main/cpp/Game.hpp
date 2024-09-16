#ifndef MANGO_GAME_HPP
#define MANGO_GAME_HPP

#include "Texture_loader.hpp"
#include "Ingame.hpp"
#include "Menu.hpp"

class Game {
public:
    Game(Vector2 const& ScreenDims);

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout

    std::string state = "Menu";
    TextureLoader textures;

    Ingame ingame;
    Menu menu;

private:
    Bouton startButton;
};

#endif // GAME_HPP
