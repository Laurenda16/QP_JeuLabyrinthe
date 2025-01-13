#include "doctest.h"
#include"terrain.h"
#include"robot.h"

TEST_CASE("V�rification des donn�es de sortie du robot") {
    terrain t;
    position p{1,2};
    t.redimensionne(10, 10);  // Cr�e un terrain 10x10
    t.definitCaseDepart(p);  // D�finit la position de d�part du robot

    robot monRobot(t);
    observateurRobot obs;

    // D�place le robot vers l'est pour que la direction soit 'E'
    monRobot.tournerADroite();

    // V�rifie le message de sortie
    std::string message_sortie = obs.message(monRobot);
    REQUIRE_EQ(message_sortie, "Le robot est en position x : 2 position y: 1 direction: >\n");
}
