/* drum_beats.h
    This file contains sets of drum beats
    The length of the array determines the
    division of the measure.
    Most of these are 16th note time divisions
    "0" means nothing is played
    "1" means the instrument will be played at that division

    To use one of these drum beats, you must call its
    corresponding "set" function.
    This sets the active kick/snare/hats/etc. to
    the beat you desire.
*/

// ************************************************************
// four on the floor      *************************************
// ************************************************************
bool kickFF[16] = {
  1, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
bool snareFF[16] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  1, 0, 0, 0,
  0, 0, 0, 0,
};
bool hatFF[16] = {
  1, 0, 0, 0,
  1, 0, 0, 0,
  1, 0, 0, 0,
  1, 0, 0, 0,
};
bool rideFF[16] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
// end four on the floor

// ************************************************************
// half time groove       *************************************
// ************************************************************
bool kickHT[16] = {
  1, 0, 0, 0,
  0, 0, 1, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
bool snareHT[16] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  1, 0, 0, 0,
  0, 0, 0, 0,
};
bool hatHT[16] = {
  1, 0, 1, 0,
  1, 0, 1, 0,
  1, 0, 1, 0,
  1, 0, 1, 0,
};
bool rideHT[16] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
// end half time groove

// ************************************************************
// half time groove RIDE      *********************************
// ************************************************************
bool kickHTr[16] = {
  1, 0, 0, 0,
  0, 0, 1, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
bool snareHTr[16] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  1, 0, 0, 0,
  0, 0, 0, 0,
};
bool hatHTr[16] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
bool rideHTr[16] = {
  1, 0, 0, 0,
  1, 0, 0, 0,
  1, 0, 0, 0,
  1, 0, 0, 0,
};
// end half time groove ride
