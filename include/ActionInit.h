//
// Created by VaGroZ on 14.04.2019.
//

#ifndef IBD_ACTIONINIT_H
#define IBD_ACTIONINIT_H

#include<G4VUserActionInitialization.hh>
class ActionInit: public G4VUserActionInitialization {
public:
    virtual void Build() const;
};


#endif //IBD_ACTIONINIT_H
