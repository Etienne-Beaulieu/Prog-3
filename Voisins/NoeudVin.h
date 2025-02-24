#pragma once

#include "Vin.h"

// Dans le cadre du cours
// On utilise les structs dans une classe pour les encapsuler
struct NoeudVin
{
	Vin donnee;
	NoeudVin* suivant;
};
