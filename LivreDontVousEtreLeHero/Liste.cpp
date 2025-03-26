#include <iostream>

#include "Liste.h"

Liste::Liste()
{
	m_premier = nullptr;
	m_dernier = nullptr;
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

void Liste::Ajouter(Infos infos)
{
	Noeud* nouveau = new Noeud{infos, nullptr, nullptr, nullptr, nullptr};

	if (m_premier == nullptr)
	{
		m_premier = nouveau;
		m_dernier = nouveau;
	}

	else
	{
		m_dernier->suivant = nouveau;
		nouveau->precedent = m_dernier;
		m_dernier = nouveau;
	}
}

void Liste::AssignerPtr(Infos infos)
{
	Noeud* iterateur = m_premier;

	while (iterateur != nullptr)
	{
		if (iterateur->infos.id == infos.id)
		{
			Noeud* temp = m_premier;

			while (temp != nullptr)
			{
				if (temp->infos.id == iterateur->infos.choix1)
				{
					iterateur->choix1 = temp;
				}

				if (temp->infos.id == iterateur->infos.choix2)
				{
					iterateur->choix2 = temp;
				}

				temp = temp->suivant;
			}
		}

		iterateur = iterateur->suivant;
	}
}

void Liste::Afficher()
{
	Noeud* iterateur = m_premier;

	while (iterateur != nullptr)
	{
		std::cout << "ID: " << iterateur->infos.id << "\n";
		std::cout << "Choix1: " << (iterateur->choix1 ? std::to_string(iterateur->choix1->infos.id) : "None") << "\n";
		std::cout << "Choix2: " << (iterateur->choix2 ? std::to_string(iterateur->choix2->infos.id) : "None") << "\n";
		std::cout << "------------------\n";

		iterateur = iterateur->suivant;
	}
}

Noeud* Liste::TrouverNoeud(int id)
{
	Noeud* courant = m_premier;
	while (courant != nullptr)
	{
		if (courant->infos.id == id)
			return courant;
		courant = courant->suivant;
	}
	return nullptr;
}

Noeud* Liste::TrouverNoeudDepart()
{
	Noeud* courant = m_premier;
	while (courant != nullptr)
	{
		if (courant->infos.indicateur == 'd')
			return courant;
		courant = courant->suivant;
	}
	return nullptr;
}