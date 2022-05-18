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

``` mermaid
flowchart TD
terminalStart([Start])
terminalEnd([End])
terminalStart --> ButtonActivate{ReadButton}
ButtonActivate --> |True| ActivateMotor
ButtonActivate --> |False| KeepMotoroff
-->terminalEnd


```

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
