# 🤖 Two-Axis Pick-and-Place Motion Controller

A simulated two-axis pick-and-place motion controller built using **Arduino, stepper motors and the AccelStepper library**.

The system coordinates independent X and Y axes to move between predefined pick and place positions, while applying speed, acceleration and position constraints.

> 🧪 **Simulation:** Wokwi
> ⚙️ **Platform:** Arduino
> 🔧 **Control:** AccelStepper
> 🎯 **Focus:** Multi-axis motion & position control

---

## 📌 Overview

This project explores the fundamentals of **multi-axis motion control** by coordinating two stepper-motor-driven axes.

The controller moves the X and Y axes simultaneously toward programmed coordinates, performs a simulated pick/place sequence and finally returns the system to its home position.

The project was developed and tested entirely through simulation using **Wokwi**.

---

## 🎯 Objectives

* Control two stepper motors independently.
* Coordinate X and Y axis movement.
* Move to predefined Cartesian positions.
* Apply maximum speed and acceleration limits.
* Validate target positions before executing motion.
* Execute a sequential pick-and-place routine.
* Return the system to a defined home position.

---

## 🧩 System Architecture

```text
                    Arduino
                       │
             ┌─────────┴─────────┐
             │                   │
             ▼                   ▼
        X-Axis Motor         Y-Axis Motor
        Stepper Driver       Stepper Driver
             │                   │
             ▼                   ▼
          X Motion            Y Motion
             │                   │
             └─────────┬─────────┘
                       ▼
               2-Axis Position
                   Control
                       │
                       ▼
             Pick / Place Sequence
```

---

## ⚙️ Hardware & Software

### Hardware / Simulation Components

* Arduino-compatible controller
* 2 × Stepper motors
* 2 × Stepper motor driver interfaces
* Wokwi simulation environment

### Software

* C++
* Arduino framework
* AccelStepper library
* Wokwi

---

## 🔌 Motor Configuration

| Axis   | Step Pin | Direction Pin |
| ------ | -------: | ------------: |
| X Axis |        4 |             5 |
| Y Axis |        2 |             3 |

The project uses the `AccelStepper` driver interface for both axes.

---

## 🧠 Motion Control

Both motors are configured with:

| Parameter      |        Value |
| -------------- | -----------: |
| Maximum Speed  |  800 steps/s |
| Acceleration   | 200 steps/s² |
| Position Range |       0–1999 |
| Home Position  |     `(0, 0)` |

The `movexy()` function receives an X and Y target position and commands both motors toward those coordinates.

The controller continuously executes both motor `run()` functions until the two axes reach their respective targets.

---

## 📍 Pick-and-Place Sequence

The programmed sequence consists of multiple pick and place operations.

```text
START
  │
  ▼
Move → (500, 300)
  │
  ▼
Pick
  │
  ▼
Move → (1200, 800)
  │
  ▼
Place
  │
  ▼
Move → (800, 200)
  │
  ▼
Pick
  │
  ▼
Move → (300, 1200)
  │
  ▼
Place
  │
  ▼
Return → (0, 0)
  │
  ▼
END / Repeat
```

The current implementation simulates the **motion sequence**; the physical gripping and object-detection mechanisms are not implemented.

---

## 🛡️ Position Validation

Before executing a movement command, the controller checks whether the requested coordinates are within the permitted range.

```text
0 ≤ X < 2000
0 ≤ Y < 2000
```

If an invalid position is requested, the system rejects the movement and reports:

```text
Invalid Position !!
```

This provides a basic software-level motion boundary.

---

## 🔄 Control Flow

```text
Initialize X & Y motors
        ↓
Set speed & acceleration
        ↓
Move to Pick Position
        ↓
Simulate Picking
        ↓
Move to Place Position
        ↓
Simulate Placing
        ↓
Move to next Pick Position
        ↓
Repeat Pick/Place
        ↓
Return to Home
        ↓
Repeat Sequence
```

---

## 🧪 Simulation

### ▶️ Run the Project

**[Open the live Wokwi simulation](https://wokwi.com/projects/468338816751567873)**

The simulation allows the motion sequence and serial messages to be observed directly.

---

## 📊 What This Project Demonstrates

This project helped me work with:

* Stepper motor control
* Acceleration-controlled motion
* Position-based control
* Two-axis coordination
* Sequential automation
* Motion boundaries
* State-based execution
* Arduino C++
* AccelStepper
* Simulation-based development

---

## ⚠️ Current Limitations

This is a **motion-control simulation**, rather than a complete industrial pick-and-place machine.

The current version does not include:

* Physical gripper actuation
* Object detection
* Limit switches
* Encoders / position feedback
* Collision detection
* Emergency-stop hardware
* Real-world mechanical constraints

These are potential improvements for a future version.

---

## 🚀 Future Improvements

### Version 2

* Add a servo-controlled gripper.
* Add object detection.
* Add X/Y limit switches.
* Implement homing procedure.
* Add emergency-stop logic.
* Introduce sensor feedback.

### Version 3

* Closed-loop position control.
* Dynamic target positions.
* Multiple object locations.
* Automated pick-and-place scheduling.
* Fault detection and recovery.

---

## 📚 Key Learning

The main learning from this project was understanding how **individual motor control becomes coordinated multi-axis motion**.

Instead of simply rotating a motor by a fixed number of steps, the system defines target positions and coordinates both axes toward those targets while respecting speed and acceleration constraints.

This forms a foundation for systems such as:

* CNC machines
* XY plotters
* Automated positioning systems
* Pick-and-place machines
* Robotic manipulators
* Industrial motion-control systems

---

## 🛠️ Technologies

`C++` `Arduino` `AccelStepper` `Stepper Motors` `Motion Control` `Wokwi` `Embedded Systems` `Robotics`

---

## 👨‍💻 Author

**Soham Bharat Punjal**

Electrical & Electronics Engineering
NIT Warangal

**Interests:** Robotics • Embedded Systems • Industrial Automation
