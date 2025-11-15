const char* Version     = "V.002";

// Installare:
// GxEPD2         (by Jean-Marc Zingg from IDE)
// Bus IO Library (by Adafruit from IDE)
// GFX Library    (by Adafruit from IDE)

// V.001 14/11/2025 Inserito esempio Bitmap da caricare con l'ausilio di Image2Lcd
// V.002 15/11/2025 Inserita versione firmware a display

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeSerif18pt7b.h>

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

  int Valore = 0;


const int SLEEP_LENGTH = 200;
//50x50 pixels
#define yt3_width 100
#define yt3_height 61
static unsigned char youtube[112] = { /* 0X00,0X01,0X20,0X00,0X1C,0X00, */
0XDF,0XFF,0XFF,0XF7,0XBF,0XFF,0XFF,0XFB,0X7F,0XFF,0XFF,0XFD,0X60,0X00,0X00,0X06,
0X60,0X00,0X00,0X06,0X40,0X00,0X00,0X02,0XC0,0X00,0X00,0X03,0XC0,0X00,0X30,0X03,
0XC0,0X00,0X70,0X03,0XC0,0X00,0XF0,0X03,0XC0,0X01,0XF0,0X03,0XC0,0X03,0XF0,0X03,
0XC0,0X07,0XF0,0X03,0XC0,0X0F,0XF0,0X03,0XC0,0X0F,0XF0,0X03,0XC0,0X07,0XF0,0X03,
0XC0,0X03,0XF0,0X03,0XC0,0X01,0XF0,0X03,0XC0,0X00,0XF0,0X03,0XC0,0X00,0X70,0X03,
0XC0,0X00,0X30,0X03,0XC0,0X00,0X00,0X03,0X40,0X00,0X00,0X02,0X60,0X00,0X00,0X06,
0X60,0X00,0X00,0X06,0XBF,0XFF,0XFF,0XFD,0XDF,0XFF,0XFF,0XFB,0XEF,0XFF,0XFF,0XF7,
};

const unsigned char ImagePaolo[112] = { /* 0X00,0X01,0X20,0X00,0X1C,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X04,0X00,0X06,0X00,0X04,
0X00,0X09,0X00,0X04,0X00,0X10,0X80,0X04,0X3F,0XE0,0X7F,0XC4,0X10,0X00,0XFF,0X84,
0X08,0X01,0XFF,0X04,0X04,0X03,0XFE,0X04,0X04,0X07,0XFE,0X04,0X08,0X0F,0XFF,0X08,
0X10,0X1F,0XFF,0X88,0X3F,0XFF,0XFF,0XC8,0X00,0X1F,0X80,0X08,0X00,0X0F,0X00,0X08,
0X00,0X06,0X00,0X10,0X00,0X00,0X00,0X10,0X0F,0X80,0X00,0X10,0X10,0X70,0X00,0X20,
0X21,0XCC,0X01,0X20,0X21,0X23,0X01,0X40,0X41,0X2E,0XF9,0XB8,0X41,0XC1,0X4F,0X44,
0X41,0X0F,0X45,0X44,0X41,0X09,0X41,0X44,0X01,0X0F,0X39,0X38,0X00,0X00,0X00,0X00,
};


void setup() {
  // Wait for a second. Anti-brick code
  delay(1000);                       

  // Inizializza e prepara il display
  display.init();
  display.setRotation(0);
  display.setTextColor(GxEPD_BLACK);
  display.setFullWindow();
  display.refresh(false);
  display.fillScreen(GxEPD_WHITE);
  display.firstPage();                                  


  // Visualizzo sul display la prima pagina
  do {
    //display.setFont(&FreeSerif18pt7b);
    display.setCursor(170, 0);
    display.setTextSize(1);
    display.print(Version);


    display.setCursor(10, 30);
    display.setTextSize(3);
    display.print("D1_EPaper");

    display.setCursor(10, 70);
    display.setTextSize(3);
    display.print("By Paolo");

    display.setCursor(10, 110);
    display.setTextSize(3);
    display.print("Colombari");

    // Disegna il bitmap
    display.drawBitmap(5, 150, youtube, 32, 28, GxEPD_BLACK);
    //display.drawBitmap(5, 150, ImagePaolo, 32, 28, GxEPD_BLACK);

    } while (display.nextPage());

  display.powerOff();
  delay(5000); 


}

void loop() {

    Valore++;

  // Aggiorno il dato in alto
  do {
    display.setPartialWindow (50, 2, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(50, 2);
    display.print(Valore);
    } while (display.nextPage());
    //display.powerOff();
    display.hibernate();
    delay(1000); 

  // Aggiorno il dato in basso
  do {
    display.setPartialWindow (100, 150, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(100, 150);
    display.print(Valore*3);
    } while (display.nextPage());


  //display.powerOff();
  display.hibernate();
  delay(1000); 


}
