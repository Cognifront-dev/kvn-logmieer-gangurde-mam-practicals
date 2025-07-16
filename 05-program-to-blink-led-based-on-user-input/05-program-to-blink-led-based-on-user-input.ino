const int greenPin = 6;
const int yellowPin = 5;
const int redPin = 4;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);

    if (command == 'g') {
      digitalWrite(greenPin, HIGH); 
    } 
    else if (command == 'y') {
      digitalWrite(yellowPin, HIGH);  
    } 
    else if (command == 'r') {
      digitalWrite(redPin, HIGH); 
    } 
    else if (command == 'b') {
      for (int i = 0; i < 3; i++) {
        digitalWrite(greenPin, HIGH);
        delay(300);
        digitalWrite(greenPin, LOW);
        delay(300);
      }
    }
  }
}
