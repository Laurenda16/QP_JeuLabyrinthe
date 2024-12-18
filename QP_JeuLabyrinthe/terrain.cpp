#include "terrain.h"

terrain::terrain(int lignes, int colonnes, const position& caseDepart, const position& caseArrivee): d_lignes{lignes}, d_colonnes{colonnes}, d_caseDepart{caseDepart},
d_caseArrivee{caseArrivee}{initialiseTableau();}
position terrain::caseDepart() const{return d_caseDepart;}
position terrain::caseArrivee() const{return d_caseArrivee ;}
bool terrain::estPositionValide(const position& pos) const
{
  return (pos.x >= 0 && pos.x < d_lignes &&
           pos.y >= 0 && pos.y < d_colonnes);
}
bool terrain::sontPositionsDepartArriveeValides() const
{
  return estPositionValide(d_caseDepart) && estPositionValide(d_caseArrivee);
}
void terrain::initialiseTableau() {

    d_tableau = vector<vector<char>>(d_lignes, vector<char>(d_colonnes, 'X'));

    if (!sontPositionsDepartArriveeValides()) {
        throw invalid_argument("Les positions de départ et/ou d'arrivée sont invalides.");
    }
    else
    {
     d_tableau[d_caseDepart.x][d_caseDepart.y] = 'D';
     d_tableau[d_caseArrivee.x][d_caseArrivee.y] = 'A';
    }

}
