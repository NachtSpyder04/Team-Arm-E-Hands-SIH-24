# Team-Arm-E-Hands-SIH-24

We read Electromyography (EMG) data using sensors, amplify it, filter it, perform ADC conversion, and process it. Using the analyzed data, we train a DL model that can understand what hand movement was performed to get those readings. Later, those readings are fed into a DL model to recognize and classify those motions. An ESP/Raspberry Pi will have the deep learning model running on it. Based on the predicted label, the ESP/Raspberry Pi will control the prosthetic arm, giving us an affordable but effective myoelectric prosthetic arm.

## To run the project:

0. Make sure the EMG data collection sensors are connected.
1. Make sure you have ESP-IDF installed on your device.
2. Go to `src/EMG-Firmware`.
3. In the terminal, run the following commands:
    ```bash
   get_idf
   idf.py build
   idf.py flash monitor

This will get the EMG data collection code running. From the monitor, copy the IP address of the ESP/Raspberry Pi after updating the Wi-Fi SSID and password.


