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

void terrain::reinitialise()
 {
   d_tableau.clear();
   d_caseDepart = {-1, -1};
   d_caseArrivee = {-1, -1};
 }
void terrain::redimensionne(int hauteur, int largeur)
{
    if(hauteur  <= 0 || largeur <= 0)
    {
     throw std::invalid_argument("Les dimensions doivent être strictement positives.");
    }
    reinitialise();
    d_tableau.resize(hauteur, std::vector<TypeCase>(largeur, TypeCase::VIDE));
    position depart{0, 0};
    position arrivee{hauteur-1, largeur-1};
    definitCaseDepart(depart);// case depart definit par defaut
    definitCaseArrivee(arrivee);// case arrivee definit par defaut
}

bool terrain::estCaseValide(const position& Case) const
{
   return (Case.ligne >= 0 && Case.ligne  < hauteur())&&
                   (Case.colonne >= 0 && Case.colonne < largeur()) ? true : false;
}

void terrain::modifieCase(const position& Case, TypeCase type)
{

  if(!estCaseValide(Case))
  {
    throw std::out_of_range("Indice hors bornes dans ajouteCaseVide");
  }
  d_tableau[Case.ligne][Case.colonne] = type;
  if(type == TypeCase::DEPART)
  {
    d_caseDepart = {Case.ligne, Case.colonne};
  }
  if(type == TypeCase::ARRIVEE)
  {
    d_caseArrivee = {Case.ligne, Case.colonne};
  }
}
void terrain::definitCaseDepart(position& Depart)
{
    if(!estCaseValide(Depart))
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
    if(!estCaseValide(Arrivee))
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
