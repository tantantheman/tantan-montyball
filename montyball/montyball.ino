#include <ESP32Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

Servo oneServo;
Servo twoServo; 
int servoOnePosition = 0;
int servoTwoPosition = 0;

const int buttonPin = 34;
const int piezoPin = 4;

int buttonCount = 0;
int myPos[] = {10, 30, 50, 70, 90, 110, 130, 150}; 
int moving = 0;

int gameStarted = 0;

int highScore = 0;
int scoreCount = 0;

int buttonState = 0;
int piezoState = 0;
int newPos = 0;
int playingGame = 1;

//the initial Hidden Positions when the game is not active
int servoOneHidden = 0;
int servoTwoHidden = 0;

long previousMillis = 0;         // will store last time LED 1 was updated
long previousMillis2 = 0;        // will store last time LED 2 was updated
long previousMillis3 = 0;        // will store last time LED 3 was updated

long timeHeartbeat = 500;        // time between flashes of LED 1, as a sign of life  (milliseconds)
long timeWarning = 5000;         // time before warning light starts flashing (milliseconds)
long timeExpired = 30000;        // time at which last LED turns on (milliseconds)

boolean beating = true;          // status of each process for easy boolean checks
boolean warning = false;         // status of each process for easy boolean checks
boolean expired = false;         // status of each process for easy boolean checks


void setup() {
  // put your setup code here, to run once:
  oneServo.attach(27);
  twoServo.attach(25);
  Serial.begin (115200);
  oneServo.write(servoOnePosition);
  twoServo.write(servoTwoPosition);

  pinMode(buttonPin, INPUT);
  pinMode(piezoPin, INPUT);

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
piezoState = digitalRead(piezoPin);
Serial.println(piezoState);

if (piezoState == 1 && gameStarted == 0)
{
  gameStarted = 1;

}

if (gameStarted == 0)
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

  if (piezoState == 1)
  {
    scoreCount++;
  newPos = (int)random(0, 7);
  oneServo.write(myPos[newPos]);
  newPos = (int)random(0, 7);
  twoServo.write(myPos[newPos]);  
  }


}

if (gameStarted == 2)
{
    gameStarted = 0;

    if (scoreCount > highScore)
  {
    highScore = scoreCount; 
  }
  oneServo.write(servoOnePosition);
  twoServo.write(servoTwoPosition);
  lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("  GAME OVER         "); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print("                    "); // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print("Score: ");
  lcd.print(scoreCount); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print("                    ");
  delay(10000);

  scoreCount = 0;
  previousMillis = 0;         // will store last time LED 1 was updated
  previousMillis2 = 0;        // will store last time LED 2 was updated
  previousMillis3 = 0;        // will store last time LED 3 was updated
  
  beating = true;          // status of each process for easy boolean checks
  warning = false;         // status of each process for easy boolean checks
  expired = false;

  //Serial.println(gameStarted);

}

 // check to see if it's time to blink the LED; that is, is the difference
 // between the current time and last time we blinked the LED bigger than
 // the interval at which we want to blink the LED.
 
 // Check to see if it is time to flash the HEARTBEAT
 if (millis() - previousMillis > timeHeartbeat){

     // Check to see if it is time to turn on the WARNING LED
     if (millis() - previousMillis2 > timeWarning) {
       warning = true;     // set flag so warning LED will start flashing with heartbeat
      // digitalWrite(ledPin2, HIGH);
       
       // Check to see if it is time to turn on the EXPIRED LED
       // Once this LED is turned on, it stays on until reset
       if(millis() - previousMillis3 > timeExpired){
         expired = true;   // set flag so warning LED won't flash anymore
         beating = false;  // set flag so heartbeat LED won't flash anymore
         if (gameStarted == 1)
         {
         gameStarted = 2;   
         }               
         previousMillis3 = millis();   // remember the last time we blinked the LED
       }
     previousMillis2 = millis();       // remember the last time we blinked the LED
     }
     previousMillis = millis();        // remember the last time we blinked the LED
 }

}
