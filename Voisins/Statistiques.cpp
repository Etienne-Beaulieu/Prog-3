#include "Statistiques.h"

#include <iostream>
#include <algorithm>
#include <cmath>

int CalculerMoyenne(std::vector<int> resultats)
{
	if (resultats.empty())
	{
		std::cout << "Il n'y a aucun resultats" << std::endl;
	}

	int total{0};

	for (int i = 0; i < resultats.size(); i++)
	{
		total += resultats[i];
	}

	int moyenne = total / resultats.size();

	return moyenne;
}

int CalculerMedianne(std::vector<int> resultats)
{
	if (resultats.empty())
	{
		std::cout << "Il n'y a aucun resultats" << std::endl;
	}

	std::sort(resultats.begin(), resultats.end());

	int medianne{ 0 };

	if (resultats.size() % 2 == 1)
	{
		medianne = resultats[resultats.size() / 2];
	}

	else
	{
		medianne = resultats[resultats.size() / 2 - 1] + resultats[resultats.size() / 2] / 2;
	}

	return medianne;
}

double CalculerEcartType(std::vector<int> resultats)
{
	int moyenne = CalculerMoyenne(resultats);
	double carer = 0;

	for (int i = 0; i < resultats.size(); i++)
	{
		carer += (resultats[i] - moyenne) * (resultats[i] - moyenne);
	}

	double ecart{carer / resultats.size()};

	return ecart;
}

double CalculerDistanceEuclidienne(std::vector<double> pointA, std::vector<double> pointB)
{
	if (pointA.size() != pointB.size())
	{
		std::cout << "Les points n'ont pas les memes dimentions";
	}

	double sommeDistanceCarrer{ 0 };

	for (int i = 0; i < pointA.size(); i++)
	{
		sommeDistanceCarrer += std::pow(pointB[i] - pointA[i], 2);
	}

	return std::sqrt(sommeDistanceCarrer);
}

double CalculerDistanceManhattan(std::vector<double> pointA, std::vector<double> pointB)
{
	if (pointA.size() != pointB.size())
	{
		std::cout << "Les points n'ont pas les memes dimentions";
	}

	double sommeDistance{ 0 };

	for (int i = 0; i < pointA.size(); i++)
	{
		sommeDistance += std::abs(pointB[i] - pointA[i]);
	}

	return sommeDistance;
}