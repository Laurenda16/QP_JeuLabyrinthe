#include "doctest.h"

#include "observateurRobot.h"
#include "robot.h"

class robot;
class observateurRobot;


TEST_CASE("V�rification des donn�es de sortie du robot ") {
    robot monRobot {1, 2, "E"};
    observateurRobot obs;

    // Construction du message attendu
    std::string message_sortie = "Le robot est en position x : 1 position y: 2 direction: E\n";

    // Test : Construction de la cha�ne comme dans la m�thode notifie
    std::string message = "Le robot est en position x : " + std::to_string(monRobot.positionRobot().x) +
                          " position y: " + std::to_string(monRobot.positionRobot().y) +
                          " direction: " + monRobot.direction() + "\n";

    // V�rification que la cha�ne construite correspond � ce que nous attendons
    REQUIRE_EQ(message, message_sortie);
}
