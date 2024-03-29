/* set_funtions.h
    This file contains functions that allow you
    to switch between beats with the call of a single
    function.

    Each beat needs its own set function.
*/

// setup "blank" arrays for each instrument in the actively used arrays
bool kick[16] = {};
bool snare[16] = {};
bool hat[16] = {};
bool ride[16] = {};

void set_four_on_the_floor() {
  for (int i = 0 ; i < 16 ; i++)
  {
    kick[i] = kickFF[i];
    snare[i] = snareFF[i];
    hat[i] = hatFF[i];
    ride[i] = rideFF[i];
  }
}

void set_half_time_groove() {
  for (int i = 0 ; i < 16 ; i++)
  {
    kick[i] = kickHT[i];
    snare[i] = snareHT[i];
    hat[i] = hatHT[i];
    ride[i] = rideHT[i];
  }
}

void set_half_time_groove_ride() {
  for (int i = 0 ; i < 16 ; i++)
  {
    kick[i] = kickHTr[i];
    snare[i] = snareHTr[i];
    hat[i] = hatHTr[i];
    ride[i] = rideHTr[i];
  }
}
