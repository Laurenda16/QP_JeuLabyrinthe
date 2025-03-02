#ifndef TERRAIN_H
#define TERRAIN_H
#include<iostream>
#include<vector>
class affichage;
enum class TypeCase {
    MUR,
    VIDE,
    DEPART,
    ARRIVEE
};
struct  position{
    int ligne, colonne;
    bool operator==(const position& p) const {return p.ligne == ligne && p.colonne == colonne;}
};
using namespace std;
class terrain
{
    public:
           terrain();
           //terrain(const std::string& nomFichier);
           position caseDepart() const;
           position caseArrivee() const;
           const vector<vector<TypeCase>>& tableau() const;
           int hauteur() const;
           int largeur() const;
           void reinitialise();
           void redimensionne(int hauteur, int largeur);
           bool estCaseValide(const position& Case) const;
           void modifieCase(const position& Case, TypeCase type);
           void definitCaseDepart(position& Depart);
           void definitCaseArrivee(position& Arrivee);
           void imprimeSur(const string& nomFichier, affichage& Aff) const;
           void litDepuis(const string& nomFichier);
 private:
        vector<vector<TypeCase>> d_tableau;
        position d_caseDepart, d_caseArrivee;//{-1, -1},{-1, -1} si tableau vide
        void verifieIndiceValide(const position& pos) const;
};
#endif
