#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H
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
    string message() const ;
    void notifie(const robot& r) const override;

};

#endif // OBSERVATEURROBOT_H
