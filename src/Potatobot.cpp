#include <Potatobot.h>
#include "WPILib.h"
#include "Commands/ExampleCommand.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* Potatobot::exampleSubsystem = NULL;
OI* Potatobot::oi = NULL;

void Potatobot::RobotInit()
{
    autonomousCommand = new ExampleCommand();
    lw = LiveWindow::GetInstance();

    // Show what command your subsystem is running on the SmartDashboard
    SmartDashboard::PutData(exampleSubsystem);
}

void Potatobot::DisabledPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Potatobot::AutonomousInit()
{
    if (autonomousCommand != NULL)
        autonomousCommand->Start();
}

void Potatobot::AutonomousPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Potatobot::TeleopInit()
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (autonomousCommand != NULL)
        autonomousCommand->Cancel();
}

void Potatobot::TeleopPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Potatobot::TestPeriodic()
{
    lw->Run();
}


START_ROBOT_CLASS(Potatobot);

