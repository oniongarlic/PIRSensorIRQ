PIR Sensor with IRQ
===================
Arduino test application for monitoring a PIR sensor using interrupts and sleeping.

* PIR sensor output is connected to pin 3.

The AVR will be put into deep sleep when no movement is detected. On movement the
sensor will the trigger the IRQ on pin 3 and the AVR will wake up, increment a counter,
print out the value and go back to sleep.
