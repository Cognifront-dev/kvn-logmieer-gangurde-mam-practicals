const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int redPot = A0;
const int greenPot = A1;
const int bluePot = A2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int redVal = analogRead(redPot);
  int greenVal = analogRead(greenPot);
  int blueVal = analogRead(bluePot);

  redVal = map(redVal, 0, 1023, 0, 255);
  greenVal = map(greenVal, 0, 1023, 0, 255);
  blueVal = map(blueVal, 0, 1023, 0, 255);

  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);

  delay(10); 
}
