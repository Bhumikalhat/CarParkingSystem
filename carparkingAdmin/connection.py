import time

import serial

ser = serial.Serial(port="COM3", baudrate=9600)

def read():
    return ser.readline().decode('Ascii')

def write():
    ser.write(str(1).encode('Ascii'))
