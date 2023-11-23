#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

#include "stepper.h"

Stepper::Stepper(int pin_s, int pin_d, int pin_e) {
    this->pin_s = pin_s;
    this->pin_d = pin_d;
    this->pin_e = pin_e;
    this->prev_step_state = LOW;
    this->inst_usec = 0;

    gpio_init(this->pin_s);
    gpio_init(this->pin_d);
    gpio_init(this->pin_e);

    gpio_set_dir(this->pin_s, GPIO_OUT);
    gpio_set_dir(this->pin_d, GPIO_OUT);
    gpio_set_dir(this->pin_e, GPIO_OUT);

    sleep_ms(50);
}

void Stepper::step(double angular_velocity) {
    // Angular velocity takes rad/s
    long us_halfstep = (long)abs(1000000.0 / (2 * SPR * MICRO_STEPS * angular_velocity / (2.0 * PI)));
    
    // set direction
    int dir;
    if (angular_velocity > 0) {
        dir = CCW;
    } else if (angular_velocity < 0) {
        dir = CW;
    } else {
        return;
    }
    gpio_put(this->pin_d, dir);

    // step
    uint64_t curr_usec = time_us_64();
    if (curr_usec - this->inst_usec >= us_halfstep) {
        gpio_put(this->pin_s, !this->prev_step_state);
        this->prev_step_state = !this->prev_step_state;
        this->inst_usec = curr_usec;
    }
}

void Stepper::halt() {
    // set en pin to high in order to disable
    gpio_put(this->pin_e, HIGH);
}