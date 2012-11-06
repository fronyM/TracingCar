#!/usr/bin/env python2
# -*- coding:utf-8 -*-

import serial
import array
import sys

zigbee = serial.Serial('/dev/ttyUSB0')

a = [0xff, 0xff, 0x01, 0x01 ,0x02]
a = array.array('B', a).tostring()
zigbee.write(a)
rece = zigbee.read()
rece = [ord(c) for c in rece]
zigbee.close()
print rece

def getResponse():
    response = zigbee.read(5)
    response = [ord(c) for c in response]
    if(response[0] == 0xff and response[1] = 0xff):
        print 'Car' + response[2] + 'returned error'
        sys.exit(1)

