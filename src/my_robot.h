#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H 

#include "enviro.h"

using namespace enviro;

// Player control robot, with keyboard control and hint detection
class MyRobotController : public Process, public AgentInterface {

    public:
    MyRobotController() : Process(), AgentInterface() {}

    void init();
    void start() {}
    void update();
    void stop() {}

};

class MyRobot : public Agent {
    public:
    MyRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MyRobotController c;
};

DECLARE_INTERFACE(MyRobot)

#endif