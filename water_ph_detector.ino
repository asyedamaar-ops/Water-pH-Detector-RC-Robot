/*
  Water pH Detector RC Robot
  Course: Computer Organization and Architecture (21CSS201T)
  SRM Institute of Science and Technology, Kattankulathur

  Description:
    Reads analog pH sensor data from pin A0, converts the raw
    ADC value to voltage, and prints it to the Serial Monitor.
    Runs on Arduino Uno at 9600 baud.

  Hardware:
    - Arduino Uno
    - pH sensor rod connected to analog pin A0
    - RC circuit (resistor-capacitor) for signal conditioning
    - DC motors + rotary wheels (joystick/RF controlled)
    - LED indicator for pH status feedback
    - Rechargeable battery pack
*/

int pH_Value;
float Voltage;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);  // A0 — analog input from pH sensor
}

void loop() {
  pH_Value = analogRead(A0);                   // Raw ADC reading (0–1023)
  Voltage   = pH_Value * (5.0 / 1023.0);       // Convert to voltage (0–5V)

  Serial.print("ADC Value: ");
  Serial.print(pH_Value);
  Serial.print("  |  Voltage: ");
  Serial.print(Voltage, 3);
  Serial.println(" V");

  delay(500);  // Sample every 500 ms
}
