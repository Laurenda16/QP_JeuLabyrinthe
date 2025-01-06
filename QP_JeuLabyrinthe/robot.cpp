#include "robot.h"
#include "terrain.h"
#include "affichage.h"
robot::robot(const position& pos, char direction, const terrain& t) : d_pos{pos}, d_direction{direction}, t{t} {}

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

void robot::avanceUneCase() {
    if (d_direction == 'E' && d_pos.colonne < t.caseArrivee().colonne) d_pos.colonne++;
    else if (d_direction == 'S' && d_pos.ligne < t.caseArrivee().ligne) d_pos.ligne++;
    else if (d_direction == 'W' && d_pos.colonne > 0) d_pos.colonne--;
    else if (d_direction == 'N' && d_pos.ligne > 0) d_pos.ligne--;

    /*switch (d_direction) {
        case 'N': d_pos.ligne--; break;
        case 'E': d_pos.colonne++; break;
        case 'S': d_pos.ligne++; break;
        case 'W': d_pos.colonne--; break;
    }*/
    notifierObservation();
    //afficherTerrainAvecRobot(t, *this);
}

void robot::tournerAGauche() {
    d_direction = (d_direction == 'N') ? 'W' : (d_direction == 'W') ? 'S' : (d_direction == 'S') ? 'E' : 'N';
    notifierObservation();
    //afficherTerrainAvecRobot(t, *this);
}

void robot::tournerADroite() {
    d_direction = (d_direction == 'N') ? 'E' : (d_direction == 'E') ? 'S' : (d_direction == 'S') ? 'W' : 'N';
    notifierObservation();
    //afficherTerrainAvecRobot(t, *this);
}

bool robot::detecterObstacle() const {
    position pos = d_pos;
    switch (d_direction) {
        case 'N': pos.ligne--; break;
        case 'E': pos.colonne++; break;
        case 'S': pos.ligne++; break;
        case 'W': pos.colonne--; break;
    }
    return !t.estCaseValide(pos) || t.tableau()[pos.ligne][pos.colonne] == TypeCase::MUR;
}

void robot::notifierObservation() const {
    for (auto ob : d_observateurs) {
        ob.notifier(d_pos.ligne, d_pos.colonne, d_direction);
    }
}

void robot::enregistrerObservateur(const observateurRobot& ob) {
    d_observateurs.push_back(ob);
}
