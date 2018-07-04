//
// Created by student on 27.04.18.
//
#include <fstream>
#include "EventAction.hh"
#include "RunAction.hh"
using namespace std;


EventAction::EventAction(RunAction* runAct) :run(runAct) {

}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event* anEvent) {
    EnergyDep = 0;
}

void EventAction::EndOfEventAction(const G4Event* anEvent) {
    run->AddEnergy("orb1",EnergyDep);
    run->AddEnergy("orb2",EnergyDep);
}


void EventAction::AddEvent(G4double energy){
    EnergyDep += energy;
}
