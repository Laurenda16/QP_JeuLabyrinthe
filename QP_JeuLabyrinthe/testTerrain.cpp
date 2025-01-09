#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include"terrain.h"
void verifierDimensionsInvalides(terrain& tr) {
    REQUIRE_THROWS_AS(tr.redimensionne(0, 10), std::invalid_argument);
    REQUIRE_THROWS_AS(tr.redimensionne(10, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(tr.redimensionne(-5, 10), std::invalid_argument);
    REQUIRE_THROWS_AS(tr.redimensionne(10, -5), std::invalid_argument);
}
TEST_CASE("Le terrain est bien construit")
{
    terrain tr{};
    position positionInitiale{-1, -1};
  SUBCASE("les cases de depart sont biens definis au debut")
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
   terrain tr{};
   int hauteur{10}, largeur{10};
   tr.redimensionne(hauteur, largeur);
   tr.reinitialise();
   SUBCASE(" verifier que le terrain est vide")
   {
     REQUIRE_EQ(tr.hauteur(), 0);
     REQUIRE_EQ(tr.largeur(), 0);
   }
   SUBCASE("verifier que les cases speciaux ne sont plus definies")
   {
     position nonDefinie{-1, -1};
     REQUIRE_EQ(tr.caseDepart(), nonDefinie);
     REQUIRE_EQ(tr.caseArrivee(), nonDefinie);
   }
}
TEST_CASE("la methode redimensionne est correcte")
{
  SUBCASE("Verifier que les dimensions invalides sont gerees correctement") {
    terrain tr{};
    verifierDimensionsInvalides(tr);
   }
  terrain tr{};
  int hauteur{10}, largeur{10};
  tr.redimensionne(hauteur, largeur);
  position depart{0, 0}; // case depart par defaut
  position arrivee{hauteur-1, largeur-1}; // case arrivee par defaut
  SUBCASE("Verifier que la taille du terrain est correcte")
  {
   REQUIRE_EQ(tr.hauteur(),  hauteur);
   REQUIRE_EQ(tr.largeur(),  largeur);
  }
 SUBCASE("Verifier que les cases speciales sont bien  definies ")
  {
      REQUIRE_EQ(tr.caseDepart(), depart);
      REQUIRE_EQ(tr.caseArrivee(), arrivee);
  }
}
TEST_CASE("La methode largeur est correcte")
{
   terrain tr{};
   SUBCASE("Verifier que le terrain est vide")
   {
     REQUIRE_EQ(tr.largeur(),  0);
   }
   SUBCASE("verifier que la largeur du terrain est la largeur qu'on lui a donne")
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
   SUBCASE("Verifier que la case est valide si elle est dans les bornes")
   {
     int ligne{hauteur-1 }, colonne{largeur-1};
     position Case{ligne, colonne};
     bool valide = tr.estCaseValide(Case);
     REQUIRE_EQ(valide, true);
   }
   SUBCASE("Verifier que la case n'est pas valide")
   {

    SUBCASE("si la ligne est egale a la hauteur")
    {
       int ligne{hauteur}, colonne{largeur-1};
       position Case{ligne, colonne};
       bool valide = tr.estCaseValide(Case);
       REQUIRE_EQ(valide, false);
    }
    SUBCASE(" si la ligne est superieure a la hauteur")
    {
       int ligne{hauteur+1}, colonne{largeur-1};
       position Case{ligne, colonne};
       bool valide = tr.estCaseValide(Case);
       REQUIRE_EQ(valide, false);
    }
    SUBCASE("si la colonne est egale a la largeur")
    {
     int ligne{hauteur-1 }, colonne{largeur};
     position Case{ligne, colonne};
     bool valide = tr.estCaseValide(Case);
     REQUIRE_EQ(valide, false);
    }
    SUBCASE("si la colonne est superieure a la largeur")
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
      position Case{hauteur, largeur};
      TypeCase type{TypeCase::VIDE};
      CHECK_THROWS_AS(tr.modifieCase(Case, type), std::out_of_range);
    }
    SUBCASE("La case est modifiee si la case est valide")
    {
      position Case{hauteur-1, largeur-1};
      TypeCase type{TypeCase::MUR};
      tr.modifieCase(Case, type);
      REQUIRE_EQ((tr.tableau())[Case.ligne][Case.colonne], TypeCase::MUR);
    }
    SUBCASE("Si la case modifiee est un depart, le depart est mis a jour")
    {
      position Case{hauteur-2, largeur-2};
      TypeCase type{TypeCase::DEPART};
      tr.modifieCase(Case, type);
      position nouveauDepart{Case};
      REQUIRE_EQ(tr.caseDepart(), nouveauDepart);
    }
    SUBCASE("Si la case modifiee est une arrivee, l'arrivee est mise a jour")
    {
      position Case{hauteur-3, largeur-3};
      TypeCase type{TypeCase::ARRIVEE};
      tr.modifieCase(Case, type);
      position nouvelleArrivee{Case};
      REQUIRE_EQ(tr.caseArrivee(), nouvelleArrivee);
    }

}
TEST_CASE("La methode definit CaseDepart est correcte")
{
  position nouveauDepart{1, 2};
  terrain tr{};
  int hauteur{7}, largeur{20};
  SUBCASE("verifier que Le nouveau depart devient le depart")
  {
    tr.redimensionne(hauteur, largeur);
    tr.definitCaseDepart(nouveauDepart);
    REQUIRE_EQ(tr.caseDepart(), nouveauDepart);// Verifie que le départ est mis a jour
  }
  SUBCASE("verifier que le depart n' est pas modifie si le terrain est vide")
  {
    REQUIRE_FALSE(tr.caseDepart()==nouveauDepart);
  }
  SUBCASE("verifier que le depart n' est pas modifie s'il y'a un mur a la position nouveau depart")
  {
    tr.redimensionne(hauteur, largeur);
    tr.modifieCase(nouveauDepart, TypeCase::MUR);
    REQUIRE_FALSE(tr.caseDepart()== nouveauDepart);
  }
}
TEST_CASE("La methode definit Case Arrivee est correcte")
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
  SUBCASE("verifier que l'arrivee n' est pas modifiee si le terrain est vide")
  {
    REQUIRE_FALSE(tr.caseArrivee()==nouvelleArrivee);
  }
  SUBCASE("verifier que l'arrivee n' est pas modifiee s'il y'a un mur a la position nouvelle Arrivee")
  {
    tr.redimensionne(hauteur, largeur);
    tr.modifieCase(nouvelleArrivee, TypeCase::MUR);
    REQUIRE_FALSE(tr.caseArrivee()==nouvelleArrivee);
  }
}
int main(int argc, char** argv) {
    doctest::Context context;
    int res = context.run();
    system("pause");
    return res;
}
