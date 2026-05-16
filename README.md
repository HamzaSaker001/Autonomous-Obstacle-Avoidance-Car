# 🤖 Autonomous Obstacle-Avoiding Car

A self-driving embedded car that uses an ultrasonic sensor mounted on a servo motor to scan its environment across 180°, detect obstacles, and autonomously decide its next direction — all in real time.

---

## 📌 Project Overview

This project implements a fully autonomous ground vehicle that navigates its environment without human input. An HC-SR04 ultrasonic sensor rotates on a servo axis to scan ahead and to both sides. When an obstacle is detected within range, the car stops, evaluates both directions, and chooses the clearest path to continue moving.

---

## ✨ Features

- 🔍 **180° ultrasonic scanning** — servo-mounted sensor sweeps the environment
- ⚡ **Fast obstacle response** — stops and reroutes immediately on detection
- 🧭 **Autonomous direction decision** — compares left and right clearance to choose path
- 🚗 **Dual-motor drive** — speed and direction controlled via L293D
- 📟 **LCD status display** — shows current movement direction in real time
- 🔋 **Standalone embedded system** — no external computer or Wi-Fi required

---

## 🗂️ System Architecture

```
                    ┌──────────────────────────┐
  HC-SR04           │       ATmega32 MCU        │
  (Ultrasonic) ────►│                          │──► Servo Motor (scan axis)
                    │  • Distance measurement   │
                    │  • Obstacle detection     │──► L293D ──► Motor 1 (Left)
                    │  • Direction decision     │
                    │  • Motor speed control   │──► L293D ──► Motor 2 (Right)
                    │                          │
                    │                          │──► LCD (direction display)
                    └──────────────────────────┘
```

---

## ⚙️ Decision Algorithm

```
LOOP:
  Scan FORWARD via ultrasonic
  IF distance < threshold:
    STOP motors
    Scan LEFT  → save distance_left
    Scan RIGHT → save distance_right

    IF distance_left > distance_right:
      TURN LEFT
    ELSE:
      TURN RIGHT

    Resume FORWARD movement
  ELSE:
    Continue FORWARD
```

---

## 🧰 Components

| Component | Model | Purpose |
|---|---|---|
| Microcontroller | ATmega32 | Main processing & control |
| Ultrasonic Sensor | HC-SR04 | Obstacle distance measurement |
| Servo Motor | Standard (SG90) | Rotates ultrasonic sensor 0–180° |
| Motor Driver | L293D | Controls speed & direction of both motors |
| DC Motors | x2 | Drive wheels |
| Caster Wheel | — | Front balance support |
| Chassis | — | Car frame / body |
| LCD | 16x2 Character | Displays current direction |
| Battery | — | Power supply |

---

## 🔌 Interfaces Used

- **GPIO / Timer (Input Capture)** — HC-SR04 trigger & echo measurement
- **PWM** — Servo motor position control (0°–180°)
- **PWM** — L293D motor speed control
- **GPIO** — L293D direction control
- **GPIO** — LCD display (4-bit mode)

---

## 📐 Ultrasonic Distance Formula

```
Distance (cm) = (Echo pulse duration in µs) / 58
```

The servo sweeps in steps: **0° (Right) → 90° (Forward) → 180° (Left)**

---

## 🛠️ Tools & Environment

- **Language:** Embedded C
- **MCU:** ATmega32 (AVR)
- **Build:** Hardware only
- **Programmer:** AVRDUDE / USBasp

---

## 🔭 Future Improvements

- [ ] Add IR sensors for line-following mode
- [ ] Implement PID speed control for smoother navigation
- [ ] Add Bluetooth override for manual control
- [ ] Use multiple ultrasonic sensors to eliminate servo scan delay
- [ ] Add OLED map display showing scanned environment

---

## 👥 Team

Project built as part of the **Embedded Systems Diploma** at AMIT Learning.

---

## 📄 License

This project is for educational purposes.
