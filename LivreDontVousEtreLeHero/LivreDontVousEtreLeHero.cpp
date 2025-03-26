// LivreDontVousEtreLeHero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Liste.h"
#include "RessourceLoader.h"

int main()
{
    RessourceLoader ressourceLoader("histoire.csv");
    Liste liste;

    ressourceLoader.RemplirListe(liste);

    Noeud* courrant = liste.TrouverNoeudDepart();

    if (courrant == nullptr)
    {
        std::cout << "Erreur: Aucun point de depart trouve.\n";
        return 1;
    }

    while (courrant != nullptr)
    {
        std::cout << "\n" << courrant->infos.texte << "\n";

        if (courrant->infos.indicateur == 'f')
        {
            std::cout << "Fin de l'histoire.\n";
            break;
        }

        int choix;
        std::cout << "Votre choix (1 ou 2): ";
        std::cin >> choix;

        if (choix == 1)
            courrant = liste.TrouverNoeud(courrant->infos.choix1);
        else if (choix == 2)
            courrant = liste.TrouverNoeud(courrant->infos.choix2);
        else
            std::cout << "Choix invalide.\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
