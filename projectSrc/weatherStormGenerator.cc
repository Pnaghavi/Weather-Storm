#include <chrono>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include "elma.h"
#include "weatherStormGenerator.h"
using namespace elma; 
void weatherStormGenerator::init(){}
void weatherStormGenerator::start()
{
    weatherStormStateMachine wssm =weatherStormStateMachine("Weather Storm State Machine");
    Manager m;
    m.schedule(wssm,10_s)
    .init()
    .start()
    .emit(Event("start"));
    std::cout<<"Weather Storm State Machine started."<<std::endl;
    while(!wssm.getGetDateState().taskCompleted()){std::this_thread::sleep_for(std::chrono::milliseconds(10));}
    std::cout<<"Weather Storm State Machine received data."<<std::endl;

    m.emit(Event("energize",wssm.getGetDateState().getJsonData()));
    while(!wssm.getEnergizeState().taskCompleted()){std::this_thread::sleep_for(std::chrono::milliseconds(10));}
    std::cout<<"Weather Storm State Machine is energized."<<std::endl;

    m.emit(Event("deenergize",wssm.getGetDateState().getJsonData()));
    while(!wssm.getDeenergizeState().taskCompleted()){std::this_thread::sleep_for(std::chrono::milliseconds(10));}
    std::cout<<"Weather Storm State Machine is deenergized."<<std::endl;

    m.emit(Event("idle",wssm.getGetDateState().getJsonData()));
    std::cout<<"Weather Storm State Machine is idle."<<std::endl;
}
void weatherStormGenerator::stop(){}
void weatherStormGenerator::update()
{
    weatherStormStateMachine wssm =weatherStormStateMachine("Weather Storm State Machine");
    Manager m;
    m.schedule(wssm,10_s)
    .init()
    .start()
    .emit(Event("start"));
    std::cout<<"Weather Storm State Machine started."<<std::endl;
    while(!wssm.getGetDateState().taskCompleted()){std::this_thread::sleep_for(std::chrono::milliseconds(10));}
    std::cout<<"Weather Storm State Machine received data."<<std::endl;

    m.emit(Event("energize",wssm.getGetDateState().getJsonData()));
    while(!wssm.getEnergizeState().taskCompleted()){std::this_thread::sleep_for(std::chrono::milliseconds(10));}
    std::cout<<"Weather Storm State Machine is energized."<<std::endl;

    m.emit(Event("deenergize",wssm.getGetDateState().getJsonData()));
    while(!wssm.getDeenergizeState().taskCompleted()){std::this_thread::sleep_for(std::chrono::milliseconds(10));}
    std::cout<<"Weather Storm State Machine is deenergized."<<std::endl;

    m.emit(Event("idle",wssm.getGetDateState().getJsonData()));
    std::cout<<"Weather Storm State Machine is idle."<<std::endl;
}