#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include"terrain.h"

TEST_CASE("Les cases spéciales du terrain sont valides"){
   position caseDepart{1, 2}, caseArrivee{2, 3};
   terrain t{10, 10,caseDepart, caseArrivee};
   REQUIRE_EQ(t.caseDepart(), caseDepart);
   REQUIRE_EQ(t.caseArrivee(), caseArrivee);
}
TEST_CASE("La méthode estPositionValide est correcte"){
    int nombreLignes{10};
    int nombreColonnes{10};
    position caseDepart{2, 3};
    position caseArrivee{9, 8};
   SUBCASE("La position est valide")
   {
    terrain terr1{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
     bool valide1 = terr1.estPositionValide(caseDepart);
     bool valide2 = terr1.estPositionValide(caseArrivee);
     REQUIRE_EQ(valide1, true);
     REQUIRE_EQ(valide2, true);
   }
   SUBCASE("La position n'est pas valide")
   {
     caseDepart = {11, 13};
     caseArrivee = {13, 14};
     terrain terr2{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
     bool nonValide1 = terr2.estPositionValide(caseDepart);
     bool nonValide2 = terr2.estPositionValide(caseArrivee);
     REQUIRE_EQ(nonValide1, false);
     REQUIRE_EQ(nonValide2, false);
   }
}
int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();

    system("pause");  // Pause pour garder la fenêtre ouverte sur Windows
    return res;
}
