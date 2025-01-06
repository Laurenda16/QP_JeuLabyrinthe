#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "robot.h"
#include "terrain.h"

TEST_CASE("Test robot mouvement et d�tection d'obstacle") {
    terrain t;
    t.redimensionne(5, 5);
    position dep{0, 0};  // D�part en haut � gauche
    robot r(dep, 'E', t);  // Robot orient� Est

    CHECK(r.positionXY().ligne == 0 && r.positionXY().colonne == 0);

    // Test du mouvement vers la droite (Est)
    r.avanceUneCase();
    CHECK(r.positionXY().ligne == 0 && r.positionXY().colonne == 1);

    // Test de la d�tection d'obstacle (si la case suivante est un mur)
    CHECK(r.detecterObstacle() == false);  // Aucun obstacle sur la case (0,1)

    // Tourner � droite et avancer
    r.tournerADroite();
    r.avanceUneCase();
    CHECK(r.positionXY().ligne == 1 && r.positionXY().colonne == 1);

    // D�placer vers un obstacle
    r.avanceUneCase();  // L'intervalle est une case non d�finie ici
    CHECK(r.detecterObstacle() == true);  //obstacle detecte

}

TEST_CASE("Test robot orientation") {
    terrain t;
    t.redimensionne(5, 5);
    position dep{0, 0};
    robot r(dep, 'N', t);  // Robot orient� Nord

    CHECK(r.direction() == '^');
    r.tournerADroite();
    CHECK(r.direction() == '>');
    r.tournerAGauche();
    CHECK(r.direction() == '^');
}
