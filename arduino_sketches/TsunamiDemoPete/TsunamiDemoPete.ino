// ****************************************************************************
//       Sketch: Tsunami Serial Control Example
// Date Created: 11/22/2016
//
//     Comments: Demonstrates advanced, two-way, serial control of the Tsunami
//               from a 3.3V Arduino.
//
//  Programmers: Jamie Robertson, info@robertsonics.com
//
//  WARNING: The Tsunami is a 3.3V device. Attempting to connect it to a 5V
//   Arduino (such as an UNO) without level-shifters, will likely damage your
//   Tsunami!
//
// ****************************************************************************
//
// To use this sketch with an Arduino, you'll need:
//
// 1) An Arduino with an operating voltage of 3.3V, *** NOT 5V ***!
// 2) Download and install the Metro library.
// 3) Connect 3 wires from the Arduino to the Tsunami's serial connector:
//
//    Arduino       Tsunami
//    =======       =======
//    GND  <------> GND
//    TXn  <------> RX
//    RXn  <------> TX
//
//    If you're using an Arduino with at least one extra hardware serial port,
//    such as an M0 or Teensy, the Tsunami library is already set to use
//    Serial1. If you need to change that, or want to use AltSoftSerial, you
//    must make a small edit the Tsunami.h file, according the instructions in
//    that file.
//
// 4) Download and install the demo wav files onto the Tsunami's microSD
//    card. You can find them here:
//
//    http://robertsonics.com/2015/04/25/arduino-serial-control-tutorial/
//
//    You can certainly use your own tracks instead, although the demo may
//    not make as much sense. If you do, make sure your tracks are at least
//    10 to 20 seconds long and have no silence at the start of the file.
//
// 5) Open the Arduino Serial Monitor window to see status messages.


#include <Tsunami.h>            // Include the Tsunami library header
//#include <AltSoftSerial.h>    // Optional for using AltSoftSerial

Tsunami tsunami;                // Our Tsunami object

// ****************************************************************************
void setup() {
  Serial1.begin(57600);
  //tsunami.samplerateOffset(0, 0);        // Reset sample rate offset to 0
  //tsunami.masterGain(0, 0);              // Reset the master gain to 0dB
  
  //tsunami.trackGain(1, 0);             // Preset Track 2 gain to -40dB
  tsunami.trackPlayPoly(1, 1, true);     // Start Track 2
  //tsunami.trackFade(1, 0, 500, false);  // Fade Track 2 to 0dB over 2 sec  
 }

void loop() {
}

