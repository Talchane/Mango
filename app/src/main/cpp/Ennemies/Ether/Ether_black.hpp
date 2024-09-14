//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_ETHER_BLACK_HPP
#define MANGO_ETHER_BLACK_HPP

#include "../../Ennemy.hpp"
#include "../../Clock.hpp"
#include "../../Fonctions.hpp"
#include "../../Personnage.hpp"
#include "Ether_type.hpp"


class EtherBlack :public EtherType
{
public:
    explicit EtherBlack(Texture2D &_tex_);

    virtual void actualize(Personnage &player, const float dt);
    virtual void Draw(bool debug) const;
};


#endif //MANGO_ETHER_BLACK_HPP
