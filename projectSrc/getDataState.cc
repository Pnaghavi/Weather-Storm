#include <chrono>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include "elma.h"
#include "getDataState.h"
using namespace elma; 
void getDataState::entry(const Event& e)
{
    Client c;
    c.get("https://api.openweathermap.org/data/2.5/weather?id=5809844&APPID=25b8a0c53857909d84eaa9835e4ac2ac", [this](json& response) {
        std::cout<<"Received data from server:"<<std::endl;
        std::cout<<response.dump(4)<<std::endl;
        std::cout<<"Seattle's max temperature in Kelvins: "<<(int)round((double)response["main"]["temp_max"])<<std::endl;
        this->_data=response;
    });
    std::this_thread::sleep_for(std::chrono::seconds(2));
    c.process_responses();
    this->_taskCompleted=true;
}
void getDataState::during(){}
void getDataState::exit(const Event& e){}