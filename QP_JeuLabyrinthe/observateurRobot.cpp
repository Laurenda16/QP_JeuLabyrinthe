#include <istream>
#include <ostream>
#include "observateurRobot.h"
#include"string"

#include "robot.h"


observateurRobot::observateurRobot():d_nombreDeplacement{0}
{}

void observateur::notifie(const robot& r) const
{
    std::string message = "Le robot est en position x : " + std::to_string(r.positionRobot().x)
    + " position y: " + std::to_string(r.positionRobot().y)
    + "direction: " + r.direction() + '\n';
    cout<<message;
}

int observateurRobot::nombreDeDeplacement() const{
return d_nombreDeplacement;
}


void observateurRobot::notifie(const robot& r) const{
  nombreDeDeplacement();
    std::cout << "Le robot est en position x : "<<r.positionRobot().x <<" position y: "<<r.positionRobot().y;
    std::cout<< "direction: " << r.direction() << "\n";
  }




