#include "terrain.h"
terrain::terrain(): d_caseDepart{-1, -1},
d_caseArrivee{-1, -1}, d_tableau{} {}

position terrain::caseDepart() const {return d_caseDepart;}

position terrain::caseArrivee() const {return d_caseArrivee ;}

vector<vector<char>> terrain::tableau() const {return d_tableau;}

int terrain::hauteur() const {return d_tableau.size();}

int terrain::largeur() const {return !d_tableau.empty() ? d_tableau[0].size() : 0;}

void terrain::redimensionne(int hauteur, int largeur)
{
    d_tableau.clear();
    d_tableau.resize(hauteur, std::vector<char>(largeur, '.'));
    d_caseDepart = {-1, -1};
    d_caseArrivee = {-1, -1};
}

bool terrain::estCaseValide(int ligne, int colonne) const
{
   return (ligne >= 0 && ligne  < hauteur())&&
                   (colonne >= 0 && colonne < largeur()) ? true : false;
}

void terrain::ajouteCaseVide(int ligne, int colonne)
{
  if(!estCaseValide(ligne, colonne))
  {
    throw std::out_of_range("Indice hors bornes dans ajouteCaseVide");
  }
  d_tableau[ligne][colonne] = '.';
}

void terrain::ajouteMur(int ligne, int colonne)
{
  if(!estCaseValide(ligne, colonne))
  {
    throw std::out_of_range("Indice hors bornes dans ajouteCaseVide");
  }
  d_tableau[ligne][colonne] = 'x';
}

void terrain::modifieDepart(position& Depart)
{
  if (d_tableau.empty()) {
        throw std::runtime_error("Terrain vide, impossible de definir un depart");
    }
    if(!estCaseValide(Depart.ligne, Depart.colonne))
    {
        throw std::out_of_range("Depart hors bornes");
    }
    if (d_tableau[Depart.ligne][Depart.colonne] == 'x') {
        throw std::runtime_error("Depart sur un mur, interdit");
    }
   d_caseDepart = Depart;
}

void terrain::modifieArrivee(position& Arrivee)
{
  if (d_tableau.empty()) {
        throw std::runtime_error("Terrain vide, impossible de definir un depart");
    }
    if(!estCaseValide(Arrivee.ligne, Arrivee.colonne))
    {
        throw std::out_of_range("Depart hors bornes");
    }
    if (d_tableau[Arrivee.ligne][Arrivee.colonne] == 'x') {
        throw std::runtime_error("Arrivee sur un mur, interdit");
    }
   d_caseDepart = Arrivee;
}
