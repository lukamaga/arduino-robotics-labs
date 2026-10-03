# Ultrasonic distance alarm

A switchable distance indicator with a trigger/echo sensor, digital alarm outputs, a hardware timer and serial distance reporting. A falling-edge button interrupt toggles the system.

## Components and pins

| Role | Pin | Configuration |
| --- | ---: | --- |
| Ultrasonic trigger | D9 | Digital output |
| Ultrasonic echo | D10 | Digital input |
| Buzzer/alarm signal | D11 | Digital HIGH/LOW output |
| LED | D13 | Digital output |
| System button | D2 | `INPUT_PULLUP`, falling-edge interrupt |

The code specifies the trigger/echo interface but not a sensor model. It drives the buzzer pin digitally; it does not generate a particular audio frequency with `tone()`. The external alarm component must match that form of drive. The button uses the internal pull-up and is interpreted as pressed on a falling edge.

## Behaviour

The system starts off. While enabled, the loop checks for a measurement approximately every 100 ms. It generates a 10 microsecond trigger pulse and measures the echo with `pulseIn`.

```text
distance_cm = echo_duration_us * 0.034 / 2
```

The result is stored as an integer. At 50 cm or below, both alarm outputs go HIGH and the inactivity counter resets. Above that threshold, the measurement branch drives them LOW.

TimerOne calls `timerIsr` once per second. The handler increments the counter while the system is enabled and clears it while disabled. Once the counter reaches five, the code also toggles the alarm outputs on a 500 ms schedule. The distance branch and blinking branch both write those pins, so the output is governed by both conditions. A close reading resets the counter. Switching the system off clears the outputs and counter.

Distances are printed with the label `Atstumas` at 9600 baud. The 100 ms interval is a scheduling check; `pulseIn` can block while waiting for an echo. A zero-duration reading is converted to zero distance and enters the same threshold branch.

The original button interrupt has no debounce interval and writes serial messages inside the handler. It shares `systemOn` with the main loop without a `volatile` declaration; the multi-byte `timerCounter` is read and written without an atomic snapshot on the 8-bit AVR. These details are preserved in the source and should be considered when adapting its interrupt handling.

## Dependency and opening

Open [ultrasonic_alarm.ino](ultrasonic_alarm.ino) in the Arduino IDE. Install the **TimerOne** library through the Library Manager if it is not available. The saved local library is version 1.1.1 and declares AVR support; select a board supported by the library and the external interrupt mapping. The library itself is not vendored in this repository.

See [wiring notes](../../docs/wiring.md) for the scope of the signal-pin information.

## Source

The complete contents of `Robotika/sensor-2.1.txt`, with the `.ino` filename required by the Arduino sketch layout. The timing and interrupt logic is the saved coursework implementation.
