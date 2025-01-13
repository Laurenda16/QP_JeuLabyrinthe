#include "doctest.h"
#include"terrain.h"
#include"robot.h"

TEST_CASE("Vérification des données de sortie du robot") {
    terrain t;
    position p{1,2};
    t.redimensionne(10, 10);  // Crée un terrain 10x10
    t.definitCaseDepart(p);  // Définit la position de départ du robot

    robot monRobot(t);
    observateurRobot obs;

    // Déplace le robot vers l'est pour que la direction soit 'E'
    monRobot.tournerADroite();

    // Vérifie le message de sortie
    std::string message_sortie = obs.message(monRobot);
    REQUIRE_EQ(message_sortie, "Le robot est en position x : 2 position y: 1 direction: >\n");
}
