

#define VREF_MV 4930    // actual reference voltage of the board, in mV

#define  LED1 12
#define  LED2 11
#define  LED3 10
#define  LED4 9

#define Button A3

#define E_PIN 3
#define B_PIN 4
#define C_PIN 5
#define E_READ_PIN A0
#define B_READ_PIN A1
#define C_READ_PIN A2

#define SETTLE_DELAY 50
void setup ()
{
  pinMode(LED1,OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3,OUTPUT); 
  pinMode(LED4,OUTPUT); 
  pinMode(Button, INPUT);

}

void loop() {
  if(digitalRead(Button) == HIGH)
  testForNPN() ;
   if (digitalRead(Button)==LOW)
  testForPNP();
  
 delay(100);
  
}


/*
  Run test to see if we have an NPN BJT present
 */
boolean testForNPN() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
 

  // power the Base
  pinMode(B_PIN,OUTPUT);
  digitalWrite(B_PIN, HIGH);

  // test B->E
  pinMode(E_PIN,OUTPUT);
  digitalWrite(E_PIN, LOW);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  pinMode(E_PIN,INPUT);

  
  // reset base
  digitalWrite(B_PIN, LOW);
  pinMode(B_PIN,INPUT);


  if(ebaseReading>1000) {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW); 
    digitalWrite(LED4,LOW);
    return true ;
   
  } else {
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW); 
    digitalWrite(LED4,LOW);
    digitalWrite(LED1,HIGH);
    return false ; 
   
  }

}


/*
  Run test to see if we have an PNP BJT present
 */
boolean testForPNP() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
  int collectorReading;
  

 
  pinMode(B_PIN,OUTPUT);
  digitalWrite(B_PIN, LOW);

  // test E->B
  pinMode(E_PIN,OUTPUT);
  digitalWrite(E_PIN, HIGH);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  pinMode(E_PIN,INPUT);

  // test C->B
  pinMode(C_PIN,OUTPUT);
  digitalWrite(C_PIN, HIGH);
  delay(SETTLE_DELAY);
  cbaseReading = analogRead(B_READ_PIN);
  collectorReading = analogRead(C_READ_PIN);
  pinMode(C_PIN,INPUT);

  // reset base
  pinMode(B_PIN,INPUT);

  if(ebaseReading<100) {
    digitalWrite(LED4,HIGH);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW); 
    return true ; 
  } else {
    digitalWrite(LED3,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED4,LOW); 
    digitalWrite(LED1,LOW);
    return false ; 
      }
      

}
