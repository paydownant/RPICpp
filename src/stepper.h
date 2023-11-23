#ifndef STEPPER_H
#define STEPPER_H

class Stepper {
    public:
    // Constructor
    Stepper(int pin_s, int pin_d, int pin_e);

    // Methods
    void step(double angular_velocity);
    void stepTest(double angular_velocity);
    void halt(); 

    private:
    // Variables
    const int CW = 0;
    const int CCW = 1;

    const int HIGH = 1;
    const int LOW = 0;

    const int SPR = 200;
    const double PI = 3.14159265359;

    int pin_s;
    int pin_d;
    int pin_e;

    int prev_step_state;
    uint64_t time_step;

};

#endif