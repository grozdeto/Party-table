const int trigPin1 = 11;
const int echoPin1 = 12;
const int trigPin2 = 13;
const int echoPin2 = 22;
const int trigPin3 = 23;
const int echoPin3 = 24;
const int trigPin4 = 25;
const int echoPin4 = 26   ;

const int pompPin1 = 7;
const int pompPin2 = 8; 
const int pompPin3 = 9; 
const int pompPin4 = 10;

float duration1, distance1, duration2, distance2, duration3, distance3, duration4, distance4;
bool pomp1 = true, pomp2 = true, pomp3 = true, pomp4 = true;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  
  pinMode(pompPin1, OUTPUT);
  pinMode(pompPin2, OUTPUT);
  pinMode(pompPin3, OUTPUT);
  pinMode(pompPin4, OUTPUT);
  
  digitalWrite(pompPin1, HIGH);
  digitalWrite(pompPin2, HIGH);
  digitalWrite(pompPin3, HIGH); 
  digitalWrite(pompPin4, HIGH); 

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(trigPin1, HIGH);
  
  delayMicroseconds(10);
  
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH);
  
  distance1 = (duration1/2)*0.0343;
  
  digitalWrite(trigPin2, LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(trigPin2, HIGH);
  
  delayMicroseconds(10);
  
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2, HIGH);
  
  distance2 = (duration2/2)*0.0343;
  
  digitalWrite(trigPin3, LOW);

  delayMicroseconds(2);
  
  digitalWrite(trigPin3, HIGH);

  delayMicroseconds(10);
  
  digitalWrite(trigPin3, LOW);  
  
  duration3 = pulseIn(echoPin3, HIGH);

  distance3 = (duration3/2)*0.0343;
  
  digitalWrite(trigPin4, LOW);

  delayMicroseconds(2);
  
  digitalWrite(trigPin4, HIGH);

  delayMicroseconds(10);
  
  digitalWrite(trigPin4, LOW);
  
  duration4 = pulseIn(echoPin4, HIGH);
  
  distance4 = (duration4/2)*0.0343;
  Serial.print("Distance2: ");
//if(distance2 >= 400 || distance2 <= 1) {
    Serial.println(distance2);
    Serial.println(distance3);
    Serial.println(distance4);
//  } else {
    //Serial.print(distance2);
    //Serial.println(" cm");
    //pomp2 = false;
  //} 
  Serial.print("Distance1: ");
  if(distance1 >= 5 || distance1 <= 1) {
    Serial.print("Out of range");
  } else {
    Serial.print(distance1);
    Serial.println(" cm");
    pomp1 = false;
  }  

  delay(500);

  Serial.print("Distance2: ");
  if(distance2 >= 400 || distance2 <= 1) {
    Serial.print("Out of range");
  } else {
    Serial.print(distance2);
    Serial.println(" cm");
    pomp2 = false;
  } 

  delay(500);

  Serial.print("Distance3: ");
  if(distance3 >= 5 || distance3 <= 1) {
    Serial.print("Out of range");
  } else {
    Serial.print(distance3);
    Serial.println(" cm");
    pomp3 = false;
  } 

  delay(500);

  Serial.print("Distance4: ");
  if(distance4 >= 5 || distance4 <= 1) {
    Serial.print("Out of range");
  } else {
    Serial.print(distance4);
    Serial.println(" cm");
    pomp4 = false;
  } 

  delay(500);
  
  digitalWrite(pompPin1, pomp1);
  digitalWrite(pompPin2, pomp2);
  digitalWrite(pompPin3, pomp3);
  digitalWrite(pompPin4, pomp4);
  delay(10000);
  Serial.println("nalq se");
  digitalWrite(pompPin1, HIGH);
  digitalWrite(pompPin2, HIGH);
  digitalWrite(pompPin3, HIGH);
  digitalWrite(pompPin4, HIGH);
  pomp1 = true, pomp2 = true, pomp3 = true, pomp4 = true;
}
/*
void start_pomp() {
    
    digitalWrite(pompPin1, pomp1);
    digitalWrite(pompPin2, pomp2);
    digitalWrite(pompPin3, pomp3);
    digitalWrite(pompPin4, pomp4);
    delay(10000);
    Serial.println("nalq se");
    digitalWrite(pompPin1, HIGH);
    digitalWrite(pompPin2, HIGH);
    digitalWrite(pompPin3, HIGH);
    digitalWrite(pompPin4, HIGH);
}*/
