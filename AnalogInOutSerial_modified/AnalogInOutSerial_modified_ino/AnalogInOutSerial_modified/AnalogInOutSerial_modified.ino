/*
  Analog input, analog output, serial output
 
 Reads an analog input pin prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin1 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A1;  // Analog input pin that the potentiometer is attached to

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot

#define ABS_MAX 270
#define ABS_MIN 185

int lowThresh = (ABS_MAX-ABS_MIN)*1/3+ABS_MIN;
int highThresh = (ABS_MAX-ABS_MIN)*2/3+ABS_MIN;

boolean isWhite = false;

int count = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(57600); 
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(analogInPin1);  
  sensorValue2 = analogRead(analogInPin2);              

  if (isWhite && (sensorValue2<lowThresh)){
    Serial.println("Saw black");
    isWhite = false;
    count++;
    delay(50);
  }

  if (!isWhite && (sensorValue2>highThresh)){
    Serial.println("Saw white");
    isWhite = true;
    count++;
    delay(50);
  }

  // print the results to the serial monitor:
  Serial.print("count = " );                       
  Serial.print(count);      
  Serial.print("sensor1 = " );                       
  Serial.print(sensorValue1);      
  Serial.print("\t sensor2 = ");      
  Serial.println(sensorValue2);   

  // wait * milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
