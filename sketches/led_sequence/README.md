# LED sequence warm-up

A small Arduino digital-output exercise. Four output pins are activated one at a time in a repeating sequence, while the built-in LED follows the first phase.

| Phase | Active output | Built-in LED | Duration |
| ---: | ---: | --- | --- |
| 1 | D5 | HIGH | 1000 ms |
| 2 | D6 | LOW | 1000 ms |
| 3 | D4 | LOW | 1000 ms |
| 4 | D3 | LOW | 1000 ms |

After the last phase, D3 is cleared and the four-second sequence starts again. `LED_BUILTIN` uses the board's own definition; the source does not hardcode its pin number.

## Open the sketch

Open [led_sequence.ino](led_sequence.ino) in the Arduino IDE. It uses the standard Arduino core and no additional libraries. External LEDs require suitable wiring; the source specifies output pins only and does not record resistor values.

## Source

The complete `Downloads/daring_snicket1.ino` file. It is included as a warm-up exercise, without assigning it a course-lab number that is absent from the saved source.
