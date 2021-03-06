#ifndef __PATROL_AGENT__H
#define __PATROL_AGENT__H 

#include "enviro.h"

using namespace enviro;

// The fixed-point patroller
class PatrolController : public Process, public AgentInterface {

    public:
    PatrolController() : Process(), AgentInterface() {}

    void init();
    void start() {}
    void update();
    void stop() {}

};

class Patrol : public Agent {
    public:
    Patrol(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    PatrolController c;
};

DECLARE_INTERFACE(Patrol)

#endif