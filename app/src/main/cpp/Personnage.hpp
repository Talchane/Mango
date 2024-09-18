#ifndef MANGO_PERSONNAGE_HPP
#define MANGO_PERSONNAGE_HPP

#include <vector>       // Pour std::vector
#include "Ball.hpp"    // Assurez-vous que ce fichier existe et est accessible
#include "Clock.hpp"
#include "raylib.h"    // Pour raylib, si vous utilisez ses fonctions comme DrawCircle
#include "Circle.hpp"
#include "Texture_loader.hpp"
#include <map>

class Personnage
{
public:
    Personnage(const Vector2 ScreenDims, TextureLoader *_textures_ptr_, map<string, Color> *correspondances);

    void Draw(bool debug) const;
    void actualize(const float dt);
    void setColor(const Color& col);
    void reset();

    int life;
    Color shootColor;
    Vector2 position;
    vector<Ball> balles;
    Circle colCircle;
    Clock clockTir;

private:
    float globalTime;
    Texture2D texAct;
    float rotation;
    float speedRotation;
    TextureLoader *textures_ptr;
    map<string, Color> *correspondances;
};

#endif // PERSONNAGE_HPP
