#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(240 ,240);   // A single instance is used for 1 or 2 displays
TFT_eSprite img = TFT_eSprite(&tft);

int FirstScreenCS = 15;
int SecondScreenCS = 21;
int JoyInput       = 22;
int Ravein         = 25;
int Rave         = 0;
const int JoyXin  = 34;
const int JoyYin  = 35;

int JoyX          = 0;
int JoyXout       = 120;
int JoyY          = 0;
int JoyYout       = 120;


int JoyButton     = 1;
int JoyValue      = LOW; 
int FirstLayer    = 20;
int SecondLayer   = 35;

int VerticalMax1  = 50;
int Vertical1     = 1;
int VerticalMin1  = 2;
int HorzMax1      = 50;
int Horz1         = 1;
int HorzMin1      = 40;
int RefNumV1      = 1;
int RefNumH1      = 1;
int Speed1        = 5.5;
int SpeedH1       = 1.5;
int SeqV1         = 1;
int SeqH1         = 1;


int VerticalMax2  = 50;
int Vertical2     = 1;
int VerticalMin2  = 2;
int HorzMax2      = 50;
int Horz2         = 1;
int HorzMin2      = 40;
int RefNumV2      = 1;
int RefNumH2      = 1;
int Speed2        = 8;
int SpeedH2       = 1.5;
int SeqV2         = 1;
int SeqH2         = 1;

int Color1  = 0xAC60;
int Color2  = 0xFF60;
int Color3  = 0xE9C4;
int Color4  = 0x20E4;


void setup() {
   
  pinMode(FirstScreenCS, OUTPUT);
  pinMode(SecondScreenCS, OUTPUT);
  pinMode(JoyInput, INPUT);
  pinMode(Ravein, INPUT);
  
  digitalWrite(SecondScreenCS, LOW);
  digitalWrite(FirstScreenCS, LOW);
  tft.init();
  tft.setTextSize(5);
  img.setCursor(120,120);
  tft.setRotation(0);
  tft.fillScreen(TFT_GREEN);
  img.createSprite(240,240);
}

void loop() {




      
      Vertical1  = ((VerticalMax1 + RefNumV1) / JoyButton);
      Horz1      = ((HorzMax1 + RefNumH1) / JoyButton);      
      Vertical2  = ((VerticalMax2 + RefNumV2) / JoyButton);
      Horz2      = ((HorzMax2 + RefNumH2) / JoyButton);
  ///////////////////////////////////////////////
  //            Push the Eye Screens          // 
  /////////////////////////////////////////////
      digitalWrite(FirstScreenCS, LOW);
        img.fillScreen(Color1);
        tft.setRotation(2);
      digitalWrite(FirstScreenCS, HIGH);
      digitalWrite(FirstScreenCS, LOW);
        img.fillEllipse(JoyYout, JoyXout, Vertical1, Vertical1/2.3, Color2);   //Outer Vertical ellipse
        img.fillEllipse(JoyYout, JoyXout, Horz1/2.3, Horz1, Color2);               //Outer Horazontal ellipse
        img.fillEllipse(JoyYout, JoyXout, Vertical1-FirstLayer, (Vertical1-FirstLayer)/2.3, Color3);           //Second Vertical ellipse
        img.fillEllipse(JoyYout, JoyXout, (Horz1-FirstLayer)/2.3, Horz1-FirstLayer, Color3);                  //Second Horazontal ellipse
        img.fillEllipse(JoyYout, JoyXout, Vertical1-SecondLayer, (Vertical1-SecondLayer)/2.5, Color4);         //Inner Vertical ellipse
        img.fillEllipse(JoyYout, JoyXout, (Horz1-SecondLayer)/2.5, Horz1-SecondLayer, Color4);                //Inner Horazontal ellipse
        img.pushSprite(0,0);
      digitalWrite(FirstScreenCS, HIGH);

      digitalWrite(SecondScreenCS, LOW);
        tft.setRotation(0);
        img.fillScreen(Color1);
      digitalWrite(SecondScreenCS, HIGH);
      digitalWrite(SecondScreenCS, LOW);
        img.fillEllipse(JoyYout, JoyXout, Vertical2, Vertical2/2.3, Color2);   //Outer Vertical ellipse
        img.fillEllipse(JoyYout, JoyXout, Horz2/2.3, Horz2, Color2);               //Outer Horazontal ellipse
        img.fillEllipse(JoyYout, JoyXout, Vertical2-FirstLayer, (Vertical2-FirstLayer)/2.3, Color3);           //Second Vertical ellipse
        img.fillEllipse(JoyYout, JoyXout, (Horz2-FirstLayer)/2.3, Horz2-FirstLayer, Color3);                  //Second Horazontal ellipse
        img.fillEllipse(JoyYout, JoyXout, Vertical2-SecondLayer, (Vertical2-SecondLayer)/2.5, Color4);         //Inner Vertical ellipse
        img.fillEllipse(JoyYout, JoyXout, (Horz2-SecondLayer)/2.5, Horz2-SecondLayer, Color4);                //Inner Horazontal ellipse
        img.pushSprite(0,0);
      digitalWrite(SecondScreenCS, HIGH);

      
  ///////////////////////////////////////////////
  //        Sets the size of the eyes         // 
  /////////////////////////////////////////////

 /*------------------------------------------*/
 /*         Eye #1            
/*------------------------------------------*/    
      if (RefNumV1 > VerticalMax1){
            SeqV1 = 2;
      }
      else if (RefNumV1 < VerticalMin1){
            SeqV1 = 1;
      }
      if (RefNumH1 > HorzMax1){
            SeqH1 = 2;
      }
      else if (RefNumH1 < HorzMin1){
            SeqH1 = 1;
      }

      if (SeqV1 == 1){
      RefNumV1 = (RefNumV1 + (Speed1 * JoyButton));
      }
      else if (SeqV1 == 2){
        RefNumV1 = (RefNumV1 - (Speed1 * JoyButton));
      }
      if (SeqH1 == 1){
      RefNumH1 = (RefNumH1 + (SpeedH1 * JoyButton));
      }
      else if (SeqH1 == 2){
        RefNumH1 = (RefNumH1 - (SpeedH1 * JoyButton));
      }
           

 /*------------------------------------------*/
 /*         Eye #2            
/*------------------------------------------*/ 
      if (RefNumV2 > VerticalMax2){
            SeqV2 = 2;
      }
      else if (RefNumV2 < VerticalMin2){
            SeqV2 = 1;
      }
      if (RefNumH2 > HorzMax2){
            SeqH2 = 2;
      }
      else if (RefNumH2 < HorzMin2){
            SeqH2 = 1;
      }

      if (SeqV2 == 1){
      RefNumV2 = (RefNumV2 + (Speed2 * JoyButton));
      }
      else if (SeqV2 == 2){
        RefNumV2 = (RefNumV2 - (Speed2 * JoyButton));
      }
      if (SeqH2 == 1){
      RefNumH2 = (RefNumH2 + (SpeedH2 * JoyButton));
      }
      else if (SeqH2 == 2){
        RefNumH2 = (RefNumH2 - (SpeedH2 * JoyButton));
      }

  //////////////////////////////////////////////
  //      Sets JoyStick Info                 // 
 /////////////////////////////////////////////
      JoyValue = digitalRead(JoyInput);            
            if (JoyValue == HIGH){
              JoyButton = 2; 
              
            }
            else {
              JoyButton = 1;
             // JoyXout = 120;
             // JoyYout = 120;
            }

            JoyX = analogRead(JoyXin);
              JoyY = analogRead(JoyYin);
              JoyYout = (JoyY / 15);  
              JoyXout = (JoyX / 15);
              
            if (Rave == HIGH) {
                Color1  = 0xAC60;
                Color2  = 0xFF60;
                Color3  = 0xE9C4;
                Color4  = 0x20E4;
                if (digitalRead(Ravein) == LOW){ Rave = LOW;}
              }
              else if (Rave == LOW) {
    
              Color1  = (random(0x0000, 0xffff));
              Color2  = (random(0x0000, 0xffff));
              Color3  = (random(0x0000, 0xffff));
              Color4  = (random(0x0000, 0xffff));
              if (digitalRead(Ravein) == LOW){ Rave = HIGH;}
                }
    
      
      digitalRead(RefNumH1);
      digitalRead(RefNumV1);
      digitalRead(RefNumH2);
      digitalRead(RefNumV2);
    
}
