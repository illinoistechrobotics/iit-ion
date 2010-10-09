import serial
ser = serial.Serial('COM4',57600)
print ser.portstr
ser.write(chr(128))
ser.write(chr(130))
ser.write(chr(132))
print "start-control-full"
ser.write(chr(137))
ser.write(chr(40))
ser.write(chr(40))
ser.write(chr(128))
ser.write(chr(0))