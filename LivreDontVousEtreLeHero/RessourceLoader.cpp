#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "RessourceLoader.h"

RessourceLoader::RessourceLoader(std::string fichier)
{
	Remplir(fichier);
}

void RessourceLoader::Remplir(std::string fichier)
{
    std::ifstream iFile(fichier);
    std::string line;

    // Ouvre le fichier CSV en lecture

    // Vérification si le fichier s'ouvre correctement
    if (!iFile.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier!" << std::endl;
        return;
    }

    // Lire chaque ligne du fichier
    while (std::getline(iFile, line)) {

        Infos infos;

        std::stringstream ss(line);
        std::string valeur;

        // Lire chaque valeur de la ligne
        std::getline(ss, valeur, ';');
        infos.id = std::stoi(valeur);

        std::getline(ss, valeur, ';');
        infos.texte = valeur;

        std::getline(ss, valeur, ';');
        infos.choix1 = std::stoi(valeur);

        std::getline(ss, valeur, ';');
        infos.choix2 = std::stoi(valeur);

        std::getline(ss, valeur, ';');
        infos.indicateur = valeur[0];

        data.push_back(infos);
    }

    iFile.close(); // Ferme le fichier une fois la lecture terminée
}

void RessourceLoader::Afficher()
{
    for (const auto& infos : data)
    {
        std::cout << "Id: " << infos.id << std::endl;
        std::cout << "Texte: " << infos.texte << std::endl;
        std::cout << "Choix 1: " << infos.choix1 << std::endl;
        std::cout << "Choix 2: " << infos.choix2 << std::endl;
        std::cout << "Indicateur: " << infos.indicateur << std::endl << std::endl;
    }
}

void RessourceLoader::RemplirListe(Liste& liste)
{
    for (Infos info : data)
    {
        liste.Ajouter(info);
    }

    for (Infos info : data)
    {
        liste.AssignerPtr(info);
    }
}
