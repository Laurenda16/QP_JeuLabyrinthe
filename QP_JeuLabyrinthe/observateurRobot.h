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
public:
    void notifie(const robot& r) const override;
 
    int nombreDeplacement() const;
    private:
    int d_nombreDeplacement;
};

#endif // OBSERVATEURROBOT_H
