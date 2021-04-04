// defines pins numbers
const int trig_Pin = 9;
const int echo_Pin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trig_Pin, OUTPUT); // Sets the trig_Pin as an Output
pinMode(echo_Pin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trig_Pin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig_Pin, HIGH);
delayMicroseconds(10);
digitalWrite(trig_Pin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo_Pin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  Serial.println("Movement");
  delay (4000);
  digitalWrite(buzzer, LOW);
  delay (5000);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}


}
