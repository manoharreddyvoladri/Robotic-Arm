#include <Servo.h>
Servo myservo1,myservo2,myservo3,myservo4;
int xpin=A0;
int ypin=A1;
int spin=A2;
int y2pin=A3;
int dt=250;
int i=0;
int j=0;
int k=0;
int l=0;
String name;
void setup(){
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT); 
  pinMode(spin,INPUT);
  pinMode(y2pin,INPUT);
  Serial.begin(9600);
  digitalWrite(spin,HIGH);
  myservo1.attach(3);
  myservo2.attach(4);
  myservo3.attach(5);
  myservo4.attach(6);
  myservo1.write(i);
  myservo2.write(j);
  myservo3.write(k);
  myservo4.write(l);
}
void loop(){
   int xval=analogRead(xpin);
  int yval=analogRead(ypin);
  int sval=analogRead(spin);
  int y2val=analogRead(y2pin);
  if(name=="T0" || name[0]=="T" ||yval>600 ){
    Serial.println("true");
    j=j+5;
  }
  if(name=="B0"|| name[0]=="B"||yval<400){
    j=j-5;
  }
  if(name=="R0"|| name[0]=="R"|| xval>600){
    i=i+5;
  }
  if(name=="L0"|| name[0]=="L"|| xval<400){
    i=i-5;
  }
  if(name=="1o"|| name[0]=="1"|| sval>600){
    k=k+5;
  }
  if(name=="2o"|| name[0]=="2"||sval<400){
    k=k-5;
  }
  if(y2val>600){
    l=l+10;
  }
  if(y2val<400){
    l=l-10;
  }
  if(i>180){
    i=180;
  }
  if(i<0){
    i=0;
  }
  if(j>180){
    j=180;
  }
  if(j<0){
    j=0;
  }
  if(k>180){
    k=180;
  }
  if(k<0){
    k=0;
  }
  if(l>180){
    l=180;
  }
  if(l<0){
    l=0;
  }
  Serial.println(name);
  myservo1.write(i);
  myservo2.write(j);
  myservo3.write(k);
  myservo4.write(l);
  Serial.print("k==");
  Serial.println(k);
  Serial.print("i==");
  Serial.println(i);
  Serial.print("j==");
  Serial.println(j);
  
}
