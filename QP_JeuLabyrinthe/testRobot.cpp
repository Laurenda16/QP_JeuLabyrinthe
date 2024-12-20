#include "doctest.h"
#include "robot.h"

/*
TEST_CASE("Tester l'initialisation du robot")
{

    position positionInitial{5, 5};
    char direction = 'E'; // Nord
    robot rob(positionInitial, direction);

     SUBCASE("Initialisation du robot") {
        CHECK(rob.positionXY() == positionInitial);
        CHECK(rob.direction() == 'E');
    }
}*/

TEST_CASE("Tester le deplacement du robot")
{

    position positionInitial{5, 5};
    char direction = 'E'; // Nord
    robot rob(positionInitial, direction);

      SUBCASE("Déplacement vers le nord") {
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{4, 5}); // Avance en réduisant X
        CHECK(rob.direction() == 'N');
    }

    SUBCASE("Déplacement vers l'est après rotation") {
        rob.tounerADroite();
        CHECK(rob.direction() == 'E'); // Après rotation à droite
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{5, 6}); // Avance en augmentant Y
    }

    SUBCASE("Déplacement vers le sud après deux rotations à droite") {
        rob.tounerADroite();
        rob.tounerADroite();
        CHECK(rob.direction() == 'S'); // Après deux rotations à droite
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{6, 5}); // Avance en augmentant X
    }

    SUBCASE("Déplacement vers l'ouest après rotation à gauche") {
        rob.tounerAGauche();
        CHECK(rob.direction() == 'W'); // Après rotation à gauche
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{5, 4}); // Avance en réduisant Y
    }


    SUBCASE("Position apres avancement d'une case")
    {

    }
    SUBCASE("Position apres avoir tourner a Gauche")
    {

    }
     SUBCASE("Position apres avoir tourner a Droite")
    {

    }


}
