#include <stdio.h>
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "elma.h"
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
#include <iostream>   // genuinely only here to output the word 'Dead'
#include "weatherStormGenerator.h"
using namespace elma; 
using namespace std;

static const int CHANNEL = 1;

//! main function creates a Manager and a weatherStormGenerator process object by the name, Evil weather master's evil storm generator, to run for 100s
//! By starting the weatherStormGenerator the start method gets called which runs the weatherStormStateMachine through all the states in correct sequence.
//! The process also gets updated every 7 seconds for 100 seconds before the machine stops doing evil things such as brighteing LEDs and rotating a stepper
//! motor and then dimmimg the LEDs in the evil deenergize state periodically. 
int main(int argc, char **argv)
{
  Manager m; 
  weatherStormGenerator eveilGenerator("Evil weather master's evil storm generator");
  m.schedule(eveilGenerator,7_s).start().run(100_s); 
}
 /* std::cout<<"hello world!"<<std::endl; 
  Client c;
  int * temp;
  c.get("https://api.openweathermap.org/data/2.5/weather?id=5809844&APPID=25b8a0c53857909d84eaa9835e4ac2ac", [](json& response) {
                std::cout<<"Seattle's temperature in Kelvins: "<<(int)round((double)response["main"]["temp_max"])<<std::endl;
            });
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout<<c.num_responses()<<std::endl;
  c.process_responses();
  wiringPiSetup();
  pinMode(16,OUTPUT);  //run motor
  if (start())
  {
    std::cout << "Unable to start apa102: bcm not initialising?\n";
    return 1;
  }
  signal(SIGINT, dieNicely);   // On keyboard interrupt, darkens pixels and stops gpio
                               // uses exit(0) - write your own if that is a deal-breaker

  PixelList Graph(NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++)
    { Graph.setP(3, i);}

  int maxCount=400;
  int count=0, countDown=maxCount ;
  //std::cout<<*temp<<std::endl;
  bool oneShot=false;
  // replace NUM_LEDS with whatever input you desire
  int lastUp=0;
  uint32_t ledColor0=0x000000003, ledColor1=0x000000003, ledColor2=0x000000003, ledColor3=0x000000003, ledColor4=0x000000003, ledColor5=0x000000003, ledColor6=0x000000001, ledColor7=0x000000001;
  while(1)
  {
    if(count<maxCount)
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
    else if(countDown>0)
    {
      countDown--;
      int thisUp = (int)((double)(countDown)/maxCount*255);
      if(ledColor0<=0x0ff000003 && lastUp!=thisUp)
      {
        ledColor0-=0x001000000;
        ledColor1-=0x001000000;
      }
      if(ledColor2<=0x000ff0003 && lastUp!=thisUp)
      {
        ledColor2-=0x000010000;
        ledColor3-=0x000010000;
      }
      if(ledColor4<=0x00000ff03 && lastUp!=thisUp)
      {
        ledColor4-=0x000000100;
        ledColor5-=0x000000100;
      }
      if(ledColor6<=0x0ffffff01 && lastUp!=thisUp)
      {
        ledColor6-=0x001010100;
        ledColor7-=0x001010100;
      }
      std::this_thread::sleep_for(std::chrono::microseconds(4000));
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
    }
    else 
    {
      Graph.setP(0x000000001, 0);
      Graph.setP(0x000000001, 1);
      Graph.setP(0x000000001, 2);
      Graph.setP(0x000000001, 3);
      Graph.setP(0x000000001, 4);
      Graph.setP(0x000000001, 5);
      Graph.setP(0x000000001, 6);
      Graph.setP(0x000000001, 7);
      Graph.show();
      return 0;
    }
  }
  stop(); // ends gpio nicely in the highly strange event of us getting here  
  return 0;	
          */