
#include "axle.h"
#include "stepper.h"

Axle::Axle() {
    this->s1 = new Stepper(12,13,14);
    this->s2= new Stepper(15,16,17);
    this->s3 = new Stepper(18,19,20);
}

void Axle::motionVector(double platform_vx, double platform_vy, double platform_av) {
    /*  Takes x and y components in mm/s
        Works with stepper configuration of
       ↑                        ↑
       1 ---------------------- 2
                    |
                    O
                    |
                    |
                    |
                    ↑
                    3                   */
    
    s1->step((platform_vx * S1VAR1 + platform_vy * S1VAR2 + platform_av * PLATFORM_RADIUS) / WHEEL_RADIUS);
    s2->step((platform_vx * S2VAR1 + platform_vy * S2VAR2 + platform_av * PLATFORM_RADIUS) / WHEEL_RADIUS);
    s3->step((platform_vx * S3VAR1 + platform_vy * S3VAR2 + platform_av * PLATFORM_RADIUS) / WHEEL_RADIUS);

}