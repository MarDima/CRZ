//
// Created by idalov on 12.05.18.
//

#include <StepAction.hh>
#include <EventAction.hh>
#include <G4Step.hh>
#include <G4VProcess.hh>


StepAction::StepAction(EventAction *_event) : event(_event) {}

void StepAction::UserSteppingAction(const G4Step *step) {

    if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName()=="G4_BGO")
    {
        event->AddEvent(step->GetTotalEnergyDeposit());
    } else
    {
        if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName()=="LaBr3")
        {
            event->AddEvent(step->GetTotalEnergyDeposit());
        }
    }
}