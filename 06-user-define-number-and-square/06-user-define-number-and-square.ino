void setup() {
  Serial.begin(9600); 
  Serial.println("Enter a number to square:");
}

void loop() {
  if (Serial.available() > 0) {
    int num = Serial.parseInt();       
    int square = num * num;    

    Serial.print("The square of ");
    Serial.print(num);
    Serial.print(" is ");
    Serial.println(square);

    Serial.println("Enter another number to square:");
  }
}
