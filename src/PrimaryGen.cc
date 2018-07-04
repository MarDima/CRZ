//
// Created by student on 08.05.18.
//

#include <G4Event.hh>
#include <PrimaryGen.hh>
#include "G4SystemOfUnits.hh"
#include <G4Neutron.hh>
#include <Randomize.hh>


void PrimaryGen::GeneratePrimaries(G4Event *anEvent) {
    gun->GeneratePrimaryVertex(anEvent);
}

PrimaryGen::PrimaryGen() {

    G4double a1= 2*G4UniformRand()-1;
    G4double a2= 2*G4UniformRand()-1;
    G4double a3= 2*G4UniformRand()-1;

    G4double t = sqrt(pow(a1,2)+pow(a2,2)+pow(a3,2));
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    gun->SetParticleMomentumDirection(G4ThreeVector(a1/t,a2/t,a3/t));
    gun->SetParticlePosition(G4ThreeVector(0,0,0));
    gun->SetParticleEnergy(14*MeV);
}

PrimaryGen::~PrimaryGen() {
    delete gun;
}
