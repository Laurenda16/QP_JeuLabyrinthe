#ifndef ROBOT_H
#define ROBOT_H
#include <memory>

#include "point.h"
#include "observateurRobot.h"



class robot
{
    public:
        robot();
        bool obstacleEstDetecte() const;
        int avanceUneCase();
        void tounerAGauche() ;
        void tounerADroite() ;
        void notifierObservation() const ;
        void enregistrerObservateur() ;

///cardinal direction
  enum { east=0, north=90, west=180, south=270 };


    private:
       geom::point d_pos;
     std::vector<std::unique_ptr<observateurRobot> d_observateurs;
       Direction d_direction;
};

#endif // ROBOT_H


