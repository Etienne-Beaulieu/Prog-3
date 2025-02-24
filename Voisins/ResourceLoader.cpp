#include "ResourceLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

ResourceLoader::ResourceLoader()
{
    Remplir();
}

void ResourceLoader::Remplir()
{
    std::ifstream iFile("binary-winequality-white.csv");
    std::string line;

    // Ouvre le fichier CSV en lecture

    // Vérification si le fichier s'ouvre correctement
    if (!iFile.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier!" << std::endl;
        return;
    }

    // Lire chaque ligne du fichier
    while (std::getline(iFile, line)) {

        Vin vin;

        std::stringstream ss(line);
        std::string valeur;

        // Lire chaque valeur de la ligne
        std::getline(ss, valeur, ',');
        vin.aciditeFixe = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.acideVolatile = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.acideCitrique = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.acideResiduel = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.chlorureDeSodium = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.dioxydeDeSoufreLibre = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.dioxydeDeSoufreTotal = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.densite = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.ph = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.sulfateDePotassium = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.alcool = std::stof(valeur);

        std::getline(ss, valeur, ',');
        vin.bonOuNon = std::stoi(valeur); // Utilisation de std::stoi pour les entiers

        data.push_back(vin);
    }

    iFile.close(); // Ferme le fichier une fois la lecture terminée
}

std::vector<Vin> ResourceLoader::GetTrainData(float k)
{
    size_t taille = static_cast<size_t>(data.size() * k);
    return std::vector<Vin>(data.begin(), data.begin() + taille);
}

std::vector<Vin> ResourceLoader::GetTestData(float k) {
    size_t taille = static_cast<size_t>(data.size() * k);
    return std::vector<Vin>(data.begin() + taille, data.end());
}

ListeVin ResourceLoader::GetTrainDataLinked(float k)
{
    ListeVin liste;
    size_t taille = static_cast<size_t>(data.size() * k);

    for (int i = 0; i < taille; i++)
    {
        liste.Ajouter(data[i]);
    }
    
    return liste;
}

ListeVin ResourceLoader::GetTestDataLinked(float k)
{
    ListeVin liste;
    size_t tailleTrain = static_cast<size_t>(data.size() * k);
    size_t tailleTest = data.size() - tailleTrain;

    for (size_t i = tailleTest; i < data.size(); i++)
    {
        liste.Ajouter(data[i]);
    }

    return liste;
}

void ResourceLoader::Afficher()
{
    for (const auto& vin : data) {
        std::cout << "Acidite Fixe: " << vin.aciditeFixe << ", ";
        std::cout << "Acide Volatile: " << vin.acideVolatile << ", ";
        std::cout << "Acide Citrique: " << vin.acideCitrique << ", ";
        std::cout << "Acide Residuel: " << vin.acideResiduel << ", ";
        std::cout << "Chlorure de Sodium: " << vin.chlorureDeSodium << ", ";
        std::cout << "Dioxyde de Soufre Libre: " << vin.dioxydeDeSoufreLibre << ", ";
        std::cout << "Dioxyde de Soufre Total: " << vin.dioxydeDeSoufreTotal << ", ";
        std::cout << "Densite: " << vin.densite << ", ";
        std::cout << "pH: " << vin.ph << ", ";
        std::cout << "Sulfate de Potassium: " << vin.sulfateDePotassium << ", ";
        std::cout << "Alcool: " << vin.alcool << ", ";
        std::cout << "Bon ou Non: " << vin.bonOuNon << std::endl;
    }
}