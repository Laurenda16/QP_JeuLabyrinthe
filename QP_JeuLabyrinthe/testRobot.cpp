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

     /* SUBCASE("D�placement vers le nord") {
        rob.avanceUneCase();
        CHECK(rob.positionRobot() == position{4, 5}); //
        CHECK(rob.direction() == 'N');
    }

    SUBCASE("D�placement vers l'est apr�s rotation") {
        rob.tounerADroite();
        CHECK(rob.direction() == 'E');
        rob.avanceUneCase();
        CHECK(rob.positionRobot() == position{5, 6});
    }

    SUBCASE("D�placement vers le sud apr�s deux rotations � droite") {
        rob.tounerADroite();
        rob.tounerADroite();
        CHECK(rob.direction() == 'S');
        rob.avanceUneCase();
        CHECK(rob.positionRobot() == position{6, 5});
    }

    SUBCASE("D�placement vers l'ouest apr�s rotation � gauche") {
        rob.tounerAGauche();
        CHECK(rob.direction() == 'W');
        rob.avanceUneCase();
        CHECK(rob.positionRobot() == position{5, 4});
    }*/
    SUBCASE("Tester l'avancement du robot d'une casse")
    {

    }




}
