#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "terrain.h"
class affichage {
public:
    virtual void afficher(const terrain& t) const = 0;
    virtual ~affichage() = default;
};
class affichageSimple : public affichage {
public:
    void afficher(const terrain& t) const{
        const auto& tableau = t.tableau();
        for (const auto& ligne : tableau) {
            for (TypeCase caseTerrain : ligne) {
                switch (caseTerrain) {
                    case TypeCase::MUR:    std::cout << 'x'; break;
                    case TypeCase::VIDE:   std::cout << '.'; break;
                    case TypeCase::DEPART: std::cout << 'D'; break;
                    case TypeCase::ARRIVEE: std::cout << 'A'; break;
                }
            }
            std::cout << "\n";
        }
    }
};
class affichageAmeliore : public affichage {
public:
    void afficher(const terrain& t) const override {
        const auto& tableau = t.tableau();
        for (const auto& ligne : tableau) {
            for (TypeCase caseTerrain : ligne) {
                switch (caseTerrain) {
                    case TypeCase::MUR:    std::cout << '#'; break;
                    case TypeCase::VIDE:   std::cout << ' '; break;
                    case TypeCase::DEPART: std::cout << 'S'; break;
                    case TypeCase::ARRIVEE: std::cout << 'E'; break;
                }
            }
            std::cout << "\n";
        }
    }
};
#endif // AFFICHAGE_H
