                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              #define REDPIN A3
#define GREENPIN A4
#define BLUEPIN A5
#define MAX_COLORS 10 
#define INVALID_COLOR -1 
#define INVALID_PIN -1 


const int trigPin1 = 11;
const int echoPin1 = 12;
const int trigPin2 = 13;
const int echoPin2 = 22;
const int trigPin3 = 23;
const int echoPin3 = 24;
const int trigPin4 = 25;
const int echoPin4 = 26;
int buttonStart = 27;
int buttonPin1 = 2; 
int buttonPin2 = 3;
int buttonPin3 = 4;
int buttonPin4 = 5; 

int pompPin1 = 7;
int pompPin2 = 8; 
int pompPin3 = 9; 
int pompPin4 = 10;

int currentButton1State = digitalRead(buttonPin1);
int currentButton2State = digitalRead(buttonPin2);
int currentButton3State = digitalRead(buttonPin3);
int currentButton4State = digitalRead(buttonPin4); 

int lastButton1State = currentButton1State;
int lastButton2State = currentButton2State;
int lastButton3State = currentButton3State; 
int lastButton4State = currentButton4State;
int start = 0;
int level = 3; 
int colors[MAX_COLORS]; 
int colorPins[] = {A3,A4,A5};
int randomChange = 0;
int gameState = 0;
bool gameEnd = false;
bool bug = false; 
int ledState = HIGH;
unsigned long prevMillis = 0;
unsigned long currentMillis = 0;
float duration1, distance1, duration2, distance2, duration3, distance3, duration4, distance4;
bool pomp1 = true, pomp2 = true, pomp3 = true, pomp4 = true;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(19200);
  resetGame();

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  pinMode(buttonStart, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  
  pinMode(pompPin1, OUTPUT);
  pinMode(pompPin2, OUTPUT);
  pinMode(pompPin3, OUTPUT);
  pinMode(pompPin4, OUTPUT);
  
  digitalWrite(pompPin1, HIGH);
  digitalWrite(pompPin2, HIGH);
  digitalWrite(pompPin3, HIGH); 
  digitalWrite(pompPin4, HIGH); 

  analogWrite(BLUEPIN, 0);
}

void loop() {
  Serial.print("start = ");
  Serial.println(start);
  start = digitalRead(buttonStart);
  Serial.print("start = ");
  Serial.println(start);
  if(start == HIGH) {

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

    Serial.print("Distance1: ");
    Serial.println(distance1);
    Serial.print("Distance2: ");
    Serial.println(distance2);
    Serial.print("Distance3: ");
    Serial.println(distance3);
    Serial.print("Distance4: ");
    Serial.println(distance4);

    Serial.print("Distance1: ");
    if(distance1 >= 15 || distance1 <= 1) {
      Serial.println("Out of range");
    } else {
      Serial.print(distance1);
      Serial.println(" cm");
      pomp1 = false;
    }  

    delay(500);

    Serial.print("Distance2: ");
    if(distance2 >= 15 || distance2 <= 1) {
      Serial.println("Out of range");
    } else {
      Serial.print(distance2);
      Serial.println(" cm");
      pomp2 = false;
    } 

    delay(500);

    Serial.print("Distance3: ");
    if(distance3 >= 15 || distance3 <= 1) {
      Serial.println("Out of range");
    } else {
      Serial.print(distance3);
      Serial.println(" cm");
      pomp3 = false;
    } 

    delay(500);

    Serial.print("Distance4: ");
    if(distance4 >= 15 || distance4 <= 1) {
      Serial.println("Out of range");
    } else {
      Serial.print(distance4);
      Serial.println(" cm");
      pomp4 = false;
    } 

    delay(500);
    
    addColors(); 
    displayColors(); 
    level++;
    pomp1 = true, pomp2 = true, pomp3 = true, pomp4 = true;
  } 
} 
void resetGame() { 
//delay(20000);
  level = 3;
  for(int j=0;j<MAX_COLORS;j++) colors[j] = INVALID_COLOR; 
    gameState = 0;
    gameEnd = false;
}
void addColors() {
  int randomChange = 0;
  for(int i=0;i<level;i++) { 
    if(i>3 && i != level) { 
      randomChange = random(1,100);
    } 
    if(randomChange > 0 && randomChange < 20) { 
      if(colors[i] == 2) {
        colors[i]--; 
      } else {
        colors[i]++;
      }
      bug = true; 
    } 
    if(colors[i] == INVALID_COLOR){ 
      colors[i] = random(0,3); 
    } 
  } 
} 
void displayColors(){ 
  int analogColorPin = 0; 
  for(int i = 0; i < level; i++) { 
    analogColorPin = colorPins[colors[i]];
    int res = 0; 
    analogWrite(analogColorPin, 255);
    res = checkButtonState(); 
    analogWrite(analogColorPin, 0); 
    if(res != INVALID_PIN) { 
      readPlayers(res); 
      return; 
    } 
    res = checkButtonState();
    if(res != INVALID_PIN) { 
      readPlayers(res);
      return;
    } 
  }
  delay(1000); 
  bug = false;
}
 
int checkButtonState() { 
  prevMillis = millis();
  currentMillis = millis(); 
  while(currentMillis - prevMillis < 500) { 
    currentMillis = millis();
    currentButton1State = digitalRead(buttonPin1); 
    currentButton2State = digitalRead(buttonPin2); 
    currentButton3State = digitalRead(buttonPin3); 
    currentButton4State = digitalRead(buttonPin4); 
    if(currentButton1State != lastButton1State) {
      return buttonPin1;
    }
   
    if(currentButton2State != lastButton2State) {
      return buttonPin2;
    }
   
    if(currentButton3State != lastButton3State) { 
      return buttonPin3;
    }
   
    if(currentButton4State != lastButton4State) { 
      return buttonPin4;
    } 
    delay(10); 
  } 
  return INVALID_PIN; 
} 
void readPlayers(int res) {
 //prevMillis = millis();
 //currentMillis = millis();
 //while(currentMillis - prevMillis < 3000) { 
//currentMillis = millis(); 
  currentButton1State = digitalRead(buttonPin1); 
  currentButton2State = digitalRead(buttonPin2); 
  currentButton3State = digitalRead(buttonPin3); 
  currentButton4State = digitalRead(buttonPin4); 
  if(res == buttonPin1) {
    if(bug){ 
      Serial.print("checkButtonState");
      digitalWrite(pompPin2, pomp2);
      digitalWrite(pompPin3, pomp3); 
      digitalWrite(pompPin4, pomp4); 
      delay(5000); 
      digitalWrite(pompPin2, HIGH); 
      digitalWrite(pompPin3, HIGH); 
      digitalWrite(pompPin4, HIGH); 
     } else { 
       Serial.print("NO");
       digitalWrite(pompPin1, pomp1); 
       delay(5000); 
       digitalWrite(pompPin1, HIGH); 
     } 
     resetGame(); 
     lastButton1State = currentButton1State; 
     lastButton2State = currentButton2State; 
     lastButton3State = currentButton3State;   
     lastButton4State = currentButton4State; 
     delay(20000); 
     return; 
  } 
  if(res == buttonPin2) {
    if(bug){ 
      Serial.print("checkButtonState"); 
      digitalWrite(pompPin1, pomp1); 
      digitalWrite(pompPin3, pomp3); 
      digitalWrite(pompPin4, pomp4); 
      delay(5000); 
      digitalWrite(pompPin1, HIGH); 
      digitalWrite(pompPin3, HIGH); 
      digitalWrite(pompPin4, HIGH); 
    } else { 
      Serial.print("NO"); 
      digitalWrite(pompPin2, pomp2); 
      delay(5000); 
      digitalWrite(pompPin2, HIGH); 
    } 
    resetGame(); 
    lastButton1State = currentButton1State; 
    lastButton2State = currentButton2State; 
    lastButton3State = currentButton3State; 
    lastButton4State = currentButton4State; 
    delay(20000); 
    return;
  } 
  if(res == buttonPin3){ 
    if(bug){ 
     Serial.print("checkButtonState");
     digitalWrite(pompPin1, pomp1); 
     digitalWrite(pompPin2, pomp2); 
     digitalWrite(pompPin4, pomp4); 
     delay(5000); 
     digitalWrite(pompPin1, HIGH); 
     digitalWrite(pompPin2, HIGH); 
     digitalWrite(pompPin4, HIGH); 
    } else { 
      Serial.print("NO"); 
      digitalWrite(pompPin3, pomp3); 
      delay(5000); 
      digitalWrite(pompPin3, HIGH); 
    } 
    resetGame();
    lastButton1State = currentButton1State; 
    lastButton2State = currentButton2State; 
    lastButton3State = currentButton3State; 
    lastButton4State = currentButton4State; 
    delay(20000); 
    return; 
  } 
  if(res == buttonPin4){ 
    if(bug){ 
      Serial.print("checkButtonState"); 
      digitalWrite(pompPin1, pomp1); 
      digitalWrite(pompPin2, pomp2); 
      digitalWrite(pompPin3, pomp3); 
      delay(5000); 
      digitalWrite(pompPin1, HIGH); 
      digitalWrite(pompPin2, HIGH); 
      digitalWrite(pompPin3, HIGH); 
    } else { 
      Serial.print("NO"); 
      digitalWrite(pompPin4, pomp4); 
      delay(20000); 
      digitalWrite(pompPin4, HIGH); 
    } 
    resetGame(); 
    lastButton1State = currentButton1State; 
    lastButton2State = currentButton2State; 
    lastButton3State = currentButton3State; 
    lastButton4State = currentButton4State; 
    delay(20000);
    return; 
  }
}    
