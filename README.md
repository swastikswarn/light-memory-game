# Light Memory Game  
Arduino Nano + 4 LEDs + 4 Buttons  

## Description  
This is a “Simon-style” light memory game using an Arduino Nano.  A sequence of LED lights is shown, and the player must repeat the sequence by pressing the corresponding buttons.  Each round the sequence grows by one.  If the player presses a wrong button, the game resets to level 1.

## Hardware  
- Arduino Nano  
- 4 LEDs (connected to digital pins D2, D3, D4, D5)  
- 4 Buttons (connected to digital pins D6, D7, D8, D9)  
  - Buttons use the internal pull-up resistors of the Arduino (so one side of each button goes to GND, the other to the input pin)  
- No external resistors required for LEDs or buttons in this version  

### Wiring summary  
| Signal | Arduino Pin | Connection |
|--------|-------------|------------|
| LED 1  | D2          | LED anode → D2, LED cathode → GND |
| LED 2  | D3          | LED anode → D3, LED cathode → GND |
| LED 3  | D4          | LED anode → D4, LED cathode → GND |
| LED 4  | D5          | LED anode → D5, LED cathode → GND |
| Button 1 | D6        | Button between D6 and GND (internal pull-up) |
| Button 2 | D7        | Button between D7 and GND |
| Button 3 | D8        | Button between D8 and GND |
| Button 4 | D9        | Button between D9 and GND |

## Code  
- Setup initializes 4 LED pins as OUTPUT, and 4 button pins as INPUT_PULLUP.  
- A random sequence of indexes (0-3) is generated at the start.  
- In each round (level), the sequence up to the current level is shown (LED flashes).  
- The player then presses the buttons in the correct order.  
- If the player succeeds, level++ and next round.  
- If the player fails, game over animation and reset to level 1.

## Usage  
1. Upload the `light_memory_game.ino` sketch to your Arduino Nano.  
2. Power everything and ensure buttons and LEDs are wired correctly.  
3. Press the correct sequence of buttons after the LEDs flash.  
4. Continue until you make a mistake — then the game restarts.

## Enhancement ideas  
- Add a buzzer or speaker so that each LED/button has a distinct tone.  
- Display the current level on a 7-segment display or OLED.  
- Add high score memory (in EEPROM).  
- Increase difficulty by speeding up the flashes each level.  
- Use RGB LEDs or more than 4 LEDs/buttons for a larger game.

## Repository  
Code and circuit diagram available at:  
[https://github.com/swastikswarn/light-memory-game](https://github.com/swastikswarn/light-memory-game)


