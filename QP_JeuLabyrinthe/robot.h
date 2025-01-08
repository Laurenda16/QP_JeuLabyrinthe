#ifndef ROBOT_H
#define ROBOT_H
#include <memory>
#include <vector>
#include "terrain.h"
#include "observateurRobot.h"
class affichage;

class robot {
public:
    robot(const terrain& t);
    position positionXY() const;
    char direction() const;
    int nombreDeplacement() const;
    terrain terain() const;
    void avanceUneCase();
    void tournerAGauche();
    void tournerADroite();
    bool detecterObstacle() const;
    void notifierObservation();
    void enregistrerObservateur(const observateurRobot& ob);
    void affiche(std::ostream& ost, const robot& r) const ;
    bool tournerEtAvancerAGauchePossible();
    void algorithmDeMainDroite(affichage& aff);
    void algorithmeDePledge(affichage& aff);
private:
    position d_pos;
    char d_direction;  // N, E, S, W
    const terrain& t;
    std::vector<observateurRobot> d_observateurs;
    int d_nombreDeplacement;

};
#endif // ROBOT_H

