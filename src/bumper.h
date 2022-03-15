#ifndef __BUMPER_AGENT__H
#define __BUMPER_AGENT__H 

#include "enviro.h"

// Up and down bumper to detect whether to change the direction of the patrol

using namespace enviro;

class bumperController : public Process, public AgentInterface {

    public:
    bumperController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class bumper : public Agent {
    public:
    bumper(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    bumperController c;
};

DECLARE_INTERFACE(bumper)

#endif