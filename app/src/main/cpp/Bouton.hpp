#ifndef MANGO_BOUTON_HPP
#define MANGO_BOUTON_HPP

#include "raylib.h"

class Bouton
{
public:
    Bouton();
    // Constructeur qui initialise le bouton avec les paramètres donnés
    Bouton(float x, float y, float width, float height, Color _color_, const char* text);

    // Méthode pour dessiner le bouton à l'écran
    void Draw(bool fill) const;

    // Méthode pour vérifier si le bouton a été pressé
    bool isPressed(int marge = 0) const;

    Color buttonColor;    // Couleur du bouton
    Color buttonTextColor;  // Couleur du texte du bouton
private:
    Rectangle buttonRect; // Rectangle représentant le bouton
    const char* buttonText; // Texte affiché sur le bouton
};

#endif // BOUTON_HPP
