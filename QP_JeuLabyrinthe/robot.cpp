#include "terrain.h"
#include "robot.h"
#include"observateurRobot.h"

robot::robot(const terrain& t,const position& pos, char direction):
     d_terrain{t},d_pos{pos}, d_direction{direction}
{}
position robot:: positionRobot() const
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

terrain robot::terain() const{
    return d_terrain;
}
void robot::notifierObservateur() const
{
    for(const auto& o : d_observateurs)
        o.notifie(*this);
}

void robot::avanceUneCase()
{
//tenir compte de sa direction
    //if(!detecterObstacle){
            switch (d_direction) {
            case 'N': d_pos.x--; break;
            case 'E': d_pos.y++; break;
            case 'S': d_pos.x++; break;
            case 'W': d_pos.x--; break;
        }


    //}

    notifierObservateur() ;
}
void robot::tounerAGauche()
{
    d_direction = (d_direction == 'N') ? 'W' : (d_direction == 'W') ? 'S' : (d_direction == 'S') ? 'E' : 'N';
    notifierObservateur() ;
}
void robot::tounerADroite()
{

    d_direction = (d_direction == 'N') ? 'E' : (d_direction == 'E') ? 'S' : (d_direction == 'S') ? 'W' : 'N';
    notifierObservateur();
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

    if (d_terrain.obtenirContenuCase(newPos) == 'X')
        return true;
    return false;
}

 */



