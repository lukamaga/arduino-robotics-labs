# Barrier TXT-source variant

This is the complete sketch saved as `Robotika/robitka4.txt`, given an Arduino-compatible folder/file name. The [main barrier sketch](../../sketches/parking_barrier/README.md) comes from the separate saved INO file.

Both versions have identical signal pins, LCD initialization, integer distance calculation, strict 5 to 10 cm condition, servo angles, five-second hold and five-pulse light/tone routine.

This TXT-source variant does not include the `Scan your car` message or the additional 500 ms delay after each ON/OFF LCD message. It also retains two Russian explanatory comments that are absent from the INO file. No chronological or submission-order claim is made from those differences.

Dependencies: **LiquidCrystal** and **Servo**. The complete pin map and timing explanation are in the main barrier documentation. This archived file remains a separate sketch; do not combine both versions into the same Arduino sketch folder.
