#include "LabyrintheFileReader.h"
#include <fstream>
#include <stdexcept>

Labyrinthe LabyrintheFileReader::read(const std::string& filename, std::vector<std::pair<uint16_t, uint16_t>>& links) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Erreur d'ouverture du fichier.");
    }

    uint16_t fileType;
    file.read(reinterpret_cast<char*>(&fileType), sizeof(fileType));

    if (fileType != 0x6969) {
        throw std::runtime_error("Type de fichier invalide.");
    }

    uint32_t fileSize, dataOffset, dataSize;
    uint16_t nbCases, debut, fin;

    file.read(reinterpret_cast<char*>(&fileSize), sizeof(fileSize));
    file.read(reinterpret_cast<char*>(&dataOffset), sizeof(dataOffset));
    file.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));
    file.read(reinterpret_cast<char*>(&nbCases), sizeof(nbCases));
    file.read(reinterpret_cast<char*>(&debut), sizeof(debut));
    file.read(reinterpret_cast<char*>(&fin), sizeof(fin));

    Labyrinthe labyrinthe(nbCases, debut, fin);

    // Aller à l'offset des liens
    file.seekg(dataOffset, std::ios::beg);

    size_t nbLinks = dataSize / 4;
    for (size_t i = 0; i < nbLinks; ++i) {
        uint16_t a, b;
        file.read(reinterpret_cast<char*>(&a), sizeof(a));
        file.read(reinterpret_cast<char*>(&b), sizeof(b));
        labyrinthe.ajouterLien(a, b);
        links.push_back(std::make_pair(a, b));
    }

    return labyrinthe;
}