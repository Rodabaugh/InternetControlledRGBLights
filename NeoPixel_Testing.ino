#include <Adafruit_NeoPixel.h>

#define PIN 4

#define NUMPIXELS 50

int randG;
int randR;
int randB;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  pixels.begin();
  pixels.setBrightness(50);
  pixels.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:

  hsvColorWheelProgressive();
  clearLEDs();
  delay(2000);
  hsvColorWheel();
  clearLEDs();
  delay(2000);
  ramdomColors();
  clearLEDs();
  delay(2000);
  mostlyReds();
  clearLEDs();
  delay(2000);
  mostlyBlue();
  clearLEDs();
  delay(2000);
  mostlyGreens();
  clearLEDs();
  delay(2000);
  xMas();
  clearLEDs();
  delay(2000);
}

void clearLEDs(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
}

void ramdomColors(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    randG = random(255);
    randR = random(255);
    randB = random(255);
    pixels.setPixelColor(i, pixels.Color(randG, randR, randB));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(250);
  }
}

void mostlyReds(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    randG = random(50);
    randR = random(255);
    randB = random(50);
    pixels.setPixelColor(i, pixels.Color(randG, randR, randB));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(250);
  }
}

void mostlyBlue(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    randG = random(50);
    randR = random(50);
    randB = random(255);
    pixels.setPixelColor(i, pixels.Color(randG, randR, randB));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(250);
  }
}

void mostlyGreens(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    randG = random(255);
    randR = random(50);
    randB = random(50);
    pixels.setPixelColor(i, pixels.Color(randG, randR, randB));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(250);
  }
}

void xMas(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    if(i % 2 == 0){
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }else{
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    }

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(250);
  }
}

void hsvColorWheelProgressive(){
  for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.ColorHSV(i*1310, 255, 255));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(250);
  }
}

void hsvColorWheel(){
  for (int h=0; h<65535; h=h+100) {

    for (int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.ColorHSV(h, 255, 255));
    }

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(50);
  }
}
