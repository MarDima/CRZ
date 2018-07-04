//
// Created by student on 08.05.18.
//

#include <G4VPhysicalVolume.hh>
#include <Geometry.hh>
#include <G4Box.hh>
#include <G4RunManager.hh>
#include <G4Sphere.hh>
#include <G4NistManager.hh>
#include "G4SystemOfUnits.hh"
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>


G4VPhysicalVolume *Geometry::Construct()
{

G4NistManager * nist = G4NistManager::Instance();



    G4Element *La1 = new G4Element("La1","La",57,140* g / mole);

    G4Element *Br1 = new G4Element("Br1","Br",35,79* g / mole);

    G4Material *LaBr3= new G4Material("LaBr3",5*g/cm3,1,kStateSolid);
    LaBr3->AddElement(nist->FindOrBuildElement("La"),1);
//    LaBr3->AddElement(nist->FindOrBuildElement("Br"),3);


//
    G4double world_size = 5*m;
    auto world = new G4Box("world", world_size/2.,world_size/2.,world_size/2.);
    auto world_log = new G4LogicalVolume(world,nist->FindOrBuildMaterial("G4_AIR"),"world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);


    auto Sphere1 = new G4Sphere("orb1",10*cm,20*cm,0,360*deg,0,360*deg);
    auto Sphere_log1= new G4LogicalVolume(Sphere1,nist->FindOrBuildMaterial("G4_POLYETHYLENE"),"Sphere_log1");
    new G4PVPlacement(0,G4ThreeVector(0,0,0),Sphere_log1,"orb_pvp1",world_log,false,0);

    auto Sphere2 = new G4Sphere("orb2",20*cm,30*cm,180*deg,360*deg,0*deg,180*deg);
   auto Sphere_log2= new G4LogicalVolume(Sphere2,nist->FindOrBuildMaterial("G4_La"),"orb_log2");
//   std::cout<<Sphere_log2->GetMaterial()<<"\n";

   new G4PVPlacement(nullptr,G4ThreeVector(),Sphere_log2,"orb_pvp2",world_log,false,0);


    auto Sphere3 = new G4Sphere("orb3",20*cm,sphere_size*cm,0,180*deg,0,180*deg);
    auto Sphere_log3= new G4LogicalVolume(Sphere3,nist->FindOrBuildMaterial("G4_BGO"),"orb_log3");
    new G4PVPlacement(nullptr,G4ThreeVector(),Sphere_log3,"orb_pvp3",world_log,false,0);

    return new G4PVPlacement(nullptr,G4ThreeVector(),world_log,"world_pvp", nullptr,false,0);
}

Geometry::Geometry()

{
    comandMan = new ComandMan (this);
    sphere_size = 30;

}

void Geometry::setSphere_size(G4double sphere_size) {

    Geometry::sphere_size = sphere_size;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

Geometry::~Geometry()
{
    delete comandMan;
}