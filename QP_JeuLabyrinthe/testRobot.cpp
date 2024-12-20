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

      SUBCASE("D�placement vers le nord") {
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{4, 5}); // Avance en r�duisant X
        CHECK(rob.direction() == 'N');
    }

    SUBCASE("D�placement vers l'est apr�s rotation") {
        rob.tounerADroite();
        CHECK(rob.direction() == 'E'); // Apr�s rotation � droite
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{5, 6}); // Avance en augmentant Y
    }

    SUBCASE("D�placement vers le sud apr�s deux rotations � droite") {
        rob.tounerADroite();
        rob.tounerADroite();
        CHECK(rob.direction() == 'S'); // Apr�s deux rotations � droite
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{6, 5}); // Avance en augmentant X
    }

    SUBCASE("D�placement vers l'ouest apr�s rotation � gauche") {
        rob.tounerAGauche();
        CHECK(rob.direction() == 'W'); // Apr�s rotation � gauche
        rob.avanceUneCase();
        CHECK(rob.positionXY() == position{5, 4}); // Avance en r�duisant Y
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
