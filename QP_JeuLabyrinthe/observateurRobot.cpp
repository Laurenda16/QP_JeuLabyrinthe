#include <istream>
#include <iostream>
#include "observateurRobot.h"

/*observateurRobot::observateurRobot():
    d_nombreDeplacement{0}
{}

void observateurRobot::notifier(int x, int y, char direction) {
    d_nombreDeplacement++;
    std::cout << "Déplacement " << d_nombreDeplacement << ": Position (" << x << ", " << y << ") Direction: " << direction << std::endl;
}

int observateurRobot::nombreDeplacement() const {
    return d_nombreDeplacement;
}
*/



std::string observateurRobot::message(const robot& r) const
{
     return "Le robot est en position x : " + std::to_string(r.positionXY().colonne)
            + " position y: " + std::to_string(r.positionXY().ligne)
            + "direction: " + r.direction() + '\n';

}


void observateurRobot::notifie(const robot& r) const
{
   std::cout << message(r);

}
