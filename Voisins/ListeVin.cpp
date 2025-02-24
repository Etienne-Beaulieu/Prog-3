#include <iostream>

#include "ListeVin.h"

ListeVin::ListeVin()
{
	m_premier = nullptr;
}

ListeVin::~ListeVin()
{
	NoeudVin* deleteptr = m_premier;
	while (deleteptr != nullptr)
	{
		NoeudVin* temp = deleteptr;
		deleteptr = deleteptr->suivant;
		delete temp;
	}
}

void ListeVin::Ajouter(Vin donnee)
{
	NoeudVin* nouveau = new NoeudVin{ donnee, nullptr };

	if (m_premier == nullptr)
	{
		m_premier = nouveau;
	}

	else
	{
		NoeudVin* iterateur = m_premier;
		while (iterateur->suivant != nullptr)
		{
			iterateur = iterateur->suivant;
		}
		iterateur->suivant = nouveau;
	}
}



void ListeVin::AfficherLinked()
{
    NoeudVin* current = m_premier;

    while (current != nullptr)
	{

        std::cout << "Acidite Fixe: " << current->donnee.aciditeFixe << ", ";
        std::cout << "Acide Volatile: " << current->donnee.acideVolatile << ", ";
        std::cout << "Acide Citrique: " << current->donnee.acideCitrique << ", ";
        std::cout << "Acide Residuel: " << current->donnee.acideResiduel << ", ";
        std::cout << "Chlorure de Sodium: " << current->donnee.chlorureDeSodium << ", ";
        std::cout << "Dioxyde de Soufre Libre: " << current->donnee.dioxydeDeSoufreLibre << ", ";
        std::cout << "Dioxyde de Soufre Total: " << current->donnee.dioxydeDeSoufreTotal << ", ";
        std::cout << "Densite: " << current->donnee.densite << ", ";
        std::cout << "pH: " << current->donnee.ph << ", ";
        std::cout << "Sulfate de Potassium: " << current->donnee.sulfateDePotassium << ", ";
        std::cout << "Alcool: " << current->donnee.alcool << ", ";
        std::cout << "Bon ou Non: " << current->donnee.bonOuNon << std::endl;

        current = current->suivant;
    }
}

