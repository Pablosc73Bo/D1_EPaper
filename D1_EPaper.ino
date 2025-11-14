// Installare:
// GxEPD2         (by Jean-Marc Zingg from IDE)
// Bus IO Library (by Adafruit from IDE)
// GFX Library    (by Adafruit from IDE)

// V.007 18/01/2024 Ripreso progetto dopo due anni di inattivita'. Ricomincio da 0

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeSerif18pt7b.h>

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

  int Valore = 0;

void setup() {
  // Wait for a second. Anti-brick code
  delay(1000);                       

  display.init();
  display.setRotation(0);
  display.setTextColor(GxEPD_BLACK);
  display.setFullWindow();
//  display.setPartialWindow (1, 1, 199, 199);

//  display.writeScreenBuffer();  

//  display.refresh(true);
  display.refresh(false);

  display.fillScreen(GxEPD_WHITE);

  display.firstPage();                                  // Inizializza e prepara il display

//  display.setFont(&FreeSerif18pt7b);
  display.setCursor(10, 30);
  display.setTextSize(3);
  display.print("Colombari");

  display.setCursor(10, 70);
  display.setTextSize(3);
  display.print("Paolo ");

  display.setCursor(10, 110);
  display.setTextSize(2);
  display.print("D1_EPaper");

  display.nextPage();
  display.powerOff();
  delay(5000); 




}

void loop() {

    Valore++;
 
    // Tutto il codice di disegno va qui dentro
    display.setPartialWindow (50, 2, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(50, 2);
    display.print(Valore);
    display.nextPage();
    display.powerOff();
    delay(600); 

    // Tutto il codice di disegno va qui dentro
    display.setPartialWindow (100, 150, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(100, 150);
    display.print(Valore*3);
    display.nextPage();

 
    display.powerOff();
    delay(600); 
  // put your main code here, to run repeatedly:



/*
    display.setPartialWindow (1, 20, 48, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(1, 20);
    display.print(Valore);
    display.nextPage();
*/
//  display.hibernate();
//  display.powerOff();

/*
    display.setPartialWindow (100, 20, 48, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(100, 20);
    display.print(Valore);
    display.nextPage();
*/

 // delay(1000);  

}
