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
TEST_CASE("La méthode sontPositionsDepartArriveeValides est correcte")
{
    int nombreLignes{10};
    int nombreColonnes{10};
    position caseDepart{2, 3};
    position caseArrivee{9, 8};
   SUBCASE("toutes les positions sont valides")
   {
     terrain terr1{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
     bool valide = terr1.sontPositionsDepartArriveeValides();
     REQUIRE_EQ(valide, true);
   }
   SUBCASE("Toutes les positions ne sont pas valides lorsque l'une au moins n'est pas valide")
   {
    SUBCASE("si la case depart n'est pas valide")
     {
        caseDepart = {10, 10};
        terrain terr1{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
        bool nonvalide = terr1.sontPositionsDepartArriveeValides();
        REQUIRE_EQ(nonvalide, false);
     }
     SUBCASE("si la case d'arrivee n'est pas valides ")
     {
      caseArrivee = {19, 8};
      terrain terr2{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
      bool nonvalide = terr2.sontPositionsDepartArriveeValides();
      REQUIRE_EQ(nonvalide, false);
     }
     SUBCASE("si toutes les cases ne sont pas valides ")
     {
       caseDepart = {10, 10};
       caseArrivee = {19, 8};
       terrain terr3{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
       bool nonvalide = terr3.sontPositionsDepartArriveeValides();
       REQUIRE_EQ(nonvalide, false);
     }
   }
}

int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();

    system("pause");  // Pause pour garder la fenêtre ouverte sur Windows
    return res;
}
