Weather-Storm
===

The Elma Weather Storm uses the [Elam](https://github.com/klavinslab/elma) library as its infrastructure to implement an event loop process manager for raspberry pi to read weather related data from online sources and use that to create visual indications, such as blinking LEDs and or turning a stepper motor. In addition, I will be using the [http.h](https://github.com/yhirose/cpp-httplib) library and [json.h](https://github.com/nlohmann/json) library for this project. In order to succeed in this project, I must be able to run Elma on a raspberry pi which may seem simple, but I have no experience using raspberry pi. Additional goals of this project are getting weather related data of Seattle from an online server such as Google. Finally, the ultimate success in this project is achieved by turning this information into visual responses using the raspberry pi. These visual responses could be as simple as blinking an LED every 2 minutes as many times as the current temperature in Fahrenheit. I have also found a stepper motor and a switching power supply that I can use to create a more visual outputs with; however, I would need a stepper drive that works well with raspberry pi, so if time allows, I will be adding that functionality. An example of a complete project can be a loop where latest Seattle’s temperature is pulled from an online server then the stepper rotates as many steps as the current temperature of Seattle and finally the system sleeps for one minute.
The source code for this project is available [on github](https://github.com/Pnaghavi/Weather-Storm).

Milestones 
---

The milestones for this project are listed below:

1-	Get Docker, doxygen, google test, Visual Studio Code, and Elma working on raspberry pi. This will be completed 3/13/2019.

2-	including [http.h](https://github.com/yhirose/cpp-httplib) library and [json.h](https://github.com/nlohmann/json) library in this         project. This will be completed 3/13/2019.

3-	Get weather related data from an online source. This will be completed 3/19/2019.

4-	Develop a process that creates visual response based on weather data. This will be completed 3/20/2019.

5-	Completing API documentation for the project. This will be completed 3/21/2019.
   
To Date Accomplishments
---

Docker, doxygen, google test, Visual Studio Code, and Elam are all working on raspberry pi. This required a number of libraries installed including http and json.
The milestones have not changed yet as there is five days remaining to the due date of the project.

Working Aspects of the Project       
---

Currently the Elma project can be made with the docker installed on the pi. Elma can also be made by calling the make file in the terminal.
Next step is to get weather data from an online sorce which should be simpler after completing homework 9.   

Installation
---

    git clone https://github.com/Pnaghavi/Weather-Storm.git
    cd elma_project
    docker run -v $PWD:/source -it klavins/elma:latest bash
    make
    make docs


Execution
---
To run the stopwatch, type

    bin/stopwatch

The stopwatch is controlled via the keyboard, via these keys:
- **s**: Start or stop
- **l**: Lap
- **r**: Reset
- **q**: Quit

Testing
---
To run tests, do
```bash
bin/test
```

Architecture
---
Describe how your project was designed, what choices you made, how things are organized, etc.

Results
---
Describe the results of testing and running your code. Include visuals when possible.

Acknowledgements
---
Mention anyone who helped you and how.

References
---
List all libraries, articles, stack overflow answers, etc. that you used to get your code working.
