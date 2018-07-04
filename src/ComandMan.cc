//
// Created by idalov on 04.07.18.
//

#include "ComandMan.hh"
void ComandMan::SetNewValue(G4UIcommand *command, G4String newValue) {

    if(command == ras)
        my_geom->setSphere_size(ras->GetNewDoubleValue(newValue));

}
ComandMan::ComandMan(Geometry* geom): my_geom(geom)
{
    auto dir = new G4UIdirectory("/my_com/");

    ras= new G4UIcmdWithADouble("/my_com/ras",this);
    ras->SetDefaultValue(12);







}
ComandMan::~ComandMan() {
}