//
// Created by VaGroZ on 14.04.2019.
//

#ifndef IBD_DETECTORCONSTRUCTION_H
#define IBD_DETECTORCONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    virtual G4VPhysicalVolume* Construct();

    //virtual void ConstructSDandField();
};


#endif //IBD_DETECTORCONSTRUCTION_H
