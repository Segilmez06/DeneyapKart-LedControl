#include "LedControl.h"

LedControl control = LedControl(D5, D6, D7, 1);


byte images[][8] = {
  { 0,  //kalp
    B01100110,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000 },
  { B00111100,  //uzgun ifade
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },
  { B00111100,  //normal ifade
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  { B00111100,  //gulen ifade
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 }
};

void MatrixeYazdir(byte* ch) {
  for (int i = 0; i < 8; i++) {
    control.setRow(0, i, ch[i]);
  }
}

void loop() {
  for (int j = 0; j < 4; j++)  //Tüm şekilleri yazdırma
  {
    MatrixeYazdir(images[j]);
    delay(1000);
  }
  for (int i = 0; i < 15; i++)  //Azdan çoğa parlaklık
  {
    control.setIntensity(0, i);
    delay(100);
  }
}

void setup() {
  control.shutdown(0, false);
  control.setIntensity(0, 8);
  control.clearDisplay(0);
}
