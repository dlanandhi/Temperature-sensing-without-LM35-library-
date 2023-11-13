#define lm35Pin  A0  // Analog pin for LM35 temperature sensor
#define ledPin   2   // Digital pin for LED 

int blinkInterval = 250;  // Default interval for temperature below 30 degrees Celsius
unsigned long previousMillis = 0;
boolean ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT); // set ledpin as output 
  Serial.begin(9600);
}

void loop() {
  
  int sensorValue = analogRead(lm35Pin);  // read temperature from sensor
  // The LM35 sensor outputs voltage proportional to the Celsius temperature.
  float temperature = (sensorValue / 1023.0) * 500.0; 

  Serial.println(temperature);  // prints temperature manipulated after reading from sensor
  
  if (temperature < 30)  // checking if temperature is 30 then update LED state to blink every 250 millisecond
  {
    updateLEDState(250);
  } 
  else                 // when temperature goes above 30 then update LED state to blink every 500 millisecond 
  
  {
    updateLEDState(500);
  }
}

void updateLEDState(int interval) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Save the last time LED state was changed
    previousMillis = currentMillis;

    // Toggle the LED state
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
