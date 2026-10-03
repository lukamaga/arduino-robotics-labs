# Fan controller with LCD

A button cycles four motor-control levels while a 16 by 2 character display shows the selected label. The sketch uses a PWM control output and the LiquidCrystal parallel interface.

## Components and pins

| Role | Pin |
| --- | ---: |
| Motor-control PWM signal | D9 |
| Button, `INPUT_PULLUP` | D8 |
| LCD RS | D12 |
| LCD enable | D11 |
| LCD data D4 | D5 |
| LCD data D5 | D4 |
| LCD data D6 | D3 |
| LCD data D7 | D2 |

The LCD pin mapping follows `LiquidCrystal lcd(12, 11, 5, 4, 3, 2)`. The code does not specify LCD power/contrast wiring or a motor driver. D9 is the control signal; this is not a complete motor-power connection diagram.

## Control levels

| Level | LCD label | Value passed to `analogWrite` |
| ---: | --- | ---: |
| 0 | Off | 0 |
| 1 | 25% | 16 |
| 2 | 50% | 32 |
| 3 | 100% | 64 |

The labels are the original user-interface labels. They are not the same as 25%, 50% and 100% of the usual 0 to 255 PWM range. The preserved output values are exactly 0, 16, 32 and 64.

## Behaviour

At startup, the LCD displays `Fan Control` for two seconds and is then cleared. Each detected HIGH-to-LOW button transition advances the level, wrapping from 3 back to 0, writes the PWM value and updates the display. The loop has a 50 ms delay. A held button does not repeatedly advance the level because the previous input state is tracked.

## Open the sketch

Open [fan_controller.ino](fan_controller.ino) in the Arduino IDE. The only named library dependency is **LiquidCrystal**. The code initializes the display as 16 columns by 2 rows and uses its four-bit parallel interface.

See [wiring notes](../../docs/wiring.md) for circuit-level context.

## Source

The complete saved `Robotika/rob3.txt` sketch. Output values, labels and button logic are unchanged.
