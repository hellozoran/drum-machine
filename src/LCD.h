#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
#define TFT_SCLK 52
#define TFT_MOSI 51
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

float p = 3.1415926;

void WriteText(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
