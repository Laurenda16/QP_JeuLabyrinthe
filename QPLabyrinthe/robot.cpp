#include "robot.h"
#include "terrain.h"
#include "affichage.h"
#include <cstdlib>
#include "chrono"
#include"thread"
#include <iostream>



robot::robot( const terrain& ter) : d_pos{ter.caseDepart()}, d_direction{'N'}, t{ter} {}

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

std::vector<observateurRobot> robot::observateurs() const
{
    return d_observateurs;
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
}

void robot::tournerAGauche() {

    d_direction = (d_direction == 'N') ? 'W' : (d_direction == 'W') ? 'S' : (d_direction == 'S') ? 'E' : 'N';
    notifierObservation();

}

void robot::tournerADroite() {
    d_direction = (d_direction == 'N') ? 'E' : (d_direction == 'E') ? 'S' : (d_direction == 'S') ? 'W' : 'N';
    notifierObservation();
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
    for (auto& ob : d_observateurs) {
        ob.notifie(*this);
    }
}

void robot::enregistrerObservateur(const observateurRobot& ob) {
    d_observateurs.push_back(ob);
}


bool robot::tournerEtAvancerAGauchePossible() {
    char ancienneDirection = d_direction;
    tournerAGauche();
    bool possible = !detecterObstacle();
    d_direction = ancienneDirection;
    return possible;
}


void robot::algorithmDeMainDroite(affichage& aff) {
    int casesParcourues = 0;
    while (true) {
        tournerADroite();
        if (!detecterObstacle()) {
            avanceUneCase();
        }
        else {
            tournerAGauche();

            if (detecterObstacle()) {
                tournerAGauche();
            }
            else {
                avanceUneCase();
            }
        }
        casesParcourues++;
        notifierObservation();
        if (positionXY() == terain().caseArrivee()) {
            std::cout << "Le robot a atteint la sortie !" << "\nNombre de cases parcourues : " << casesParcourues << std::endl;
            break;
        }

        system("cls");
        aff.affiche(std::cout,t, *this);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}



void robot::algorithmeDePledge(affichage& aff) {
    int compteurPledge = 0;
    int casesParcourues = 0;

    while (d_pos.ligne != t.caseArrivee().ligne || d_pos.colonne != t.caseArrivee().colonne) {
        if (compteurPledge == 0) {
            if (!detecterObstacle()) {
                avanceUneCase();
            }
            else {
                tournerADroite();
                compteurPledge--;
            }
        }
        else {
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
        notifierObservation();
        system("cls");
        aff.affiche(std::cout,t, *this);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "Le robot a atteint la sortie !" << "\nNombre de cases parcourues : " << casesParcourues << std::endl;
}




