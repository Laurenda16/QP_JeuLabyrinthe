#include "doctest.h"
#include "observateurRobot.h"

class observateurRobot;


TEST_CASE("Vérification des données de sortie du robot ") {
    robot monRobot(1, 2, "E");
    observateurRobot obs;

    // Construction du message attendu
    std::string message_sortie = "Le robot est en position x : 1 position y: 2 direction: E\n";

    // Test : Construction de la chaîne comme dans la méthode notifie
    std::string message = "Le robot est en position x : " + std::to_string(monRobot.positionRobot().x) +
                          " position y: " + std::to_string(monRobot.positionRobot().y) +
                          " direction: " + monRobot.direction() + "\n";

    // Vérification que la chaîne construite correspond à ce que nous attendons
    REQUIRE_EQ(message, message_sortie);
}
