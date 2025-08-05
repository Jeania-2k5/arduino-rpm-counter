# Arduino RPM Counter (Tachometer) 🚀

This project implements a digital **tachometer** using an Arduino Uno, an IR sensor, and an I2C 16x2 LCD display. It calculates **rotations per minute (RPM)** of a rotating object in real-time and displays the results both on the Serial Monitor and LCD. This system is accurate, low-cost, and ideal for educational, DIY, and small-scale industrial use.

---

## 🎯 Objective

- Detect rotations using an IR sensor or Hall-effect sensor.
- Count the number of pulses using Arduino.
- Compute and display the RPM after 1 minute of rotation.
- Gain hands-on experience in sensor interfacing, microcontroller programming, and LCD communication.

---

## 🧠 Working Principle

The IR sensor detects one pulse per rotation (e.g., by using reflective tape or a rotating magnet). Arduino counts the number of pulses per second and multiplies by 60 to calculate RPM.

**Formula:**
```
RPM = Pulses per second × 60
```

The result is displayed live every second, and the final RPM after 60 seconds is shown on the LCD.

---

## 🔧 Components Used

| S.No | Component             | Specification                   | Quantity |
|------|-----------------------|----------------------------------|----------|
| 1    | Arduino Uno           | Microcontroller board            | 1        |
| 2    | IR Sensor             | Infrared rotation detection      | 1        |
| 3    | 16x2 LCD              | With I2C interface module        | 1        |
| 4    | Jumper Wires          | Male-to-female                   | 10       |

---

## ⚙️ Circuit Connections

### IR Sensor → Arduino Uno

| IR Sensor Pin | Arduino Pin | Description         |
|---------------|-------------|---------------------|
| VCC           | 5V          | Power supply        |
| GND           | GND         | Ground              |
| OUT           | D2          | Digital pulse input |

### I2C LCD → Arduino Uno

| LCD Pin | Arduino Pin | Description         |
|---------|-------------|---------------------|
| VCC     | 5V          | Power supply        |
| GND     | GND         | Ground              |
| SDA     | A4          | I2C Data Line       |
| SCL     | A5          | I2C Clock Line      |

---

## 📺 Output Examples

- **Serial Monitor**:
  ```
  Rotations: 12
  Rotations: 28
  ...
  Final RPM: 82
  ```

- **LCD Display**:
  ```
  Counting...
  Rot: 36
  ```
  After 60 seconds:
  ```
  Final RPM:
  36
  ```

---

## 📷 Circuit Diagram

_You can add a hand-drawn or Fritzing-style wiring diagram here._

```markdown
![Circuit Diagram](circuit-diagram.png)
```

---

## 💻 Code Overview

The core logic is written in `RPM_Counter.ino`. It:
- Initializes the LCD and interrupt
- Uses an interrupt to count each pulse
- Prints the live rotation count every second
- Computes and prints final RPM after 60 seconds

> Debouncing is handled by checking time difference between consecutive pulses.

---

## 🚗 Real-World Applications

- **Automotive**: Engine RPM monitoring
- **Industrial Machines**: Motor speed feedback
- **Robotics**: Precision motor control
- **Aerospace**: Rotor speed measurement
- **R&D Labs**: Testing and experiments in motion dynamics

---

## 📊 Results

The tachometer system performed accurately under various speeds:

| Speed Range           | Observed RPM |
|------------------------|--------------|
| Low (manual rotation)  | 60–120       |
| Medium (small motor)   | 300–600      |
| High (fan/drill)       | 1000+        |

📈 Compared with a commercial handheld tachometer, the results were consistent within acceptable margins of error.

---

## ✅ Conclusion

This project demonstrates the successful implementation of a low-cost, accurate digital RPM counter. It integrates key concepts like sensor interfacing, interrupts, real-time processing, and I2C communication in a single embedded system.

🔧 **Future Improvements**:
- Add SD card logging
- Wireless data transfer (e.g., Bluetooth)
- Use a Hall-effect sensor for magnetic detection

---

## 📚 References

- [Arduino Official Documentation](https://www.arduino.cc)
- [Project Example: RPM Tracker](https://projecthub.arduino.cc/scienceactivitycentre/rpm-tracker-33c819)

---

## 📬 Feedback / Contributions

Open to contributions, suggestions, and improvements. Feel free to fork, star ⭐, or submit pull requests!
