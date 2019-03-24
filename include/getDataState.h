#ifndef _GETDATESTATE_H
#define _GETDATESTATE_H
#include <chrono>
#include <string>
#include <iostream>
#include "elma.h"

using namespace elma;

//! This class is inherited from the State class of Elma that represents the get data state of the weatherStormStateMachine class

//! The getDataState class represents one of the states used by the weatherStormStateMachine class.
//! Most of the code is written in the entry method because once that method is done the taskCompleted will become true and
//! the manager that is running the process which is running the weatherStormStateMachine will emit event for the next state  
class getDataState : public State
{
    public:

    //! Constructor that takes a name for the getDataState 
    /*!
      \param name the name of the state
    */
    getDataState(string name) : State(name){}

    //! Default constructor calling the default constructor of State
    getDataState() : State(){}

    //! entry method is called when the state machine enters a new state
    //! This method will send a get request to https://api.openweathermap.org/data/2.5/weather?id=5809844&APPID=25b8a0c53857909d84eaa9835e4ac2ac   
    //! retrieving a json object from the server that includes weahter data of Seattle. When all tasks are complete this method sets private 
    //! taskCompletd boolean that can be retrieved by calling the taskCompleted mathod.
    /*!
      \param e is the Event emitted by the manager of weatherStormGenerator. 
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

    //! A getter method that returns a json object set by the response of the get request in the entry method
    inline json getJsonData(){ return _data;}

    //! A getter method that returns true when all tasks are completed in the entry method 
    inline bool taskCompleted(){return _taskCompleted;}

    private:
    json _data;
    bool _taskCompleted=false;   
};
#endif