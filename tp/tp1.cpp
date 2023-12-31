/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"
#include "string.h"

//MicroBit uBit;

int _main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    // MicroBitAccelerometer accelerometer = uBit.accelerometer;
    // accelerometer.setPeriod(20);
    // accelerometer.setRange(8);
    // MicroBitCompass compass = uBit.compass;
    // compass.setPeriod(20);
    // compass.calibrate();

    uBit.compass.calibrate();

    // Insert your code here!
    while (1) {
        int bearing = uBit.compass.heading();
        if (bearing < 20 || bearing >335) {
            uBit.display.print("N");
        } else {
            uBit.display.print(" ");
        }
        // if (uBit.buttonA.isPressed()) {
        //     uBit.display.scroll("TEST!");
        // } else {
        //     if (compass.heading() < 45 || compass.heading() > 315) {
        //         uBit.display.print("N");
        //     } else if (compass.heading() == MICROBIT_COMPASS_EVT_CALIBRATE) {
        //         uBit.display.print("X");
        //     }

            // int dx = uBit.accelerometer.getX();
            // int dy = uBit.accelerometer.getY();
            // if (abs(dx) > abs(dy)) {
            //     if(dx < 0) {
            //         uBit.display.print("<");
            //     } else {
            //         uBit.display.print(">");
            //     }
            // }

            
        //}
    }


    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

