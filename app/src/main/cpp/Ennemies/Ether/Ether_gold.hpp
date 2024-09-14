//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_ETHER_GOLD_HPP
#define MANGO_ETHER_GOLD_HPP

#include "../../Ennemy.hpp"
#include "../../Clock.hpp"
#include "../../Fonctions.hpp"
#include "../../Personnage.hpp"
#include "../../Stats.hpp"
#include "Ether_type.hpp"


class EtherGold :public EtherType
{
public:
    explicit EtherGold(Texture2D &_tex_, Stats _stats_);

    virtual void actualize(Personnage &player, const float dt);
    virtual void Draw(bool debug) const;
};

#endif //MANGO_ETHER_GOLD_HPP
