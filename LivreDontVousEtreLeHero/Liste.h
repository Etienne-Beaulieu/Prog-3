#pragma once

#include "Noeud.h"

class Liste
{
private:
	Noeud* m_premier;
	Noeud* m_dernier;
public:
	Liste();
	~Liste();
	void Ajouter(Infos);
	void AssignerPtr(Infos);
	void Afficher();
	Noeud* TrouverNoeudDepart();
	Noeud* TrouverNoeud(int id);
};

