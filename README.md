# Autonomous Obstacle Avoidance Car 🤖

### Description
An intelligent robotic platform that navigates independently in unknown environments. It uses a fusion of ultrasonic ranging and servo-motor scanning to map the surroundings and make real-time movement decisions.

### Key Features
* **180° Environment Scanning:** Uses an Ultrasonic sensor on a Servo motor to detect the best path when an obstacle is encountered.
* **Fail-Safe Logic:** Implements threshold-based stopping and reversing algorithms to prevent collisions[cite: 1].
* **Power Management:** Efficient DC motor control using the L293D H-Bridge driver[cite: 1].

### Tech Stack
* **MCU:** ATmega32[cite: 1].
* **Sensors:** HC-SR04 Ultrasonic, Servo Motor[cite: 1].
* **Drivers:** L293D Motor Driver[cite: 1].
