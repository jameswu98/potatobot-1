#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "WPILib.h"

class ExampleCommand: public Command
{
public:
    ExampleCommand();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
