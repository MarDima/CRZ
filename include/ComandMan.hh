//
// Created by idalov on 04.07.18.
//

#ifndef M_DGW_5_COMANDMAN_HH
#define M_DGW_5_COMANDMAN_HH
#include <G4UImessenger.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <Geometry.hh>
#include <StepAction.hh>
#include <PrimaryGen.hh>
#include <EventAction.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWith3Vector.hh>

class Geometry;
class StepAction;
class PrimaryGen;
class ComandMan :public G4UImessenger{

    G4UIcmdWithADouble * ras;
    Geometry* my_geom;

public:
    ComandMan(Geometry* geom);
    ~ComandMan();
    void SetNewValue(G4UIcommand *command, G4String newValue) override;

};
#endif //M_DGW_5_COMANDMAN_HH
