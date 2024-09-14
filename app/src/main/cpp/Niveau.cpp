//
// Created by benfe on 14/09/2024.
//

#include "Niveau.hpp"

Niveau::Niveau() : progression(0)
{}

Niveau::Niveau(int _numlvl_) : numlvl(_numlvl_), progression(0)
{
    loadLvl(_numlvl_);
}

void Niveau::loadLvl(int _numlvl_)
{
    numlvl = _numlvl_;
    progression = 0;
    levelData = readLevel(_numlvl_);
}

float Niveau::getNextTimeCode()
{
    if (ended())
    {
        LOGE("Error : getTimeCode level %d, etape %d", numlvl, progression);
        exit(1);
    }
    return get<0>(levelData[progression]);
}

int Niveau::getNextQuantity()
{
    if (ended())
    {
        LOGE("Error : getTimeCode level %d, etape %d", numlvl, progression);
        exit(1);
    }
    return get<1>(levelData[progression]);
}

string Niveau::getNextType()
{
    if (ended())
    {
        LOGE("Error : getTimeCode level %d, etape %d", numlvl, progression);
        exit(1);
    }
    return get<2>(levelData[progression]);
}

void Niveau::nextStep()
{
    progression++;
}

bool Niveau::ended()
{
    return (progression >= size(levelData));
}
