```mermaid
flowchart TD
terminalStart([Start])
terminalEnd([End])
terminalStart --> thresholdSet(distanceThreshold = 100)
thresholdSet --> PiezoPin=8


ifDistanceLessThanThreshold{ReadDistanceThreshold} 
ifDistanceLessThanThreshold --> |False| ReadDistanceThreshold
ifDistanceLessThanThreshold --> |True| ReadLinesensor 
--> 
IfLineSensorActive{distanceSensor =< 100 >}
IfLineSensorActive --> |False| WriteServoPiezoLED=LOW
IfLineSensorActive --> |True| ServoMotor=DigitalWriteHIGH
--> PiezoBuzzer=DigitalWriteHIGH
--> LEDPin=HIGH


```