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

void robot::afficherTerrainAvecRobot() {
    // Efface l'écran (cela dépend du système, ici pour Windows)
    system("cls"); // Si vous êtes sous Windows
    //system("clear"); // Si vous êtes sous Linux/Unix/Mac

    // Déplace le curseur à la position du robot (r.positionXY().colonne, r.positionXY().ligne)
    //goto_xy(positionXY().colonne, positionXY().ligne);

    affichageSimple affichage;
    affichage.affiche(std::cout, t, *this); // Affichage du terrain avec le robot à sa position
}

bool robot::tournerEtAvancerAGauchePossible() {
    // Vérifier si le robot peut tourner à gauche en détectant un mur ou non
    char ancienneDirection = d_direction;
    tournerAGauche();  // On tourne à gauche
    bool possible = !detecterObstacle();  // Si on peut avancer après avoir tourné à gauche, c'est possible
    d_direction = ancienneDirection;  // Restauration de la direction initiale
    return possible;
}

void robot::algorithmDeMainDroite() {
    while (true) {
        // Tourner à droite pour vérifier si le chemin est libre
        tournerADroite();
        if (!detecterObstacle()) {
            // Si pas d'obstacle à droite, avancer dans cette direction
            avanceUneCase();
        } else {
            // Sinon, revenir à la direction initiale (tourner à gauche)
            tournerAGauche();
            if (!detecterObstacle()) {
                // Si pas d'obstacle devant, avancer
                avanceUneCase();
            } else {
                // Sinon, tourner encore à gauche pour suivre le mur
                tournerAGauche();
            }
        }

        // Pause pour visualiser les étapes
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Notifier l'observation et afficher la position
        notifierObservation();

        // Vérifier si le robot a atteint la sortie
        if (positionXY() == terain().caseArrivee()) {
            std::cout << "Le robot a atteint la sortie !" << std::endl;
            break;
        }
    }
}

/*void robot::algorithmDeMainDroite() {
    while (true) {
        std::cout << "Position actuelle : " << d_pos.ligne << ", " << d_pos.colonne << " | Direction : " << direction << std::endl;

        tournerADroite();
        std::cout << "Tourne à droite. Nouvelle direction : " << direction << std::endl;

        if (!detecterObstacle()) {
            std::cout << "Pas d'obstacle. Avance une case." << std::endl;
            avanceUneCase();
        } else {
            tournerAGauche();
            std::cout << "Obstacle détecté. Tourne à gauche. Nouvelle direction : " << direction << std::endl;

            if (!detecterObstacle()) {
                avanceUneCase();
            } else {
                tournerAGauche();
                std::cout << "Obstacle toujours présent. Tourne à gauche encore." << std::endl;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (positionXY() == terrain().caseArrivee()) {
            std::cout << "Le robot a atteint la sortie !" << std::endl;
            break;
        }
    }
}*/


void robot::algorithmeDePledge() {
    int compteurPledge = 0;  // Compteur pour suivre les rotations
    int casesParcourues = 0;

    // Tant que le robot n'a pas atteint la case d'arrivée
    while (d_pos.ligne != t.caseArrivee().ligne || d_pos.colonne != t.caseArrivee().colonne) {
        // Si le compteur est à 0, avance dans la direction globale
        if (compteurPledge == 0) {
            if (!detecterObstacle()) {
                avanceUneCase();
            } else {
                tournerADroite();
                compteurPledge--;
            }
        } else {
            // Sinon, continue à suivre le mur
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

        // Affiche la position actuelle du robot
        afficherTerrainAvecRobot();

        // Pause pour visualiser les étapes (facultatif)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    // Le robot a atteint la sortie
    std::cout << "Le robot a atteint la sortie !" << "\nNombre de cases parcourues : " << casesParcourues << std::endl;
}




