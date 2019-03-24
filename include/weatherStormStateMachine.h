#ifndef _WEATHERSTORMSTATEMACHINE_H
#define _WEATHERSTORMSTATEMACHINE_H
#include <chrono>
#include <string>
#include <iostream>
#include "elma.h"
#include "getDataState.h"
#include "energizeState.h"
#include "deenergizeState.h"

using namespace elma;

//! This class is inherited from the State class of Elma that represents the idle state of the weatherStormStateMachine class

//! The idleState class represents one of the states used by the weatherStormStateMachine class.
//! This was necessary because the Elam State class is abstract. None of the entry, during, and exit methods perform an
//! essential task.    
class idleState : public State
{
    public:

    //! Constructor that takes a name for the idleState 
    /*!
      \param name the name of the state
    */
    idleState(string name) : State(name){}

    //! Default constructor calling the default constructor of State
    idleState() : State(){}

    //! This method is virtual from the abstract class State of Elma
    //! for this project the during performs no task.
    /*!
      \param e is the Event emitted by the manager of weatherStormGenerator, it includes the json object received by the getDataSate. 
    */
    void entry(const Event& e){}

    //! This method is virtual from the abstract class State of Elma
    //! for this project the during performs no task.
    void during(){}

    //! This method is virtual from the abstract class State of Elma
    //! for this project the during performs no task.
    /*!
      \param e is the Event emitted by the manager of weatherStormGenerator.
    */
    void exit(const Event& e){}
};

//! This class is inherited from the StateMachine class of Elma

//! The weatherStormStateMachine class has four states that are:  idel state, get data state, energize state, and deenergize state.
//! there are four transitions for this state machine that are: start, that changes idel state to get data state; energize, that 
//! changes get data state to energize state; deenergize, that changes energize state to deenergize state; and idle, that changes 
//! deenergize state to idle state.  
class weatherStormStateMachine : public StateMachine
{
    public:

    //! Constructor that takes a name for the weatherStormStateMachine 
    //! In this method all the states are constructed. Also, all the transitions are added.    
    /*!
      \param name the name of the state machine
    */
    weatherStormStateMachine(string name) : StateMachine(name)
    {
        _getDataState = getDataState("getDataState");
        _energizeState = energizeState("energizeState");
        _deenergizeState = deenergizeState("deenergizeState");
        _idle=idleState("idle");
        set_initial(_idle);
        this->add_transition("start", _idle,_getDataState);
        this->add_transition("energize", _getDataState,_energizeState);
        this->add_transition("deenergize", _energizeState,_deenergizeState);
        this->add_transition("idle", _deenergizeState, _idle);
    }

    //! Default constructor calling the default constructor of StateMachine 
    //! In this method all the states are constructed. Also, all the transitions are added.    
    weatherStormStateMachine() : StateMachine()
    {
        _getDataState = getDataState("getDataState");
        _energizeState = energizeState("energizeState");
        _deenergizeState = deenergizeState("deenergizeState");
        _idle=idleState("idle");
        set_initial(_idle);
        this->add_transition("start", _idle,_getDataState);
        this->add_transition("energize", _getDataState,_energizeState);
        this->add_transition("deenergize", _energizeState,_deenergizeState);
        this->add_transition("idle", _deenergizeState, _idle);
    }

    //! A getter method that returns the getDatestate object created in the constructor
    //! Using this method I can access the getter methods in the getDatestate class to see if all state tasks are complete or retrieve the json object    
    inline getDataState  getGetDateState(){ return _getDataState;}

    //! A getter method that returns the energizeState object created in the constructor
    //! Using this method I can access the getter methods in the energizeState class to see if all state tasks are complete or retrieve the json object 
    inline energizeState  getEnergizeState(){ return _energizeState;}

    //! A getter method that returns the deenergizeState object created in the constructor
    //! Using this method I can access the getter methods in the deenergizeState class to see if all state tasks are complete or retrieve the json object 
    inline deenergizeState  getDeenergizeState(){ return _deenergizeState;}

    private:
    idleState _idle;
    getDataState _getDataState;
    energizeState _energizeState;   
    deenergizeState _deenergizeState;
};
#endif