#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include  <Wire.h>
SoftwareSerial mySerial(2, 0);
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#define WLAN_SSID       "JioFi_1034DF3"
#define WLAN_PASS       "Aniket@22"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "renuka3"
#define AIO_KEY         "a86093b5f56b4fb3a6919c962a688848"
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish photocell = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/finger");
const byte buttonPin=14;
const byte buttonPin1=12;
const byte buttonPin2=13;

const char* host = "192.168.15.26";
const byte buttonPin3=10;
boolean a=true;

boolean b=true;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
uint8_t id;
int count=0;
int enter=0;
int z=0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void MQTT_connect();

 
void setup()  
{
  Serial.begin(9600);
  while (!Serial);  // 
  delay(100);   
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
    lcd.clear();
    Serial.println("Found fingerprint sensor!");
    lcd.setCursor(0,0);
    lcd.print("Booting");
     lcd.setCursor(0,1);
    lcd.print("Sensor");
    delay(2000);
    
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    lcd.clear();
lcd.setCursor(0,0);
    lcd.print("DID NOT FIND SENSOR");
     lcd.setCursor(0,1);
    lcd.print("##################");
    while (1) { delay(1); }
  }
    finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");

  pinMode(buttonPin,INPUT); 
  pinMode(buttonPin1,INPUT_PULLUP); 
   pinMode(buttonPin2,INPUT_PULLUP); 
  pinMode(buttonPin3,INPUT_PULLUP);

 
 {
  Serial.begin(9600);
  


  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    
 {
  lcd.clear();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("connecting to");
  lcd.setCursor(0,1);
  lcd.print("WiFi");
  
  
 }
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Wifi Connected");
   lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  delay(4000);
  

}
uint32_t x=0;

 {
  lcd.clear();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Connecting to");
  lcd.setCursor(0,1);
  lcd.print("Server");

  delay(2000);

 
  
 



  
}

  
}

uint8_t readnumber(void) {
  uint8_t num = 0;
  
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connecting to");
  lcd.setCursor(0,1);
  lcd.print("Server");
  

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connected  to");
  lcd.setCursor(0,1);
  lcd.print("Server");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BIOMETRIC");
  lcd.setCursor(0,1);
  lcd.print("ATTENDANCE");
  delay(5000);
  
}


void loop()   //run over and over again
{
 int reading=digitalRead(buttonPin); 
 int reading1=digitalRead(buttonPin1);
 int reading2=digitalRead(buttonPin2);
  int reading3=digitalRead(buttonPin3);
  

 
Serial.println("SELECT YOUR SUBJECT");
lcd.setCursor(0,0);
                                          lcd.clear();
                                          lcd.print("SELECT YOUR ");
                                          lcd.setCursor(0,1);
                                          lcd.print("SUBJECT");



while(reading2==LOW){
  enroll();
  delay(10);
  }

  if(reading1==LOW){
    delay(2000);
    while(enter==0)
    
          { 
              int reading=digitalRead(buttonPin); 
              int reading1=digitalRead(buttonPin1);
              int reading2=digitalRead(buttonPin2);
              int reading3=digitalRead(buttonPin3);
              Serial.println("SATELLITE COMMUNICATION");
              lcd.setCursor(0,0);
                                          lcd.clear();
                                          lcd.print("SATELLITE ");
                                          lcd.setCursor(0,1);
                                          lcd.print("COMMUNICATION");
              
              
                while(reading3==LOW){
                                          
                                         MQTT_connect();
                                          lcd.clear();
  
                                          lcd.setCursor(0,0);
                                          lcd.print("Place Your ");
                                          lcd.setCursor(0,1);
                                          lcd.print("Finger");
      
                                          getfinger();
     
                                          b==false;
                                          delay(10);
                                  }
            while(reading1==LOW){
              int reading=digitalRead(buttonPin); 
              int reading1=digitalRead(buttonPin1);
              int reading2=digitalRead(buttonPin2);
              int reading3=digitalRead(buttonPin3);
              Serial.println("WIRELESS COMMUNICATION");
              lcd.setCursor(0,0);
                                          lcd.clear();
                                          lcd.print("WIRELESS ");
                                          lcd.setCursor(0,1);
                                          lcd.print("NETWORK");
                               while(reading3==LOW){
                                          
                                         MQTT_connect();
                                          lcd.clear();
  
                                          lcd.setCursor(0,0);
                                          lcd.print("Place Your ");
                                          lcd.setCursor(0,1);
                                          lcd.print("Finger");
      
                                          getfinger2();
     
                                          b==false;
                                          delay(10);
                                  }

                                  delay(10);
                     
              while(reading2==LOW)
              {

                int reading=digitalRead(buttonPin); 
              int reading1=digitalRead(buttonPin1);
              int reading2=digitalRead(buttonPin2);
              int reading3=digitalRead(buttonPin3);
                loop();
                delay(10);
                
                }
              
              
              
              }
            delay(10);
            int enter=1;
          }

}
}




void enroll()                     
{
  
  
    int reading1=digitalRead(buttonPin1);
    int reading2=digitalRead(buttonPin2);
    int reading3=digitalRead(buttonPin3);

  
  if(a==true)
  {
   
  lcd.clear();
  Serial.println("Ready to enroll a fingerprint!");

  Serial.println("Please type in the ID # (from 1 to 1000) you want to save this finger as...");
   lcd.setCursor(0,0);
  lcd.print("Ready to Enroll");
  lcd.setCursor(0,1);
  lcd.print("INPUT ID #");
  }
  a=false;
  
  if (reading1==LOW)
      {
        
        count++;
        delay(100);
      Serial.println(count);
      lcd.clear();
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("ID");
  lcd.setCursor(0,1);
  lcd.print(             count);
 
      }
    if (reading2==LOW)
      {
        
        count--;
        delay(100);
      Serial.println(count);
          lcd.clear();
lcd.setCursor(0,0);
  lcd.print("ID");
  lcd.setCursor(0,1);
  lcd.print(             count);
      }
  
  
if(reading3==LOW)
          {
        id=count;
        lcd.clear();
        Serial.print("Enrolling ID #");
        
        Serial.println(id);
        lcd.setCursor(0,0);
  lcd.print("Enrolling ID  #");
  lcd.setCursor(0,1);
  lcd.print(id);
  delay(2000);
        
  
        while (!  getFingerprintEnroll() );
      }
  
  
   
 
}
void getfinger2()                     // for second finger
{
 
  getFingerprintIDez2();
   
  } 


void getfinger()                     // for second finger
{
 
  getFingerprintIDez();
   
  }            




uint8_t getFingerprintEnroll() {

  int p = -1;
  Serial.print("Waiting for valid finger to enroll as #"); 
  Serial.println(id);
  lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("ENROLLING");
  lcd.setCursor(0,1);
  lcd.print(id);
  delay(2000);
  
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      Serial.println("Image taken");
      lcd.print("Image taken");
      delay(1000);
      break;
    case FINGERPRINT_NOFINGER:
    lcd.clear();
      Serial.println(".");
     lcd.clear();
lcd.setCursor(0,0);
  lcd.print("Waiting For");
  lcd.setCursor(0,1);
  lcd.print("Your Finger");
      
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
    lcd.clear();
      Serial.println("Communication error");
      lcd.print("Communication error");
      delay(2000);
      break;
    case FINGERPRINT_IMAGEFAIL:
    lcd.clear();
      Serial.println("Imaging error");
      lcd.print("Imaging error");
      delay(2000);
      break;
    default:
      Serial.println("Unknown error");
      lcd.clear();
      lcd.setCursor(0,0);
  lcd.print("UNKNOWN");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
  delay(2000);
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
    lcd.clear();
      Serial.println("Image converted");
       lcd.print("Image converted");
       delay(1000);
      break;
    case FINGERPRINT_IMAGEMESS:
     lcd.clear();
      Serial.println("Image too messy");
      lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      lcd.clear();
      lcd.setCursor(0,0);
  lcd.print("COMMUNICATION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("NO FEATURE");
  lcd.setCursor(0,1);
  lcd.print("FOUND");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("INVALID");
  lcd.setCursor(0,1);
  lcd.print("IMAGE");
      return p;
    default:
      Serial.println("Unknown error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("UNKNOWN");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return p;
  }
  lcd.clear();
  Serial.println("Remove finger");
  lcd.print("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  lcd.clear();
  Serial.print("ID ");
lcd.print("ID ");
lcd.clear();
  Serial.println(id);
  lcd.print(id);
  p = -1;
  lcd.clear();
  Serial.println("Place same finger again");
  lcd.clear();
lcd.setCursor(0,0);
    lcd.print("Place Same");
     lcd.setCursor(0,1);
    lcd.print("Finger Again");
    delay(2000);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
    lcd.clear();
      Serial.println("Image taken");
      lcd.print("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      lcd.clear();
      Serial.print(".");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("Waiting For");
  lcd.setCursor(0,1);
  lcd.print("Your finger");
      

      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      Serial.println("Communication error");
      lcd.print("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      lcd.clear();
      Serial.println("Imaging error");
      lcd.print("Imaging error");
      break;
    default:
      lcd.clear();
      Serial.println("Unknown error");
      lcd.print("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("IMAGE");
  lcd.setCursor(0,1);
  lcd.print("CONVERTED");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("IMAGE TOO");
  lcd.setCursor(0,1);
  lcd.print("MESSY");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("COMMUNICATION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("NO FEATURE");
  lcd.setCursor(0,1);
  lcd.print("FOUND");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("INVALID");
  lcd.setCursor(0,1);
  lcd.print("IMAGE");
      return p;
    default:
      Serial.println("Unknown error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("UNKNOWN ");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return p;
  }
  
  // OK converted!
  lcd.clear();
  Serial.print("Creating model for #"); 
 
    
  Serial.println(id);
  lcd.clear();
lcd.setCursor(0,0);
    lcd.print("Creating Model");
     lcd.setCursor(0,1);
    lcd.print("for");
    lcd.setCursor(5,1);
    lcd.print(id);
 
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
      lcd.clear();
    Serial.println("Prints matched!");
    lcd.print("Prints matched!");
    delay(2000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
      lcd.clear();
    Serial.println("Communication error");
    lcd.print("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    lcd.clear();
    Serial.println("Fingerprints did not match");
  lcd.clear();
lcd.setCursor(0,0);
    lcd.print("Fingerprint Did ");
     lcd.setCursor(0,1);
    lcd.print("Not Matched");
    delay(2000);
    lcd.clear();
lcd.setCursor(0,0);
    lcd.print("Enter The ID");
     lcd.setCursor(0,1);
    lcd.print("Again!!!");
    return p;
  } else {
    lcd.clear();
    Serial.println("Unknown error");
   lcd.print("Unknown error");
    return p;
  }   
  
  Serial.print("ID ");

  Serial.println(id);
 lcd.clear();
lcd.setCursor(0,0);
  lcd.print("ID");
  lcd.setCursor(0,1);
  lcd.print(id);
  delay(2000);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    
    Serial.println("Stored!");
    Serial.println("input next id");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("STORED");
  lcd.setCursor(0,1);
  lcd.print(id);
     
     delay(3000);
     lcd.clear();
     lcd.print("Enter ID");
   
   
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("COMMUNICATION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("LOCATION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("FLASH");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
    return p;
  } else {
    Serial.println("Unknown error");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("UNKNOWN");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
    return p;
  }   
}

uint8_t getFingerprintID() {
  uint8_t q = finger.getImage();
  switch (q) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("IMAGE");
  lcd.setCursor(0,1);
  lcd.print("TAKEN");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("NO FINGER");
  lcd.setCursor(0,1);
  lcd.print("DETECTED");
      return q;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("COMMUNICATION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return q;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("IMAGING");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return q;
    default:
      Serial.println("Unknown error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("UNKNOWN");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return q;
  }

  // OK success!

  q = finger.image2Tz();
  switch (q) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("IMAGE");
  lcd.setCursor(0,1);
  lcd.print("CONVERTED");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("IMAGE TOO ");
  lcd.setCursor(0,1);
  lcd.print("         MESSY");
      return q;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("COMMUNICTION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return q;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("NO FEATURE");
  lcd.setCursor(0,1);
  lcd.print("FOUND");
      return q;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("INVALID");
  lcd.setCursor(0,1);
  lcd.print("IMAGE");
      return q;
    default:
      Serial.println("Unknown error");
      lcd.clear();
lcd.setCursor(0,0);
  lcd.print("UNKNOWN");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
      return q;
  }
  
  // OK converted!
  q = finger.fingerFastSearch();
  if (q == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("FOUND A ");
  lcd.setCursor(0,1);
  lcd.print("    MATCH");
  } else if (q == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("COMMUNICATION");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
    return q;
  } if (q == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("DID NOT ");
  lcd.setCursor(0,1);
  lcd.print("FIND MATCH");
  delay(2000);
    return q;
  } else {
    Serial.println("Unknown error");
    lcd.clear();
lcd.setCursor(0,0);
  lcd.print("UNKNOWN");
  lcd.setCursor(0,1);
  lcd.print("ERROR");
    return q;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("Attendance Taken");
  lcd.setCursor(0,1);
  lcd.print(finger.fingerID);
  delay(4000);
  
  return finger.fingerID;
  b=true;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t q = finger.getImage();
  if (q != FINGERPRINT_OK)  return -1;

  q = finger.image2Tz();
  if (q != FINGERPRINT_OK)  return -1;

  q = finger.fingerFastSearch();
  if (q != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  lcd.clear();
lcd.setCursor(0,0);
  lcd.print("ATTENDACE TAKEN");
  lcd.setCursor(0,1);
  lcd.print(finger.fingerID);
  delay(5000);

  
    WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
   
  }

  
  
 String url = "/satellite_communication.php?student_id=" + String(finger.fingerID);   
  Serial.print("Requesting URL: ");
   
 Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
   if (! photocell.publish(finger.fingerID))
    return finger.fingerID;
 
}
int getFingerprintIDez2() {
  uint8_t q = finger.getImage();
  if (q != FINGERPRINT_OK)  return -1;

  q = finger.image2Tz();
  if (q != FINGERPRINT_OK)  return -1;

  q = finger.fingerFastSearch();
  if (q != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  lcd.clear();
lcd.setCursor(0,0);
  lcd.print("ATTENDACE TAKEN");
  lcd.setCursor(0,1);
  lcd.print(finger.fingerID);
  delay(5000);

  
    WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
   
  }

  if(finger.fingerID==3)
  {
    z++;
    }

    if(z==1){
      String url = "/wireless_network.php?student_id=" + String(finger.fingerID);   
  Serial.print("Requesting URL: ");
   
 Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  else{
    String url = "/wireless_network.php?student_id=" + String(finger.fingerID);   
  Serial.print("Requesting URL: ");
   
 Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    }
  
  Serial.println();
  Serial.println("closing connection");
   if (! photocell.publish(finger.fingerID))
    return finger.fingerID;
 
      
      
      }
      if(z>1){
        lcd.clear();
         lcd.setCursor(0,0);
    lcd.print("Sorry1");
     lcd.setCursor(0,1);
    lcd.print("Already Marked");
        delay(2000);
        
        
        
        
        }
  
 
}




