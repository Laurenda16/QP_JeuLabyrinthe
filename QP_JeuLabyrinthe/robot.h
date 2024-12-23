#ifndef ROBOT_H
#define ROBOT_H
#include <memory>
#include <vector>

#include "terrain.h"
#include "observateurRobot.h"
class robot
{
    public:
        robot(const terrain& t, const position& pos, char direction);
        position positionRobot() const;
        char direction() const;
        terrain terain() const;
        void avanceUneCase();
        void tounerAGauche() ;
        void tounerADroite() ;

        bool detecterObstacle() const;
        void notifierObservateur() const ;
        void enregistrerObservateur(const observateurRobot& ob) ;



private:
    terrain d_terrain;
    position d_pos;
    std::vector<observateurRobot> d_observateurs;
    char d_direction; //N,E,S,W
#endif // ROBOT_H


