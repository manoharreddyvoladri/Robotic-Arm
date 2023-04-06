// moving the Arm with the the recording colour frequency

#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int posStartServo1 = 0;
int posEndServo1 = 150;
int posStartServo2 = 45;
int posEndServo2 = 140;
int posStartServo3 = 0;
char c=" ";
#define S0 7
#define S1 6
#define S2 4
#define S3 5
#define sensorOut 3
int redFrequency =0;
int blueFrequency =0;
int greenFrequency =0;
bool colorFind = false;
void setup() {
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  moveservostart();
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);
}
void loop() {
  getfrequency();
  delay(100);
  if(!colorFind){
    checkColor();
  }
  else{
    checkColor();
    if(c=='r'){
      moveblock();
    }
    else if(c=='g'){
      moveblockg();
    }
  }
  
}
void moveservostart(){
  servo1.write(0);
  servo2.write(45);
  servo3.write(0);
  servo4.write(110);
}
void moveblock(){
  setServoPosition(servo1, posStartServo1, posEndServo1);
  setServoPosition(servo2, posStartServo2, posEndServo2);
  setServoPosition(servo4,110,50);  
  setServoPosition(servo2, posEndServo2, posStartServo2);
  setServoPosition(servo1, posEndServo1, posStartServo1);
  delay(2000);
  setServoPosition(servo4,50,110);
  moveservostart();
}
void setServoPosition(Servo servo, int startPosition, int endPosition) {
  if (startPosition > endPosition) {
    for (int i = startPosition; i >= endPosition; i--) {
      servo.write(i);
      delay(30);
    }
  } else {
    for (int i = startPosition; i <= endPosition; i++) {
      servo.write(i);
      delay(30);
    }
  }
}
void getfrequency(){
// Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(500);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(500);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  delay(500);  
}
void checkColor(){
  moveservostart();
  delay(1000);
  if ((redFrequency <= 54  && redFrequency >= 51 )
      && (greenFrequency <= 58 && greenFrequency >= 54)
      && (blueFrequency <= 42 && blueFrequency >= 40)) {
    Serial.println("Red");
    colorFind=true;
    c='r';
  } else if ((redFrequency <= 56 && redFrequency >= 53)
      && (greenFrequency <= 47 && greenFrequency >= 45)
      && (blueFrequency <= 40 && blueFrequency >= 38)) {
    Serial.println("Green");
    colorFind=true;
    c='g';
  } 
  /*else if ((redFrequency <= 24 && redFrequency >= 22)
      && (greenFrequency <= 10 && greenFrequency >= 8)
      && (blueFrequency <=24 && blueFrequency >= 22)) {
    Serial.println("yellow");
    colorFind=true;
  }*/
}
void moveblockg(){
  setServoPosition(servo1, posStartServo1, posEndServo1);
  setServoPosition(servo2, posStartServo2, posEndServo2);
  setServoPosition(servo4,110,50);
  setServoPosition(servo2, posEndServo2, posStartServo2);
  setServoPosition(servo1, posEndServo1, 90);
  delay(2000);
  setServoPosition(servo4,50,110);
  servo4.write(0);
  moveservostart();
}
