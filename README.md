# Digital Circuits Laboratory - Christmas Lights with ESP32

## Description
ESP32 project with five LED lighting patterns controlled by a finite state machine and a push button.

## Materials
- ESP32 DevKit V1 and Arduino UNO
- 5 LEDs and 5 resistors (220 Ω)
- Push button and 10 kΩ resistor
- 2 breadboards
- Jumper wires and USB data cable

## Connections
- LEDs: GPIO 18, 19, 21, 22, 23
- Button: GPIO 4 with a 10 kΩ pull-down resistor

## Project Files
- `Christmas_Lights_ESP32`: Main program.
- `Experiment_A_PullDown`: Digital input experiment.
- `Experiment_B_LED_Current`: LED current experiment.
- `Experiment_C_V1_Delay`: Delay without debounce.
- `Experiment_C_V2_Millis_Debounce`: Millis with debounce.
- `Experiment_C_V3_Millis_NoDebounce`: Millis without debounce.

## Upload Instructions
1. Install Arduino IDE and the ESP32 board package.
2. Connect the board using a USB data cable.
3. Open the `.ino` file from its corresponding folder.
4. Select the correct board and USB port.
5. Click **Upload**.
6. Open the Serial Monitor at **115200 baud**.
7. Press the button to change the lighting patterns.

For Experiment B, select the Arduino UNO when uploading its corresponding program.

## Documentation
- `State_Diagram.png`
- `State_Transition_Table.PNG`
- `Circuit_Schematic.pdf`
