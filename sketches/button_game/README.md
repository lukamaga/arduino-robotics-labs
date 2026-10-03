# Two-player button game

A five-second button-count challenge for two players. A separate button toggles the system, another starts a round, two player buttons increment scores, and LEDs identify the winner. Scores are printed to the serial monitor at 9600 baud.

## Components and pins

| Role | Pin | Configuration |
| --- | ---: | --- |
| System toggle button | D2 | Active-high input |
| Start/restart button | D3 | Active-high input |
| Player 2 button | D4 | Active-high input |
| Player 1 button | D5 | Active-high input |
| Player 2 LED | D8 | Digital output |
| Player 1 LED | D9 | Digital output |
| Piezo/tone output | D13 | `tone()` output |
| Random-seed reading | A0 | Read once by `randomSeed(analogRead(0))` |

The four buttons use `INPUT`, not `INPUT_PULLUP`. Their external circuit must therefore provide defined released and pressed levels. A0 is used for seeding; no separate sensor on A0 is specified by the sketch. The saved circuit illustration shows an Arduino Uno, four buttons, two LEDs, resistors and a piezo component. Component values are not defined in the code.

## Round sequence

1. The system starts off. Press D2 to toggle it on; both player LEDs and a 50 Hz tone signal activation.
2. Press D3 to start or restart a round. `random(1,3)` produces a one- or two-second delay.
3. The sketch records the start time, gives a 500 ms light cue and clears both scores.
4. Rising-edge button detections add one point to the corresponding player. Holding a button does not repeatedly score until it is released and pressed again.
5. When five seconds have elapsed from the recorded start time, the higher score wins. The matching LED lights; both light for a tie. A 100 Hz tone and a 500 ms light indication finish the round.

The start timestamp is recorded before the 500 ms start cue, so the cue is part of the five-second timing window. The program uses blocking delays for cues and simple edge tracking without a separate debounce timer.

## Open the sketch

Open [button_game.ino](button_game.ino) in the Arduino IDE. It uses the standard Arduino core only. The folder and file names match Arduino's sketch convention. The serial monitor uses 9600 baud.

For the circuit overview and the distinction between signal pins and complete wiring, see [wiring notes](../../docs/wiring.md).

## Source

Extracted from the cell labelled `good:` in `Robotika/robitika1.txt`, lines 465 to 597. The unrelated optimization Python code is excluded. The [counter variant](../../archive/button_counter_variant/README.md) and [component checks](../../archive/component_checks/README.md) retain other distinct work from the same notebook.
