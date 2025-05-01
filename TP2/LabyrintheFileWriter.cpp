#include "LabyrintheFileWriter.h"
#include <fstream>
#include <stdexcept>

void LabyrintheFileWriter::ecrireSolution(const std::string& filename, const std::vector<uint16_t>& solution) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error("Erreur d'ouverture pour écriture.");
    }

    // Calculer la longueur du chemin
    uint32_t pathLength = solution.size();

    // Aller à l'emplacement de l'en-tête pour la taille du chemin
    file.seekp(18, std::ios::beg); // 18e octet : à cet endroit pour écrire la taille

    // Écrire la longueur du chemin
    file.write(reinterpret_cast<const char*>(&pathLength), sizeof(pathLength));

    // Aller à la fin du fichier pour enregistrer la solution
    file.seekp(0, std::ios::end);

    uint32_t solutionOffset = file.tellp(); // position actuelle dans le fichier
    file.write(reinterpret_cast<const char*>(&solutionOffset), sizeof(solutionOffset));

    // Écrire les cases du chemin
    for (uint16_t caseId : solution) {
        file.write(reinterpret_cast<const char*>(&caseId), sizeof(caseId));
    }
}
