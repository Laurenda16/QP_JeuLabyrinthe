#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "terrain.h"
class affichage {
public:
    virtual void affiche(std::ostream& ost, const terrain& t) const = 0;
    virtual ~affichage() = default;
};
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
    void affiche(std::ostream& ost,const terrain& t) const override {
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
#endif // AFFICHAGE_H
