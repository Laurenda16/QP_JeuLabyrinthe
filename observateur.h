#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

class observateur
{
public:
    virtual void notifie(const robot& r) const = 0;
    virtual ~observateur() = default;

};


#endif // OBSERVATEUR_H

