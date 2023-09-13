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
#include "inc/neopixel.h"



MicroBit uBit;
int NP_LED_COUNT = 3;
Color RED_L (0, 40, 0);
Color RED (0, 70, 0);
Color RED_H (0, 100, 0);
Color GREEN (70, 0, 0);
Color GREEN_H (100, 0, 0);
Color YELLOW (35, 80, 0);
Color PURPLE (0, 35, 80);
Color BLACK (0, 0, 0);
Neopixel np = Neopixel(MICROBIT_PIN_P0,NP_LED_COUNT);

void show_neopixel(int8_t red,int8_t green,int8_t blue){
    for(int i = 0 ; i< NP_LED_COUNT; i++){
        np.setColor(i, red, green, blue);
        np.show();
    }
    uBit.sleep(100);
}

void rainbow(int8_t R, int8_t G, int8_t B){

  for(G ; G < 255; G+=5){
    show_neopixel(R, G, B);
  }
  for(R ; R > 50; R-=5){
    show_neopixel(R, G, B);
  }
  for(B ; B < 255; B+=5){
    show_neopixel(R, G, B);
  }
  for(G ; G > 50; G-=5){
    show_neopixel(R, G, B);
  }
  for(R ; R < 255; R+=5){
    show_neopixel(R, G, B);
  }
  for(B ; B > 50; B-=5){
    show_neopixel(R, G, B);
  }
  rainbow(R, G, B);
}


int main()
{
    int8_t R = 255;
    int8_t G = 50;
    int8_t B = 50;
    uBit.init();

    rainbow(R, G, B);
    
    

    release_fiber();

}

