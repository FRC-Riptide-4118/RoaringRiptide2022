# Subsystems

### Drive Subsystem
This subsystem is in charge of controlling the robots general mobility. The core funtionality includes teleoperated driving modes and interfacing with general purpose position or orientation sensors connected to the motor controllers. Other autonomous functions to control robot positioning are also implemented here. Here are the functions defined at the subsystem level:
- Periodic: not implemented
- CurvatureDrive: drive via a forward velocity and radius of curvature
- ArcadeDrive: drive via a forward velocity and rotational velocity
- SetHighGear: for robots with a shifting gearbox, this will set the high gear
- SetLowGear: for robots with a shifting gearbox, this will set the low gear
- ResetEncoder: this will set the encoders position to 0. Useful for mitigating accumulated error
- DriveToDistance: this function will drive the robot a specific distance along a line (no ability to change orientation.)
