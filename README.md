# TEMPERATURE-MONITORING-SYSTEM

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: SEEPANA MURALIKRISHNA

*INTERN ID*: CT08DF1739

*DOMAIN*: EMBEDDED SYSTEMS

*DURATION*: 8 WEEKS

*MENTOR*: NEELA SANTOSH


# 🌡️ Task 3: Temperature Monitoring System

## 📘 Objective

The objective of this project is to design and simulate a **Temperature Monitoring System** using an **LM35 analog temperature sensor** and an **Arduino Uno**. The sensed temperature data is displayed in real-time on a **16x2 LCD display** using the LiquidCrystal library in 4-bit mode. This system can be used in environmental monitoring applications, industrial temperature sensing, greenhouse monitoring, and more. It helps beginners understand analog sensor integration with microcontrollers and real-time data display using LCDs.


## 💻 Software Used

* **Tinkercad Circuits** – An online simulation platform by Autodesk used for designing, wiring, and simulating the entire circuit including the LCD and sensor. It allows you to run Arduino code and test real-time readings without physical hardware.

* **Arduino IDE (C Code Structure)** – Although the code runs on Tinkercad, it is written in **embedded C**, following the **Arduino programming style**, which includes setup and loop functions, pin configuration, analog reading, and formatted output display.

* **LiquidCrystal Library** – A built-in Arduino library used to control the 16x2 LCD display in 4-bit mode using only 6 digital pins.


## 🧰 Components Used

| Component                | Quantity    |
| ------------------------ | ----------- |
| Arduino Uno R3           | 1           |
| LM35 Temperature Sensor  | 1           |
| 16x2 LCD Display         | 1           |
| 10kΩ Potentiometer       | 1           |
| Breadboard               | 1           |
| Jumper Wires             | As required |
| 220Ω Resistor (optional) | 1           |


## 🔌 Circuit Connections

### 🟢 LM35 Temperature Sensor

| LM35 Pin | Connection        |
| -------- | ----------------- |
| Left     | 5V                |
| Middle   | A0 (Analog Input) |
| Right    | GND               |

Make sure the **flat face of the LM35** is facing you for correct pin orientation.


### 🟦 LCD (16x2) Display

| LCD Pin  | Arduino Pin / Connection    |
| -------- | --------------------------- |
| VSS      | GND                         |
| VDD      | 5V                          |
| V0       | Center pin of Potentiometer |
| RS       | D12                         |
| RW       | GND                         |
| E        | D11                         |
| D4       | D5                          |
| D5       | D4                          |
| D6       | D3                          |
| D7       | D2                          |
| A (LED+) | 5V via 220Ω resistor        |
| K (LED-) | GND                         |

### 🎚️ Potentiometer Connections

* One end → 5V
* Other end → GND
* Middle pin → LCD pin 3 (V0) for contrast control


## 🧠 Working Principle

The **LM35** sensor outputs a voltage proportional to the temperature in °C at a scale of **10 mV per degree Celsius**. The **Arduino** reads this analog voltage from the **A0 pin** using `analogRead()` and converts it into a temperature value using the formula:

voltage = analogValue × (5.0 / 1023.0)
temperature (°C) = voltage × 100
```

This temperature is then displayed on a **16x2 LCD display** using the `LiquidCrystal` library. The temperature value updates every second, allowing the user to observe real-time changes.


## 💻 Arduino Code

```c
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7
int sensorPin = A0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp Monitor");
  delay(1000);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(sensorPin);
  float voltage = analogValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C   ");

  delay(1000);
}
```

This code uses analog input, mathematical conversion, and LCD display output. It is optimized for use with Tinkercad but also works on real hardware.


## ▶️ Steps to Simulate in Tinkercad

1. Go to [https://www.tinkercad.com/](https://www.tinkercad.com/)
2. Click **“Circuits” → “Create New Circuit”**
3. Add the following components:

   * Arduino Uno
   * LM35 temperature sensor
   * 16x2 LCD display
   * Potentiometer (10kΩ)
   * Breadboard
4. Wire the components as per the connections described above.
5. Open the **Code Editor** and switch to **“Text” mode**.
6. Paste the Arduino code provided above.
7. Click **“Start Simulation”**.
8. Click on the **LM35 sensor** to change the temperature and observe the reading on the LCD.


## 🧪 Simulation Output

When the simulation starts, the LCD will display:

Temp: 120.23 C
This value changes dynamically as you simulate the sensor input. You can click on the LM35 and adjust the temperature slider to simulate different ambient conditions. The LCD updates every second to show real-time readings.

##Output

<img width="1914" height="1091" alt="Image" src="https://github.com/user-attachments/assets/77abe6cb-d979-4ce4-8d2f-37b822740d82" />

## 🎯 Final Notes

This project demonstrates how to interface an analog temperature sensor with an Arduino and display live data using a 16x2 LCD. It gives a practical introduction to analog-to-digital conversion, LCD interfacing, and temperature calculation in embedded systems. The use of **Tinkercad Circuits** makes the project highly accessible, as it requires no physical components while offering realistic behavior. The code is written in **C using Arduino syntax**, making it compatible with both simulation and actual hardware. This project can easily be extended to trigger alarms or control fans based on temperature thresholds.
