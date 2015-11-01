# Potatobot
This repository gives you a skeleton of code to control a basic tank-style
drivebase using *C++*, for use with the 2015 *FRC* control system.

## Preparation

### Eclipse/WPILib
Before you can start writing code, you will need to get your computer set up
with the tools you need. Eclipse CDT is an *integrated development environment* (IDE). It is probably the easiest option to get going with programming for FRC.

1. [Download Eclipse for C/C++ from here](https://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/mars1)
2. The next step is to install the FRC Libraries for eclipse. To do this go to *Help->Install New Software->Add”. In the *Name* dialogue type *FRC Plugins for Eclipse* and  in the *Location* dialogue enter this url: http://first.wpi.edu/FRC/roborio/release/eclipse/
3. Select the *Robot C++ Development* checkbox
4. Continue through the dialogues until it is installed. When it prompts you to restart, restart. You have now installed WPILib in Eclipse!

### GitHub
The next step is to set up with *GitHub*. GitHub is a site that lets people collaborate on software projects easily using *Git*, a *version control system*, which essentially means a piece of software that lets different people work on the same code at once without conflict. Git is a very powerful piece of software, and it is worth learning how it works in more detail: https://git-scm.com/book/en/v2

1. The first step is to go to [GitHub’s Site](https://github.com/). Here you have to create an account. Do that and then proceed.
2. You need to know the URL of your team’s repository. In this case it is *github.com/thedropbears/potatobot*
3. You will have to *fork* the repository into your own account. To do this go to *github.com/thedropbears/potatobot* and click *Fork* (in the top right-hand corner).
4. Now go to Eclipse. In the *Project Explorer* tab on the left, right click *Import->Git dropbown->Projects from Git->Clone URI*. In the URI box at the top, enter *https://github.com/Your_GitHub_Username/potatobot.git*
5. Accept all the defaults. Make sure you select *Import existing Eclipse projects*.

## Planning
### Robot Configuration
You need to know about the hardware of the Potatobot if you are to control it.
On all of the robots we build we stick to a right-hand rule to define directions.

### Axes
* The forward direction on the robot is the positive X-axis.
* To the left (port side) of the robot is the positive Y-axis.
* Upwards is the positive Z-axis.
* This forms a right-hand axis system because if you take your right hand and
  point your index finger in the direction of X (forward), bend your middle, ring
  and pinky fingers at 90 degrees and point them in the direction of Y (left),
  your thumb points upwards (Z).

### Rotations
* All of our rotations are defined using the right hand rule. Point your (right
  hand) thumb in the direction of the axis of rotation, and your fingers will
  curl in the direction of a positive rotation around that axis.
* For example, when the robot spins anti-clockwise when viewed from above this is
  a positive rotation around the Z-axis. (Try it for yourself).
* We define positive rotations of wheels in the same way. Point your thumb in the
  direction of the axle through the wheel, and your fingers curl in the direction
  of a positive rotation.

### Wheel/Motor Numbering
* We name our motors alphabetically, starting with the motor in the positive-X,
  positive-Y quadrant. If there is doubt, choose the motor closest to the
  positive X-axis in the direction of a positive Z rotation. Motors are named
  sequentially as you rotate around the Z-axis in a positive direction.
* Thus, for the Potatobot motor A is the front left, B the rear left, C the rear
  right, and D the front right.

### Hardware
Find out what motor controllers are used on the Potatobot. You need to know
this if you are to write the correct code for them. Find out what number
controller is connected to each motor.

## Coding
Here comes the fun bit! But before you get going, you need to understand how
the control library we are using (WPILib) treats the components of the robot
and the tasks that it performs.

### Components
WPILib considers a robot to be made up of many *subsystems*. In our case, the
chassis is a subsystem. It is a collection of actuators and sensors that form a
logical unit. A gripper, claw or arm would be examples of other subsystems.
We have to define *methods* (or *functions*) that get the subsystem to do
something. For the chassis we might want to be able to tell it to drive at a
certain speed with a certain yaw rate (rate of change of direction).

Subsystems are used by *commands* to perform a particular task. These tasks have
a beginning and an end - we must be able to tell when we have finished the
task. For example, we might want the robot to drive forwards 2 metres and stop
in autonomous mode. The command we would write to do this would use the chassis
subsystem to achieve it.
When the command starts, it takes charge of the chassis and tells it to drive
forward at a certain speed. When the distance travelled is 2 metres, the
command tells the chassis to stop and the command stops running.

The final piece of the puzzle is how the robot knows when to start a command.
This is done through the *Operator Interface (OI)*. The OI can, for example,
start a command running when a joystick button is pressed. We can also start a
command running when the robot changes modes - a good example of this is
running a command when the autonomous period starts. Finally, subsystems can be
set up with a default command - they will keep running this command when no
other command wants to use that subsystem. An example of this type of behaviour
is a command to drive the chassis based on the joystick position. This command
runs continuously in a loop as the default command for the chassis.

### Building
There is a button on the menu bar in the top left that looks like a hammer. This button
will build the code - turn your code into binary instructions that the roboRIO can
understand. Use this button regularly to check that your code actually builds!
If it doesn't build there is a problem that you need to fix before it will work on the robot.

#### Committing
Once you have finished making a part of your code compile and run as it should, you should *commit* it
to git. Git saves snapshots (called *commits*) that describe the changes you made from the previous version.
By doing this, you can easily go back to a known working state if things get out of hand.
Commit regularly so that you have a log of what you have done. Remember, you should only have
one change per commit - this is so that if one new piece of code you write works but another doesn't, it's
easy to remove the non-working code and leave the working stuff.
To make a commit: right-click on the Potatobot project and select
*Team->Commit...*

You can share your code with your software lead by publishing it on your GitHub account.
By doing this, they can see your code and integrate it into the main repository that will actually go
onto the competition robot. This is how many students can work on the software simultaneously - you
do your work, publish it, and it gets integrated into the main project with everyone else's work.
To *push* (publish) to GitHub: right-click on the Potatobot project and select
*Team->Push to upstream*.

### Create a Chassis Subsystem
* The chassis subsystem is the place where you tell the robot how to drive. The first step to this is to find out what *class* you need for your motor controllers. 
Some common motor controller classes:
 * [Talon SRX (CAN)](http://first.wpi.edu/FRC/roborio/release/docs/cpp/classCANTalon.html)
 * [Talon SRX (PWM)](http://first.wpi.edu/FRC/roborio/release/docs/cpp/classTalonSRX.html)
 * [Victor SP (PWM)](http://first.wpi.edu/FRC/roborio/release/docs/cpp/classVictorSP.html)
* Create *instances* of the appropriate motor controller class for the chassis hardware you are using.
Set the motor controller connection IDs in the *RobotMap.h* file - this makes changing things easier
if you rewire the robot - the values are all stored in one place.
* Create a *Drive()* method in the Chassis subsystem that takes four arguments-
  the x speed (*vX*), the yaw rate/z axis rotation rate (*vZ*) and
  the throttle. vX and vZ all must be between +/-1, while the throttle
  should be between 0 and 1

### Create a DriveFromJoystick Command
* This command should read the current joystick position from the OI, and send appropriate
values (speed and yaw rate) to the *Drive()* method of the chassis subsystem.
* Make this command the default command for the chassis subsystem.

### Create a DriveForTime Command
* When this command starts running, we want to use the chassis's *drive()* method to set a speed.
We also want to set the timeout for the command.
* When the command is running it doesn't need to do anything - just wait for the timeout.
* The *IsFinished()* method should return the value of whether the command has timed out or not.
(Look up the API docs for this!) 
* When the command has ended, call the chassis's *Drive()* method to stop the motors.
* Make this command run when the robot is in autonomous mode,
and when a joystick button is pressed (your choice of button!)

## Deploy to the roboRIO
Putting your code on the roboRIO is straightforward.
* Check that you have a connection to the roboRIO - either ethernet or USB.
* Right-click the potatobot project and select *Run as->WPILib C++ Deploy*.

## Test Drive
Do some sweet drifting! (and test your code, of course!)
