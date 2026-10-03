# Wiring and component guide

Each sketch is a separate project with its own wiring. The pin tables describe the signals addressed by the source. The saved illustration shows the button-game arrangement; component models and complete circuits for the other projects were not retained.

The setup guide uses the **classic Arduino Uno with an ATmega328P** as its reference board. The [Uno R3 documentation](https://docs.arduino.cc/hardware/uno-rev3/) and [official pinout](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) describe its 5 V logic and pin capabilities. Uno R4 and other boards require a separate compatibility review, particularly for TimerOne.

## Components by project

| Project | Components addressed by the program |
| --- | --- |
| Button game | Four pushbuttons, two external LEDs, tone-capable piezo or suitable sounder, breadboard, resistors and jumper wires |
| Ultrasonic alarm | Trigger/echo ultrasonic sensor, button, LED and an active buzzer or compatible buzzer-driver input |
| Fan controller | Motor or fan with a suitable PWM control stage, button and parallel 16x2 character LCD |
| Parking barrier | Trigger/echo ultrasonic sensor, servo, button, LED, tone-capable sounder and parallel 16x2 character LCD |
| LED sequence | Four external LEDs with series resistors; the board's built-in LED is also used |

The archive does not identify a sensor, motor or servo part number. Check the selected component's datasheet for its supply voltage, current requirements and terminal order.

## Buttons

### Button game: active HIGH

The game configures D2, D3, D4 and D5 as `INPUT` and counts a transition to HIGH as a press. Provide an external pull-down from each input to ground and connect its button to the board's logic supply. This keeps the released input at a defined LOW level.

The original circuit illustration contains resistor networks, but their values are not established by the source. A 10 kΩ pull-down is a conventional reference choice for this arrangement, as illustrated in Arduino's [Button example](https://docs.arduino.cc/built-in-examples/digital/Button/).

### Alarm, fan and barrier: active LOW

These sketches use `INPUT_PULLUP`. Connect the selected input to ground through the button. A released button reads HIGH; pressing it reads LOW. Their button pins are D2 for the alarm, D8 for the fan and D7 for the barrier.

See the [Arduino input-mode reference](https://github.com/arduino/reference-en/blob/master/Language/Variables/Constants/inputOutputPullup.adoc) for pull-up and floating-input behavior.

## External LEDs and sounders

Connect external LEDs with a suitable series current-limiting resistor and correct polarity. The classic Uno's official pinout specifies a 20 mA per-I/O limit; choose the resistor for the LED and desired operating current. `LED_BUILTIN` maps to D13 on this board.

The game and barrier produce a waveform with `tone`. The alarm instead drives its buzzer output HIGH or LOW. For that alarm, use an active buzzer or driver that responds to a logic control signal. The source does not establish that the three projects used the same sounder hardware.

## Parallel 16x2 LCD

The fan and barrier use this constructor:

```cpp
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
```

It selects the four-bit parallel interface of an HD44780-compatible display:

| LCD signal | Arduino Uno pin |
| --- | --- |
| RS | D12 |
| Enable | D11 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |
| R/W | GND |

The [official LiquidCrystal HelloWorld example](https://github.com/arduino-libraries/LiquidCrystal/blob/master/examples/HelloWorld/HelloWorld.ino) uses the same signal mapping. For its 5 V reference display, VSS connects to ground, VCC to 5 V and the contrast input VO to a potentiometer wiper. Follow the actual module's documentation for supply, contrast, backlight and current limiting. An I2C backpack uses a different interface and does not match these sketches as written.

## Motor control

The fan sketch sends PWM on D9. Connect D9 to the control input of a motor driver or appropriately designed transistor stage. Supply the motor through that stage with a supply rated for its voltage and stall current, and connect its ground to the Uno ground.

For a brushed DC motor, the switching stage needs the appropriate inductive-load protection. Arduino's [transistor motor-control guide](https://github.com/arduino/docs-content/blob/main/content/learn/04.electronics/09.transistor-motor-control/09.transistor-motor-control.md) illustrates the driver, separate motor supply, common ground and protective diode. The archived source does not specify a driver model or its terminal pinout.

D9 supplies the control signal, not motor power. The LCD labels correspond to program levels; the actual PWM values are listed in the [fan guide](../sketches/fan_controller/README.md).

## Servo

The barrier sends its position signal through D6. Power the servo according to its datasheet, allowing for movement and stall current. With an external servo supply, connect its ground to the Arduino ground as described in the [Arduino servo guidance](https://support.arduino.cc/hc/en-us/articles/360017053760-Troubleshoot-servo-motors).

The commands `write(0)` and `write(90)` are target angles. Actual arm travel, direction, mechanical limits and movement time depend on the servo and linkage. There is no position feedback or closing-time obstacle check in the saved program.

## Ultrasonic sensors

Both ranging programs use separate trigger and echo signals. Their arithmetic converts pulse duration to integer centimeters:

$$
d_{\mathrm{cm}}\approx\frac{t_{\mu s}\cdot0.034}{2}.
$$

This interface is consistent with common trigger/echo modules, but a particular sensor model is not identified. Confirm the module's supply and echo voltage before connecting it to the reference board or adapting the code to another board.

The sketches call `pulseIn` without an explicit timeout. Its [documented default](https://github.com/arduino/reference-en/blob/master/Language/Functions/Advanced%20IO/pulseIn.adoc) is one second, with zero returned when no complete pulse is obtained. Consequently, the measurement can block and a zero reading is not a confirmed zero-distance measurement. The alarm treats it as within its threshold; the barrier's trigger condition excludes it.
