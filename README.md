# PIDEasy - Simple PID Library for Arduino

PIDEasy is an easy-to-use PID (Proportional-Integral-Derivative) controller library for Arduino projects.

## 🚀 Features
- Simple and lightweight
- Supports windup limits
- Includes derivative smoothing
- Allows output constraints

## 📥 Installation
### Arduino IDE (Manual Installation)
1. Download the latest version of **PIDEasy** from the [GitHub Releases](https://github.com/seu-usuario/PIDEasy/releases).
2. Extract the ZIP file.
3. Move the `PIDEasy` folder to your Arduino libraries directory:
   - **Windows:** `Documents/Arduino/libraries`
   - **Mac:** `~/Documents/Arduino/libraries`
   - **Linux:** `~/Arduino/libraries`
4. Restart the Arduino IDE.
5. Go to **Sketch** > **Include Library** > **Manage Libraries**, search for `PIDEasy`, and check if it's installed.

## 📖 Usage

### 1️⃣ Include the Library
```cpp
#include <PIDEasy.h>
```

### 2️⃣ Create a PID Controller
```cpp
PID myPID(1.0, 0.5, 0.1); // Kp, Ki, Kd
```

### 3️⃣ Compute the PID Output
```cpp
float error = desiredValue - actualValue;
unsigned long dt = millis() - lastTime;
float control = myPID.compute(error, dt);
lastTime = millis();
```

### 4️⃣ Set Constraints (Optional)
```cpp
myPID.setConstrain(-255, 255); // Limit output
```

### 5️⃣ Enable Windup Prevention (Optional)
```cpp
myPID.setWindUP(-1000, 1000);
```

### 6️⃣ Adjust Derivative Smoothing (Optional)
```cpp
myPID.setSmoothingDerivate(0.8);
```

## 📜 License
This project is licensed under the MIT License.

## 🤝 Contributing
Feel free to contribute! Fork the repository and submit a pull request.

