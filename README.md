<p align="center">
  <img src="./img.png" alt="Project Banner" width="100%">
</p>

# [Smart LPG Level Indicator] 🎯

## Basic Details

### Team Name: [CaffieneCompile]

### Team Members
- Member 1: [Alba Asha] - [College of Engineering Perumon]
- Member 2: [Fathima Rasheed] - [College of Engineering Perumon]

### Project Description
[The **Smart LPG Level Indicator** monitors LPG cylinder levels in real-time using an **ESP32** and **ultrasonic sensor**. It provides alerts via LEDs and a buzzer when the gas is low, ensuring timely refills and improved safety. The design includes a compact PCB for easy installation.]

### The Problem statement
[Many households face unexpected LPG shortages, leading to inconvenience. Manual checking is unreliable and unsafe. There is a need for an automated system to monitor LPG levels and alert users when the gas is low.]

### The Solution
[The **Smart LPG Level Indicator** offers an automated, real-time solution using an ESP32 and ultrasonic sensor. Users receive LED and buzzer alerts for low gas levels, preventing shortages and enhancing safety.]

---

## Technical Details

### Technologies/Components Used

**For Software:**
- Languages used: [C++]
- Libraries used: [WiFi.h, WebServer.h, ArduinoJson, EEPROM.h]
- Tools used: [Arduino IDE]

**For Hardware:**
- Main components: [ESP32 WROOM, HC-SR04 ultrasonic sensor, LEDs, buzzer, resistors, wires, power supply]
- Specifications: [ESP32: 3.3V logic, 240 MHz, WiFi & Bluetooth
                   HC-SR04: 5V operating voltage, distance 2–400 cm, accuracy ±3mm
                   LEDs: 5mm, 2–3V, 220Ω resistors
                   Buzzer: 5V active/passive]
- Tools required: [breadboard, jumper wire]

---

## Features

- Real-time LPG level monitoring  
- LED and buzzer alerts  
- Compact PCB design for easy installation  
- Color-coded wiring for simple assembly

---

## Implementation

We used water to mimic LPG gas for the ease of building the demo.

### For Hardware:

#### Components Required
[**Main components:** ESP32 WROOM, HC-SR04 ultrasonic sensor, LEDs, buzzer, resistors, jumper wires, power supply  
- **Specifications:**  
  - ESP32: 3.3V logic, 240 MHz, WiFi & Bluetooth  
  - HC-SR04: 5V, 2–400 cm range, ±3mm accuracy  
  - LEDs: 5mm, 2–3V with 220Ω resistors  
  - Buzzer: 5V active/passive  ]

#### Circuit Setup
[Explain how to set up the circuit]

---

## Project Documentation

### For Hardware:

#### Schematic & Circuit

![Circuit](Add your circuit diagram here)
*Add caption explaining connections*

![Schematic](Add your schematic diagram here)
*Add caption explaining the schematic*

#### Build Photos

![Team](Add photo of your team here)

![Components](Add photo of your components here)
*List out all components shown*

![Build](Add photos of build process here)
*Explain the build steps*

![Final](Add photo of final product here)
*Explain the final build*

---

## Additional Documentation

---

### For Hardware Projects:

#### Bill of Materials (BOM)

| Component                     | Quantity | Specifications                               | Price      |
|------------------------------|----------|----------------------------------------------|------------|
| ESP32 WROOM                 | 1        | 3.3V logic, WiFi + Bluetooth, 240MHz        | ₹370       |
| Arduino Uno                 | 1        | ATmega328P, 16MHz, 5V logic                 | ₹450       |
| HC-SR04 Ultrasonic Sensor   | 1        | 5V, 2–400 cm range, ±3mm accuracy           | ₹80        |
| LED                         | 3        | Red/Green, 5mm, 20mA                        | ₹5 each    |
| Resistor                    | 3        | 220Ω, 1/4W (for LEDs)                       | ₹10 each    |
| Buzzer                      | 1        | 5V active/passive                           | ₹40        |
| Breadboard                  | 1        | 830 points                                  | ₹120       |
| Jumper Wires                | 15–20    | Male-to-Male / Male-to-Female               | ₹100       |

**Total Estimated Cost:** ₹1,205

#### Assembly Instructions

**Step 1: Prepare Components**
1. Gather all components listed in the BOM.
2. Verify specifications (voltage ratings, resistor values, etc.).
3. Arrange components neatly on your workspace.
![Step 1](images/assembly-step1.jpg)
*Caption: All components laid out*

**Step 2: Build the Power Supply**
1. Connect the power rails on the breadboard
2. Connect Arduino 5V to breadboard positive rail
3. Connect Arduino GND to breadboard negative rail
![Step 2](images/assembly-step2.jpg)
*Caption: Power connections completed*

**Step 3: Connect Ultrasonic Sensor (HC-SR04)**
1. VCC → 5V rail
2. GND → GND rail
3. TRIG → ESP32 GPIO 5
4. ECHO → ESP32 GPIO 18
![Step 3](images/assembly-step3.jpg)
*Caption: LED circuit assembled*

**Step 4: Connect LEDs**
1. Red LED
  - Anode → GPIO 19 (through 220Ω resistor)
  - Cathode → GND
2. Yellow LED
  - Anode → GPIO 21 (through 220Ω resistor)
  - Cathode → GND
3. Green LED
  - Anode → GPIO 22 (through 220Ω resistor)
  - Cathode → GND

**Step 5: Connect Buzzer**
1. Positive terminal → GPIO 23
2. Negative terminal → GND

**Step 6: Upload Code**
1. Connect ESP32 to computer via USB.
2. Open Arduino IDE.
3. Select ESP32 board.
4. Upload code.
5. Open Serial Monitor to check IP address.

**Final Assembly**
1. Place ultrasonic sensor facing the bottom of LPG cylinder.
2. Secure connections.
3. Connect WiFi.
4. Open browser and enter ESP32 IP address to view LPG status.

![Final Build](images/final-build.jpg)
*Caption: Completed project ready for testing*

---



#### Demo Output



## Project Demo

### Video
[Add your demo video link here - YouTube, Google Drive, etc.]

*Explain what the video demonstrates - key features, user flow, technical highlights*

### Additional Demos
[Add any extra demo materials/links - Live site, APK download, online demo, etc.]

---

## AI Tools Used (Optional - For Transparency Bonus)

If you used AI tools during development, document them here for transparency:

**Tool Used:** [ ChatGPT ]

**Purpose:** [What you used it for]
- Placement of components
- Circuit connection
- Code

**Key Prompts Used:**
- How does ultrasonic sensor work?
- Configure GPIO pin mapping for ESP32-WROOM-32
- Implement LED and buzzer alert logic based on LPG level thresholds
- Give the code needed to be used

**Percentage of AI-generated code:** [Approximately X%]

**Human Contributions:**
- Modification of code
- Idea for demo
- Additions to the idea


---

## Team Contributions

- [Name 1]: [Specific contributions - e.g., Frontend development, API integration, etc.]
- [Name 2]: [Specific contributions - e.g., Backend development, Database design, etc.]
- [Name 3]: [Specific contributions - e.g., UI/UX design, Testing, Documentation, etc.]

---

## License

This project is licensed under the [LICENSE_NAME] License - see the [LICENSE](LICENSE) file for details.

**Common License Options:**
- MIT License (Permissive, widely used)
- Apache 2.0 (Permissive with patent grant)
- GPL v3 (Copyleft, requires derivative works to be open source)

---

Made with ❤️ at TinkerHub
