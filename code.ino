#include <Keypad.h> 
#include <Servo.h> 
Servo lockServo; 
// Keypad setup 
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = { 
{'1','2','3','A'}, 
{'4','5','6','B'},   
{'7','8','9','C'}, 
{'*','0','#','D'} 
}; 
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
void setup() { 
 
lockServo.attach(10); 
// Servo connected to pin 10
  lockServo.write(0); 
// Initially locked position 
  
} 
void loop() { 
  
char key = keypad.getKey(); 
if (key == '1') { 
// Press key '1' to unlock 
lockServo.write(90); // Rotate servo to unlock 
delay(2000);  
// Stay unlocked for 2 seconds 
lockServo.write(0); // Return to locked position 
} 
} 