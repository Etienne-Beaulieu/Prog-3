#pragma once

#include <vector>

std::vector<int> resultats;

void AfficherResultat();

int CalculerMoyenne(std::vector<int> resultats);

int CalculerMedianne(std::vector<int> resultats);

double CalculerEcartType(std::vector<int> resultats);

double CalculerDistanceEuclidienne(std::vector<double> pointA, std::vector<double> pointB);

double CalculerDistanceManhattan(std::vector<double> pointA, std::vector<double> pointB);
