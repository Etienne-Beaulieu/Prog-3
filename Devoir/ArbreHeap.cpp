#include "ArbreHeap.h"

ArbreHeap::ArbreHeap()
{
}

// Fonction Heapify : elle permet de r�ajuster l'arbre pour qu'il respecte la propri�t� d'un tas (heap)
void ArbreHeap::Heapify(int index)
{
    int taille = donnees.size(); // Taille du vecteur qui contient les �l�ments du tas
    int plusGrand = index; // On suppose initialement que le plus grand est � l'index actuel
    int gauche = 2 * index + 1; // Calcul de l'index du fils gauche
    int droite = 2 * index + 2; // Calcul de l'index du fils droit

    // V�rifie si le fils gauche existe et s'il est plus grand que le noeud actuel
    if (gauche < taille && donnees[gauche] > donnees[plusGrand]) {
        plusGrand = gauche;
    }

    // V�rifie si le fils droit existe et s'il est plus grand que le noeud actuel (ou le fils gauche si d�j� mis � jour)
    if (droite < taille && donnees[droite] > donnees[plusGrand]) {
        plusGrand = droite;
    }

    // Si un des fils est plus grand que l'�l�ment actuel, on �change et on continue r�cursivement
    if (plusGrand != index) {
        std::swap(donnees[index], donnees[plusGrand]);
        Heapify(plusGrand); // R�curse sur le sous-arbre affect�
    }
}

// Fonction d'insertion basique (ajoute simplement l'�l�ment � la fin du vecteur)
void ArbreHeap::Inserer(int valeur)
{
    donnees.push_back(valeur);
}

// Fonction d'insertion qui maintient la propri�t� de tas (Heap Insert)
void ArbreHeap::InsererHeap(int valeur)
{
    donnees.push_back(valeur); // Ajoute l'�l�ment � la fin du vecteur
    int i = donnees.size() - 1; // R�cup�re l'index du nouvel �l�ment

    // Remonte dans l'arbre pour assurer la propri�t� de tas max
    while (i > 0 && donnees[(i - 1) / 2] < donnees[i]) {
        std::swap(donnees[i], donnees[(i - 1) / 2]); // �change avec le parent si n�cessaire
        i = (i - 1) / 2; // Remonte � la position du parent
    }
}

// Fonction de suppression de la racine dans le tas max
void ArbreHeap::SuprimerHeap()
{
    if (donnees.empty()) return; // V�rifie si l'arbre est vide

    donnees[0] = donnees.back(); // Remplace la racine par le dernier �l�ment
    donnees.pop_back(); // Supprime l'ancien dernier �l�ment
    Heapify(0); // R�ajuste l'arbre en appliquant Heapify depuis la racine
}

// Fonction qui retourne la racine (�l�ment maximum du tas max)
int ArbreHeap::TrouverRacine()
{
    if (!donnees.empty()) {
        return donnees[0]; // La racine est toujours � l'index 0 dans un tas max
    }
    throw std::runtime_error("Arbre vide"); // Erreur si l'arbre est vide
}
