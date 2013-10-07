/*
   Basic MQTT example

   - connects to an MQTT server
   - publishes "hello world" to the topic "outTopic"
   - subscribes to the topic "inTopic"
   */

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
byte server[] = { 192, 168, 69, 96 }; //Broker IP
byte ip[]     = { 192, 168, 69, 49 }; //Arduino IP
int led_green = 9;
int led_red   = 6;
int capteur   = A4;
int v         = 0;
boolean light = false;
int thresold  = 100;


void callback(char* topic, byte* payload, unsigned int length) {
    // handle message arrived
    Serial.write(topic[4]);
    Serial.write(payload, length);
    int bright;
    if(payload[0] == char('l')){
        bright = 0;
    }
    if(payload[0] == char('m')){
        bright = 128;
    }
    if(payload[0] == char('h')){
        bright = 255;
    }
    Serial.write(bright);
    if(topic[4] == 'r') {
        analogWrite(led_red, bright);
    }
    if(topic[4] == 'g') {
        analogWrite(led_green, bright);
    }
}

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

void setup() {
    Serial.begin(19200);
    pinMode(led_red, OUTPUT);
    pinMode(led_green, OUTPUT);
    pinMode(capteur, INPUT);
    Ethernet.begin(mac, ip);
    if (client.connect("arduinoClient")) {
        client.publish("hello","from Arduino");
        client.subscribe("led/#");
    }
}

void loop() {
    int v = analogRead(capteur);
    Serial.println(v);
    if( v < thresold && ! light) {
        light = true;
        client.publish("light", "on");
    }
    if( v > thresold && light) {
        light=false;
        client.publish("light", "off");
    }
    delay(1);
    client.loop();
}
