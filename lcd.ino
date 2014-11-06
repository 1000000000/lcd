#include "ST7565.h"

// lcd dimensions:
//      character: 6x8
//      screen:
//         character: 21x8
//         pixel: 128x64

// pin 9 - Serial data out (SID)
// pin 8 - Serial clock out (SCLK)
// pin 7 - Data/Command select (RS or A0)
// pin 6 - LCD reset (RST)
// pin 5 - LCD chip select (CS)
ST7565 glcd(9, 8, 7, 6, 5);

int x = 0;
int y = 0;

void setup() {
  glcd.begin(0x18);
}

void loop() {
  glcd.clear();
  drawPlayer();
  glcd.display();
  delay(1000/60);
}

void drawPlayer() {
  glcd.drawchar(toPixelX(x), y, '@', 1);
}

int toPixelX(int charX) {
  return 1 + charX*6;
}

int toPixelY(int charY) {
  return charY*8;
}


