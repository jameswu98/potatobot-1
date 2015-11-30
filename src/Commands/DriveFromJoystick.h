#ifndef DRIVE_FROM_JOYSTICK_H
#define DRIVE_FROM_JOYSTICK_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFromJoystick: public CommandBase
{
public:
    DriveFromJoystick();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
