# Subsystems

### Drive Subsystem
This subsystem is in charge of controlling the robots general mobility. The core funtionality includes teleoperated driving modes and interfacing with general purpose position or orientation sensors connected to the motor controllers. Other autonomous functions to control robot positioning are also implemented here. Here are the functions defined at the subsystem level:
- Periodic: update the filter with the current velocity value of the left speed controller
- CurvatureDrive: drive via a forward velocity and radius of curvature
- ArcadeDrive: drive via a forward velocity and rotational velocity
- ResetEncoder: this will set the encoders position to 0. Useful for mitigating accumulated error
- DriveToDistance: this function will drive the robot a specific distance along a line (no ability to change orientation)
- GetVelocity: this will return the left speed controllers (filtered!) velocity. Primarily for testing purposes
- GetWheelSpeeds: this will return a set of left and right wheel speeds based on a linear and angular velocity of the differential drive

### Intake Subsystem
This subsystem is in charge of intaking the game pieces. Its goal is to pick up the game piece on the ground and put it on the transfer subsystem. This subsystem usses a motor controller that controlls the speed of the intake. It will also use a pnumatic piston to raise and lower the intake so its can be in frame peremeter. Here are some of the functions that thus subsystem usses:
- Periodic: update the filter with the current velocity value of the speed controller
- IntakeForward: runs the motors forward to intake the game piece at a certain speed
- IntakeBackward: runs the motors backward to intake the game piece at a certain speed
- LowerIntake: This lowers the intake to allow it to into contact with field elements
- RaiseIntake: This raises the intake so that it fits within frame perimeter

### Transfer Subsystem
This subsystem is in charge of moving the game pieces between subsystems. Its goal is to move the game pieces from the intake subsystem to the launcher subsystem. This subsystem uses a motor controller to control the speed of the transfer. Here are some of the function used in this subsystem:
- Periodic: update the filter with the current velocity value of the speed controller
- TransferFoward: runs the motors forward to transfer the game piece at a certain speed
- TransferBackward: runs the motors backwards to posibly unjam a stuck game peice

### Launcher Subsystem
This subsystem is in charge of launching the game pieces into the goal. Its goal is the launch the game peices into the upper hub. This subsystem usses a motor controller which can be found in the motor (falcon 500) that controlls the speed of the launch. Here are some of the function used in this subsystem:
- Periodic: update the filter with the current velocity value of the speed controller
- RunToSpeed: This runs the launcher motor up to the speed we want to launch the ball
- Stop: This stops the launcher motor

### Climber Subsystem
TODO

### Limelight Subsystem
TODO
