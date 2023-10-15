byte Geschwindigkeit = 0;


void setup() {
  pinMode(9, INPUT); 
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  
 if(digitalRead(9)){
  Geschwindigkeit = 0;
  }

  if(digitalRead(10) && (Geschwindigkeit < 255)){
  Geschwindigkeit++;
  }

  if(digitalRead(11) && (Geschwindigkeit > 0)){
  Geschwindigkeit--;
  analogWrite(6, Geschwindigkeit);
  delay(40);
  }

  if(digitalRead(12)){
  Geschwindigkeit = 255;
  analogWrite(6, Geschwindigkeit);
  delay(40);
  }
  
 analogWrite(6, Geschwindigkeit);
 delay(10);
 
}
