#include <LiquidCrystal.h>
#include <DFRobot_DHT11.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define DHT11_PIN 7
DFRobot_DHT11 DHT;
int Contrast = 75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorPin = 0;
int lightlevel;

 void setup(){
    analogWrite(6, Contrast);
    Serial.begin(9600);
    Serial.print("temperature, humidity, and light"); //prints ordering once
 }
void lcdwrite(){
    lightlevel = analogRead(sensorPin);  // reads the voltage on the sensorPin
    lcd.setCursor(0, 0); //starts the cusor at the begining of the LCD
    lcd.print("T:"); //Prints a "T" to singal that the following data is the temperature
    lcd.print(DHT.temperature); //prints out the temperature in celcus
    lcd.print("H:"); //Prints a "H" to singal that the following data is the humidity
    lcd.print(DHT.humidity); //prints out the humidity in percentage
    lcd.print("L:"); //Prints a "L" to singal that the following data is the lightLevel
    lcd.print(lightlevel); //Prints out the lightlevel
    lcd.setCursor(0, 1); //Sets the cusor to the second line for the date
    lcd.print("6/??/23"); //prints out the data
}

 void serialwrite(){
    DHT.read(DHT11_PIN); //reads the data from the sensor
    Serial.print(DHT.temperature); //prints out the temperature first
    Serial.print(","); //adds a commaa so the serial can make a chart
    Serial.print(DHT.humidity); //prints out the humidity second
    Serial.print(","); //adds a commaa so the serial can make a chart
    Serial.print(lightlevel); //finally prints the light level which
    Serial.println(",");
    }
    
 void loop(){
    lcdwrite(); //runs the lcdwrite command to write to the LCD
    serialwrite(); //runs the serialwrite command to print to serial the data
    delay(1000);
}
