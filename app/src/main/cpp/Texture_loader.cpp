//
// Created by benfe on 14/09/2024.
//

#include "Texture_loader.hpp"

TextureLoader::TextureLoader()
{

}

Vector2 TextureLoader::getMobTextureDims()
{
    return (Vector2){600, 600};
}

void TextureLoader::loadAll()
{
    texAnneau80 = LoadTexture("cercle_contour_80px.png");
    texEtherBlack = LoadTexture("textures_v1/mobs/ether/ether_black.png");
    texEtherBlue = LoadTexture("textures_v1/mobs/ether/ether_blue.png");
    texEtherGold = LoadTexture("textures_v1/mobs/ether/ether_gold.png");
}