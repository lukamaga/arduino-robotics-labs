# Timed button-counter variant

A distinct saved version from `robitika1.txt`, lines 366 to 450. It counts two players' button presses and compares their scores after five seconds measured from startup.

It uses the same player input pins as the main game: D5 for player 1 and D4 for player 2, with LEDs D9 and D8 respectively and tone output D13. The source defines ON and RESET button constants and configures D2 and D3 as inputs, but this version does not use them to control the loop.

Unlike the [selected button game](../../sketches/button_game/README.md), there is no separate on/off state, restart logic or completed-round state. After the five-second threshold, the winner indication is repeated on subsequent loop iterations while scores can continue to increase. The file is kept as a distinct coursework variant, not described as a second independent game assignment.

It uses only the Arduino core. The code is an exact excerpt and contains its own `setup`, `loop` and `buttonClick` definitions.
