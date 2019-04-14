//
// Created by VaGroZ on 14.04.2019.
//
#include<G4VUserActionInitialization.hh>
#ifndef IBD_ACTIONINIT_H
#define IBD_ACTIONINIT_H


class ActionInit: public G4VUserActionInitialization {
public:
    virtual void Build() const;
};


#endif //IBD_ACTIONINIT_H
