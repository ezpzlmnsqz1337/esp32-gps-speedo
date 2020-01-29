#include <TFT_eSPI.h>
#include "bitmap.h" //(Bitmap generated with LCD Image Converter) https://sourceforge.net/projects/lcd-image-converter/
TFT_eSPI tft = TFT_eSPI();   // Invoke library

float p = 3.1415926;

void setup(void) {
  Serial.begin(115200);
  Serial.print("ST7789 TFT Bitmap Test");

  tft.begin();     // initialize a ST7789 chip
  tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness

  tft.fillScreen(TFT_BLACK);
}

void loop() {
  drawwidthheihgt();
  tft.pushImage(0,0,240,240,mercy);
  delay(500);
  tft.invertDisplay(true);
  delay(500);
  tft.invertDisplay(false);
  delay(500);
  testlines(TFT_RED);
  delay(1000);
  testdrawtext("FUCK YOU", TFT_WHITE);
  delay(1000);
  testfastlines(TFT_RED, TFT_BLUE);
  delay(1000);
  testdrawrects(TFT_GREEN);
  delay(1000);
  testfillrects(TFT_WHITE, TFT_MAGENTA);
  delay(1000);
  testdrawcircles(10, TFT_RED);
  delay(1000);
  testfillcircles(10, TFT_BLUE);
  delay(1000);
  testtriangles();
  delay(1000);
  testroundrects();
  delay(1000);
  tftPrintTest();
  delay(1000);
  mediabuttons();
  delay(1000);
  
}

void testlines(uint16_t color) {
  tft.fillScreen(TFT_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(0, 0, x, tft.height()-1, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(0, 0, tft.width()-1, y, color);
  }

  tft.fillScreen(TFT_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(tft.width()-1, 0, x, tft.height()-1, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(tft.width()-1, 0, 0, y, color);
  }

  tft.fillScreen(TFT_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(0, tft.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(0, tft.height()-1, tft.width()-1, y, color);
  }

  tft.fillScreen(TFT_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(tft.width()-1, tft.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(tft.width()-1, tft.height()-1, 0, y, color);
  }
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void drawwidthheihgt() {
  tft.setCursor(0, 0);
  tft.setTextColor(TFT_RED);
  tft.setTextWrap(true);
  int w = tft.width();
  int h = tft.height();
  tft.print(w);
  tft.print("x");
  tft.print(h);
}

void testfastlines(uint16_t color1, uint16_t color2) {
  tft.fillScreen(TFT_BLACK);
  for (int16_t y=0; y < tft.height(); y+=5) {
    tft.drawFastHLine(0, y, tft.width(), color1);
  }
  for (int16_t x=0; x < tft.width(); x+=5) {
    tft.drawFastVLine(x, 0, tft.height(), color2);
  }
}

void testdrawrects(uint16_t color) {
  tft.fillScreen(TFT_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color);
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(TFT_BLACK);
  for (int16_t x=tft.width()-1; x > 6; x-=6) {
    tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);
    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color2);
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < tft.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft.height(); y+=radius*2) {
      tft.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  tft.fillScreen(TFT_BLACK);
  int color = 0xF800;
  int t;
  int w = tft.width()/2;
  int x = tft.height()-1;
  int y = 0;
  int z = tft.width();
  for(t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects() {
  tft.fillScreen(TFT_BLACK);
  int color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft.width()-2;
    int h = tft.height()-2;
    for(i = 0 ; i <= 16; i+=1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void tftPrintTest() {
  tft.setTextWrap(false);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(TFT_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(TFT_BLUE);
  tft.setTextSize(4);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(TFT_GREEN);
  tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(TFT_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(TFT_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(TFT_WHITE);
  tft.print(" seconds.");
}

void mediabuttons() {
  // play
  tft.fillScreen(TFT_BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, TFT_WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, TFT_RED);
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, TFT_WHITE);
  tft.fillRoundRect(39, 98, 20, 45, 5, TFT_GREEN);
  tft.fillRoundRect(69, 98, 20, 45, 5, TFT_GREEN);
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, TFT_BLUE);
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, TFT_RED);
  tft.fillRoundRect(69, 98, 20, 45, 5, TFT_RED);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, TFT_GREEN);
}
