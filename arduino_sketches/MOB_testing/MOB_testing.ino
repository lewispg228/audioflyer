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

#include <Metro.h>              // Include the Metro library header
#include <Tsunami.h>            // Include the Tsunami library header
#include <AltSoftSerial.h>    // Optional for using AltSoftSerial

#define LED 13                  // our LED

Tsunami tsunami;                // Our Tsunami object

Metro gLedMetro(500);           // LED blink interval timer
Metro gSeqMetro(6000);          // Sequencer state machine interval timer

byte gLedState = 0;             // LED State
int  gSeqState = 0;             // Main program sequencer state
int  gRateOffset = 0;           // Tsunami sample-rate offset
int  gNumTracks;                // Number of tracks on SD card

int delay_time = 100;

char gTsunamiVersion[VERSION_STRING_LEN];    // Tsunami version string


// ****************************************************************************
void setup() {
  
  // Serial monitor
  Serial.begin(9600);
 
  // Initialize the LED pin
  pinMode(LED,OUTPUT);
  digitalWrite(LED,gLedState);

  // We should wait for the Tsunami to finish reset before trying to send
  // commands.
  delay(1000);

  // Tsunami startup at 57600
  tsunami.start();
  delay(10);
  
  // Send a stop-all command and reset the sample-rate offset, in case we have
  //  reset while the Tsunami was already playing.
  tsunami.stopAllTracks();
  tsunami.samplerateOffset(0, 0);
  
  // Enable track reporting from the Tsunami
  tsunami.setReporting(true);
  
  // Allow time for the Tsunami to respond with the version string and
  //  number of tracks.
  delay(100); 
  
}


// ****************************************************************************
// This program uses a Metro timer to create a sequencer that steps through
//  states at 6 second intervals - you can change this rate above. Each state
//  Each state will demonstrate a Tsunami serial control feature.
//
//  In this example, some states wait for specific audio tracks to stop playing
//  before advancing to the next state.

void loop() {
  
int i;

  // Call update on the Tsunami to keep the track playing status current.
  tsunami.update();

              delay_time = 2000;
              // First retrieve and print the version and number of tracks        
              if (tsunami.getVersion(gTsunamiVersion, VERSION_STRING_LEN)) {
                  Serial.print(gTsunamiVersion);
                  Serial.print("\n");
                  gNumTracks = tsunami.getNumTracks();
                  Serial.print("Number of tracks = ");
                  Serial.print(gNumTracks);
                  Serial.print("\n");
              }
              else
                  Serial.print("WAV Trigger response not available");
              //delay(delay_time);
              Serial.print("1");
              tsunami.stopAllTracks();
              tsunami.samplerateOffset(0, 0);        // Reset sample rate offset to 0
              //delay(delay_time);
              Serial.print("2");
              tsunami.masterGain(0, 0);              // Reset the master gain to 0dB
              //delay(delay_time);
              Serial.print("3");
              tsunami.trackGain(1, -5);             // Preset Track 2 gain to -40dB
              tsunami.trackGain(2, -5);

              while(1)
              {
                for(int i = 10 ; i < 18 ; i++)
                {
                  delay(delay_time);
                  Serial.print("track: ");
                  Serial.println(i);
                  tsunami.trackGain(i, -5);
                  delay(50);
                  tsunami.trackPlayPoly(i, 0, false);                   
                }
              }         

              delay(delay_time);
              tsunami.trackPlayPoly(3, 0, true);   
              tsunami.trackPlayPoly(4, 0, true);    
              
              delay(delay_time);
              tsunami.trackFade(1, 0, 5, false);
              tsunami.trackFade(4, 0, 50, false);
              
              tsunami.trackFade(100, 0, 50, false);
              tsunami.trackFade(101, 0, 50, false);
              tsunami.trackFade(102, 0, 50, false);
              tsunami.trackFade(103, 0, 50, false);
              delay(2000);
              while(1)
              {
                  
                  tsunami.trackFade(1, -10, 5000, false);
                  tsunami.trackFade(2, 0, 5000, false);
                  tsunami.trackFade(3, 0, 5000, false);
                  tsunami.trackFade(4, -10, 5000, false);                  
                  delay(5000);
                  tsunami.trackFade(1, 0, 5000, false);
                  tsunami.trackFade(2, -10, 5000, false);
                  tsunami.trackFade(3, -10, 5000, false);
                  tsunami.trackFade(4, 0, 5000, false);   
                  delay(5000);
              }
              gSeqState = 1;                         // Advance to state 1
              while(1);
}

