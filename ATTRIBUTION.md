# Coursework source record

Lukaš Patrik Magalinski, Vilnius University, Faculty of Mathematics and Informatics. The saved robotics material dates from autumn 2024.

## Source selection

| Published sketch | Original source | Selection |
| --- | --- | --- |
| `sketches/button_game/button_game.ino` | `Robotika/robitika1.txt`, lines 465-597 | Complete cell explicitly labelled `good:` |
| `sketches/ultrasonic_alarm/ultrasonic_alarm.ino` | `Robotika/sensor-2.1.txt` | Complete sketch |
| `sketches/fan_controller/fan_controller.ino` | `Robotika/rob3.txt` | Complete sketch |
| `sketches/parking_barrier/parking_barrier.ino` | `Arduino/sketch_nov4a/sketch_nov4a.ino` | Saved sketch with the `Scan your car` prompt |
| `sketches/led_sequence/led_sequence.ino` | `Downloads/daring_snicket1.ino` | Separate introductory exercise |
| `archive/barrier_text_variant/barrier_text_variant.ino` | `Robotika/robitka4.txt` | Distinct barrier version without the scan prompt or extra status delays |
| `archive/button_counter_variant/button_counter_variant.ino` | `Robotika/robitika1.txt`, lines 366-450 | Distinct counter prototype with timing from startup |

All seven sketches retain the exact original bytes or the exact indicated source excerpt. Only the containing directories and filenames are organized for Arduino's sketch format. The source comments, pin choices, timing and algorithms are unchanged.

The [component-check notes](archive/component_checks/README.md) preserve the notebook's distinct LED, button and sounder fragments. Repeated blank sections and unrelated Python optimization code are excluded. The two barrier variants are not described as earlier and later revisions because their order cannot be established reliably from their contents.

## Circuit image

`docs/assets/button-game-circuit.png` is a byte-identical copy of the saved `Robotika/Screenshot 2024-09-21 at 21.59.22.png`. It depicts the classic Uno, buttons, LEDs and sounder used in the game material. The original image has not been relabelled, redrawn or presented as a physical-hardware photograph.

A separate saved Tinkercad HTML page contains a historical design reference but no exported circuit or sketch. Its relationship to this image is not established, so it is not used to claim additional recovered projects.

## Libraries and documentation

The programs use the Arduino core and the external **LiquidCrystal**, **Servo** and **TimerOne** libraries where listed. Their source code is not vendored here. Follow the linked library projects for their authors, licenses and board support:

- [Arduino core for AVR boards](https://github.com/arduino/ArduinoCore-avr)
- [LiquidCrystal](https://github.com/arduino-libraries/LiquidCrystal)
- [Servo](https://github.com/arduino-libraries/Servo)
- [TimerOne](https://github.com/PaulStoffregen/TimerOne)

The wiring guide uses official Arduino documentation to explain the recorded signal assignments and component-dependent connections. It does not claim that new hardware measurements or sketch executions were performed.

The [source manifest](docs/provenance.json) records source filenames, selected line ranges and hashes.
