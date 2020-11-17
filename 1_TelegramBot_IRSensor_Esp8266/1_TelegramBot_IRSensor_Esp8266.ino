/* created by Joydip Dutta, http://cybotians.com
 Organization: CYBOTIANS
    IR sensor Pins:
        VCC: +3.3vVDC
        Out : Pin D7 or GPIO 13
        GND: GND
 */
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "XXXXXXX";
const char* password = "XXXXXXXXX";

int inputPin = 13; //D7 choose input pin (for Infrared sensor) 
int val = 0;

// Initialize Telegram BOT
#define BOTtoken "XXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXX"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "XXXXXXXX"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);



bool ledState = HIGH;

void setup() {
  Serial.begin(115200);
  client.setInsecure();

 pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(inputPin, INPUT);
  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void loop() {
  
     val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { 
        bot.sendMessage(CHAT_ID, "Motion detected!!", "");  //Sending response to the telegram bot
        Serial.println("Motion Detected");
        
   } 
   
}
