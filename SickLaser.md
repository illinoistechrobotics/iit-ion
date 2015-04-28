# Overview #

The Sick laser we have is model PLS101-112. It is designed for industrial applications. For more details about this line of lasers, see:
  * http://www.pages.drexel.edu/~kws23/tutorials/sick/sick.html
  * http://en.wikipedia.org/wiki/LIDAR
  * http://www.hizook.com/blog/2008/12/15/sick-laser-rangefinder-lidar-disassembled

# Interface #

The laser has a RS232 (serial) port. So-called "telegraph codes" are used for communication. These are sequences of binary data which initiate events or read/set registers on the laser.

# Progress #

So far we have:
  * unscrewed the heavy mounting bracket from the laser
  * traced and labeled the wires on the power connector
  * powered up the laser, red light always lit, yellow when something is close
  * tried LMS commands over serial, with mysterious response

To be done:
  * figure out Sick-provided documentation
  * write app (python?) to initiate scan and display scan result
  * write driver/software to integrate with ION control system