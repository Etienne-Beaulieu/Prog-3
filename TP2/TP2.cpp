#include <iostream>
#include <vector>
#include "Labyrinthe.h"
#include "LabyrintheFileReader.h"
#include "LabyrintheFileWriter.h"
#include "Solution.h"

int main() {
    // Nom du fichier binaire du labyrinthe
    std::string filename = "TestMaze.TP2";

    // Vecteur pour stocker les liens (connections entre les cases)
    std::vector<std::pair<uint16_t, uint16_t>> links;

    try {
        // Lire le fichier et récupérer le labyrinthe avec ses liens
        Labyrinthe maze = LabyrintheFileReader::read(filename, links);

        // Afficher des informations de base sur le labyrinthe
        std::cout << "Labyrinthe chargé avec " << maze.getNbCases() << " cases.\n";
        std::cout << "Case de départ : " << maze.getDebut() << "\n";
        std::cout << "Case d'arrivée : " << maze.getFin() << "\n";

        // Créer un solver pour résoudre le labyrinthe
        Solution solver(maze);
        bool solved = solver.resoudre();

        if (solved) {
            std::cout << "Solution trouvée ! Chemin : \n";
            // Afficher le chemin de la solution
            std::vector<uint16_t> solution = solver.getSolution();
            for (uint16_t caseId : solution) {
                std::cout << caseId << " ";
            }
            std::cout << "\n";

            // Réécrire le fichier avec la solution trouvée
            LabyrintheFileWriter::ecrireSolution(filename, solution);
            std::cout << "Solution écrite dans le fichier.\n";
        }
        else {
            std::cout << "Aucune solution trouvée pour le labyrinthe.\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
    }

    return 0;
}
