#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_MULTITHREADING

#include "doctest.h"

#include "robot.h"


TEST_CASE("Tester de la classe robot")
{

    position positionInitial{0,0};
    char direction = 'N'; // Nord
    robot rob(positionInitial, direction);
    SUBCASE("Initialisation du robot") {
        CHECK(rob.positionRobot() == positionInitial);
        CHECK(rob.direction() == 'N');
    }


    SUBCASE("Avancer d'une case en gardant sa direction ") {
        rob.avanceUneCase();
        CHECK(rob.positionRobot() == position{0,1}); //vers l Nord
    }

    SUBCASE("Tourner à droite") {
        rob.tounerADroite();
        CHECK(rob.direction() == 'E');
    }

    SUBCASE("Tourner à gauche") {
        rob.tounerAGauche();
        CHECK(rob.direction() == 'W');
    }


    SUBCASE("Detection d'un obstacle")
    {
        CHECK_FALSE(r.detecterObstacle());
    }

}
int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();

    system("pause");  // Pause pour garder la fenêtre ouverte sur Windows
    return res;
}

