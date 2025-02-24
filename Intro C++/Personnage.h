#pragma once

#include <string>

using namespace std;

class Personnage
{
private:
	int str;
	int dex; 
	int con;
	int intel;
	int wis;
	int cha;
public:
	string nom;
	Personnage(string nom);
	void GenererStats();
};

