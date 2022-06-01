#include <BluetoothSerial.h>
#define  trig  13
#define  echo  12
#define  buzzer 15

float duration;
float distance;
int level;

BluetoothSerial SerialBT;

void setup() {

  Serial.begin(115200);

  SerialBT.begin();

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  ledcSetup(0,1E5,12);
  ledcAttachPin(buzzer,0);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  level = distance * -7.0422 + 122.00;



 if (level > 100) {level = 100;ledcWriteTone(0,1000);} else if (level < 0) {level = 0;}
  SerialBT.write(level);
  Serial.print("level = ");
  Serial.println(level);
  delay(100);
  ledcWriteTone(0,0);
  
  
  }
