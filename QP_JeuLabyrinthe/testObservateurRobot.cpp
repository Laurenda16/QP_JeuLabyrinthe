#include "doctest.h"
#include"terrain.h"
#include"robot.h"



TEST_CASE("Vérification des données de sortie du robot ") {
    terrain t;
    position p;
    p.colonne = 1;
    p.ligne = 2;
    robot monRobot(t);
    observateurRobot obs;
    std::string message_sortie = obs.message(monRobot);
    REQUIRE_EQ(message_sortie, "Le robot est en position x : 1  position y: 2 direction: E");
}
