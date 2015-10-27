#define CANDLELED 4
#define REDLED 5
#define BUZZER 5
#define SENSOR 3
//#define PROXIMITY_THRESHOLD 85
//#define PROXIMITY_CONSECUTIVE_READINGS 3
#define BUZZER_FREQUENCY 38
#define FLICKER_INTERVAL 250

long previousMillis = 0;
//long closeReadings = 0;

void setup() {
  pinMode(CANDLELED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SENSOR, INPUT);
  delay(1000); // Allow the proximity sensor to initialize
}
void loop() {
  if (digitalRead(SENSOR) == HIGH) // Someone nearby? TODO: rewrite this with pin change interrupt?
  {
    digitalWrite(CANDLELED, LOW);
    digitalWrite(REDLED, HIGH);
    //tone(BUZZER, BUZZER_FREQUENCY); // disabled for now, until I have a buzzer connected, else it fails.
    // do I need some timing stuff here? how long does it buzz?
  }
  else
  { //regular candle flicker. Based on Arduino example BlinkWithoutDelay.
    noTone(BUZZER);
    digitalWrite(REDLED, LOW);
    unsigned long currentMillis = millis(); // TODO: rewrite this to make the chip sleep instead? (saving power)
    if (currentMillis - previousMillis > FLICKER_INTERVAL)
    {
      previousMillis = currentMillis;
      analogWrite(CANDLELED, random(30, 100)); // testing different values for now. need to change this when I actually have the right leds for my usage.
    }
  }
}
