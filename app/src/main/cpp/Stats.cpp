//
// Created by benfe on 14/09/2024.
//

#include "Stats.hpp"

Stats::Stats()
{}

map<string, Stats> LoadAllMobStats()
{
    map<std::string, Stats> caracteristiques;

    // ------------- Chargement du flux -------------
    string filePath = "StatistiquesMobs.txt";
    char* fileData = LoadFileText(filePath.c_str());

    if (fileData == nullptr) {
        LOGE("Error Stats.cpp : Ouverture fichier StatistiquesMobs.txt.");
        exit(1);
    }


    // ----------- Lecture des lignes ---------------
    string fileContent(fileData);  // Convertir le char* en string pour le traitement
    UnloadFileText(fileData);      // Libérer la mémoire après conversion

    stringstream fileStream(fileContent);  // Utiliser stringstream pour lire les lignes
    Stats tmpStats;
    string str;
    string tmp;

    // On saute la partie de commentaires en en-tête du fichier
    while (str[0] != '-')
        getline(fileStream, str);

    // On lit et stock les valeurs
    while (getline(fileStream, str))
    {
        std::stringstream ss(str);

        // Get Type
        getline(ss, tmp, ',');
        traiterString(tmp);
        tmpStats.type = tmp;


        // Get life
        getline(ss, tmp, ',');
        traiterString(tmp);
        tmpStats.life = stof(tmp);

        // Get vitesse
        getline(ss, tmp, ',');
        traiterString(tmp);
        tmpStats.speed = stof(tmp);

        // Get vitesse d'attaque
        getline(ss, tmp, ',');
        traiterString(tmp);
        tmpStats.speedAttack = stof(tmp);

        // Get damages
        getline(ss, tmp, ',');
        traiterString(tmp);
        tmpStats.damages = stof(tmp);

        // ---- Get resistances ----
        tuple<float, float, float> tmpResistances;

        getline(ss, tmp, ',');
        traiterString(tmp);
        get<0>(tmpResistances) = stof(tmp);
        getline(ss, tmp, ',');
        traiterString(tmp);
        get<1>(tmpResistances) = stof(tmp);
        getline(ss, tmp, ',');
        traiterString(tmp);
        get<2>(tmpResistances) = stof(tmp);

        tmpStats.resistances = tmpResistances;

        caracteristiques[tmpStats.type] = tmpStats;
    }

    return caracteristiques;
}