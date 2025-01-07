#include <iostream>
#include <cstdlib>
#include "robot.h"
#include "terrain.h"
#include "observateurRobot.h"
#include "affichage.h"


int main()
{


   terrain t{};
   t.redimensionne(7, 20);
    for (int i = 0; i < t.hauteur(); ++i) {
        for (int j = 0; j < t.largeur(); ++j) {
            if (i == 0 || i == t.hauteur() - 1 || j == 0 || j == t.largeur() - 1) {
                position    Case{i, j};
                t.modifieCase(Case, TypeCase::MUR);
            }
        }
    }

    for (int j = 8; j <= 11; ++j) {
        position    Case{1, j};
        t.modifieCase(Case, TypeCase::MUR);
    }
    for (int i = 3; i <= 6; ++i) {
        position    Case{i, 3};
        t.modifieCase(Case, TypeCase::MUR);
    }
    for (int i = 4; i <= 6; ++i) {
        position    Case{i, 12};
        t.modifieCase(Case, TypeCase::MUR);
    }
    position depart = {1, 1};
    t.definitCaseDepart(depart);
    position arrivee = {5, 18};
    t.definitCaseArrivee(arrivee);

    robot r{t};

    //affichageSimple Aff;
    //Aff.affiche(std::cout, t);
    r.afficherTerrainAvecRobot();
    r.tournerADroite();
    r.avanceUneCase();
    r.avanceUneCase();
    r.tournerADroite();
    r.avanceUneCase();
    r.avanceUneCase();
    affichageSimple aff;
    t.imprimeSur("terrain.txt", aff);

    //r.tournerAGauche();
    //r.tournerADroite();
    //t.imprimeSur("terrain.tx", Aff);
    //terrain t2{};
    //t2.litDepuis("terrain.tx");
    //Aff.affiche(std::cout, t2,r);
    system("pause");
    return 0;
}
