
#include <iostream>

#include "src/rpp.h"
#include "src/stepper.h"

int main(int argc, char *argv[]) {
    RPP board("/dev/ttyACM0","controller/main.py");
    // board.printData();
    
    Stepper stepper1(11, 12, 13);

    while(1) {
        stepper1.step(3.1415 * 2);
    }
    
    return 0;
}