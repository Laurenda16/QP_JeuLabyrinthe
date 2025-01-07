#include "robot.h"
#include "terrain.h"
#include "affichage.h"
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

void robot::notifierObservation() const {
    for (auto ob : d_observateurs) {
        ob.notifier(d_pos.ligne, d_pos.colonne, d_direction);
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
