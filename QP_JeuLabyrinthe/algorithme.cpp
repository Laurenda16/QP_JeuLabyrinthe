
#include"robot.h"
#include"terrain.h"




void algoMainDroite(robot& r) {
    while (true) {
        r.tounerADroite();
        if (!r.detecterObstacle()) {
            r.avanceUneCase();
        } else {
            r.tounerAGauche();
            if (r.detecterObstacle()) {
                r.tounerAGauche();
            } else {
                r.avanceUneCase();
            }
        }
        r.notifierObservation();
        if (r.positionRobot().x == caseArrivee().x && r.positionRobot().y == caseArrivee().y)) {
            break;
        }
    }
}


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

