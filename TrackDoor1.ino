//Arduino board code for the Adafruit Circuit Playground Express (CPX) used for a small data study measuring the frequency of visitation to my
//room during the later weeks of October 2025. -Asongafac Asaha 

#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

//Variable definitions. xVal will hold the acceleration/directional force of the CPX Board along it's X Axis. opSpeed logs that value and
//tells us how forcefully or quickly the door was opened. gapStart and gapEnd serve and time markers for when the door is opened and closed.
int xVal, opSpeed, gapStart, gapEnd;

//Not actually necessary, but I enjoy having the visual feedback of the begin() function, which shines green LEDs on startup.
void setup() 
{
  CircuitPlayground.begin();
}

//Main loop for the program to operate in. Constantly measures the acceleration of the CPX.
void loop() 
{
  xVal = CircuitPlayground.motionX();

  //If the measured x-Axis motion is greater than 3 (it usually reads between -1 and 2 when at "rest" for me), the logging process begins.
  //The orientation of my CPX on my door made it so that opening the door would result in positive values. 
  if(xVal >= 3)
  {
    opSpeed = xVal;
    gapStart = millis(); //Start time is from a running local clock that measures in milliseconds from the start of the program.

    //Loop used to track how long the door was opened for. Time tracking will persist until xVal reads a significantly strong and directionally
    //negative acceleration, at which point the end time-value is taken.
    while (xVal >= -1)
    {
      xVal = CircuitPlayground.motionX();
      delay(50); //delay to prevent program overrunning. The board is mighty, but still small :)
    }
    gapEnd = millis();

    //Prints the data to the console to be collected. String casting and concatenation chosen as the simplest way to deliver all data on a single
    //line without breaking serial output timestamps. The C++ based programing restrictions within Arduino hurt sometimes :(
    Serial.println(String(opSpeed)+","+String((float(gapEnd-gapStart))/1000));
    
    //Note that  also casted the duration of the door opening (^) to a floating decimal to the hundredths place. Order of parentheses is important here.
  }

  //Another delay to not overbear the board. Since door openings are *usually* not in quick succession, 2 seconds should be fine and likely modest.
  delay(2000);
}
