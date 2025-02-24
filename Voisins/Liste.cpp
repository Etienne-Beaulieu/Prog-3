#include "Liste.h"

Liste::Liste()
{
	m_premier = nullptr;
}

Liste::~Liste()
{
	Noeud* deleteptr = m_premier;
	while (deleteptr != nullptr)
	{
		Noeud* temp = deleteptr;
		deleteptr = deleteptr->suivant;
		delete temp;
	}
}

void Liste::Ajouter(int donnee)
{
	Noeud* nouveau = new Noeud{donnee, nullptr};
	// Méthode longue
	nouveau->donnee = donnee;

	if (m_premier == nullptr)
	{
		m_premier = nouveau;
	}
	else
	{
		Noeud* iterateur = m_premier;
		while (iterateur->suivant != nullptr)
		{
			iterateur = iterateur->suivant;
		}
		iterateur->suivant = nouveau;
	}
}
