#include <Commands/DriveFromJoystick.h>
#include "../CommandBase.h"
#include "../RobotMap.h"

DriveFromJoystick::DriveFromJoystick() {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(chassis);

}

// Called just before this Command runs the first time
void DriveFromJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveFromJoystick::Execute() {

    double x = oi->getJoyDrvY();
    double z = oi->getJoyDrvZ();
    double throttle = oi->getJoyDrvThrottle();

    chassis->Drive(x, z, throttle);

    //SmartDashboard::PutNumber("Joystick x", x);
    //SmartDashboard::PutNumber("Joystick y", y);
    //SmartDashboard::PutNumber("Joystick z", z);
    //SmartDashboard::PutNumber("Joystick throttle", throttle);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveFromJoystick::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void DriveFromJoystick::End() {
    chassis->Drive(0.0,0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromJoystick::Interrupted() {
    End();
}
