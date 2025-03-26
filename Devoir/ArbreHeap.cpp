#include "ArbreHeap.h"

ArbreHeap::ArbreHeap()
{
}

// Fonction Heapify : elle permet de réajuster l'arbre pour qu'il respecte la propriété d'un tas (heap)
void ArbreHeap::Heapify(int index)
{
    int taille = donnees.size(); // Taille du vecteur qui contient les éléments du tas
    int plusGrand = index; // On suppose initialement que le plus grand est à l'index actuel
    int gauche = 2 * index + 1; // Calcul de l'index du fils gauche
    int droite = 2 * index + 2; // Calcul de l'index du fils droit

    // Vérifie si le fils gauche existe et s'il est plus grand que le noeud actuel
    if (gauche < taille && donnees[gauche] > donnees[plusGrand]) {
        plusGrand = gauche;
    }

    // Vérifie si le fils droit existe et s'il est plus grand que le noeud actuel (ou le fils gauche si déjà mis à jour)
    if (droite < taille && donnees[droite] > donnees[plusGrand]) {
        plusGrand = droite;
    }

    // Si un des fils est plus grand que l'élément actuel, on échange et on continue récursivement
    if (plusGrand != index) {
        std::swap(donnees[index], donnees[plusGrand]);
        Heapify(plusGrand); // Récurse sur le sous-arbre affecté
    }
}

// Fonction d'insertion basique (ajoute simplement l'élément à la fin du vecteur)
void ArbreHeap::Inserer(int valeur)
{
    donnees.push_back(valeur);
}

// Fonction d'insertion qui maintient la propriété de tas (Heap Insert)
void ArbreHeap::InsererHeap(int valeur)
{
    donnees.push_back(valeur); // Ajoute l'élément à la fin du vecteur
    int i = donnees.size() - 1; // Récupère l'index du nouvel élément

    // Remonte dans l'arbre pour assurer la propriété de tas max
    while (i > 0 && donnees[(i - 1) / 2] < donnees[i]) {
        std::swap(donnees[i], donnees[(i - 1) / 2]); // Échange avec le parent si nécessaire
        i = (i - 1) / 2; // Remonte à la position du parent
    }
}

// Fonction de suppression de la racine dans le tas max
void ArbreHeap::SuprimerHeap()
{
    if (donnees.empty()) return; // Vérifie si l'arbre est vide

    donnees[0] = donnees.back(); // Remplace la racine par le dernier élément
    donnees.pop_back(); // Supprime l'ancien dernier élément
    Heapify(0); // Réajuste l'arbre en appliquant Heapify depuis la racine
}

// Fonction qui retourne la racine (élément maximum du tas max)
int ArbreHeap::TrouverRacine()
{
    if (!donnees.empty()) {
        return donnees[0]; // La racine est toujours à l'index 0 dans un tas max
    }
    throw std::runtime_error("Arbre vide"); // Erreur si l'arbre est vide
}
