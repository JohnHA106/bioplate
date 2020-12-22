#include <OneWire.h>
#include <DallasTemperature.h>
#include <math.h>
int heater = 7; // D7 Pin to turn on Relay
int time = 0;   // Time counter for cycle timing
int cycle = 1;  // Cycle counter
 
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 

void setup() {
  // put your setup code here, to run once:
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(heater, OUTPUT);  // Set Pin connected to Relay as an OUTPUT
  digitalWrite(heater, LOW);  // Set Pin to LOW to turn Relay OFF
}
}

void loop() {
  // put your main code here, to run repeatedly:
 sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("Starting up...");
 //change the number in the line below to choose temp 
  if (sensors.getTempCByIndex(0) < 30) {      // While Loop to Bring up to Temp 30C                  
    sensors.requestTemperatures(); // Send the command to get temperatures
    Serial.print("Temperature is: ");
    Serial.println(sensors.getTempCByIndex(0));
    digitalWrite(heater, HIGH);
  }

  else {
    digitalWrite(heater, LOW);
  }
    delay(1000);
}
}
}
