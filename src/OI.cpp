#include "OI.h"

OI::OI()
{
    JoyDrv = new Joystick(1);// Process operator interface input here.
}

double OI::getJoyDrvY(){
    return JoyDrv->GetY();
}

double OI::getJoyDrvZ(){
    return JoyDrv->GetZ();
}

double OI::getJoyDrvThrottle(){
    return (JoyDrv->GetTwist()-1.0)/2.0;

}
