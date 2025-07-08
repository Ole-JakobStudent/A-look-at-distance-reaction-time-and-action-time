/*
 * Baserd of the work by;
 * HC-SR04 example sketch
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 * by Isaac100
 * 
 * Further Development by Ole-Jakob S.
 */

const int trigPin = 12;
const int echoPin = 13;

float duration, distance;

void setup() {
    pinMode(trigPin, OUTPUT);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  //Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
