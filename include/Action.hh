//
// Created by student on 08.05.18.
//

#ifndef TEMPLATE_ACTION_HH
#define TEMPLATE_ACTION_HH

#include <G4VUserActionInitialization.hh>
#include "PrimaryGen.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "StepAction.hh"

class PrimaryGen;
class Action: public G4VUserActionInitialization{
public:
    void Build() const override {
        SetUserAction(new PrimaryGen());
       // auto run = new RunAction;
      //  auto event = new EventAction(run);
      //  SetUserAction(run);
      //  SetUserAction(event);
      //  SetUserAction(new StepAction(event));
    }
};
#endif //TEMPLATE_ACTION_HH
