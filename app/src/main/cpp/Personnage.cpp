#include "Personnage.hpp"

// Constructeur
Personnage::Personnage(const Vector2 ScreenDims, TextureLoader *_textures_ptr_, map<string, Color> *_correspondances_) :
    life(3),
    rotation(0),
    speedRotation(100),
    shootColor({255, 0, 0, 255}),   // Attention, à ne pas garder car correspondances peut changer
    position({ScreenDims.x / 2, ScreenDims.y / 2}),
    textures_ptr(_textures_ptr_),
    correspondances(_correspondances_),
    globalTime(0.f)
{
    colCircle.position = position;
    colCircle.radius = 100;
    texAct = (*textures_ptr).texEtherRed;
}

// Méthode Draw
void Personnage::Draw(bool debug) const
{
    for (int i = 0; i < balles.size(); ++i)
        balles[i].Draw();

    float scale = 200.f / 360; // Tu factor de escala
    Vector2 textureSize = { (float)texAct.width * scale, (float)texAct.height * scale };
    Vector2 origin = { textureSize.x / 2.0f, textureSize.y / 2.0f };

    DrawTexturePro(texAct,
                   { 0.0f, 0.0f, (float)texAct.width, (float)texAct.height }, // sourceRec
                   { position.x, position.y, textureSize.x, textureSize.y }, // destRec
                   origin, // origin
                   rotation,
                   WHITE);
   /*if (debug)
        colCircle.Draw();*/
}

// Méthode actualize
void Personnage::actualize(const float dt)
{
    globalTime += dt;

    // --- Check tir ---
    if (clockTir.getElapsedTime() > 0.1f)
    {
        int touchCount = GetTouchPointCount();
        if (touchCount > 0)
        {
            Vector2 touchPosition{GetTouchPosition(0)};

            // Sert uniquement à donner la rotation aux balles
            float rotationRad = M_PI / 2.f - atan2(touchPosition.x - position.x, touchPosition.y - position.y);
            balles.emplace_back(position, rotationRad, shootColor); // On crée une nouvelle balle
            clockTir.restart();
        }
    }

    // Actualisation de la rotation de la balle

    rotation += speedRotation * dt;

    // ------- Actualisation des balles -----
    for (int i = 0; i < size(balles); ++i) {
        balles[i].actualize(dt);
    }
}

void Personnage::setColor(const Color& col)
{
    shootColor = col;
    colCircle.color = col;

    LOGE("Correspondance setColor = %p", correspondances);

    if (col == (*correspondances)["Red"])
        texAct = (*textures_ptr).texEtherRed;

    else if (col == (*correspondances)["Green"])
        texAct = (*textures_ptr).texEtherGreen;

    else if (col == (*correspondances)["Blue"])
        texAct = (*textures_ptr).texEtherBlue;

}

void Personnage::reset()
{
    setColor((*correspondances)["Red"]);
    clockTir.restart();
    balles.clear();
}