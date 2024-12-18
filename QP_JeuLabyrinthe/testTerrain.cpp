#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include"terrain.h"

TEST_CASE("Les cases sp�ciales du terrain sont valides"){
   position caseDepart{1, 2}, caseArrivee{2, 3};
   terrain t{10, 10,caseDepart, caseArrivee};
   REQUIRE_EQ(t.caseDepart(), caseArrivee);
   REQUIRE_EQ(t.caseArrivee(), caseArrivee);
}
int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();

    system("pause");  // Pause pour garder la fen�tre ouverte sur Windows
    return res;
}
