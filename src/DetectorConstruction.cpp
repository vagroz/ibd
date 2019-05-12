//
// Created by VaGroZ on 14.04.2019.
//

#include <G4Box.hh>
#include "G4SystemOfUnits.hh"
#include <G4NistManager.hh>
#include "G4RunManager.hh"
#include <G4PVPlacement.hh>
#include <G4LogicalVolume.hh>
#include <G4VisAttributes.hh>
#include <G4Orb.hh>

#include "DetectorConstruction.h"

G4VPhysicalVolume* DetectorConstruction::Construct() {

    G4double size = 30.*cm;
    G4Box *solidWorld = new G4Box("world", size / 2., size / 2., size / 2.);
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *world_mat = nist->FindOrBuildMaterial("G4_AIR");
    G4LogicalVolume *logicalWorld = new G4LogicalVolume(solidWorld, world_mat, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, //rotation
                                                     G4ThreeVector(),
                                                     logicalWorld,
                                                     "World",
                                                     0,                 //mother's world
                                                     false,
                                                     0);

    G4Orb* orb = new G4Orb("my_orb", 5. * cm);
    G4LogicalVolume *logicDetector = new G4LogicalVolume(orb, nist->FindOrBuildMaterial("G4_W"), "Detector");
    new G4PVPlacement(0, G4ThreeVector(0,0,15.*cm), logicDetector, "Detector", logicalWorld, false, 0);

//    logicalWorld->SetVisAttributes(G4VisAttributes::Invisible);

    return physWorld;

}
