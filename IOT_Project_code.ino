#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7

long duration, distance, Sensor1,Sensor2,Sensor3;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
Sensor1 = duration;

SonarSensor(trigPin2, echoPin2);
Sensor2 = duration;

SonarSensor(trigPin3, echoPin3);
Sensor3 = duration;

Serial.print(Sensor1);
Serial.print(",");
Serial.print(Sensor2);
Serial.print(",");
Serial.println(Sensor3);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delay(5);
digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

delay(1000);
}
