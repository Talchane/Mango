//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_TEXTURE_LOADER_HPP
#define MANGO_TEXTURE_LOADER_HPP

#include "raylib.h"

class TextureLoader
{
public:
    TextureLoader();
    void loadAll();
    static Vector2 getMobTextureDims();

    Texture2D texAnneau80;
    Texture2D texEtherBlack;
    Texture2D texEtherBlue;
    Texture2D texEtherGold;
};


#endif //MANGO_TEXTURE_LOADER_HPP
