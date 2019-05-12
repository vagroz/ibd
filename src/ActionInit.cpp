//
// Created by VaGroZ on 14.04.2019.
//

#include <G4ParticleGun.hh>
#include "G4SystemOfUnits.hh"
#include <G4Positron.hh>
#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4Proton.hh>
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "ActionInit.h"

class PrimaryGeneration: public G4VUserPrimaryGeneratorAction {
private:
    G4ParticleGun* gun;
public:
    PrimaryGeneration(){
        gun = new G4ParticleGun(1);
        G4ParticleTable* table = G4ParticleTable::GetParticleTable();
        G4ParticleDefinition* particle = table->FindParticle("e+");
        gun->SetParticleDefinition(particle);
        gun->SetParticleEnergy(50 * MeV);
        gun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    };
    ~PrimaryGeneration(){
        delete gun;
    };
    void GeneratePrimaries(G4Event* anEvent){
        G4double x = -1 *cm, y = 0, z = -10. * cm;
        gun->SetParticlePosition(G4ThreeVector(x, y, z));
        gun->GeneratePrimaryVertex(anEvent);
    };
};

void ActionInit::Build() const {
    SetUserAction(new PrimaryGeneration());
}