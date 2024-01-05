#include <Servo.h>        // 包含 Arduino 內建程式庫 Servo.h
Servo xservo;             // 宣告伺服馬達名稱 xservo ，由雙軸按鍵模組X軸控制
Servo yservo;             // 宣告伺服馬達名稱 yservo ，由雙軸按鍵模組Y軸控制
int XServoPin = 9;        // X 軸伺服器接 Arduino pin 9
int YServoPin = 8;        // Y 軸伺服器接 Arduino pin 8
int XServoPin2 = 11;
int YServoPin2 = 10;

int xposPin = A0;         // 雙軸按鍵搖桿 VRx 接 Arduino Analog pin A0
int yposPin = A1;         // 雙軸按鍵搖桿 VRy 接 Arduino Analog pin A1
int xposPin2 = A3;
int yposPin2 = A4;
int Xpos = 0;             // 定義X軸伺服器位址參數
int Ypos = 0;             // 定義丫軸伺服器位址參數
int buttonPin = 7;        // 搖桿按鍵輸出 SW 接 Arduino pin 7
int buttonPress = 0;      // 定義 Arduino 從搖桿按鍵 SW 讀入值為 buttonPress 
int buttonPin2 = 6;        

void setup() {
  Serial.begin(9600);         //與電腦連接鲍率->(9600)
  Serial.println("ready");
      
  pinMode(buttonPin,INPUT);      //Arduino 從搖桿按鍵讀入電壓
  digitalWrite(buttonPin,HIGH);  //設定當按鍵沒按時，輸出為高電壓

  pinMode(buttonPin2,INPUT);      //Arduino 從搖桿按鍵讀入電壓
  digitalWrite(buttonPin2,HIGH);  //設定當按鍵沒按時，輸出為高電壓
  
  xservo.attach(XServoPin);      // X 軸伺服器接 Arduino pin 9
  yservo.attach(YServoPin);      //Y 軸伺服器接 Arduino pin 8

  xservo.attach(XServoPin2);      // X 軸伺服器接 Arduino pin 9
  yservo.attach(YServoPin2);      //Y 軸伺服器接 Arduino pin 8

}

void loop () {
buttonPress = digitalRead(buttonPin);    //讀入搖桿按鍵電位
  if(buttonPress == LOW)                 // 當搖桿按鍵為低電位時，（即按下按鍵）
  {
   Serial.println("on");       //開啟雷射
  
  }
  else
  {
   Serial.println("off");       //開啟雷射
  }
  
  Xpos = analogRead(xposPin);            // 讀入搖桿 x 軸數值，0-1023
  Xpos = map(Xpos,0,1023,0,180);         //將數值轉為伺服馬達轉動的角度，0-180度
  Ypos = analogRead(yposPin);            //讀入搖桿 y 軸 數值，0-1023
  Ypos = map(Ypos,0,1023,0,180);         //將數值轉為伺服馬達轉動的角度，0-180度
  xservo.write(Xpos);                    // 轉動 x軸伺服馬達至那個角度
  yservo.write(Ypos);                    // 轉動 y軸何服馬達至那個角度
  delay(50);
}