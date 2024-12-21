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


void robot::avanceUneCase()
{
//tenir compte de sa direction
    if(!detecterObstacle){

        switch (d_direction) {
        case 'N': d_pos.x--; break;
        case 'E': d_pos.y++; break;
        case 'S': d_pos.x++; break;
        case 'W': d_pos.x--; break;
        }
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

 void robot::enregistrerObservateur(const observateurRobot& ob){
     d_observateurs.push_back(ob);
 }

 /*
 bool robot::detecterObstacle() const{
    position newPos = d_pos;
    if (d_direction == 'N') --newPos.x;
    else if (d_direction == 'E') ++newPos.y;
    else if (d_direction == 'S') ++newPos.x;
    else if (d_direction == 'W') --newPos.y;

    if (d_terrain->obtenirContenuCase(newPos) == 'X')
        return true;
    return false;
}

 */

void robot::notifierObservateur() const
{
   for(const auto& o : d_observateurs){
    o.notifier(d_pods.x,d_pos.y,direction);
    }

 }


