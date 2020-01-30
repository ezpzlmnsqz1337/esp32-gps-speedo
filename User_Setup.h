// See SetupX_Template.h for all options available

#define ST7789_DRIVER

// #define TFT_SDA_READ      // This option is for ESP32 ONLY, tested with ST7789 display only

// If colours are inverted (white shows as black) then uncomment one of the next
// 2 lines try both options, one of the options should correct the inversion.
// #define TFT_INVERSION_ON
// #define TFT_INVERSION_OFF

// For ST7789 ONLY, define the colour order IF the blue and red are swapped on your display
// Try ONE option at a time to find the correct colour order for your display
// #define TFT_RGB_ORDER TFT_RGB  // Colour order Red-Green-Blue
// #define TFT_RGB_ORDER TFT_BGR  // Colour order Blue-Green-Red


// My ST7789 display has TCT_CS wired permananently low so the pin is not defined here
#define TFT_WIDTH  240 // ST7789 240 x 240 and 240 x 240
#define TFT_HEIGHT  240 // ST7789 240 x 240 and 240 x 240

// For NodeMCU - use pin numbers in the form PIN_Dx where Dx is the NodeMCU pin designation/#define TFT_MISO 19
#define TFT_MOSI 13
#define TFT_SCLK 14
// #define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST

#define TFT_BL   32  // LED back-light (only for ST7789 with backlight control pin)


#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT


// #define SPI_FREQUENCY  20000000
#define SPI_FREQUENCY  27000000
// #define SPI_FREQUENCY  40000000
// #define SPI_FREQUENCY  80000000

#define SPI_TOUCH_FREQUENCY  2500000


//#define SUPPORT_TRANSACTIONS
