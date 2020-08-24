#include "Arduino.h"
#include <TFT_eSPI.h>
#include <TinyGPS++.h>

#define RXD2 16
#define TXD2 17

TFT_eSPI tft = TFT_eSPI(); // Invoke library

float p = 3.1415926;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device

void setup(void)
{
  Serial.begin(115200);
  Serial2.begin(GPSBaud, SERIAL_8N1, RXD2, TXD2);
  Serial.print("ST7789 TFT Bitmap Test");
  Serial.print(F("Testing TinyGPS++ library v. "));
  Serial.println(TinyGPSPlus::libraryVersion());

  tft.begin();            // initialize a ST7789 chip
  tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness

  tft.fillScreen(TFT_BLACK);
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (Serial2.available() > 0)
    if (gps.encode(Serial2.read()))
      displayInfo();
  delay(1000);

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while (true)
      ;
  }
}

void displayInfo()
{
  tft.fillScreen(TFT_BLACK);
  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
    const int cDateSize = 50;
    char date[cDateSize];
    snprintf(date, cDateSize, "Date: %d.%d.%d", gps.date.day(), gps.date.month(), gps.date.year());
    drawText(date, TFT_WHITE, 30, 40);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
    const int cTimeSize = 50;
    char time[cTimeSize];
    snprintf(time, cTimeSize, "Time: %d:%d:%d", gps.time.hour(), gps.time.minute(), gps.time.second());
    drawText(time, TFT_WHITE, 30, 90);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Speed: "));
  if (gps.speed.isValid())
  {
    const int cSpeedSize = 50;
    char size[cSpeedSize];
    snprintf(size, cSpeedSize, "Speed: %f km/h", gps.speed.kmph());
    drawText(size, TFT_WHITE, 10, 150);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Satelites: "));
  if (gps.satellites.isValid())
  {
    const int cSatelitesSize = 50;
    char satelites[cSatelitesSize];
    snprintf(satelites, cSatelitesSize, "Sats: %d", gps.satellites.value());
    drawText(satelites, TFT_WHITE, 10, 200);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

void drawText(char* text, uint16_t color, int x, int y)
{
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.setTextWrap(true);
  tft.print(text);
}
