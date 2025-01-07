#include <iostream>
#include "observateurRobot.h"
#include"robot.h"

class robot;
using namespace std;
class observateurRobot;

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



string observateurRobot::message(robot& r) const
{
     return "Le robot est en position x : " + to_string(r.positionXY().colonne)
            + " position y: " + to_string(r.positionXY().ligne)
            + "direction: " + r.direction() + '\n';

}


void observateurRobot::notifie(robot& r) const
{
   cout<<message(r);

}

