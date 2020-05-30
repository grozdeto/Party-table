const int trigPin = 9;
const int echoPin = 10;
const int pompPin = 7;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pompPin, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)*0.0343;

  Serial.print("Distance: ");
  if(distance >= 5 || distance <= 1) {
    Serial.print("Out of range");
    delay(500);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(7, LOW);
    delay(10000);
    Serial.println("nalq se");
    digitalWrite(7, HIGH);
    delay(10000);
  }
  delay(500);
}
