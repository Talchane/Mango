#ifndef BOUTON_HPP
#define BOUTON_HPP

#include "raylib.h"

class Bouton
{
public:
    // Constructeur qui initialise le bouton avec les paramètres donnés
    Bouton(float x, float y, float width, float height, const char* text);

    // Méthode pour dessiner le bouton à l'écran
    void Draw() const;

    // Méthode pour vérifier si le bouton a été pressé
    bool isPressed() const;

private:
    Rectangle buttonRect; // Rectangle représentant le bouton
    Color buttonColor;    // Couleur du bouton
    Color buttonTextColor;  // Couleur du texte du bouton
    const char* buttonText; // Texte affiché sur le bouton
};

#endif // BOUTON_HPP
