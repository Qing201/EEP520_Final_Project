#include <iostream>
#include "patrol.h"


using namespace enviro;
using namespace std;

int LEVEL = 1;
int ID;
int speed = LEVEL * 300;

void PatrolController::init() {
    // notice when a patrol touched the bumper
    notice_collisions_with("bumper", [&](Event &e) {
        ID = id();
    });
}

void PatrolController::update() {

    // change the direction of patrol which touch the bumper
    if ( ID == id() ){
        if (y()>=0){
            omni_apply_force(0,-speed);
        }else{
            omni_apply_force(0,speed);
        }
    }else{
        if (vy()>0){
            omni_apply_force(0,speed);
        }else{
            omni_apply_force(0,-speed);
        }
    }
}