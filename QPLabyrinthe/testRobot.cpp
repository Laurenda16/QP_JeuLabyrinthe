//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "affichage.h"

TEST_CASE("Test robot mouvement et détection d'obstacle"){
    terrain t;
    t.redimensionne(5, 5);
    robot r(t);
    REQUIRE_EQ(r.positionXY(),t.caseDepart());
    r.tournerADroite();
    r.avanceUneCase();
    position p{0,1};
    REQUIRE_EQ(r.positionXY(),p);

}

TEST_CASE("Test robot orientation") {
    terrain t;
    t.redimensionne(5, 5);

    robot r(t);

    CHECK(r.direction() == '^');
    r.tournerADroite();
    CHECK(r.direction() == '>');
    r.tournerAGauche();
    CHECK(r.direction() == '^');
}
TEST_CASE("Le robot se deplace dans un terrain") {
    terrain t;
    affichageSimple aff;
    t.redimensionne(5,5);
    position p{0,0};
    robot r(t);
    r.tournerADroite();
    r.avanceUneCase();
    r.tournerADroite();
    r.avanceUneCase();
    r.tournerADroite();
    r.avanceUneCase();
    r.tournerADroite();
    r.avanceUneCase();
    REQUIRE_EQ(r.positionXY(),p);




}
