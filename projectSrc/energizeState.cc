#include <chrono>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <wiringPi.h>
#include <errno.h>
#include<wiringPiSPI.h>
#include<unistd.h>
#include <bcm2835.h>  // communicate with gpio
#include <stdint.h>   // fixed width ints to hold Pixel values
#include <unistd.h>   // usleep
#include <stdlib.h>   // basically everything I think
#include "pixel.h"    // Pixel and PixelList classes
#include "clinkt.h"   // just leave this one in
#include "elma.h"
#include "energizeState.h"
using namespace elma; 
void energizeState::entry(const Event& e)
{
    wiringPiSetup();
    pinMode(16,OUTPUT);  //run motor
    if (start())
    {
        std::cout << "Unable to start apa102: bcm not initialising?\n";
        return ;
    }
    PixelList Graph(NUM_LEDS);
    int halfStppingMult=2; 
    int maxCount=(int)round((double)e.value()["main"]["temp_max"])*halfStppingMult;
    int count=0;
    //std::cout<<*temp<<std::endl;
    // replace NUM_LEDS with whatever input you desire
    int lastUp=0;
    uint32_t ledColor0=0x000000003, ledColor1=0x000000003, ledColor2=0x000000003, ledColor3=0x000000003, ledColor4=0x000000003, ledColor5=0x000000003, ledColor6=0x000000001, ledColor7=0x000000001;
    while(count<maxCount)
    {
        digitalWrite(16, HIGH);
        count++;
        int thisUp = (int)((double)(count)/maxCount*255);
        if(ledColor0<0x0ff000003 && lastUp!=thisUp)
        {
            ledColor0+=0x001000000;
            ledColor1+=0x001000000;
        }
        if(ledColor2<0x000ff0003 && lastUp!=thisUp)
        {
            ledColor2+=0x000010000;
            ledColor3+=0x000010000;
        }
        if(ledColor4<0x00000ff03 && lastUp!=thisUp)
        {
            ledColor4+=0x000000100;
            ledColor5+=0x000000100;
        }
        if(ledColor6<0x0ffffff01 && lastUp!=thisUp)
        {
            ledColor6+=0x001010100;
            ledColor7+=0x001010100;
        }
        Graph.setP(ledColor0, 0);
        Graph.setP(ledColor1, 1);
        Graph.setP(ledColor2, 2);
        Graph.setP(ledColor3, 3);
        Graph.setP(ledColor4, 4);
        Graph.setP(ledColor5, 5);
        Graph.setP(ledColor6, 6);
        Graph.setP(ledColor7, 7);
        Graph.show();
        lastUp=thisUp;
        std::this_thread::sleep_for(std::chrono::microseconds(1500));
        digitalWrite(16, LOW);
        std::this_thread::sleep_for(std::chrono::microseconds(1500));
    }
    this->_data=e.value();
    this->_taskCompleted=true;
}
void energizeState::during(){}
void energizeState::exit(const Event& e){}