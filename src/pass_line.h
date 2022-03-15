#ifndef __PASS_LINE_AGENT__H
#define __PASS_LINE_AGENT__H 

#include "enviro.h"

using namespace enviro;

class pass_lineController : public Process, public AgentInterface {

    public:
    pass_lineController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class pass_line : public Agent {
    public:
    pass_line(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    pass_lineController c;
};

DECLARE_INTERFACE(pass_line)

#endif