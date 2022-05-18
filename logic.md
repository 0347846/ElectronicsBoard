
Behaviour 1. When someone arrives in the driveway activate sonar. If sonar is active and Line sensor is active start the fish feeder 

```mermaid
flowchart TD
terminalStart([Start])
terminalEnd([End])
terminalStart --> thresholdSet(distanceThreshold = 100)
thresholdSet --> ReadValueFromSensor
-->
PotenitometerSetPortionSize
-->
ifDistanceLessThanThreshold{ReadDistanceThreshold} 
ifDistanceLessThanThreshold --> |False| ReadValueFromSensor
ifDistanceLessThanThreshold --> |True| ReadLinesensor 
--> terminalEnd([End])
```
Behaviour 2. When Fish feeder active activate motor to drop food in tank and alert completetion by turing on a buzzer and light
``` mermaid
flowchart TD
terminalStart([Start])
terminalEnd([End])
terminalStart --> BothSensorsTrue
--> TurnONMotor
--> TurnONPiezo
--> TurnONLED
--> terminalEnd([End])
```

Behaviour 3. If button is pressed drop food in tank
``` mermaid
flowchart TD
terminalStart([Start])
terminalEnd([End])
terminalStart --> ButtonActivate{ReadButton}
ButtonActivate --> |True| ActivateMotor
ButtonActivate --> |False| KeepMotoroff
-->terminalEnd
```
Sensor Loop
``` mermaid
flowchart TD
terminalStart([Start Loop])
terminalEnd([End])
terminalStart([Start Loop])
-->
DistanceSensor
--> Potenitometer
--> LineSensor
--> terminalEnd
```

Loop when feeder is activated
``` mermaid
flowchart TD
terminalStart([Start Loop])
terminalStart([Start Loop])
-->
ServoMotor
--> PiezoBuzzer
--> LED
--> Button
```
