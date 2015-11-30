#include "Chassis.h"
#include "../RobotMap.h"

Chassis::Chassis() : Subsystem("Chassis")
{
    motor_a = new Talon(Motor_a_Pos);
    motor_b = new Talon(Motor_b_Pos);
    motor_c = new Talon(Motor_c_Pos);
    motor_d = new Talon(Motor_d_Pos);
}

void Chassis::Drive(double vX, double vY, double vZ, double Throttle) {
    //Set up variables for each motor
    double mA;
    double mB;
    double mC;
    double mD;

    mA = vX - vZ + vY;
    mB = vX - vZ + vY;
    mC = -vX + vZ - vY;
    mD = -vX + vZ - vY;

    double array [] = {mA, mB, mC, mD};

    double max;

    for (int i = 0; i <= 3; i += 1)
    {
        if (abs(array[i]) > max)
        {
                max = abs(array[i]);
        }
    }

    for (int i =0; i <= 3; i += 1)
    {
        array[i] = array[i]/max;
    }

    for (int i =0; i <= 3; i += 1)
    {
        array[i] = array[i] * Throttle;
    }


    motor_a->Set(array[0]);
    motor_b->Set(array[1]);
    motor_c->Set(array[2]);
    motor_d->Set(array[3]);

}

void Chassis::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

