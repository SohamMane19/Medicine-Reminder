#define BLYNK_TEMPLATE_ID "TMPL3S1IjJOFJ"
#define BLYNK_TEMPLATE_NAME "mobilenotify"
#define BLYNK_AUTH_TOKEN "UF-Croi0CFGeCZuSUhBCefKov0g11AiL"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[]=BLYNK_AUTH_TOKEN;  // Replace with your Blynk authentication token

const int ldrPin = A0;
const int led = D1;
int threshold = 100;

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth,"Soham","iambatman");  // Replace with your WiFi credentials
  pinMode(ldrPin,INPUT);
  pinMode(led,OUTPUT);
}
void sendNotification(const char* message)
{
    Blynk.virtualWrite(V1, message);  // Assuming you have a Notification widget on V1
}
void loop() {
  Blynk.run();
  int rawData = analogRead(ldrPin);
  Serial.println(rawData);
  if(rawData < threshold)
  {
    digitalWrite(led,HIGH);
    // Blynk.notify("Take your medicine!");
    sendNotification("Hello from Arduino!"); 
  }
   
  else
  {
    digitalWrite(led, LOW);
  }  
  delay(100);
}
