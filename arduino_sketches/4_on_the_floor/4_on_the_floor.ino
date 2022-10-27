/*
  Audio Flyer
  SparkFun Electronics
  Pete Lewis
  Started: 5-18-2021
*/
#include "track_numbers.h"
#include "drum_beats.h"
#include "set_functions.h"

int delay_ms_tsunami_com = 10;

#include <Tsunami.h>            // Include the Tsunami library header
//#include <AltSoftSerial.h>    // Optional for using AltSoftSerial

Tsunami tsunami;                // Our Tsunami object

char gTsunamiVersion[VERSION_STRING_LEN];    // Tsunami version string
int  gNumTracks;                // Number of tracks on SD card

long bpm = 120; // beats per minute (how many 1/4 notes there are in a minute)

bool guitar_qued = 0;
int guitar_qued_track = 20;
int guitar_qued_channel = 0;

bool bass_qued = 0;
int bass_qued_track = 100;
int bass_qued_channel = 0;

void setup()
{

  Serial.begin(115200);
  Serial.println("Audio Flyer DEBUG ON");

  tsunami.start();
  delay(delay_ms_tsunami_com);
  // Send a stop-all command and reset the sample-rate offset, in case we have
  //  reset while the Tsunami was already playing.
  tsunami.stopAllTracks();
  delay(delay_ms_tsunami_com);
  tsunami.samplerateOffset(0, 0);
  delay(delay_ms_tsunami_com);
  tsunami.setReporting(false); // disable track reporting from the Tsunami
  delay(delay_ms_tsunami_com);
  tsunami.update(); // Call update to keep the track playing status current.
  delay(delay_ms_tsunami_com);
  tsunami.masterGain(0, 0); // Reset the master gain to 0dB
  delay(delay_ms_tsunami_com);

  if (tsunami.getVersion(gTsunamiVersion, VERSION_STRING_LEN)) {
    Serial.print(gTsunamiVersion);
    Serial.print("\n");
    gNumTracks = tsunami.getNumTracks();
    Serial.print("Number of tracks = ");
    Serial.print(gNumTracks);
    Serial.print("\n");
  }


  test_audio_playback();
  pinMode(2, INPUT_PULLUP);
}

void loop()
{

  while (digitalRead(2) == false) // if ya press hte button on D2, then it will play a cycle of the song...
  {
    set_four_on_the_floor();
    // guitar
    guitar_qued = 1;
    guitar_qued_track = 20;
    guitar_qued_channel = 1;
    // bass
    bass_qued = 1;
    bass_qued_track = 100;
    bass_qued_channel = 2;

    play_measure();
    guitar_qued_track = 21;
    guitar_qued = 1;
    guitar_qued_channel = random(3, 6);
    play_measure();
    play_measure();
    play_measure();

    // guitar
    guitar_qued = 1;
    guitar_qued_track = 20;
    guitar_qued_channel = 1;
    // bass
    bass_qued = 1;
    bass_qued_track = 100;
    bass_qued_channel = 2;

    play_measure();
    guitar_qued_track = 21;
    guitar_qued = 1;
    guitar_qued_channel = random(3, 6);
    play_measure();
    play_measure();
    play_measure();

    set_half_time_groove_ride();
    // guitar
    guitar_qued = 1;
    guitar_qued_track = 203;
    guitar_qued_channel = 1;
    // bass
    bass_qued = 1;
    bass_qued_track = 202;
    bass_qued_channel = 2;

    for(int i = 0 ; i < 8 ; i++)
    {
      play_measure();
    }
  }
}

void test_audio_playback()
{
  for (int i = 0 ; i < 8 ; i++)
  {
    //int track = i + 60; // 60 is the strat of some drum tracks
    //int channel = i; // play a track on each output (0-7)
    //Serial.print("track: ");
    //Serial.println(track);
    //tsunami.trackGain(track, -5);
    //delay(delay_ms_tsunami_com);
    //tsunami.trackPlayPoly(track, channel, false);
    play_track((11), i);
    delay(1000);
  }
}

void play_track(int track = 1, int channel = 0);

void play_track(int track, int channel)
{
  Serial.print("track: ");
  Serial.println(track);
  tsunami.trackGain(track, -5);
  delay(delay_ms_tsunami_com);
  tsunami.trackPlayPoly(track, channel, false);
  delay(delay_ms_tsunami_com);
}





void play_measure()
{
  // loop through all 16th bar time divisions,
  // play each WAV (or combo of WAVS) at each division.

  long start_time_micros = micros();

  for (int i = 0 ; i < 16 ; i++)
  {
    //int val = analogRead(A0);
    //bpm = map(val, 0, 1023, 0, 240);
    bpm = 134;
    Serial.print("bpm: ");
    Serial.println(bpm);

    if (kick[i] == 1) tsunami.trackLoad(kick_t, 0, false);
    delay(delay_ms_tsunami_com);
    if (snare[i] == 1) tsunami.trackLoad(snare_t, 0, false);
    delay(delay_ms_tsunami_com);
    if (hat[i] == 1) tsunami.trackLoad(hat_t, 0, false);
    delay(delay_ms_tsunami_com);
    if (ride[i] == 1) tsunami.trackLoad(ride_t, 0, false);
    delay(delay_ms_tsunami_com);
    if (guitar_qued == 1)
    {
      tsunami.trackLoad(guitar_qued_track, guitar_qued_channel, false);
      delay(delay_ms_tsunami_com);
      tsunami.trackGain(20, -5);
      guitar_qued = 0;
    }

    if (bass_qued == 1)
    {
      tsunami.trackLoad(bass_qued_track, bass_qued_channel, false);
      delay(delay_ms_tsunami_com);
      tsunami.trackGain(100, 10);
      delay(delay_ms_tsunami_com);
      tsunami.trackGain(202, 10);
      bass_qued = 0;
    }

    delay(delay_ms_tsunami_com);
    tsunami.resumeAllInSync();

    long sixteenth_note_delay = bpm_to_16th_delayms(bpm);
    while ((micros() - start_time_micros) < (sixteenth_note_delay * 1000)) delayMicroseconds(1);
    start_time_micros = micros();
  }
}

long bpm_to_16th_delayms(long bpm)
{
  float seconds_f = 60.0 / float(bpm) ; // beats-per-minute to beats-per-second
  seconds_f /= 4.0; // to quarter notes
  seconds_f *= 1000.0; // to milliseconds
  return long(seconds_f);
}
