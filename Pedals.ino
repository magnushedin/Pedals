// Includes

// Defines
#define analog_input_pin A9

// Global variables
long t = 0;

void setup() {
  Serial.begin(115200);
  Joystick.useManualSend(true);
  
  pinMode(analog_input_pin, INPUT_PULLUP);

  t = millis();
  Serial.print(analogRead(analog_input_pin));
}


void loop() {
    int zAxisPos = 0;
    
    if ((millis() - t) > 10) {
      t = millis();

      zAxisPos = map(analogRead(analog_input_pin), 180, 785, 0, 1023);
      Joystick.Z(zAxisPos);

      Serial.print(zAxisPos);
      Serial.print(", ");
      Serial.println(analogRead(analog_input_pin));

      Joystick.send_now();
    }
    
}
