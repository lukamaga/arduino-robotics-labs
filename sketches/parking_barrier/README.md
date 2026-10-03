# Ultrasonic parking barrier

A servo barrier controlled by a trigger/echo distance sensor, with a system button, character LCD and light/sound cues.

## Components and pins

| Role | Pin |
| --- | ---: |
| Ultrasonic trigger | D9 |
| Ultrasonic echo | D8 |
| System button, `INPUT_PULLUP` | D7 |
| Servo control | D6 |
| Buzzer/tone output | D10 |
| LED | D13 |
| LCD RS | D12 |
| LCD enable | D11 |
| LCD data D4, D5, D6, D7 | D5, D4, D3, D2 |

The LCD is configured as 16 by 2. The source names no sensor model, servo model, external supply, resistor values or complete power circuit. Refer to [wiring notes](../../docs/wiring.md) for the distinction between these signal assignments and a hardware schematic.

## Behaviour

The system starts off and commands the servo to 0 degrees. The LCD briefly shows `Barrier System` and `Press Button`. A LOW button reading toggles the system state. While enabled and closed, the display shows `Scan your car`.

The sketch calculates integer centimetres from `pulseIn` using `duration * 0.034 / 2`. An opening cycle is triggered only when the measured integer distance is strictly greater than 5 and strictly less than 10, and the barrier is not already marked open.

The sequence is:

1. Command 90 degrees and show `Opening...`.
2. Produce five light/tone pulses: 200 ms HIGH with a 1000 Hz tone, then 200 ms LOW without the tone.
3. Wait an additional 5000 ms.
4. Command 0 degrees, show `Closing...` and repeat the five pulses.

The two signal routines take about two seconds each, so the blocking cycle is about nine seconds, excluding small processing overhead. The servo is commanded open during the opening cue and the additional five-second hold. The button and distance sensor are not polled during that blocking sequence.

The system button is checked by level, with delays, rather than by a stored edge state. Holding it LOW can toggle the state again on a later loop iteration.

## Open the sketch

Open [parking_barrier.ino](parking_barrier.ino) in the Arduino IDE. The named dependencies are **LiquidCrystal** and **Servo**.

## Saved variants

This file comes from `Documents/Arduino/sketch_nov4a/sketch_nov4a.ino`. The distinct [TXT-source variant](../../archive/barrier_text_variant/README.md) is also retained. Both use the same pins, distance condition, servo positions and signal routine. This variant additionally displays `Scan your car` and waits another 500 ms after each ON/OFF status message. The available filenames do not establish which variant was submitted last.
