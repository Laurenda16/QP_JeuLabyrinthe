#ifndef ROBOT_H
#define ROBOT_H
#include <memory>
#include <vector>

#include "terrain.h"
#include "observateurRobot.h"



class robot
{
    public:
        robot(const position& pos, char direction);
         position positionXY() const;
        char direction() const;

        void avanceUneCase();
        void tounerAGauche() ;
        void tounerADroite() ;
          bool detecterObstacle() const;
        void notifierObservation() const ;
        void enregistrerObservateur(const observateurRobot& ob) ;



    private:
       position d_pos;
     std::vector<observateurRobot> d_observateurs;
     char d_direction; //N,E,S,W
};

#endif // ROBOT_H


