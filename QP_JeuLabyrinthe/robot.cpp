#include "terrain.h"
#include "robot.h"

 robot::robot(const position& pos, char direction):d_pos{pos}, d_direction{direction}
{

}
position robot:: positionXY() const
    {
        return d_pos;
}
char  robot::direction() const
{
     switch (d_direction) {
        case 'N': return '^';
        case 'E': return '>';
        case 'S': return 'v';
        case 'W': return '<';
        default: return '?';
}
}

/*
void robot::notifierObservateur()
{
   for(const auto& o : d_observateurs)
{
   // o->notifier(x, y,direction);

}*/
void robot::avanceUneCase()
{
//tenir compte de sa direction
            switch (d_direction) {
            case 'N': d_pos.x--; break;
            case 'E': d_pos.y++; break;
            case 'S': d_pos.x++; break;
            case 'W': d_pos.x--; break;
        }

    // notifierObservation() ;
}
    void robot::tounerAGauche()
        {
 d_direction = (d_direction == 'N') ? 'W' : (d_direction == 'W') ? 'S' : (d_direction == 'S') ? 'E' : 'N';
     // notifierObservation() ;
        }
void robot::tounerADroite()
        {

       d_direction = (d_direction == 'N') ? 'E' : (d_direction == 'E') ? 'S' : (d_direction == 'S') ? 'W' : 'N';
      //  notifierObservateur();
        }

 void enregistrerObservateur(const observateurRobot& ob) ;

