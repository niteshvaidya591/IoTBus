

#include<SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); //TX,RX


#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9
#define SS_PIN    10

MFRC522 mfrc522(SS_PIN, RST_PIN);
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}

MFRC522::MIFARE_Key key;

const int trigPin = 4;
const int echoPin = 5;
const int trigPin2 = 7;
const int echoPin2 = 8;
long duration;
int distance;
long duration2;
int distance2;
int count = 0;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  bluetooth.begin(9600);
  Serial.begin(9600);

  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}



void loop() {




  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
 Serial.print("Distance  : ");
 Serial.println(distance);
// Serial.print("                                   ");
 /////////////////////

 digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
 Serial.print("Distance2  : ");
 Serial.println(distance2);
 //////////////////////////
  //if (distance >= 10 && distance <= 50 )
    if (distance <=5 )
  {
    count++;
    Serial.println(count);
    bluetooth.println(count);
    delay(100);
  }
// if (distance2 >= 10 && distance2 <= 50 )
  if (distance2 <=5 )
  {
    count--;
    Serial.println(count);
    bluetooth.println(count);
    delay(100);
  }
  delay(1000);
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    bluetooth.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  delay(2000);
}
