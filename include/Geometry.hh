//
// Created by student on 08.05.18.
//

#ifndef TEMPLATE_GEOMETRY_HH
#define TEMPLATE_GEOMETRY_HH

#include <G4VUserDetectorConstruction.hh>
#include "ComandMan.hh"
class ComandMan;
class Geometry: public G4VUserDetectorConstruction{

public:
    G4VPhysicalVolume *Construct() override;

    Geometry();
    virtual ~Geometry();

private:
    ComandMan* comandMan;
    G4double sphere_size;


public:
    void setSphere_size(G4double sphere_size);
};
#endif //TEMPLATE_GEOMETRY_HH
