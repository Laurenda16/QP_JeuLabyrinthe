#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H
#include "robot.h"

class robot;

class observateur
{
public:
    virtual ~observateur() = default;
    virtual void notifie(const robot& r) const = 0;


};

class observateurRobot : public observateur
{
    int d_nombreDeplacement;
public:
    observateurRobot();
    void notifie(const robot& r) const override;
    int nombreDeplacement() const;

};

#endif // OBSERVATEURROBOT_H
