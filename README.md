# ESP32 Web Server to Control LED

This project uses an ESP32 to create a simple web server that allows you to turn on an LED by visiting a specific URL (`/open`). It demonstrates how to set up a basic web server on the ESP32 using the `WebServer` library.

## Requirements

### Hardware
- **ESP32 Development Board** (e.g., ESP32 DevKit v1)
- **LED** (any standard LED)
- **220Ω Resistor**
- Jumper wires
- Breadboard (optional)

### Software
- **Arduino IDE** (or compatible)
- **ESP32 Board Support** in Arduino IDE (Install via Board Manager)
- **WebServer library** (comes pre-installed with ESP32 core)

## Circuit Diagram

1. Connect the **positive leg (anode)** of the LED to **GPIO 2** (or any GPIO pin you choose).
2. Connect the **negative leg (cathode)** of the LED to **GND** through a **220Ω resistor**.

> **Note:** If you use a different GPIO pin for your LED, update the `ledPin` variable in the code.

## Installation

### 1. Install ESP32 Support in Arduino IDE

If you haven't already, install the ESP32 board support:

- Open **Arduino IDE**.
- Go to **File > Preferences**.
- In the "Additional Board Manager URLs" field, add:
https://dl.espressif.com/dl/package_esp32_index.json
- Go to **Tools > Board > Board Manager** and search for **ESP32**. Install the package.

### 2. Code Upload

- Connect your **ESP32 board** to your computer via USB.
- Open the provided `ESP32 Web Server to Control LED` code in the Arduino IDE.
- Select the correct **board** and **port** in **Tools**.
- Upload the code to the ESP32.

## Usage

### 1. Connect to Wi-Fi
- Replace `your-SSID` and `your-PASSWORD` in the code with your Wi-Fi credentials.
- After uploading the code to your ESP32, open the **Serial Monitor** at a baud rate of **115200** to see the ESP32’s IP address.

### 2. Access the Web Server
- Open a web browser and type the **IP address** shown in the Serial Monitor.
- The home page will appear with a link to turn on the LED.
- Click on the **"Turn ON LED"** link, and the LED will light up. A confirmation message will appear on the webpage.

### 3. Turning Off the LED
You can modify the code to add another route (like `/close`) to turn off the LED by setting `digitalWrite(ledPin, LOW);` when that URL is accessed. You can also create a toggle mechanism if desired.

## Code Explanation

- The **Wi-Fi connection** is established using `WiFi.begin(ssid, password)`, and the ESP32 connects to the specified Wi-Fi network.
- The **Web Server** listens on port 80 and has two routes:
- `/` serves the main page with a link to turn on the LED.
- `/open` turns on the LED when accessed.
- The LED is controlled by **GPIO 2** and can be changed by modifying the `ledPin` variable.

## Troubleshooting

- **ESP32 Not Connecting to Wi-Fi**: Double-check your SSID and password.
- **LED Not Turning On**: Verify the LED wiring and GPIO pin configuration.
- **IP Address Not Displaying**: Ensure your ESP32 is properly connected to your computer and the Serial Monitor is set to the correct baud rate (115200).

## License

This project is open-source and free to use. Feel free to modify it as per your requirements!

---

Happy coding! 😊
