#ifndef POTATOBOT_H_
#define POTATOBOT_H_

#include "WPILib.h"
#include "Commands/ExampleCommand.h"

#include "Subsystems/ExampleSubsystem.h"
#include "OI.h"

class Potatobot: public IterativeRobot {
public:
    static OI* oi;
    static ExampleSubsystem* exampleSubsystem;

private:
    Command *autonomousCommand;
    LiveWindow *lw;

    void RobotInit();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    void TestPeriodic();
    void DisabledPeriodic();
};


#endif /* POTATOBOT_H_ */
