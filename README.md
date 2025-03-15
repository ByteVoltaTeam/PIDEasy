# PIDEasy

PIDEasy is a simple and efficient PID controller library for Arduino. It includes features like gain tuning, integral wind-up prevention, derivative smoothing, and output constraints.

## 📌 Features
- Easy-to-use PID control
- Integral wind-up prevention
- Derivative smoothing for better response
- Output constraints to prevent overshooting

## 🚀 Installation
1. Download the library as a ZIP file.
2. Open Arduino IDE.
3. Go to **Sketch** > **Include Library** > **Add .ZIP Library...**
4. Select the downloaded file.

## 🔧 Usage
### 1️⃣ **Creating a PID Controller**
```cpp
#include "PIDEasy.h"

// Create a PID instance with KP, KI, and KD values
PID myPID(1.0, 0.5, 0.1);
