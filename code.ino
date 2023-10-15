byte Bitmuster;

byte Zahlen[] = {
  B00000000, //alle aus
  B00000100, //1
  B00100001, //2
  B00100101, //3
  B01100011, //4
  B01100111, //5
  B01111011  //6
};


void setup() {
  DDRD  = B11100000;
  DDRB  = B00001111;
  PORTD = B00001000;
}


void loop() {

 while(PIND & B00001000){};
 
  randomSeed(analogRead(1)+micros());

  for(byte i = 0; i < 12; i++){

    Bitmuster = Zahlen[random(6)+1];
    PORTD = (Bitmuster << 5 | B00010000);
    PORTB = Bitmuster >> 3;
    delay(150);
  }

  Bitmuster = Zahlen[random(6)+1];

   for (byte i = 0; i < 4; i++){
    byte AlleAus = Zahlen[0];
    PORTD = (AlleAus << 5 | B0001000);
    PORTB = AlleAus >> 3;
    delay(200);

    PORTD = (Bitmuster << 5 | B0001000);
    PORTB = Bitmuster >> 3;
    delay(300);
  }
  delay(2500);
  PORTD = (Zahlen[0] << 5 | B0001000);
  PORTB = Zahlen[0] >> 3;
}
