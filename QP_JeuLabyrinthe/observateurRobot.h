#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H
#include"robot.h"


class observateur{

public:
    virtual ~observateur() = default;
    virtual void notifier(const position& p, char direction)=0;


    };

class observateurRobot :public observateur
{
    int d_nombreDeplacement;
    public:

        void notifier(const position& p, char direction) override;
        int nombreDeplacement() const;




};

#endif // OBSERVATEURROBOT_H
