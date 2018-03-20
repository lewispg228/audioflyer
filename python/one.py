import serial
from ctypes import c_uint8
import time

SOM1 = 0xf0
SOM2 = 0xaa
EOM = 0x55

TRK_PLAY_POLY = 1
CMD_TRACK_CONTROL = 3
CMD_TRACK_VOLUME = 8

ser = serial.Serial(2, 57600)  # open first serial port
print ser.portstr       # check which port was really used
ser.write("hello")      # write a string
#ser.close()             # close port


# **************************************************************
def trackGain(trk, gain):
    #unsigned short vol
    i = c_uint8(0)
    txbuf = [i.value, i.value, i.value, i.value, i.value, i.value, i.value, i.value, i.value]
    txbuf[0] = SOM1
    txbuf[1] = SOM2
    txbuf[2] = 0x09
    txbuf[3] = CMD_TRACK_VOLUME
    txbuf[4] = c_uint8(trk).value
    txbuf[5] = c_uint8(trk >> 8).value
    #vol = (unsigned short)gain
    txbuf[6] = c_uint8(vol).value
    txbuf[7] = c_uint8(vol >> 8).value
    txbuf[8] = EOM
    ser.write(txbuf)

# **************************************************************
def trackControl(trk, code, out, flags):
    o = c_uint8(0)
    i = c_uint8(0)
    txbuf = [i.value, i.value, i.value, i.value, i.value, i.value, i.value, i.value, i.value, i.value]
    o = out & 0x07
    txbuf[0] = SOM1
    txbuf[1] = SOM2
    txbuf[2] = 0x0a
    txbuf[3] = CMD_TRACK_CONTROL
    txbuf[4] = c_uint8(code).value
    txbuf[5] = c_uint8(trk).value
    txbuf[6] = c_uint8(trk >> 8).value
    txbuf[7] = c_uint8(o).value
    txbuf[8] = c_uint8(flags).value
    txbuf[9] = EOM
    print(txbuf)
    ser.write(txbuf)


# **************************************************************
def trackPlayPoly(trk, out, lock):
    flags = 0
    if (lock):
        flags |= 0x01
    trackControl(trk, TRK_PLAY_POLY, out, flags)


trackPlayPoly(1,1,False)





