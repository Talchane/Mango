//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_ETHER_TYPE_HPP
#define MANGO_ETHER_TYPE_HPP

#include "../../Ennemy.hpp"
#include "../../Personnage.hpp"

class EtherType :public Ennemy
{
public:
    EtherType(const Stats& _stats_);

    virtual void actualize(Personnage &player, const float dt) = 0;
    virtual void Draw(bool debug) const = 0;
};


#endif //MANGO_ETHER_TYPE_HPP
