#include <iostream>
#include "observateurRobot.h"
#include"robot.h"

class robot;
using namespace std;
class observateurRobot;




string observateurRobot::message(robot& r) const
{
     return "Le robot est en position x : " + to_string(r.positionXY().colonne)
            + " position y: " + to_string(r.positionXY().ligne)
            + " direction: " + r.direction() + "\n";

}


void observateurRobot::notifie(robot& r) const
{
   cout<<message(r);
}

