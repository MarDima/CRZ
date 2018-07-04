//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_STEPACTION_HH
#define TEMPLATE_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <G4String.hh>

class EventAction;
class StepAction : public G4UserSteppingAction{
    EventAction* event;

public:
    explicit StepAction(EventAction *event);

    void UserSteppingAction(const G4Step *step) override;

};
#endif //TEMPLATE_STEPACTION_HH

