#!/usr/bin/env python2
# -*- coding:utf-8 -*-

import serial
import array
import sys


places = ['Gateway', 'Park A', 'Park B', 'Storage 1', 'Storage 2','Storage 3', 'Storage 4', 'Storage 5', 'Storage 6']
sendinfo = [0xff, 0xff, 0x01, 0x01, 0x00]

def getResponse():
    response = zigbee.read(5)
    response = [ord(c) for c in response]
    if(response[0] == 0xff and response[1] = 0xff):
        print 'Car ' + response[2] + ' returned error'
        sys.exit(1)
    if(response[4] == 0x00):
        print 'Car ' + response[2] + ' got a tool from ' + places[response[3]]
    elif(response[4] == 0x01):
        print 'Car ' + response[2] + ' parking at ' + places[response[3]]
    elif(response[4] == 0x02):
        print 'Car ' + response[2] + ' returned at Gateway. '
    else:
        sys.stderr.write('received data incorrcet.\n')
        sys.exit(2)

def send(car, dest1, dest2):
    sendinfo[2] = car
    sendinfo[3] = dest1
    sendinfo[4] = dest2
    sendinfo = array.array('B', sendinfo).tostring
    zigbee.write(sendinfo)
    if(zigbee.read() != 0xaa):
        sys.stderr.write('communication erron.\n')
        sys.exit(2)

def select():
    carNo = raw_input("Chose one car you want to control: \n")
    storage1 = raw_input("Chose the first place you want to:\n")
    storage2 = raw_input("Chose the second place you want to:\n")
    storage1 += 2
    storage2 += 2
    send(carNo, storage1, storage2) 

def main():
    zigbee = serial.Serial('/dev/ttyUSB0')
    select()
    response()

if __name__ == '__main__':
    main()
