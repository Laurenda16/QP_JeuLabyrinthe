#ifndef TERRAIN_H
#define TERRAIN_H

#include<iostream>
#include<vector>
struct  position{int x, y;
   bool operator==(const position& p) const {return p.x == x && p.y == y;}
};
using namespace std;
class terrain
{
    public:
           terrain(int lignes, int colonnes, const position& caseDepart, const position& caseArrivee);
           position caseDepart() const;
           position caseArrivee() const;
           void initialiseTableau();
           void imprimeSur(const string& nomFichier) const;
           void litDepuis(const string& nomFichier);

    private:
            vector<vector<char>> d_tableau;
            int d_lignes, d_colonnes; 
            position d_caseDepart, d_caseArrivee;
            bool estPositionValide(const position& pos) const;
            bool sontPositionsDepartArriveeValides() const;
};


#endif // TERRAIN_H
