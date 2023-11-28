
#include <iostream>
#include <tusb.h>
#include "pico/stdlib.h"

#include "rpp.h"


RPP::RPP(int max_message_length) {
    this->max_message_length = max_message_length;
    this->clock = 0;
    stdio_init_all();
    while (!tud_cdc_connected()) {
        sleep_ms(100);
    }

    write_data("tud_cdc_connected()");
}


void RPP::write_data(string out) {
    // Write data to stdout
    std::cout<<out<<std::endl;
}

void RPP::write_data_timed(string out, uint64_t interval) {
    // out: string to write
    // interval: interval at which string to be written in us
    uint64_t curr_clock = time_us_64();
    if (curr_clock - this->clock >= interval) {
        std::cout<<out<<std::endl;
        this->clock = curr_clock;
    }
}

string RPP::read_data() {
    // check stdin buffer
    char buffer[this->max_message_length];
    uint buffer_index = 0;
    while (tud_cdc_available()) {
        char inByte = getchar();
        if (inByte != '\n' && (buffer_index > max_message_length - 1)) {
            buffer[buffer_index] = inByte;
            buffer_index++;
        } else {
            buffer[buffer_index] =  '\0';
            buffer_index = 0;
            return buffer;
        }
    }
    return NULL;
}