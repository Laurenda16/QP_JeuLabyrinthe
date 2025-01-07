#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "terrain.h"
#include "goto_xy_windows.h"
#include "robot.h"
class terrain;
class affichage {
public:
    virtual void affiche(std::ostream& ost, const terrain& t,const robot& r) const = 0;
    virtual ~affichage() = default;
    void afficheTerrain(std::ostream& ost, const terrain& t) const{
        const auto& tableau = t.tableau();
        for (const auto& ligne : tableau) {
            for (TypeCase caseTerrain : ligne) {
                switch (caseTerrain) {
                    case TypeCase::MUR:    ost << 'x'; break;
                    case TypeCase::VIDE:   ost << '.'; break;
                    case TypeCase::DEPART: ost << 'D'; break;
                    case TypeCase::ARRIVEE: ost << 'A'; break;
                }
            }
            ost << "\n";
        }
    }
};




class affichageSimple : public affichage {
public:
    void affiche(std::ostream& ost, const terrain& t, const robot& r) const override {
        const auto& tableau = t.tableau();
        for (int i = 0; i < tableau.size(); ++i) {
            for (int j = 0; j < tableau[i].size(); ++j) {
                if (i == r.positionXY().ligne && j == r.positionXY().colonne) {
                    ost << r.direction();  // Affichage du robot à sa position
                } else {
                    switch (tableau[i][j]) {
                        case TypeCase::MUR: ost << 'x'; break;
                        case TypeCase::VIDE: ost << '.'; break;
                        case TypeCase::DEPART: ost << 'D'; break;
                        case TypeCase::ARRIVEE: ost << 'A'; break;
                    }
                }
            }
            ost << "\n";
        }
    }

};



/*
class affichageSimple : public affichage {
public:
    void affiche(std::ostream& ost, const terrain& t) const{
        const auto& tableau = t.tableau();
        for (const auto& ligne : tableau) {
            for (TypeCase caseTerrain : ligne) {
                switch (caseTerrain) {
                    case TypeCase::MUR:    ost << 'x'; break;
                    case TypeCase::VIDE:   ost << '.'; break;
                    case TypeCase::DEPART: ost << 'D'; break;
                    case TypeCase::ARRIVEE: ost << 'A'; break;
                }
            }
            ost << "\n";
        }
    }
};
class affichageAmelioree : public affichage {
public:
    void affiche(std::ostream& ost,const terrain& t) const  {
        const auto& tableau = t.tableau();
        for (const auto& ligne : tableau) {
            for (TypeCase caseTerrain : ligne) {
                switch (caseTerrain) {
                    case TypeCase::MUR:    ost << "+"; break;
                    case TypeCase::VIDE:   ost << '.'; break;
                    case TypeCase::DEPART: ost << "#E"; break;
                    case TypeCase::ARRIVEE: ost << "#S"; break;
                }
            }
            ost<< "\n";
        }
    }
};
*/
#endif // AFFICHAGE_H
