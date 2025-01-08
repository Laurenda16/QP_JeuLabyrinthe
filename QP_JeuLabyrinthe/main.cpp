#include <iostream>
#include <cstdlib>
#include "robot.h"
#include "terrain.h"
#include "observateurRobot.h"
#include "affichage.h"


void afficherMenu() {
    std::cout << "=== Menu ===" << std::endl;
    std::cout << "1. Algorithme de la main droite" << std::endl;
    std::cout << "2. Algorithme de Pledge" << std::endl;
    std::cout << "=== Choix d'affichage ===" << std::endl;
    std::cout << "A. Affichage Amélioré" << std::endl;
    std::cout << "B. Affichage Simple" << std::endl;
    std::cout << "C. Pas d'affichage (Exécution rapide)" << std::endl;
}




int main()
{


    terrain t{};
    t.redimensionne(10, 20);

    // Création des murs extérieurs
    for (int i = 0; i < t.hauteur(); ++i) {
        for (int j = 0; j < t.largeur(); ++j) {
            if (i == 0 || i == t.hauteur() - 1 || j == 0 || j == t.largeur() - 1) {
                position Case{i, j};
                t.modifieCase(Case, TypeCase::MUR);
            }
        }
    }

    // Création de murs internes pour former un labyrinthe fonctionnel
    // Couloir horizontal
    for (int j = 3; j <= 10; ++j) {
        position Case{2, j};
        t.modifieCase(Case, TypeCase::MUR);
    }

    // Couloir vertical 1
    for (int i = 2; i <= 8; ++i) {
        position Case{i, 6};
        t.modifieCase(Case, TypeCase::MUR);
    }

    // Couloir horizontal inférieur
    for (int j = 8; j <= 15; ++j) {
        position Case{7, j};
        t.modifieCase(Case, TypeCase::MUR);
    }

    // Couloir vertical 2
    for (int i = 4; i <= 6; ++i) {
        position Case{i, 12};
        t.modifieCase(Case, TypeCase::MUR);
    }

    // Mur bloquant près de l'arrivée
    for (int i = 6; i <= 8; ++i) {
        position Case{i, 16};
        t.modifieCase(Case, TypeCase::MUR);
    }

    // Définir la case de départ et la case d'arrivée
    position depart = {1, 1};
    t.definitCaseDepart(depart);
    position arrivee = {8, 18};
    t.definitCaseArrivee(arrivee);

    affichageAmelioree aff;
    t.imprimeSur("terrain.txt", aff);

    robot r{t};
    system("cls");
    /*//affichageAmelioree affichage;
    //affichage.affiche(std::cout, t, *this);
    //affichageSimple Aff;
    //Aff.affiche(std::cout, t);
    //affichageAmelioree aff;
    //aff.affiche(std::cout, t, r);
    r.afficherTerrainAvecRobot();
    r.tournerADroite();
    r.avanceUneCase();
    r.avanceUneCase();
    r.tournerADroite();
    r.avanceUneCase();
    r.avanceUneCase();
    //affichageSimple aff;
    //r.algorithmDeMainDroite();
    //r.algorithmeDePledge();

    //r.tournerAGauche();
    //r.tournerADroite();
    //t.imprimeSur("terrain.tx", Aff);
    //terrain t2{};
    //t2.litDepuis("terrain.tx");
    //Aff.affiche(std::cout, t2,r);*/

      // Choix de l'affichage
    int choixAffichage;
    std::cout << "Choisissez le type d'affichage:\n";
    std::cout << "1. Affichage simple\n";
    std::cout << "2. Affichage améliore\n";
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

    // Afficher le terrain avec le robot
    affichageChoisi->affiche(std::cout, t, r);

    // Choix de l'algorithme
    int choixAlgo;
    std::cout << "Choisissez l'algorithme à exécuter:\n";
    std::cout << "1. Algorithme de Pledge\n";
    std::cout << "2. Algorithme de Main Droite\n";
    std::cout << "Entrez votre choix: ";
    std::cin >> choixAlgo;

    if (choixAlgo == 1) {
        std::cout << "Exécution de l'algorithme de Pledge..." << std::endl;
        r.algorithmeDePledge(*affichageChoisi);  // Algorithme de Pledge
      } else if (choixAlgo == 2) {
        std::cout << "Exécution de l'algorithme de Main Droite..." << std::endl;
        r.algorithmDeMainDroite(*affichageChoisi);  // Algorithme de Main Droite
    } else {
        std::cout << "Choix invalide, aucun algorithme exécuté." << std::endl;
    }

    // Imprimer le terrain dans un fichier après l'exécution de l'algorithme
    t.imprimeSur("terrain_final.txt", *affichageChoisi);

    // Libérer la mémoire allouée pour l'affichage
    delete affichageChoisi;

    // Pause pour que l'utilisateur puisse voir le résultat

    system("pause");
    return 0;
}

