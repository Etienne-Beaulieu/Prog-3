#include "Solution.h"

bool Solution::resoudre() {
    solution.clear();
    std::vector<bool> visited(labyrinthe.getNbCases(), false);  // Tableau pour suivre les cases visitées

    // Lancer la recherche en profondeur à partir de la case de départ
    uint16_t start = labyrinthe.getDebut();
    bool found = dfs(start, visited);

    if (found) {
        solved = true;
    }
    return found;
}

bool Solution::dfs(uint16_t curseur, std::vector<bool>& visiter) {
    // Si la case actuelle a déjà été visitée, on arrête la recherche
    if (visiter[curseur]) return false;

    // Marquer la case comme visitée
    visiter[curseur] = true;
    solution.push_back(curseur);

    // Si on est arrivé à la case de fin, la solution est trouvée
    if (curseur == labyrinthe.getFin()) {
        return true;
    }

    // Parcours récursif des voisins (liens)
    for (uint16_t voisin : labyrinthe.getVoisins(curseur)) {
        if (!visiter[voisin] && isValid(voisin)) {
            if (dfs(voisin, visiter)) {
                return true;  // Si un chemin vers la sortie est trouvé
            }
        }
    }

    // Si aucun chemin n'est trouvé depuis cette case, on la retire de la solution
    solution.pop_back();
    return false;
}

bool Solution::isValid(uint16_t caseId) {
    // Ajouter ici des règles supplémentaires de validation si nécessaire
    return true;  // Ici, on permet de visiter toutes les cases connectées par les liens
}

std::vector<uint16_t> Solution::getSolution() const {
    return solved ? solution : std::vector<uint16_t>();
}
