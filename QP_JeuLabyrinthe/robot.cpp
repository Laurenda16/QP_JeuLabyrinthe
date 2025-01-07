#include "robot.h"
#include "terrain.h"
#include "affichage.h"
#include <cstdlib>
#include "chrono"
#include"thread"
#include <iostream>



robot::robot( const terrain& t) : d_pos{t.caseDepart()}, d_direction{'N'}, t{t} {}

position robot::positionXY() const {
    return d_pos;
}

char robot::direction() const {
    switch (d_direction) {
        case 'N': return '^';
        case 'E': return '>';
        case 'S': return 'v';
        case 'W': return '<';
        default: return '?';
    }
}
int robot::nombreDeplacement() const
{
    return d_nombreDeplacement;
}

terrain robot::terain() const{
    return t;
}
void robot::avanceUneCase() {
    if (d_direction == 'E' &&  !detecterObstacle()) d_pos.colonne++;
    else if (d_direction == 'S' && !detecterObstacle()) d_pos.ligne++;
    else if (d_direction == 'W' && !detecterObstacle()) d_pos.colonne--;
    else if (d_direction == 'N' && !detecterObstacle()) d_pos.ligne--;
    notifierObservation();
    afficherTerrainAvecRobot();
}

void robot::tournerAGauche() {

    d_direction = (d_direction == 'N') ? 'W' : (d_direction == 'W') ? 'S' : (d_direction == 'S') ? 'E' : 'N';
    notifierObservation();
    afficherTerrainAvecRobot();

}

void robot::tournerADroite() {
    d_direction = (d_direction == 'N') ? 'E' : (d_direction == 'E') ? 'S' : (d_direction == 'S') ? 'W' : 'N';
    notifierObservation();
    afficherTerrainAvecRobot();

}

bool robot::detecterObstacle() const {
    position pos = d_pos;

    switch (d_direction) {
        case 'N': pos.ligne--; break;
        case 'E': pos.colonne++; break;
        case 'S': pos.ligne++; break;
        case 'W': pos.colonne--; break;
    }
    return t.tableau()[pos.ligne][pos.colonne] == TypeCase::MUR;
}

void robot::notifierObservation() {
    for (auto ob : d_observateurs) {
        ob.notifie(*this);
    }
}

void robot::enregistrerObservateur(const observateurRobot& ob) {
    d_observateurs.push_back(ob);
}

#include <iostream>
using namespace std;

void robot::afficherTerrainAvecRobot() {
    system("cls");  // Efface l'écran (Windows)

    // Affichage du menu
    cout << "Les types de choix :\n"
         << "A: tableau amélioré;\n"
         << "B: tableau simple\n";

    char choix;
    cout << "Quel est votre choix : ";
    cin >> choix;

    // Switch pour gérer le choix de l'utilisateur
    switch(choix) {
        case 'A': {
            affichageAmelioree aff;  // Création d'un objet d'affichage amélioré
            aff.affiche(std::cout, t, *this);  // Affichage du terrain avec robot
            break;
        }
        case 'B': {
            affichageSimple aff;  // Création d'un objet d'affichage simple
            aff.affiche(std::cout, t, *this);  // Affichage du terrain avec robot
            break;
        }
        default: {
            cout << "Choix invalide, affichage par défaut : tableau simple.\n";
            affichageSimple aff;  // Affichage simple par défaut
            aff.affiche(std::cout, t, *this);  // Affichage du terrain avec robot
            break;
        }
    }
     std::this_thread::sleep_for(std::chrono::seconds(80));
}


bool robot::tournerEtAvancerAGauchePossible() {
    char ancienneDirection = d_direction;
    tournerAGauche();  // On tourne à gauche
    bool possible = !detecterObstacle();  // Si on peut avancer après avoir tourné à gauche, c'est possible
    d_direction = ancienneDirection;  // Restauration de la direction initiale
    return possible;
}

void robot::algorithmDeMainDroite() {
    int casesParcourues = 0;
    while (true) {
        tournerADroite();
        if (!detecterObstacle()) {
            avanceUneCase();
        } else {
            tournerAGauche();
            if (!detecterObstacle()) {
                avanceUneCase();
            } else {
                tournerAGauche();
            }
        }
        casesParcourues++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (positionXY() == terain().caseArrivee()) {
            std::cout << "Le robot a atteint la sortie !" << "\nNombre de cases parcourues : " << casesParcourues << std::endl;
            break;
        }
    }
}


void robot::algorithmeDePledge() {
    int compteurPledge = 0;
    int casesParcourues = 0;

    while (d_pos.ligne != t.caseArrivee().ligne || d_pos.colonne != t.caseArrivee().colonne) {
        if (compteurPledge == 0) {
            if (!detecterObstacle()) {
                avanceUneCase();
            } else {
                tournerADroite();
                compteurPledge--;
            }
        } else {
            if (tournerEtAvancerAGauchePossible()) {
                tournerAGauche();
                compteurPledge++;
                avanceUneCase();
            } else if (!detecterObstacle()) {
                avanceUneCase();
            } else {
                tournerADroite();
                compteurPledge--;
            }
        }

        casesParcourues++;

        afficherTerrainAvecRobot();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "Le robot a atteint la sortie !" << "\nNombre de cases parcourues : " << casesParcourues << std::endl;
}




