#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include"terrain.h"
void leTerrainEstBienConstruit(int lignes, int colonnes, const position& caseDepart, const position& caseArrivee)
{
  terrain t{lignes, colonnes, caseDepart, caseArrivee};
  REQUIRE_EQ(t.caseDepart(), caseDepart);
  REQUIRE_EQ(t.caseArrivee(), caseArrivee);
  REQUIRE_EQ(t.nombreLignes(), lignes);
  REQUIRE_EQ(t.nombreColonnes(), colonnes);
}
TEST_CASE(" Le constructeur de terrain est correct"){
   int nombreLignes{10}, nombreColonnes{10};
   position caseDepart{1, 2}, caseArrivee{2, 3};
   leTerrainEstBienConstruit(nombreLignes,nombreColonnes, caseDepart, caseArrivee);
}
TEST_CASE("La methode estPositionValide est correcte"){
    int nombreLignes{10};
    int nombreColonnes{10};
    position caseDepart{2, 3};
    position caseArrivee{9, 8};
    terrain terr{nombreLignes, nombreColonnes, caseDepart, caseArrivee};
    position POSITION{9, 9};
   SUBCASE("La position est valide")
   {
     bool valide = terr.estPositionValide(POSITION);
     REQUIRE_EQ(valide, true);
   }
   SUBCASE("La position n'est pas valide")
   {
     POSITION  = {10, 10};
     bool nonValide = terr.estPositionValide(POSITION);
     REQUIRE_EQ(nonValide, false);
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
