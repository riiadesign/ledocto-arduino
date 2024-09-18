#include <FastLED.h>

using namespace std;

bool buttonNext, buttonStop, buttonFxA, buttonFxB = false;
#define PIN_NEXT  6
#define PIN_STOP  7
#define PIN_FX_A  8
#define PIN_FX_B  9

#define PIN_LED     5
#define NUM_LEDS    50
#define BRIGHTNESS  255
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define FRAME_BUFFER      60
#define FRAMES_PER_SECOND 30
CRGB queue[FRAME_BUFFER][NUM_LEDS];
int qPosition = 0;

void setup() {
  pinMode(PIN_NEXT, INPUT_PULLUP);
  pinMode(PIN_STOP, INPUT_PULLUP);
  pinMode(PIN_FX_A, INPUT_PULLUP);
  pinMode(PIN_FX_B, INPUT_PULLUP);

  FastLED.addLeds<LED_TYPE, PIN_LED, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // get button state (todo: make use of buttons lmao)
  buttonNext = digitalRead(PIN_NEXT) == HIGH;
  buttonStop = digitalRead(PIN_STOP) == HIGH;
  buttonFxA = digitalRead(PIN_FX_A) == HIGH;
  buttonFxB = digitalRead(PIN_FX_B) == HIGH;
  
  // set all leds to the current frame's colors
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = queue[qPosition][i];
  }
  // progress queue
  qPosition++;

  FastLED.show();
  delay(1000 / FRAMES_PER_SECOND);
}
