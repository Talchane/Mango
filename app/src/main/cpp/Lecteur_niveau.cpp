//
// Created by benfe on 13/09/2024.
//
/*
 *
 * Structure d'un fichier de niveau :
 * 1. Temps d'appartion : commence par la lettre s et termine par deux points :  (s4.65:)
 * 2. Quantité  d'ennemis : commence par la lettre x et termine par deux points : (x6)
 * 3. Type de mob : ne termine pas par deux points.
 */
#include "Lecteur_niveau.hpp"

float getFloatString(string str, int index)
{
    string tmp = "";
    while (isdigit(str[index]) || str[index] == '.')
    {
        tmp += str[index];
        index++;
    }
    return stof(tmp);
}


int getIntString(string str, int index)
{
    string tmp = "";
    while (isdigit(str[index]))
    {
        tmp += str[index];
        index++;
    }
    return stoi(tmp);
}

vector<tuple<float, int, string>> readLevel(int numLevel)
{
    // ------------ Chargement fichier avec Raylib ------------
    string filePath = "Levels/lvl_" + to_string(numLevel) + ".txt";
    char* fileData = LoadFileText(filePath.c_str());

    if (fileData == nullptr) {
        LOGE("ERROR chargement level : Levels/lvl_%d%s", numLevel, ".txt");
        exit(1);
    }

    vector<tuple<float, int, string>> valeurs;

    // ----------- Lecture des lignes ---------------
    string fileContent(fileData);  // Convertir le char* en string pour le traitement
    UnloadFileText(fileData);      // Libérer la mémoire après conversion

    stringstream fileStream(fileContent);  // Utiliser stringstream pour lire les lignes
    string str;
    float timeValue;
    int quantite;

    while (getline(fileStream, str))
    {
        if (str[0] != 's')
        {
            LOGE("Error : no 's' in level : %d", numLevel);
            exit(1);
        }
        timeValue = getFloatString(str, 1);

        getline(fileStream, str);  // Ligne suivante

        if (str[0] != 'x')
        {
            LOGE("Error : no 'x' in level : %d", numLevel);
            exit(1);
        }
        quantite = getIntString(str, 1);

        getline(fileStream, str);  // Ligne suivante

        // Traitement de la string pour ne pas qu'elle garde de charactère indésirable
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());

        valeurs.emplace_back(timeValue, quantite, str);  // Ajouter les valeurs au vector
    }

    return valeurs;
}