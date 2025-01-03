#include "terrain.h"
#include <fstream>
#include"affichage.h"
terrain::terrain(): d_tableau{}, d_caseDepart{-1, -1},
d_caseArrivee{-1, -1} {}

position terrain::caseDepart() const {return d_caseDepart;}

position terrain::caseArrivee() const {return d_caseArrivee ;}

const vector<vector<TypeCase>>& terrain::tableau() const {return d_tableau;}

int terrain::hauteur() const {return d_tableau.size();}

int terrain::largeur() const {return !d_tableau.empty() ? d_tableau[0].size() : 0;}

void terrain::redimensionne(int hauteur, int largeur)
{
    d_tableau.clear();
    d_tableau.resize(hauteur, std::vector<TypeCase>(largeur, TypeCase::VIDE));
    d_caseDepart = {-1, -1};
    d_caseArrivee = {-1, -1};
}

bool terrain::estCaseValide(int ligne, int colonne) const
{
   return (ligne >= 0 && ligne  < hauteur())&&
                   (colonne >= 0 && colonne < largeur()) ? true : false;
}

void terrain::ajouteCase(int ligne, int colonne, TypeCase type)
{
  if(!estCaseValide(ligne, colonne))
  {
    throw std::out_of_range("Indice hors bornes dans ajouteCaseVide");
  }
  d_tableau[ligne][colonne] = type;
  if(type == TypeCase::DEPART)
  {
    d_caseDepart = {ligne, colonne};
  }
  if(type == TypeCase::ARRIVEE)
  {
    d_caseArrivee = {ligne, colonne};
  }
}
void terrain::definitCaseDepart(position& Depart)
{
  if (d_tableau.empty()) {
        throw std::runtime_error("Terrain vide, impossible de definir un depart");
    }
    if(!estCaseValide(Depart.ligne, Depart.colonne))
    {
        throw std::out_of_range("Depart hors bornes");
    }
    if (d_tableau[Depart.ligne][Depart.colonne] == TypeCase::MUR) {
        throw std::runtime_error("Depart sur un mur, interdit");
    }
   d_caseDepart = Depart;
   d_tableau[Depart.ligne][Depart.colonne] = TypeCase::DEPART;
}

void terrain::definitCaseArrivee(position& Arrivee)
{
  if (d_tableau.empty()) {
        throw std::runtime_error("Terrain vide, impossible de definir un depart");
    }
    if(!estCaseValide(Arrivee.ligne, Arrivee.colonne))
    {
        throw std::out_of_range("Depart hors bornes");
    }
    if (d_tableau[Arrivee.ligne][Arrivee.colonne] == TypeCase::MUR) {
        throw std::runtime_error("Arrivee sur un mur, interdit");
    }
   d_caseArrivee = Arrivee;
   d_tableau[Arrivee.ligne][Arrivee.colonne] = TypeCase::ARRIVEE;
}
void terrain::imprimeSur(const string& nomFichier, affichage& Aff) const
{
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier.");
    }
    Aff.afficher(fichier, *this);
}
