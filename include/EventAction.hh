
#ifndef M_DGW_4_EVENTACTION_HH
#define M_DGW_4_EVENTACTION_HH


#include "RunAction.hh"
#include "StepAction.hh"
#include <G4UserEventAction.hh>
#include <G4String.hh>
using namespace std;
class RunAction;

class EventAction : public G4UserEventAction {
public:

    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);
    void AddEvent(G4double energy);

    EventAction(RunAction* runAct);
    ~EventAction();
private:

    RunAction * run;
    G4double EnergyDep;

};



#endif //M_DGW_4_EVENTACTION_HH