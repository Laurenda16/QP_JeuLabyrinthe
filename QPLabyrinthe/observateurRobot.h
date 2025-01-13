#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H
#include <iostream>
#include <string>
using namespace std;



class robot;

class observateur
{
public:
    virtual ~observateur() = default;
    virtual void notifie(robot& r)  const=0;
    virtual string message(robot& r) const =0;


};
class observateurRobot : public observateur
{
public:
    string message(robot& r) const override;
    void notifie(robot& r) const override;

};

#endif
