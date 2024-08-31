# Team-Arm-E-Hands-SIH-24

We read Electromyography (EMG) data using sensors, amplify it, filter it, perform ADC conversion, and process it. Using the analyzed data, we train an DL model that can understand what hand movement was performed to get those readings. Later those Readings are fed into a DL model to recognize and classify those motions. A rasberry Pi will haeve the Deep learning model running on it, based on the predicted label the Rasberry Pi will control the prosthetic arm, giving us a affordable but effective Myoelectric Prosthetic Arm.

To run the project:
0. Make sure the emg data collection sensors are connected.
1. Make sure you have esp-idf installed on your device
3. Go to src/EMG-Firmware
4. In the terminal, run the following commands
5. ```get_idf```
6. ```idf.py build```
7. Connect the computer to the esp and run this command
8. ```idf.py flash monitor```

This will get the emg data collection code running. From the monitor copy the IP address of the esp after updating the wifi ssid and password.


