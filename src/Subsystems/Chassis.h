#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"

class Chassis: public Subsystem
{
private:
    Talon* motor_a;
    Talon* motor_b;
    Talon* motor_c;
    Talon* motor_d;
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
public:
    Chassis();
    ~Chassis();
    void Drive(double vX, double vY, double vZ, double Throttle);
    void InitDefaultCommand();
};

#endif
