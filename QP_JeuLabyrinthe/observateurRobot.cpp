#include <istream>
#include <ostream>
#include "observateurRobot.h"

#include "robot.h"

void observateur::notifie(const robot& r) const
{
    std::cout << "Le robot est en position x : "<<r.positionRobot().x <<" position y: "<<r.positionRobot().y;
    std::cout<< "direction: " << r.direction() << "\n";
}



