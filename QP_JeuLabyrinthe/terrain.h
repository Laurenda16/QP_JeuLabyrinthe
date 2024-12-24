#ifndef TERRAIN_H
#define TERRAIN_H
#include<iostream>
#include<vector>
struct  position{int ligne, colonne;
   bool operator==(const position& p) const {return p.ligne == ligne && p.colonne == colonne;}
};
using namespace std;
class terrain
{
    public:
           terrain();
           position caseDepart() const;
           position caseArrivee() const;
           vector<vector<char>> tableau() const;
           int hauteur() const;
           int largeur() const;
           void redimensionne(int hauteur, int largeur);
           bool estCaseValide(int ligne, int colonne) const;
           void ajouteCaseVide(int ligne, int colonne);
           void ajouteMur(int ligne, int colonne);
           void modifieCaseDepart(position& Depart);
           void modifieCaseArrivee(position& Arrivee);
           void imprimeSur(const string& nomFichier) const;
           void litDepuis(const string& nomFichier);
 private:
        vector<vector<char>> d_tableau;
        position d_caseDepart, d_caseArrivee;//{-1, -1},{-1, -1} si tableau vide
};
#endif // TERRAIN_H
