#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <vector>
#include <cstdint>

class Labyrinthe {
public:
    Labyrinthe(uint16_t nbCases, uint16_t debut, uint16_t fin);

    void ajouterLien(uint16_t a, uint16_t b);
    const std::vector<uint16_t>& getVoisins(uint16_t caseId) const;

    uint16_t getDebut() const;
    uint16_t getFin() const;
    uint16_t getNbCases() const;

private:
    uint16_t nbCases;
    uint16_t debut;
    uint16_t fin;
    std::vector<std::vector<uint16_t>> liensVoisins;
};

#endif