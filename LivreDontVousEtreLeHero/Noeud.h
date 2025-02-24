#pragma once

#include "Infos.h"

struct Noeud
{
	Infos infos;
	Noeud* choix1;
	Noeud* choix2;
	Noeud* suivant;
	Noeud* precedent;
};

