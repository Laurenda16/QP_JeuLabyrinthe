#include"terrain.h"
#include"robot.h"

void PledgeAlgorithm(robot& robot) {
    int turnCount = 0;
    terrain t=(robot.terain());
    while (!(robot.positionRobot() == t.caseArrivee())) {
        if (turnCount == 0 && robot.detecterObstacle()) {
            continue;
        }

        robot.tounerAGauche();
        ++turnCount;

        if (!robot.detecterObstacle()) {
            robot.tounerADroite();
            turnCount -= 1; // Droite = -1
            if (!robot.detecterObstacle()) {
                robot.tounerADroite();
                turnCount -= 1;
            }
        }
    }
}

