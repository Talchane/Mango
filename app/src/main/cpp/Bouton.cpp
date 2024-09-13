#include "Bouton.hpp"

Bouton::Bouton(float x, float y, float width, float height, const char* text)
    : buttonRect{ x, y, width, height },
      buttonColor(BLUE),
      buttonHoverColor(DARKBLUE),
      buttonTextColor(WHITE),
      buttonText(text)
{
}

void Bouton::Draw() const
{
    // Vérifiez si l'écran tactile touche le bouton
    Vector2 touchPosition = { 0, 0 };
    bool isTouching = false;
    int touchCount = GetTouchPointCount(); // Obtenez le nombre de points de contact

    for (int i = 0; i < touchCount; i++)
    {
        touchPosition = GetTouchPosition(i);
        if (CheckCollisionPointRec(touchPosition, buttonRect))
        {
            isTouching = true;
            break;
        }
    }

    // Dessinez le bouton avec la couleur appropriée
    if (isTouching)
    {
        DrawRectangleRec(buttonRect, buttonHoverColor);
    }
    else
    {
        DrawRectangleRec(buttonRect, buttonColor);
    }

    // Dessinez le texte du bouton
    DrawText(buttonText, buttonRect.x + 10, buttonRect.y + 15, 20, buttonTextColor);
}

bool Bouton::isPressed() const
{
    Vector2 touchPosition = { 0, 0 };
    bool isTouching = false;
    int touchCount = GetTouchPointCount(); // Obtenez le nombre de points de contact

    for (int i = 0; i < touchCount; i++)
    {
        touchPosition = GetTouchPosition(i);
        if (CheckCollisionPointRec(touchPosition, buttonRect))
        {
            if (IsTouchReleased(i))
            {
                return true; // Le bouton est pressé et relâché
            }
        }
    }
    return false; // Le bouton n'est pas pressé
}
