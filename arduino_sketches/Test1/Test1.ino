/*
  Audio Flyer
  SparkFun Electronics
  Pete Lewis
  Started: 5-18-2021
*/

#define MODE_JUNGLE  0
#define MODE_CARTOON  1
#define MODE_BIRD 2
#define MODE_OCEAN 3
#define MODE_FARM 4
#define MODE_COLORADO 5

#define JUNGLE_TRACKS 8
#define CARTOON_TRACKS 10
#define BIRD_TRACKS 10
#define OCEAN_TRACKS 10
#define FARM_TRACKS 6
#define COLORADO_TRACKS 7

int group_start_track = 10;
int group_tracks = 6;
int delay_ms_tsunami_com = 10;

#include <Tsunami.h>            // Include the Tsunami library header
//#include <AltSoftSerial.h>    // Optional for using AltSoftSerial

Tsunami tsunami;                // Our Tsunami object

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
  // disable track reporting from the Tsunami
  tsunami.setReporting(false);
  delay(delay_ms_tsunami_com);
  // Call update on the Tsunami to keep the track playing status current.
  tsunami.update();
  delay(delay_ms_tsunami_com);
  tsunami.masterGain(0, 0);              // Reset the master gain to 0dB
  delay(delay_ms_tsunami_com);
  test_audio_playback();

}

void loop()
{
  //test_audio_playback();
  delay(10);
}

void test_audio_playback()
{
  for (int i = 0 ; i < 7 ; i++)
  {
    //int track = i + 60; // 60 is the strat of some drum tracks
    //int channel = i; // play a track on each output (0-7)
    //Serial.print("track: ");
    //Serial.println(track);
    //tsunami.trackGain(track, -5);
    //delay(delay_ms_tsunami_com);
    //tsunami.trackPlayPoly(track, channel, false);
    play_track((i), i);
    delay(0);
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
