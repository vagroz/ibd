//
// Created by VaGroZ on 14.04.2019.
//

#include <G4ParticleGun.hh>
#include <G4SIunits.hh>
#include <G4Positron.hh>
#include <G4VUserPrimaryGeneratorAction.hh>
#include "ActionInit.h"

class PrimaryGeneration: public G4VUserPrimaryGeneratorAction {
private:
    G4ParticleGun* gun;
public:
    PrimaryGeneration(){
        gun = new G4ParticleGun(1);
        gun->SetParticleDefinition(G4Positron::PositronDefinition());
        gun->SetParticleEnergy(0.661 * MeV);
        gun->SetParticlePosition(G4ThreeVector(0, 0, -10*m));
        gun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
    };
    ~PrimaryGeneration(){
        delete gun;
    };
    virtual void GeneratePrimaries(G4Event* anEvent){
        gun->GeneratePrimaryVertex(anEvent);
    };
};

void ActionInit::Build() const {
    SetUserAction(new PrimaryGeneration());
}