#include <istream>
#include <ostream>
#include "observateurRobot.h"




 void observateurRobot::notifier(int x, int y, char direction)
  {
     // std::cout <<"la postionx "<<x<<"la position y "<<y<< "la direction"<< direction;

  }
int observateurRobot::nombreDeplacement() const
{

    return d_nombreDeplacement;
}


