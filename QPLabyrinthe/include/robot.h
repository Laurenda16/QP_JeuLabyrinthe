#ifndef ROBOT_H
#define ROBOT_H
#include <memory>
#include <vector>
#include "affichage.h"
#include "terrain.h"
#include "observateurRobot.h"

class robot {
public:
    robot(const position& pos, char direction, const terrain& t);
    position positionXY() const;
    char direction() const;
    void avanceUneCase();
    void tournerAGauche();
    void tournerADroite();
    bool detecterObstacle() const;
    void notifierObservation() const;
    void enregistrerObservateur(const observateurRobot& ob);

private:
    position d_pos;
    char d_direction;  // N, E, S, W
    const terrain& t;
    std::vector<observateurRobot> d_observateurs;

};
#endif // ROBOT_H

