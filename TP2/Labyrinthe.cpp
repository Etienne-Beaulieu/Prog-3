#include "Labyrinthe.h"

Labyrinthe::Labyrinthe(uint16_t nbCases, uint16_t debut, uint16_t fin)
    : nbCases(nbCases), debut(debut), fin(fin), liensVoisins(nbCases) {}

void Labyrinthe::ajouterLien(uint16_t a, uint16_t b) {
    liensVoisins[a].push_back(b);
    liensVoisins[b].push_back(a);
}

const std::vector<uint16_t>& Labyrinthe::getVoisins(uint16_t caseId) const {
    return liensVoisins[caseId];
}

uint16_t Labyrinthe::getDebut() const { return debut; }
uint16_t Labyrinthe::getFin() const { return fin; }
uint16_t Labyrinthe::getNbCases() const { return nbCases; }
