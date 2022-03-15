#include <iostream>
#include "my_robot.h"

using namespace enviro;
using namespace std;

int LEVEL = 1;
int speed = 100;
int speed_x = 0;
int speed_y = 0;
bool lose = 0;

void MyRobotController::init() {

    // watching the keyboard to move the robot
    watch("keydown", [&](Event &e) {
        auto k = e.value()["key"].get<std::string>();
        if ( k == "w" ) {
            speed_y = -speed;              
        } else if ( k == "s" ) {
            speed_y = speed;     
        } else if ( k == "a" ) {
            speed_x = -speed;  
        } else if ( k == "d" ) {
            speed_x = speed;  
        } 
    });

    watch("keyup", [&](Event &e) {           
        auto k = e.value()["key"].get<std::string>();
        if ( k == "w" || k == "s" ) {
            speed_y = 0;               
        }
        if ( k == "a" || k == "d") {
            speed_x = 0;
        }
    });

    //when player hit the patrol, restart the position
    notice_collisions_with("Patrol", [&](Event &e) {
        lose = 1;
    });
    notice_collisions_with("Patrol2", [&](Event &e) {
        lose = 1;
    });
    notice_collisions_with("Wanderer", [&](Event &e) {
        lose = 1;
    });

    //when player win the game
    notice_collisions_with("pass_line", [&](Event &e) {
        LEVEL += 0.25;
        teleport(-300, 0, 0);
        label("WON!!!", -25, -25);
    });
}

void MyRobotController::update() {
    // if hit the patrol, reset the position
    if(lose == 1){
        teleport(-300, 0, 0);
        lose = 0;
        label("Try Again!!!", -25, -25);
    }

    // move the robot
    omni_apply_force(speed_x,speed_y);
}