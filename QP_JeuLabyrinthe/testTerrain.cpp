#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include"terrain.h"

TEST_CASE("Le terrain est bien construit")
{
    terrain tr{};
    position positionInitiale{-1, -1};
  SUBCASE("les cases de départ sont biens définis au début")
  {
    REQUIRE_EQ(tr.caseDepart(), positionInitiale);
    REQUIRE_EQ(tr.caseArrivee(), positionInitiale);
  }
  SUBCASE("Le tableau est vide initialement")
  {
      REQUIRE_EQ(tr.tableau().size(), 0);
  }
}
TEST_CASE("la methode redimensionne est correcte")
{
  terrain t{};
  int largeur{10}, hauteur{10};
  position positionInitiale{-1, -1};
  t.redimensionne(10, 10);
  SUBCASE("La taille du terrain est bien reinitialisee")
  {
   REQUIRE_EQ(t.hauteur(),  hauteur);
   REQUIRE_EQ(t.largeur(),  largeur);
  }
  SUBCASE("La case de depart est bien reinitialisee")
  {
      REQUIRE_EQ(t.caseDepart(), positionInitiale);
  }
  SUBCASE("La case d'arrivee est bien reinitialisee")
  {
      REQUIRE_EQ(t.caseArrivee(), positionInitiale);
  }
}
TEST_CASE("La méthode largeur est correcte")
{
   terrain tr{};
   SUBCASE("Le terrain est vide")
   {
     REQUIRE_EQ(tr.largeur(),  0);
   }
   SUBCASE("Le terrain n'est pas vide")
   {
       int hauteur{7}, largeur{20};
       tr.redimensionne(hauteur, largeur);
       REQUIRE_EQ(tr.largeur(),largeur);
   }
}
TEST_CASE("La méthode estCaseValide est correcte")
{
    terrain tr{};
    int hauteur{7}, largeur{20};
    tr.redimensionne(hauteur, largeur);
   SUBCASE("La case est valide")
   {
     int ligne{hauteur-1 }, colonne{largeur-1};
     bool valide = tr.estCaseValide(ligne, colonne);
     REQUIRE_EQ(valide, true);
   }
   SUBCASE("La case n'est pas valide")
   {

    SUBCASE("si la ligne est egale à la hauteur")
    {
       int ligne{hauteur}, colonne{largeur-1};
       bool valide = tr.estCaseValide(ligne, colonne);
       REQUIRE_EQ(valide, false);
    }
    SUBCASE(" si la ligne est superieure à la hauteur")
    {
       int ligne{hauteur+1}, colonne{largeur-1};
       bool valide = tr.estCaseValide(ligne, colonne);
       REQUIRE_EQ(valide, false);
    }
    SUBCASE("si la colonne est egale à la largeur")
    {
     int ligne{hauteur-1 }, colonne{largeur};
     bool valide = tr.estCaseValide(ligne, colonne);
     REQUIRE_EQ(valide, false);
    }
    SUBCASE("si la colonne est superieure à la largeur")
    {
     int ligne{hauteur-1 }, colonne{largeur+1};
     bool valide = tr.estCaseValide(ligne, colonne);
     REQUIRE_EQ(valide, false);
    }
   }
}
TEST_CASE("La méthode ajouteCase est correcte")
{
    int hauteur{7}, largeur{20};
    terrain tr{};
    tr.redimensionne(hauteur, largeur);
    SUBCASE("La case n'est pas ajoutee si la case n'est pas valide")
    {
      int ligne{hauteur}, colonne{largeur};
      TypeCase type{TypeCase::VIDE};
      tr.ajouteCase(ligne, colonne, type);
      WARN("Indice hors bornes dans ajouteCaseVide");
    }
    SUBCASE("La case est ajoutee si la case est valide")
    {
      int ligne{hauteur-1}, colonne{largeur-1};
      TypeCase type{TypeCase::VIDE};
      tr.ajouteCase(ligne, colonne, type);
      REQUIRE_EQ((tr.tableau())[ligne][colonne], TypeCase::VIDE);
    }

}
TEST_CASE("La methode modifieCaseDepart est correcte")
{
  position nouveauDepart{1, 2};
  terrain tr{};
  int hauteur{7}, largeur{20};
  SUBCASE("Le nouveau depart devient le depart")
  {
    tr.redimensionne(hauteur, largeur);
    tr.modifieCaseDepart(nouveauDepart);
    REQUIRE_EQ(tr.caseDepart(), nouveauDepart);
  }
  SUBCASE("Le depart n' est pas modifie si le terrain est vide")
  {
    REQUIRE_FALSE(tr.caseDepart()==nouveauDepart);
  }
  SUBCASE("Le depart n' est pas modifie s'il y'a un mur a la position nouveau depart")
  {
    tr.redimensionne(hauteur, largeur);
    tr.ajouteCase(nouveauDepart.ligne, nouveauDepart.colonne, TypeCase::MUR);
    REQUIRE_FALSE(tr.caseDepart()==nouveauDepart);
  }
}
TEST_CASE("La methode modifieCaseArrivee est correcte")
{
  position nouvelleArrivee{1, 2};
  terrain tr{};
  int hauteur{7}, largeur{20};
  SUBCASE("nouvelleArrivee devient la position d'arrivee")
  {
    tr.redimensionne(hauteur, largeur);
    tr.modifieCaseArrivee(nouvelleArrivee);
    REQUIRE_EQ(tr.caseArrivee(), nouvelleArrivee);
  }
  SUBCASE("L'arrivee n' est pas modifie si le terrain est vide")
  {
    REQUIRE_FALSE(tr.caseArrivee()==nouvelleArrivee);
  }
  SUBCASE("L'arrivee n' est pas modifie s'il y'a un mur a la position nouvelleArrivee")
  {
    tr.redimensionne(hauteur, largeur);
    tr.ajouteCase(nouvelleArrivee.ligne, nouvelleArrivee.colonne, TypeCase::MUR);
    REQUIRE_FALSE(tr.caseArrivee()==nouvelleArrivee);
  }
}
int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();
    system("pause");  // Pause pour garder la fenêtre ouverte sur Windows
    return res;
}
