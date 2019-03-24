#ifndef _ENERGIZESTATE_H
#define _ENERGIZESTATE_H
#include <chrono>
#include <string>
#include <iostream>
#include "elma.h"

using namespace elma;

//! This class is inherited from the State class of Elma that represents the energize state of the weatherStormStateMachine class

//! The energizeState class represents one of the states used by the weatherStormStateMachine class.
//! Most of the code is written in the entry method because once that method is done the taskCompleted will become true and
//! the manager that is running the process which is running the weatherStormStateMachine will emit event for the next state  
class energizeState : public State
{
    public:

    //! Constructor that takes a name for the energizeState 
    /*!
      \param name the name of the state
    */
    energizeState(string name) : State(name){}

    //! Default constructor calling the default constructor of State
    energizeState() : State(){}

    //! entry method is called when the state machine enters a new state
    //! This method will brighten the LEDs and rotate the stepper motor by the same number of count in full step mode as the current   
    //! maximum temperature of Seattle. Also, it sets the private json object that can be retrieved by calling the getJsonData method. 
    //! When all tasks are complete this method sets private taskCompletd boolean that can be retrieved by calling the taskCompleted
    //! mathod.
    /*!
      \param e is the Event emitted by the manager of weatherStormGenerator, it includes the json object received by the getDataSate 
    */
    void entry(const Event& e);

    //! This method is virtual from the abstract class State of Elma
    //! for this project the during performs no task.
    void during();

    //! This method is virtual from the abstract class State of Elma
    //! for this project the exit performs no task.
    /*!
      \param e is the Event emitted by the manager of weatherStormGenerator, it includes the json object received by the getDataSate. 
    */
    void exit(const Event& e);

    //! A getter method that returns the json object set by entry method's parameter Evant, e. e.value() method returns a json object.
    inline json getJsonData(){ return _data;}

    //! A getter method that returns true when all tasks are completed in the entry method 
    inline bool taskCompleted(){return _taskCompleted;}

    private:
        json _data;
        bool _taskCompleted=false;   
};
#endif