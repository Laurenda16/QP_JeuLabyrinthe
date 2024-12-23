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
<<<<<<< HEAD
public:
    void notifie(const robot& r) const override;
    int nombreDeplacement() const;
private:
    int d_nombreDeplacement;
=======
    int d_nombreDeplacement;
public:
    observateurRobot();
    void notifie(const robot& r) const override;
    int nombreDeplacement() const;
>>>>>>> 2a412998c24f00e23630e0da3c919839339e0b2d

};


#endif // OBSERVATEURROBOT_H
