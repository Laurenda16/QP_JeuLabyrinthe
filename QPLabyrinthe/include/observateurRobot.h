#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H
#include <iostream>
#include <string>


class robot;

class observateur
{
public:
    virtual ~observateur() = default;
    virtual void notifie(const robot& r) const = 0;
    virtual std::string message() const =0;


};
class observateurRobot : public observateur
{
public:
    std::string message() const override;
    void notifie(const robot& r) const override;

};

#endif // OBSERVATEURROBOT_H
