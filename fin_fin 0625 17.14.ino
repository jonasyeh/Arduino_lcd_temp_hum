#include <dht.h>
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
dht DHT;

#define DHT11_PIN 7
#define DHTPIN 7     // 設定DHT的接腳
#define DHTTYPE DHT11   // DHT 11 定義DHT的類型為DHT11

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial BT(10, 11); // TX | RX

void setup() {
//bluetooth
BT.begin(9600);


  
  lcd.begin(16, 2);      // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光

  // 閃爍
  lcd.backlight(); // 開啟背光
  delay(200);
  lcd.noBacklight(); // 關閉背光
  delay(200);
  lcd.backlight();

  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("DHT11 test!!");
  pinMode(DD3, OUTPUT);   //new

  Serial.begin(9600);
  Serial.println("DHT11 test!");
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.clear();
  lcd.print("Temp= ");
  lcd.print(DHT.temperature);
  lcd.print((char)0xDF);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum = ");
  lcd.print(DHT.humidity);
  lcd.print("%");

//bluetooth
   
    Serial.println("succeed!");
        BT.write(12); //send packet to phone
        BT.write(DHT.temperature);
         BT.write(DHT.humidity);
  delay(200);
}
