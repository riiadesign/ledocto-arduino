# LED Octo for Arduino

Takes an animation and uses LEDs to display it either as a background or an overlay.

Supports 4 buttons:
 - Start / Next
 - Stop
 - Effect A
 - Effect B

# PlatformIO Starter for FastLED

Basic starter project for developing FastLED applications in PlatformIO. It's also backward compatible with Arduino IDE.

## Using a board other than Arduino UNO

  1. Open up platformio.ini at the root of this repo.
  2. Modify the `board = uno` part with your board.
  3. Everything will auto magically update and you can compile/upload and it should just work.

You can also look at the platforms/ folder [here](https://github.com/FastLED/PlatformIO-Starter/tree/main/platforms) for platformio ini files that you can use to get the main sketch running for your specific board type.