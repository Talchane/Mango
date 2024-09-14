//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_NIVEAU_HPP
#define MANGO_NIVEAU_HPP

#include "Lecteur_niveau.hpp"

struct Niveau
{
    Niveau();
    Niveau(int _numlvl_);

    void loadLvl(int _numlvl_);

    float getNextTimeCode();
    int getNextQuantity();
    string getNextType();

    void nextStep();
    bool ended();

    int progression;
    int numlvl;
private:
    vector<tuple<float, int, string>> levelData; // contient respectivement : float timecode, int quantité, string type
};


#endif //MANGO_NIVEAU_HPP
