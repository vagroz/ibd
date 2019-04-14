//
// Created by VaGroZ on 14.04.2019.
//

#include <G4Box.hh>
#include "G4SystemOfUnits.hh"
#include <G4NistManager.hh>
#include <G4Orb.hh>
#include <G4PVPlacement.hh>
#include <G4LogicalVolume.hh>
#include <G4VUserDetectorConstruction.hh>

#include "DetectorConstruction.h"

G4VPhysicalVolume* DetectorConstruction::Construct() {

    G4double size = 100*cm;
    G4Box *solidWorld = new G4Box("world", size / 2., size / 2., size / 2.);
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *world_mat = nist->FindOrBuildMaterial("G4_AIR");
    G4LogicalVolume *logicalWorld = new G4LogicalVolume(solidWorld, world_mat, "world");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, //rotation
                                                     G4ThreeVector(),
                                                     logicalWorld,
                                                     "world_PVP",
                                                     0,                 //mother's world
                                                     false,
                                                     0);

    G4Box* orb = new G4Box("my_orb", 40*cm, 40*cm, 45*cm);
    G4LogicalVolume *logicDetector = new G4LogicalVolume(orb, world_mat, "detector");
    new G4PVPlacement(0, G4ThreeVector(), logicDetector, "detector", logicalWorld, false, 0);

    //world_log->SetVisAttributes(G4VisAttributes::Invisible);

    return physWorld;

}
