long duration; 
int distance; 
#define lineSensorPin 3
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  A2;      // the number of the LED pin
#define echoPin 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A4 //attach pin D3 Arduino to pin Trig of HC-SR04
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
boolean alarmSensors [2];
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(lineSensorPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }
}

void readsensors () {
 feedersensor[0] = readDistance;
 feedersensor[1] = readLinesensor;
}
boolean readDistance () {
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
   if (distance < 100) {
    return true;
  } else { 
    return false;
  }
}

boolean readLinesensor () {
int lineSensorValue = digitalRead(lineSensorPin);
return lineSensorValue;
}
