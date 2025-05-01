#ifndef SOLUTION_H
#define SOLUTION_H

#include "Labyrinthe.h"
#include <vector>
#include <cstdint>

class Solution {
public:
    Solution(Labyrinthe& labyrinthe) : labyrinthe(labyrinthe), solved(false) {}

    bool resoudre();  // Méthode principale pour résoudre le labyrinthe
    std::vector<uint16_t> getSolution() const;  // Récupère la solution

private:
    Labyrinthe& labyrinthe;  // Référence au labyrinthe à résoudre
    bool solved;  // Indique si une solution a été trouvée
    std::vector<uint16_t> solution;  // Contient la solution (liste des cases à traverser)

    bool dfs(uint16_t current, std::vector<bool>& visited);  // Fonction de recherche en profondeur récursive
    bool isValid(uint16_t caseId);  // Vérifie si une case est valide à visiter
};

#endif