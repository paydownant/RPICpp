#ifndef AXLE_H
#define AXLE_H

#include "stepper.h"

class Axle {
    public:
        // Constructor
        Axle();

        // Methods
        void motionVector(double x, double y, double platform_av);

    private:

        // Pre-calculated trigonometry values
        const double S1VAR1 = 0.5;
        const double S1VAR2 = 0.86602540378;
        const double S2VAR1 = 0.5;
        const double S2VAR2 = -0.86602540378;
        const double S3VAR1 = -1.0;
        const double S3VAR2 = 0.0;
        
        // Pre-configured dimensions (mm)
        const double WHEEL_RADIUS = 25.0;
        const double PLATFORM_RADIUS = 78.8010753607;

        Stepper* s1;
        Stepper* s2;
        Stepper* s3;

};


#endif