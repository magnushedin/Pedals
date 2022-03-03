// Includes

// Defines
#define analog_input_pin A9

// Global variables
long t = 0;
int minPos = 1023;
int maxPos = 0;

void setup() {
  Serial.begin(115200);
  Joystick.useManualSend(true);
  
  pinMode(analog_input_pin, INPUT_PULLUP);

  t = millis();
}

void debugPrint(int zAxisPos) {
      Serial.print(zAxisPos);
      Serial.print(", ");
      Serial.print(analogRead(analog_input_pin));
      Serial.print(", (");
      Serial.print(minPos);
      Serial.print("/");
      Serial.print(maxPos);
      Serial.print(") - mid: ");
      Serial.println((maxPos - minPos)/2 + minPos);
}

void loop() {
    int zAxisPos = 0;
    int sensorValue = 0;

    sensorValue = analogRead(analog_input_pin);
    maxPos = max(maxPos, sensorValue);
    minPos = min(minPos, sensorValue);
    zAxisPos = map(sensorValue, minPos, maxPos, 0, 1023);

    if ((millis() - t) > 10) {
      t = millis();

      debugPrint(zAxisPos);
      
      Joystick.Z(zAxisPos);
      Joystick.send_now();
    }
    
}
