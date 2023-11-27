
#include <string>
#include <iostream>
#include <stdio.h>

#include "pico/stdlib.h"
#include "rpp.h"


RPP::RPP(int hub) {
    stdio_init_all();
}


void RPP::writeData(string out) {
    // Write data to stdout
    std::cout<<out<<std::endl;
    printf("%s", &out);
    sleep_ms(100);
}

bool RPP::readData(char *buffer) {
    // Read data from stdin
    string data = "Test Data";

    if (fgets(buffer, 100, stdin) != NULL) {
        return true;
    }

    return false;
}