const int ldrPin = A0; // select the input pin for LDR
int ldrValue = 0; // variable to store the value coming from the sensor
const int lmpin=A1; // Assigning analog pin A1 to variable 'sensor'
const int ventPin1 = A2;
const int lightPin1=A3;
const int ventPin2 = A4;
const int lightPin2=A5;
const int trigPini = 7;
const int echoPini= 8;
const int trigPino= 12;
const int echoPino= 13;
const int doorPin = 4;
int count=0;
char choice;
long durationi, durationo;
int distancei, distanceo;
float tempc; //variable to store temperature in degree Celsius
float vout; //temporary variable to hold sensor reading
void setup()
{
pinMode(trigPini, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPini, INPUT); // Sets the echoPin as an Input
pinMode(trigPino, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPino, INPUT); // Sets the echoPin as an Input
pinMode(lmpin,INPUT); // lm35 kdun input (a1)
pinMode (ldrPin, INPUT); //ldr kdun input(a0)
pinMode (ventPin1, OUTPUT); // lm35 mule alela output
pinMode(lightPin1, OUTPUT); //ldr mule alela output
pinMode (ventPin2, OUTPUT); // lm35 mule alela output
pinMode(lightPin2, OUTPUT); //ldr mule alela output
pinMode(doorPin, OUTPUT);
Serial.begin(9600);
}
void loop()
{
vout=analogRead(lmpin);
Serial.println(vout);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
Serial.print("in Degree C:\t");
Serial.println(tempc);
ldrValue = analogRead(ldrPin); // read the value from the sensor
Serial.print("Resistance due to light:\t");
Serial.println(ldrValue); //prints the values coming from the sensor on the screen //uno madhe jashi light vadhel tsa
tyacha resistance chi value vadhte
//operations with ultrasonic sensors
digitalWrite(trigPini, LOW);
delayMicroseconds(2);
digitalWrite(trigPini, HIGH);
delayMicroseconds(10);
digitalWrite(trigPini, LOW);
durationi= pulseIn(echoPini, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
distancei= durationi*0.034/2; // Calculating the distance
digitalWrite(trigPino, LOW);
delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPino, HIGH);
delayMicroseconds(10);
digitalWrite(trigPino, LOW);
durationo= pulseIn(echoPino, HIGH);
distanceo= durationo*0.034/2;
Serial.print("Distance Incoming: "); // Prints the distance on the Serial Monitor
Serial.println(distancei);
Serial.print("Distance Outgoing: "); // Prints the distance on the Serial Monitor
Serial.println(distanceo);
if (distancei<=2000 && distanceo<=2000) {digitalWrite(doorPin, LOW); delay(2000); }
if (distancei>=2000 && distanceo<=2000) {count = count+1; digitalWrite(doorPin, HIGH); delay(2000);}
if (distancei<=2000 && distanceo>=2000) {count = count-1; digitalWrite(doorPin, HIGH); delay(2000);}
if (distancei>=2000 && distanceo>=2000) {digitalWrite(doorPin, HIGH); delay(2000); }
Serial.print("Count:\t");
Serial.println(count);
if (count < 0 ) { count = 0; }
else if (count == 0) {choice ='a';}
else if (count > 0 && count <=20 && ldrValue<=50 && tempc>=20.00) {choice = 'b';}
else if (count > 0 && count <=20 && ldrValue>=50 && tempc>=20.00){choice='c';}
else if (count > 0 && count <=20 && ldrValue<=50 && tempc<=20.00) {choice = 'd';}
else if (count > 0 && count <=20 && ldrValue>=50 && tempc<=20.00) {choice = 'e';}
else if (count > 20 && ldrValue<=50 && tempc>=20.00) {choice = 'f';}
else if (count > 20 && ldrValue>=50 && tempc>=20.00){choice='g';}
else if (count > 20 && ldrValue<=50 && tempc<=20.00) {choice = 'h';}
else if (count > 20 && ldrValue>=50 && tempc<=20.00) {choice = 'i';}
else {choice='j';}
switch (choice)
{
case 'a': digitalWrite(lightPin1, LOW); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, LOW);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'b': digitalWrite(lightPin1, HIGH); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'c': digitalWrite(lightPin1, LOW); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'd': digitalWrite(lightPin1, HIGH); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, LOW);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'e': digitalWrite(lightPin1, LOW); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'f': digitalWrite(lightPin1, HIGH); digitalWrite(lightPin2, HIGH); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, HIGH); delay(2000); break;
case 'g': digitalWrite(lightPin1, LOW); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, HIGH); delay(2000); break;
case 'h': digitalWrite(lightPin1, HIGH); digitalWrite(lightPin2, HIGH); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'i': digitalWrite(lightPin1, HIGH); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, HIGH);
digitalWrite(ventPin2, LOW); delay(2000); break;
case 'j': digitalWrite(lightPin1, LOW); digitalWrite(lightPin2, LOW); digitalWrite(ventPin1, LOW);
digitalWrite(ventPin2, LOW); delay(2000); break;
default : break;
}
}
