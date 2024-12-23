#include <istream>
#include <ostream>
#include "observateurRobot.h"
#include"string"

#include "robot.h"

<<<<<<< HEAD
void observateur::notifie(const robot& r) const
{
    std::string message = "Le robot est en position x : " + std::to_string(r.positionRobot().x)
    + " position y: " + std::to_string(r.positionRobot().y)
    + "direction: " + r.direction() + '\n';
    cout<<message;
}

int observateurRobot:: nombreDeplacement() const
{
=======
observateurRobot::observateurRobot():
    d_nombreDeplacement{0}
{}

void observateurRobot::notifie(const robot& r) const{
    d_nombreDeplacement++;
    std::cout << "Le robot est en position x : "<<r.positionRobot().x <<" position y: "<<r.positionRobot().y;
    std::cout<< "direction: " << r.direction() << "\n";
  }

int observateurRobot::nombreDeplacement() const{
>>>>>>> 2a412998c24f00e23630e0da3c919839339e0b2d
    return d_nombreDeplacement;
}



