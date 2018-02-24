
#include <Arduino.h>
#include <GxEPD.h>

// #include "display.h"

#include <GxGDEH029A1/GxGDEH029A1.cpp>      // 2.9" b/w
#define GxEPD_RED GxEPD_BLACK
// #include <GxGDEW029Z10/GxGDEW029Z10.cpp>    // 2.9" b/w/r

#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>

#if defined(ESP8266)
//GxIO_SPI(SPIClass& spi, int8_t cs, int8_t dc, int8_t rst = -1, int8_t bl = -1);
GxIO_Class io(SPI, SS, 0, 2); // dc 0, rst 2
// GxGDExnnnxn(GxIO& io, uint8_t rst = D4, uint8_t busy = D2);
GxEPD_Class display(io); // default selection of rst 2, busy 4
// GxEPD_Class display(io, 2, 12); // rst 2, busy on MISO
#endif

// #include "fonts.h"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSerifBold9pt7b.h>
#include <Fonts/FreeSerifBold12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <Fonts/FreeSerif18pt7b.h>


void showFont(const char name[], const GFXfont* f);


void setup() {
    // put your setup code here, to run once:
    display.init();
}


void loop() {
    // put your main code here, to run repeatedly:
    showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
    showFont("FreeSansBold9pt7b", &FreeSansBold9pt7b);
    showFont("FreeSerifBold9pt7b", &FreeSerifBold9pt7b);

    showFont("FreeMono12pt7b", &FreeMono12pt7b);
    showFont("FreeSans12pt7b", &FreeSans12pt7b);
    showFont("FreeSerif12pt7b", &FreeSerif12pt7b);

    showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
    showFont("FreeSansBold12pt7b", &FreeSansBold12pt7b);
    showFont("FreeSerifBold12pt7b", &FreeSerifBold12pt7b);

    showFont("FreeMono18pt7b", &FreeMono18pt7b);
    showFont("FreeMonoBold18pt7b", &FreeMonoBold18pt7b);
    showFont("FreeSans18pt7b", &FreeSans18pt7b);
    showFont("FreeSerif18pt7b", &FreeSerif18pt7b);
}


void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.print(name);
  display.setTextColor(GxEPD_RED);
  display.print(" !\"#$%&'()*+,-./");
  display.setTextColor(GxEPD_BLACK);
  display.print("0123456789:;<=>?");
  display.setTextColor(GxEPD_RED);
  display.print("@ABCDEFGHIJKLMNO");
  display.setTextColor(GxEPD_BLACK);
  display.print("PQRSTUVWXYZ[\\]^_");
  display.setTextColor(GxEPD_RED);
  display.print("`abcdefghijklmno");
  display.setTextColor(GxEPD_BLACK);
  display.print("pqrstuvwxyz{|}~ ");
  display.update();
  delay(5000);
}
