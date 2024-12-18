#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H

class observateur{

public:
    virtual ~observateur() = default;
    virtual void notifier(int x, int y, char direction)=0;


    };

class observateurRobot :public observateur
{
    public:
        observateurRobot();
        virtual ~observateurRobot() override;
        int nombreDeplacement() const;



    private:
        int d_nombreDeplacement;
};

#endif // OBSERVATEURROBOT_H
