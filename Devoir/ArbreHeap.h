#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class ArbreHeap
{
private:
	std::vector<int> donnees;
public:
	ArbreHeap();
	void Heapify(int);
	void Inserer(int);
	void InsererHeap(int);
	void SuprimerHeap();
	int TrouverRacine();
};

