#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "affichage.h"


int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();
    system("pause");
    return res;

}
