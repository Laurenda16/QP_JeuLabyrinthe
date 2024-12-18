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

        virtual ~observateurRobot() override;
        virtual void notifier(int x, int y, char direction)=0;
        int nombreDeplacement() const;



    private:
        int d_nombreDeplacement;
};

#endif // OBSERVATEURROBOT_H
