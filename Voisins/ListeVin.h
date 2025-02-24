#pragma once

#include "NoeudVin.h"

class ListeVin
{
private:
	NoeudVin* m_premier;
public:
	ListeVin();
	~ListeVin();
	void Ajouter(Vin);
	void AfficherLinked();
};
