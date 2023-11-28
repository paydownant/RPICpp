
#include <iostream>
#include "src/stepper.h"
#include "src/rpp.h"

int main(int argc, char *argv[]) {

    // Stepper stepper1(11, 12, 13);
    RPP board;
    while(1) {
        // stepper1.step(3.1415 * 2);
        board.write_data_timed("hello world");
    }
    
    return 0;
}