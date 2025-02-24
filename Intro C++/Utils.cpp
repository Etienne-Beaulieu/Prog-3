#include "Utils.h"

void swap(std::vector<int> tabNombre, int index1, int index2)
{
	int temp = tabNombre[index1];
	tabNombre[index1] = tabNombre[index2];
	tabNombre[index2] = temp;
}
