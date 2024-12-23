#include <istream>
#include <ostream>
#include "observateurRobot.h"
#include"string"

#include "robot.h"

void observateur::notifie(const robot& r) const
{
    std::string message = "Le robot est en position x : " + std::to_string(r.positionRobot().x)
    + " position y: " + std::to_string(r.positionRobot().y)
    + "direction: " + r.direction() + '\n';
    cout<<message;
}



