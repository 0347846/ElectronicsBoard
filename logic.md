```mermaid
flowchart TD
terminalStart([Start])
terminalEnd([End])
terminalStart --> thresholdSet(distanceThreshold = 100)
thresholdSet --> PiezoPin=8
-->
ifDistanceLessThanThreshold{ReadDistanceThreshold} 
ifDistanceLessThanThreshold --> |False| ReturntoDistanceThreshold
ifDistanceLessThanThreshold --> |True| ReadLinesensor 
--> 
IfLineSensorActive{ReadLinesensor}
IfLineSensorActive --> |False| ReturntoDistanceThreshold
IfLineSensorActive --> |True| ServoMotor=DigitalWriteHIGH
--> PiezoBuzzer=DigitalWriteHIGH
--> LEDPin=HIGH
-->
ButtonActivate{ReadButton}
ButtonActiavte --> |True| ServoMotor=HIGH 
ButtonActivate --> |False| ReturntoDistanceThreshold

```