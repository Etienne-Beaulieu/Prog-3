#pragma once

#include <vector>
#include <string>

#include "Infos.h"
#include "Liste.h"

class RessourceLoader
{
private:
	std::vector<Infos> data;
public:
	RessourceLoader(std::string);
	void Remplir(std::string);
	void Afficher();
	void RemplirListe(Liste&);
};

/*
id : un int
texte : phrase de description
choix1, choix2 : id des paragraphes suivants
indicateur : d = début, f = fin, i = intermédiaire
*/
