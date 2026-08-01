AVR Bare-Metal External Button & LED Control.
A high-performance, bare-metal C program written for the ATmega328P microcontroller (Arduino Uno architecture) that interfaces with an external physical circuit. 
This project reads an external push button configuration to instantly drive an external LED output with precise hardware timing.

Hardware Circuit Configuration.
Unlike standard onboard LED projects, this setup relies completely on external hardware components:
Input Pin (POTRB2 / Pin 10): Connected to an external tactile push button. 
External Pull-Up Resistor: A physical 10kΩ resistor pulls the PORTB2 pin to 5V (Logic HIGH) by default. When the button is pressed, it creates a clean path to GND (Logic LOW). 
Output Pin (PORTB5 / Pin 13): Connected to an external LED passing through a 330Ω current-limiting resistor directly to GND.

Code Design & Highlights
Standard AVR Register Architecture: Leverages the official <avr/io.h> header maps (DDRB, PORTB, PINB) instead of non-standard hardcoded memory pointers or bulky abstractions.
Precise Clock Synchronization: Driven by the native <util/delay.h> framework tuned explicitly via #define F_CPU 16000000UL for exact 16MHz execution translation.
Explicit Optimization-Safe Polling: Implements bitwise masking to actively monitor register transitions with optimized compiler-safe loop delays.

Simulation & Testing
This project is structurally modularized to run natively on physical hardware or instantly inside the Wokwi simulation engine using the included diagram.json layout definition.
