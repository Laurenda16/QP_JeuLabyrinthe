#include <iostream>
#include <cstdlib>
#include "robot.h"
#include "terrain.h"
#include "observateurRobot.h"
#include "affichage.h"





int main()
{


    terrain t{};
    t.litDepuis("LabyrintheTerrain.txt");
/*
    t.redimensionne(15, 15);

    // Encadrement du terrain avec des murs
    for (int i = 0; i < t.hauteur(); ++i) {
        for (int j = 0; j < t.largeur(); ++j) {
            if (i == 0 || i == t.hauteur() - 1 || j == 0 || j == t.largeur() - 1) {
                position Case{i, j};
                t.modifieCase(Case, TypeCase::MUR);
            }
        }
    }

    // Création de murs internes pour un chemin structuré
    for (int j = 1; j <= 12; ++j) {
        position Case{2, j};
        t.modifieCase(Case, TypeCase::MUR);
    }

    for (int i = 2; i <= 6; ++i) {
        position Case{i, 12};
        t.modifieCase(Case, TypeCase::MUR);
    }

    for (int j = 4; j <= 10; ++j) {
        position Case{6, j};
        t.modifieCase(Case, TypeCase::MUR);
    }

    for (int i = 4; i <= 10; ++i) {
        position Case{i, 4};
        t.modifieCase(Case, TypeCase::MUR);
    }

    for (int j = 6; j <= 13; ++j) {
        position Case{10, j};
        t.modifieCase(Case, TypeCase::MUR);
    }

    for (int i = 10; i <= 13; ++i) {
        position Case{i, 13};
        t.modifieCase(Case, TypeCase::MUR);
    }

    // Définition du point de départ et d'arrivée
    position depart = {1, 1};
    t.definitCaseDepart(depart);
    position arrivee = {12, 12};
    t.definitCaseArrivee(arrivee);
*/

    robot r{t};


    observateurRobot obs;
    r.enregistrerObservateur(obs);

    int choixAffichage;
    std::cout << "Choisissez le type d'affichage:\n";
    std::cout << "1. Affichage simple\n";
    std::cout << "2. Affichage ameliore\n";
    std::cout << "Entrez votre choix: ";
    std::cin >> choixAffichage;

    affichage* affichageChoisi = nullptr;
    if (choixAffichage == 1) {
        affichageChoisi = new affichageSimple();
    } else if (choixAffichage == 2) {
        affichageChoisi = new affichageAmelioree();
    } else {
        std::cout << "Choix invalide, affichage simple par défaut." << std::endl;
        affichageChoisi = new affichageSimple();
    }

    affichageChoisi->affiche(std::cout, t, r);


    int choixAlgo;
    std::cout << "Choisissez l'algorithme à exécuter:\n";
    std::cout << "1. Algorithme de Pledge\n";
    std::cout << "2. Algorithme de Main Droite\n";
    std::cout << "Entrez votre choix: ";
    std::cin >> choixAlgo;

    if (choixAlgo == 1) {
        std::cout << "Exécution de l'algorithme de Pledge..." << std::endl;
        r.algorithmeDePledge(*affichageChoisi);
      } else if (choixAlgo == 2) {
        std::cout << "Exécution de l'algorithme de Main Droite..." << std::endl;
        r.algorithmDeMainDroite(*affichageChoisi);
    } else {
        std::cout << "Choix invalide, aucun algorithme exécuté." << std::endl;
    }

    t.imprimeSur("LabyrintheTerrain.txt", *affichageChoisi);

    delete affichageChoisi;

    system("pause");
    return 0;
}

