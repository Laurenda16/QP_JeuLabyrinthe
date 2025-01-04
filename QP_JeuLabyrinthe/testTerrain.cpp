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
TEST_CASE("La methode reinitialise est correcte")
{
   terrain t{};
   int hauteur{10}, largeur{10};
   t.redimensionne(hauteur, largeur);
   t.reinitialise();
   SUBCASE(" verifier si le terrain est vide")
   {
     REQUIRE_EQ(t.hauteur(), 0);
     REQUIRE_EQ(t.largeur(), 0);
   }
   SUBCASE("verifier si les cases speciaux ne sont plus definies")
   {
     position nonDefinie{-1, -1};
     REQUIRE_EQ(t.caseDepart(), nonDefinie);
     REQUIRE_EQ(t.caseArrivee(), nonDefinie);
   }
}
TEST_CASE("la methode redimensionne est correcte")
{
  terrain t{};
  int hauteur{10}, largeur{10};
  t.redimensionne(10, 10);
  position depart{0, 0}; // case depart par defaut
  position arrivee{hauteur-1, largeur-1}; // case arrivee par defaut
  SUBCASE("La taille du terrain est bien reinitialisee")
  {
   REQUIRE_EQ(t.hauteur(),  hauteur);
   REQUIRE_EQ(t.largeur(),  largeur);
  }
 SUBCASE("La case de depart est bien definie ")
  {
      REQUIRE_EQ(t.caseDepart(), depart);
  }
  SUBCASE("La case d'arrivee est bien definie")
  {
      REQUIRE_EQ(t.caseArrivee(), arrivee);
  }
}
TEST_CASE("La methode largeur est correcte")
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
TEST_CASE("La methode estCaseValide est correcte")
{
    terrain tr{};
    int hauteur{7}, largeur{20};
    tr.redimensionne(hauteur, largeur);
   SUBCASE("La case est valide")
   {
     int ligne{hauteur-1 }, colonne{largeur-1};
     position Case{ligne, colonne};
     bool valide = tr.estCaseValide(Case);
     REQUIRE_EQ(valide, true);
   }
   SUBCASE("La case n'est pas valide")
   {

    SUBCASE("si la ligne est egale à la hauteur")
    {
       int ligne{hauteur}, colonne{largeur-1};
       position Case{ligne, colonne};
       bool valide = tr.estCaseValide(Case);
       REQUIRE_EQ(valide, false);
    }
    SUBCASE(" si la ligne est superieure à la hauteur")
    {
       int ligne{hauteur+1}, colonne{largeur-1};
       position Case{ligne, colonne};
       bool valide = tr.estCaseValide(Case);
       REQUIRE_EQ(valide, false);
    }
    SUBCASE("si la colonne est egale à la largeur")
    {
     int ligne{hauteur-1 }, colonne{largeur};
     position Case{ligne, colonne};
     bool valide = tr.estCaseValide(Case);
     REQUIRE_EQ(valide, false);
    }
    SUBCASE("si la colonne est superieure à la largeur")
    {
     int ligne{hauteur-1 }, colonne{largeur+1};
     position Case{ligne, colonne};
     bool valide = tr.estCaseValide(Case);
     REQUIRE_EQ(valide, false);
    }
   }
}
TEST_CASE("La methode modifieCase est correcte")
{
    int hauteur{7}, largeur{20};
    terrain tr{};
    tr.redimensionne(hauteur, largeur);

    SUBCASE("La case n'est pas modifiee si la case n'est pas valide")
    {
      int ligne{hauteur}, colonne{largeur};
      position Case{ligne, colonne};
      TypeCase type{TypeCase::VIDE};
      CHECK_THROWS_AS(tr.modifieCase(Case, type), std::out_of_range);
    }
    SUBCASE("La case est modifiee si la case est valide")
    {
      int ligne{hauteur-1}, colonne{largeur-1};
      position Case{ligne, colonne};
      TypeCase type{TypeCase::MUR};
      tr.modifieCase(Case, type);
      REQUIRE_EQ((tr.tableau())[Case.ligne][Case.colonne], TypeCase::MUR);
    }
    SUBCASE("Si la case modifiee est un depart, le depart est mis a jour")
    {
      int ligne{hauteur-2}, colonne{largeur-2};
      position Case{ligne, colonne};
      TypeCase type{TypeCase::DEPART};
      tr.modifieCase(Case, type);
      position nouveauDepart{ligne, colonne};
      REQUIRE_EQ((tr.tableau())[Case.ligne][Case.colonne], TypeCase::DEPART);
      REQUIRE_EQ(tr.caseDepart(), nouveauDepart);
    }
    SUBCASE("Si la case modifiee est une arrivee, l'arrivee est mise a jour")
    {
      int ligne{hauteur-3}, colonne{largeur-3};
      position Case{ligne, colonne};
      TypeCase type{TypeCase::ARRIVEE};
      tr.modifieCase(Case, type);
      position nouvelleArrivee{ligne, colonne};
      REQUIRE_EQ((tr.tableau())[Case.ligne][Case.colonne], TypeCase::ARRIVEE);
      REQUIRE_EQ(tr.caseArrivee(), nouvelleArrivee);
    }

}
TEST_CASE("La methode definitCaseDepart est correcte")
{
  position nouveauDepart{1, 2};
  terrain tr{};
  int hauteur{7}, largeur{20};
  SUBCASE("Le nouveau depart devient le depart")
  {
    tr.redimensionne(hauteur, largeur);
    tr.definitCaseDepart(nouveauDepart);
    REQUIRE_EQ(tr.caseDepart(), nouveauDepart);
  }
  SUBCASE("Le depart n' est pas modifie si le terrain est vide")
  {
    REQUIRE_FALSE(tr.caseDepart()==nouveauDepart);
  }
  SUBCASE("Le depart n' est pas modifie s'il y'a un mur a la position nouveau depart")
  {
    tr.redimensionne(hauteur, largeur);
    tr.modifieCase(nouveauDepart, TypeCase::MUR);
    REQUIRE_FALSE(tr.caseDepart()== nouveauDepart);
  }
}
TEST_CASE("La methode definitCaseArrivee est correcte")
{
  position nouvelleArrivee{1, 2};
  terrain tr{};
  int hauteur{7}, largeur{20};
  SUBCASE("nouvelleArrivee devient la position d'arrivee")
  {
    tr.redimensionne(hauteur, largeur);
    tr.definitCaseArrivee(nouvelleArrivee);
    REQUIRE_EQ(tr.caseArrivee(), nouvelleArrivee);
  }
  SUBCASE("L'arrivee n' est pas modifie si le terrain est vide")
  {
    REQUIRE_FALSE(tr.caseArrivee()==nouvelleArrivee);
  }
  SUBCASE("L'arrivee n' est pas modifie s'il y'a un mur a la position nouvelleArrivee")
  {
    tr.redimensionne(hauteur, largeur);
    tr.modifieCase(nouvelleArrivee, TypeCase::MUR);
    REQUIRE_FALSE(tr.caseArrivee()==nouvelleArrivee);
  }
}
int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();
    system("pause");  // Pause pour garder la fenêtre ouverte sur Windows
    return res;
}
