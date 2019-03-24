#ifndef _WEATHERSTORMGENERATOR_H
#define _WEATHERSTORMGENERATOR_H
#include <chrono>
#include <string>
#include <iostream>
#include "elma.h"
#include "getDataState.h"
#include "energizeState.h"
#include "deenergizeState.h"
#include "weatherStormStateMachine.h"

using namespace elma;
//! This class is inherited from the Process class of Elma

//! The weatherStormGenerator class creates a weatherStormStateMachine object. It also creates a Manager object to schedule, init, and start
//! the weatherStormStateMachine process. This process waits for the tasks of state to be completed before emitting the event for the next  
//! state to start. This process will also pass the json object received from the server in the get data state to the energize and deenergize
//! states.   
class weatherStormGenerator : public Process
{
    public:

    //! Constructor that takes a name for the weatherStormGenerator process   
    /*!
      \param name the name of the state machine
    */
    weatherStormGenerator(string name) : Process(name){}

    //! Default constructor calling the default constructor of Process 
    weatherStormGenerator() : Process(){}

    //! This method is virtual from the abstract class Process of Elma
    //! for this project the init performs no task.
    void init();
    
    //! This method is virtual from the abstract class Process of Elma
    //! for this project start method creates a weatherStormStateMachine object. It also creates a Manager object to schedule, init, and start
    //! the weatherStormStateMachine process. It also waits for the tasks of state to be completed before emitting the event for the next  
    //! state to start. This method will also pass the json object received from the server in the get data state to the energize and deenergize
    //! states.   
    void start();

    //! This method is virtual from the abstract class Process of Elma
    //! for this project start method creates a weatherStormStateMachine object. It also creates a Manager object to schedule, init, and start
    //! the weatherStormStateMachine process. It also waits for the tasks of state to be completed before emitting the event for the next  
    //! state to start. This method will also pass the json object received from the server in the get data state to the energize and deenergize
    //! states.
    void update();

    //! This method is virtual from the abstract class Process of Elma
    //! for this project the stop performs no task.
    void stop();
    
    private:
    json _data;
};
#endif