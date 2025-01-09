#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "robot.h"
#include "terrain.h"

TEST_CASE("Test robot mouvement et détection d'obstacle") {
    terrain t;
    t.redimensionne(5, 5);
    position dep{0, 0};
    robot r(dep, 'E', t);

    CHECK(r.positionXY().ligne == 0 && r.positionXY().colonne == 0);


    r.avanceUneCase();
    CHECK(r.positionXY().ligne == 0 && r.positionXY().colonne == 1);
    CHECK(r.detecterObstacle() == false);

    r.tournerADroite();
    r.avanceUneCase();
    CHECK(r.positionXY().ligne == 1 && r.positionXY().colonne == 1);

    r.avanceUneCase();
    CHECK(r.detecterObstacle() == true);

}

TEST_CASE("Test robot orientation") {
    terrain t;
    t.redimensionne(5, 5);
    position dep{0, 0};
    robot r(dep, 'N', t);

    CHECK(r.direction() == '^');
    r.tournerADroite();
    CHECK(r.direction() == '>');
    r.tournerAGauche();
    CHECK(r.direction() == '^');
}

TEST_CASE("Le robot se deplace dans un terrain") {
    terrain t;
    affichage aff;

    SUBCASE("Le robot se deplace dans un terrain sans obstacles") {
        t.reinitialise();
        position p;
        p.ligne = 0;
        p.colonne = 0;
        robot r(t);
        r.algorithmeMainDroite(aff);
        CHECK(r.positionXY() == p);
    }
    SUBCASE("Le robot se deplace dans un terrain avec des obstacles") {
        t.redimensionne(10,10);
        position p;
        p.ligne = t.caseArrivee().ligne;
        p.colonne = t.caseArrivee.colonne;
        robot r(t);
        r.algorithmeMainDroite(aff);
        CHECK(r.positionXY() == p);
    }
}

TEST_CASE("Le robot se deplace dans un terrain") {
    terrain t;
    affichage aff;

    SUBCASE("Le robot se deplace dans un terrain sans obstacles") {
        t.reinitialise();
        position p;
        p.ligne = 0;
        p.colonne = 0;
        robot r(t);
        r.algorithmeDePledge(aff);
        CHECK(r.positionXY() == p);
    }
    SUBCASE("Le robot se deplace dans un terrain avec des obstacles") {
        t.redimensionne(10,10);
        position p;
        p.ligne = t.caseArrivee().ligne;
        p.colonne = t.caseArrivee.colonne;
        robot r(t);
        r.algorithmeDePledge(aff);
        CHECK(r.positionXY() == p);
    }
}
