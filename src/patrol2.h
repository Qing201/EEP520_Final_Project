#ifndef __PATROL2_AGENT__H
#define __PATROL2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class Patrol2Controller : public Process, public AgentInterface {

    public:
    Patrol2Controller() : Process(), AgentInterface() {}

    void init();
    void start() {}
    void update();
    void stop() {}

    // private:
    // int _id;

};

class Patrol2 : public Agent {
    public:
    Patrol2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    Patrol2Controller c;
};

DECLARE_INTERFACE(Patrol2)

#endif