//Sd Card module
#include <SPI.h>
#include <SD.h>
#include <L298N.h>
#include <Servo.h>
Servo myservo;
#include "RTClib.h"
RTC_Millis rtc; 
DateTime rightNow;
#define pot A3
#define ledRed A0
#define ledYellow A1 
#define ledGreen A2
#define piezoPin 8
#define lineSensorPin 3
#define crashSensor 7
// DC Motor & Motor Module - L298N
#include <L298N.h>
#define echoPin 4 
#define trigPin 5
// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;
long duration;
int distance;
int buttonState = 0; 
L298N motor(EN, IN1, IN2);


void setup() {
pinMode(ledRed, OUTPUT);
pinMode(ledYellow, OUTPUT);
pinMode(ledGreen, OUTPUT);
motor.setSpeed(70);
 myservo.attach(9);
 pinMode(pot, INPUT);
 pinMode(piezoPin,OUTPUT);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
pinMode(lineSensorPin, OUTPUT);
pinMode(crashSensor, INPUT);  
 Serial.println("Ultrasonic Sensor HC-SR04 Test");
 Serial.println("with Arduino UNO R3");
Serial.begin(9600);           // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);                   // wait for serial port to connect. Needed for native USB port only
  }

// SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
// Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
logEvent("System Initialisation...");

}

void loop() {

FishFeeder(); // Sonar, Line sensor, Pot and DC Motor
CompletionAlarm(); // Piezo and LED
ManualFeeder();// Button
}

/* When someone arrives in the drive way (sonar) and light is detected inside the house (Line Sensor) the Fish feeder will automatically activate itself (DC Motor) adjust the portion size (Potentiometer)
 * 
 */
void FishFeeder() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

/*
 * When the Feeder is active alert the completition with a green light (LED) and a buzzer (Piezo Buzzer)
 */
void CompletionAlarm() {
}

/*
 * A button can be pressed to manually activate the feeder (Button) if needed
 */
void ManualFeeder(){

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (crashSensor == HIGH) {
    // turn LED on:
    digitalWrite(ledGreen, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledGreen, LOW);
  }
}

void logEvent(String dataToLog) {
  /*
     Log entries to a file on an SD card.
  */
  // Get the updated/current time
  DateTime rightNow = rtc.now();

  // Open the log file
  File logFile = SD.open("events.csv", FILE_WRITE);
  if (!logFile) {
    Serial.print("Couldn't create log file");
    abort();
  }

  // Log the event with the date, time and data
  logFile.print(rightNow.year(), DEC);
  logFile.print(",");
  logFile.print(rightNow.month(), DEC);
  logFile.print(",");
  logFile.print(rightNow.day(), DEC);
  logFile.print(",");
  logFile.print(rightNow.hour(), DEC);
  logFile.print(",");
  logFile.print(rightNow.minute(), DEC);
  logFile.print(",");
  logFile.print(rightNow.second(), DEC);
  logFile.print(",");
  logFile.print(dataToLog);

  // End the line with a return character.
  logFile.println();
  logFile.close();
  Serial.print("Event Logged: ");
  Serial.print(rightNow.year(), DEC);
  Serial.print(",");
  Serial.print(rightNow.month(), DEC);
  Serial.print(",");
  Serial.print(rightNow.day(), DEC);
  Serial.print(",");
  Serial.print(rightNow.hour(), DEC);
  Serial.print(",");
  Serial.print(rightNow.minute(), DEC);
  Serial.print(",");
  Serial.print(rightNow.second(), DEC);
  Serial.print(",");
  Serial.println(dataToLog);
}
