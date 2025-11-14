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
  display.refresh(false);
  display.fillScreen(GxEPD_WHITE);
  display.firstPage();                                  // Inizializza e prepara il display

/* 
//  display.setFont(&FreeSerif18pt7b);
  display.setCursor(10, 30);
  display.setTextSize(3);
  display.print("Colombari");

  display.setCursor(10, 70);
  display.setTextSize(3);
  display.print("Paolo Boss");

  display.setCursor(10, 110);
  display.setTextSize(2);
  display.print("D1_EPaper");

  display.nextPage();
*/

do {
  //display.setFont(&FreeSerif18pt7b);
  display.setCursor(10, 30);
  display.setTextSize(3);
  display.print("Colombari");

  display.setCursor(10, 70);
  display.setTextSize(3);
  display.print("Paolo Boss");

  display.setCursor(10, 110);
  display.setTextSize(2);
  display.print("D1_EPaper");
} while (display.nextPage()); // Gestisce buffer + display automaticamente



  display.powerOff();
  delay(5000); 




}

void loop() {

    Valore++;
 
/*
    // Tutto il codice di disegno va qui dentro
    display.setPartialWindow (50, 2, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(50, 2);
    display.print(Valore);
    display.nextPage();
*/

do {
    display.setPartialWindow (50, 2, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(50, 2);
    display.print(Valore);
} while (display.nextPage()); // Gestisce buffer + display automaticamente


    //display.powerOff();
    display.hibernate();
    delay(1000); 

/*
    // Tutto il codice di disegno va qui dentro
    display.setPartialWindow (100, 150, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(100, 150);
    display.print(Valore*3);
    display.nextPage();
*/

do {
    display.setPartialWindow (100, 150, 50, 16);
    display.fillScreen(GxEPD_WHITE);
    display.setTextSize(2);
    display.setCursor(100, 150);
    display.print(Valore*3);
} while (display.nextPage()); // Gestisce buffer + display automaticamente



 
    //display.powerOff();
    display.hibernate();
    delay(1000); 
  // put your main code here, to run repeatedly:


//  display.hibernate();


}
