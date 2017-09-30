#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#define RELAY 12
#define RELAY2 11
int pinValue2 = 0;
int pinValue1 = 0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e493a9880ae34ba28e49d7b609a318f2";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "fenyx.io";
char pass[] = "12345fenyX";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

char previousButton0 = 0;

void setup()
{
  // Set console baud rate
  Serial.begin(9600);
  delay(10);
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  pinMode(RELAY,OUTPUT);
  pinMode(RELAY2,OUTPUT);
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();

}

BLYNK_WRITE(V0)
{
  int pinValue1 = param.asInt();
  digitalWrite(12, !pinValue1);
}

BLYNK_WRITE(V1)
{
  pinValue2 = param.asInt();
  digitalWrite(11, !pinValue2);
}

