#include <istream>
#include <iostream>
#include "observateurRobot.h"

observateurRobot::observateurRobot():
    d_nombreDeplacement{0}
{}

void observateurRobot::notifier(int x, int y, char direction) {
    d_nombreDeplacement++;
    std::cout << "Déplacement " << d_nombreDeplacement << ": Position (" << x << ", " << y << ") Direction: " << direction << std::endl;
}

int observateurRobot::nombreDeplacement() const {
    return d_nombreDeplacement;
}



