#include <MIDI.h>
#include <FastLED.h>
#define LED_PIN 7
#define NUM_LEDS 8

CRGB leds[NUM_LEDS];


int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int value1, value2, value3, value4;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
    MIDI.begin(1);
    Serial.begin(115200);
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  
    FastLED.setBrightness(95);
    FastLED.clear();
    FastLED.show();
 
}
void loop()
{
    value1=analogRead(flexPin1);
    value2=analogRead(flexPin2);
    value3=analogRead(flexPin3);
    value4=analogRead(flexPin4);


    // Serial.println(value3);

    Serial.println(value3);

    // Serial.println(value1);
 
     
    // if  (value1>770){
    //         MIDI.sendNoteOn(60, 111, 1);
    //         leds[6]=CRGB(255,255,0);
    //         leds[7]=CRGB(255,225,0);
    //         FastLED.show();
    //            delay(20);
    // }
    // if  (value1<769){
    //         MIDI.sendNoteOn(60, 0, 1);
    //         leds[6]=CRGB(0,0,0);
    //         leds[7]=CRGB(0,0,0);
    //         FastLED.show();           
    // }

    
    if  (value2>820){
            MIDI.sendNoteOn(62, 111, 1);
            leds[4]=CRGB(255,0,255);
            leds[5]=CRGB(255,0,255);
            FastLED.show();
            delay(20);
    }
    if  (value2<819){
            MIDI.sendNoteOn(62, 0, 1);
            leds[4]=CRGB(0,0,0);
            leds[5]=CRGB(0,0,0);
            FastLED.show(); 
    }


    if  (value3>910){
            MIDI.sendNoteOn(64, 111, 1);
            leds[2]=CRGB(0,255,255);
            leds[3]=CRGB(0,255,255);
            FastLED.show();
            delay(20);
    }
    if  (value3<909){
            MIDI.sendNoteOn(64, 0, 1);
            MIDI.sendNoteOn(62, 0, 1);
            leds[2]=CRGB(0,0,0);
            leds[3]=CRGB(0,0,0);
            FastLED.show(); 
    } 

    
    if  (value4>729){
            MIDI.sendNoteOn(65, 111, 1);
            leds[0]=CRGB(255,20,40);
            leds[1]=CRGB(255,20,40);
            FastLED.show();
            delay(20);
    }
    if  (value4<728){
            MIDI.sendNoteOn(65, 0, 1);
            MIDI.sendNoteOn(62, 0, 1);
            leds[0]=CRGB(0,0,0);
            leds[1]=CRGB(0,0,0);
            FastLED.show(); 
    }                    

    delay(40);
 

    MIDI.read();

}