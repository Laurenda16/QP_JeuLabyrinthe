#include <istream>
#include <ostream>
#include "observateurRobot.h"

#include "robot.h"

observateurRobot::observateurRobot():
    d_nombreDeplacement{0}
{}

void observateurRobot::notifie(const robot& r) const{
    d_nombreDeplacement++;
    std::cout << "Le robot est en position x : "<<r.positionRobot().x <<" position y: "<<r.positionRobot().y;
    std::cout<< "direction: " << r.direction() << "\n";
  }

int observateurRobot::nombreDeplacement() const{
    return d_nombreDeplacement;
}



