#include <istream>
#include <ostream>
#include "observateurRobot.h"




 void observateurRobot::notifier(const position& p, char direction){
    d_nombreDeplacement++;
    std::cout << "Déplacement: Position (" << p.x << ", " << p.y << ") Direction: " << direction << std::endl

  }
int observateurRobot::nombreDeplacement() const
{

    return d_nombreDeplacement;
}


