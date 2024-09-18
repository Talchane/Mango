//
// Created by benfe on 14/09/2024.
//

#include "Texture_loader.hpp"

TextureLoader::TextureLoader()
{
    loadAll();
}

Vector2 TextureLoader::getMobTextureDims()
{
    return (Vector2){600, 600};
}

void TextureLoader::loadAll()
{
    texAnneau80 = LoadTexture("cercle_contour_80px.png");
    texEtherRed = LoadTexture("textures_v1/mobs/ether/ether_red.png");
    texEtherGreen = LoadTexture("textures_v1/mobs/ether/ether_green.png");
    texEtherBlue = LoadTexture("textures_v1/mobs/ether/ether_blue.png");
}