#include <ESP32Servo.h>
#include <Stepper.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

Servo oneServo;
Servo twoServo; 
int servoOnePosition = 0;
int servoTwoPosition = 0;

const int buttonPin = 34;

int gameStarted = 0;

int highScore = 0;

int scoreCount = 0;

int buttonState = 0;

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

  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
 
  lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("  MONTY BALL GAME   "); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print("  High Score: ");
  lcd.print(highScore);              // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print("              "); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print(" TO PLAY: ROLL BALL ");
}

/*
 * In this game, the servo obstacles are retracted from the machine. 
 * The LCD shows the high score, as well as the instruction: roll ball to start.
 * When the first "point" is recorded, the servos go into random positions, and the piezo
 * records anytime a ball makes it past the servos. 
 */


void loop() {

buttonState = digitalRead(buttonPin);

if (buttonState == 1 && gameStarted == 0)
{
  gameStarted = 1;
}
if (buttonState == 1 && gameStarted == 1)
{
  lcd.setCursor (0, 0);
  lcd.print("");
  lcd.setCursor (0, 1);
  lcd.print("     GAME OVER      ");
  lcd.setCursor (0, 2);
  lcd.print("");
  lcd.setCursor (0, 3);
  lcd.print("");

  delay(100);
  returnHomeScreen();
}
  
if (gameStarted == 0) //offline  
{
  //set LCD to write original screen
}

if (gameStarted == 1)
{
  //start game
  lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("  MONTY BALL GAME   "); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print("                    "); // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print("Score: ");
  lcd.print(scoreCount); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print("                    ");
  
}

}

void returnHomeScreen()
{
   lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("  MONTY BALL GAME   "); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print("  High Score: ");
  lcd.print(highScore);              // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print("              "); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print(" TO PLAY: ROLL BALL ");
}
