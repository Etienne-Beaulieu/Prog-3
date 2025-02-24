#pragma once

#include "NoeudListe.h"

class Liste
{
private:
	Noeud* m_premier;
public:
	Liste();
	~Liste();
	void Ajouter(int);
};
