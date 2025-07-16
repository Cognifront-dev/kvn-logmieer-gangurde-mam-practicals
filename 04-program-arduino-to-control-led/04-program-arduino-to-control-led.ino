#define LED1 8 
#define LED2 9

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
}

void loop() {
  digitalWrite(LED2, HIGH);  
  delay(1000);               
  digitalWrite(LED2, LOW); 
  delay(1000);   
}
