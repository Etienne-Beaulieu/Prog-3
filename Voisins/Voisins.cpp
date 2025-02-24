#include <iostream>
#include "ResourceLoader.h"

int main()
{
    ResourceLoader loader;
    double k = 0.7;
    /*std::vector<Vin> trainData = loader.GetTrainData(k);
    std::vector<Vin> testData = loader.GetTestData(k);

    std::cout << "Nombre d'echantillons d'entrainement: " << trainData.size() << std::endl;
    std::cout << "Nombre d'echantillons de test: " << testData.size() << std::endl;

    loader.Afficher();
    */

    std::cout << "Donnees d'entrainement (Liste chainee):" << std::endl;
    ListeVin trainList = loader.GetTrainDataLinked(k);

    trainList.AfficherLinked();

    std::cout << "Donnees de test (Liste chainee):" << std::endl;
    ListeVin testList = loader.GetTestDataLinked(k);

    return 0;
}
