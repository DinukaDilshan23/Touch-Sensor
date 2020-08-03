const int sensorPin = 7;
const int lightPin = 3;
unsigned long startTime01, startTime02;
unsigned long endTime01, endTime02;
unsigned long timeLap01, timeLap02;
int count = 0;
boolean lastState = LOW;
boolean currentState;

void setup() {
Serial.begin(9600);
pinMode(sensorPin, INPUT);
pinMode(lightPin, LOW);
}

void loop() {
if (count > 2) {
  count = 0;
}
currentState = digitalRead(sensorPin);
if (lastState == LOW && currentState == HIGH) {
  count++;
  startTime01 = millis();
  Serial.println(startTime01);
  startTime02 = millis();
  if (count == 1) {
    endTime01 = millis();
    Serial.println(endTime01);
    timeLap01 = endTime01 - startTime01;
    if (timeLap01 < 500) {
    Serial.println("Single Touch");
    }
    else {
      Serial.println("Long Touch");
    }
  }
  else if (count == 2) {
    endTime02 = millis();
    timeLap02 = endTime02 - startTime02;
    if (timeLap02 < 500) {
      Serial.println("Double Touch");
  }
}
}
//else if (lastState == HIGH && currentState == HIGH) {
 // digitalWrite (lightPin, HIGH);
//}
//else {
//digitalWrite (lightPin, LOW);
//}
lastState = currentState;

}
