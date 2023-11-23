#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pico.h"
#include "hardware/time.h"
#include "pico/stdlib.h"

#include "stepper.h"

Stepper::Stepper(int pin_s, int pin_d, int pin_e) {
    this->pin_s = pin_s;
    this->pin_d = pin_d;
    this->pin_e = pin_e;
    this->prev_step_state = LOW;
    this->time_step = 0;

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
    long step_delay = abs(1 / (SPR * 2 * angular_velocity * 1000 / (2 * PI)));
    
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
    uint64_t curr_msec = time_us_64();
    if (curr_msec - this->time_step >= step_delay) {
        int step;
        if (this->prev_step_state == LOW) {
            step = HIGH;
        } else if (this->prev_step_state == HIGH) {
            step = LOW;
        } else {
            printf("error: no prev step state \n");
            return;
        }
        gpio_put(this->pin_s, step);
        this->prev_step_state = step;
        this->time_step = curr_msec;
    }
    
}

void Stepper::halt() {
    // set en pin to high in order to disable
    gpio_put(this->pin_e, HIGH);
}