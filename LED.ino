#include <FastLED.h>
#define LED_PIN 7
#define NUM_LEDS 12

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.setMaxPowerInVoltsAndMilliamps(5, 600);
  FastLED.setBrightness(50);
  FastLED.clear();
  FastLED.show();
 
}

void loop() {
  // Turn lights from green to blue from left to right   R G B 
leds[4]=CRGB(0,255,0);
FastLED.show();

}