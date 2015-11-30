#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick* JoyDrv;

public:
    OI();

    Joystick* getJoyDrv();
    double getJoyDrvY();
    double getJoyDrvZ();
    double getJoyDrvThrottle();
    double applyDeadZone(double,double);
};

#endif
