<div align="center">

# 🤖 Water pH Detector RC Robot

**A remote-controlled robot that measures water pH in real time using an RC circuit and Arduino.**

</div>

---

## Overview

This project combines robotics and analog sensing to build a portable, remote-controlled robot that can navigate to a water source and measure its pH level on the spot.

The robot is joystick-controlled via an RF transmitter-receiver pair. A pH sensor rod connected to an Arduino Uno reads the water's acidity or alkalinity in real time, converts it to a voltage reading, and displays it over the Serial Monitor. LED indicators give instant visual feedback on water quality status.

---

## System Architecture

```
Joystick / Transmitter
        ↓
    RF Receiver  →  Arduino Uno  →  DC Motors → Rotary Wheels
                         ↓
                    pH Sensor (A0)
                         ↓
                  Voltage Conversion
                         ↓
               Serial Monitor + LED Indicator
```

---

## Hardware Components

| Component | Role |
|---|---|
| Arduino Uno | Central controller — reads sensor, drives motors, controls LED |
| pH Sensor Rod | Measures acidity/alkalinity of water sample |
| RC Circuit (R-C) | Signal conditioning for pH sensor analog output |
| RF Transmitter + Receiver | Wireless joystick control |
| Joystick | User input for robot navigation |
| DC Motor + Motor Driver | Drives robot movement |
| Rotary Wheels | Physical locomotion |
| LED Indicator | Visual pH status feedback |
| Rechargeable Battery | Powers the entire system |

---

## How It Works

**1. Movement**
The user controls the robot via joystick. Signals are sent wirelessly through the RF transmitter to the receiver, which passes movement commands to the Arduino. The Arduino drives the DC motors accordingly.

**2. pH Measurement**
The pH sensor rod is dipped into the water. The RC circuit converts the electrochemical signal from the sensor into an analog voltage. The Arduino reads this on pin A0, maps the 10-bit ADC value (0–1023) to a 0–5V range, and prints the reading to the Serial Monitor every 500ms.

```cpp
pH_Value = analogRead(A0);
Voltage   = pH_Value * (5.0 / 1023.0);
```

**3. LED Feedback**
The Arduino drives an LED to provide real-time status indication based on the pH reading range.

---

## Code

See [`water_ph_detector.ino`](water_ph_detector.ino) for the full Arduino sketch.

**To upload:**
1. Open the `.ino` file in the [Arduino IDE](https://www.arduino.cc/en/software)
2. Select board: `Arduino Uno`
3. Select the correct COM port
4. Click Upload
5. Open Serial Monitor at `9600 baud` to view readings

---

## Working Principle — RC Circuit

The RC (Resistance-Capacitance) circuit is the core sensing mechanism. When the pH of water changes, the ionic concentration changes, which alters the resistance seen by the circuit. This variation is captured as a change in voltage across the capacitor, which the Arduino reads as an analog signal proportional to pH.

---

## Applications

- Environmental water quality monitoring
- Aquaculture and fish farming pH checks
- Wastewater treatment field testing
- Agricultural irrigation water assessment
- Remote or hard-to-access water bodies

---

## Limitations

- **Temperature sensitivity** — pH readings can shift with temperature; calibration is needed for precise measurements.
- **No data logging** — readings are printed to Serial Monitor only; a future version could log to SD card or cloud.
- **Manual voltage-to-pH mapping** — the current code outputs raw voltage. A calibration curve is needed to map voltage directly to pH units (0–14 scale).
- **Short RF range** — depending on the RF module used, control range may be limited.

---

## Future Improvements

- Add temperature sensor (DS18B20) for compensated pH readings
- Map voltage output to pH scale using calibration with buffer solutions
- Integrate data logging to SD card or IoT dashboard
- Add GPS module for location-tagged measurements
- Replace RF with Bluetooth/Wi-Fi for longer range and mobile app control

---

<div align="center">
<sub>Built with Arduino · RC Sensing · RF Control · C++</sub>
</div>
