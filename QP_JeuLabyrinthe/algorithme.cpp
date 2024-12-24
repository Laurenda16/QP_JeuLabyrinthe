
#include"robot.h"
#include"terrain.h"




void algoMainDroite(robot& r) {
    while (true) {
        // Si le robot détecte un obstacle à droite, avancer ou tourner à gauche
        r.tounerADroite(); // Tourner à droite pour vérifier s'il y a un mur
        if (!r.detecterObstacle()) {
            r.avanceUneCase(); // Si pas d'obstacle, avancer
        } else {
            r.tounerAGauche(); // Sinon, retourner à la direction précédente
            if (r.detecterObstacle()) {
                r.tounerAGauche(); // Si un mur est devant, tourner à gauche
            } else {
                r.avanceUneCase(); // Sinon, avancer
            }
        }
        r.notifierObservation(); // Notifier les observateurs du déplacement
        // Condition d'arrêt (exemple : si le robot atteint une position cible)
        if (r.positionRobot().x == caseArrivee().x && r.positionRobot().y == caseArrivee().y)) {
            break; // Fin de l'algorithme si le robot revient à (0, 0)
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

