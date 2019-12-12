#include <ESP32Servo.h>
#include <Stepper.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

Servo oneServo;
Servo twoServo; 
int servoOnePosition = 0;
int servoTwoPosition = 0;

int gameStarted = 0;

int highScore = 0;

int scoreCount = 0;


//the initialHiddenPositions when the game is not active
int servoOneHidden = 0;
int servoTwoHidden = 0;

void setup() {
  // put your setup code here, to run once:
  oneServo.attach(27);
  twoServo.attach(25);
  Serial.begin (115200);
  oneServo.write(servoOnePosition);
  twoServo.write(servoTwoPosition);

  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
 
  lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("  MONTY BALL GAME   "); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print("High Score: "); // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print("   TO PLAY:         "); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print("   ROLL FIRST BALL  ");
}

/*
 * In this game, the servo obstacles are retracted from the machine. 
 * The LCD shows the high score, as well as the instruction: roll ball to start.
 * When the first "point" is recorded, the servos go into random positions, and the piezo
 * records anytime a ball makes it past the servos. 
 */


void loop() {
  // put your main code here, to run repeatedly:
if (gameStarted == 0) //offline  
{
  //set LCD to write original screen
}

if (gameStarted == 1)
{
  //start game
  
}


}
