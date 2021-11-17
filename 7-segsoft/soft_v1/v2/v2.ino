#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 analog;

#define referenceValue    2.5

#define aPin 2  //        
#define bPin 3  //      _____
#define cPin 4  //     |  A  |
#define dPin 5  //   F |_____| B
#define ePin 6  //     |  G  |
#define fPin 7  //   E |_____| C
#define gPin 8  //        D     O dot
#define dpPin 9

#define c1Pin 10  // Common pin for digit 1
#define c2Pin 11 // Common pin for digit 2
#define c3Pin A0 // Common pin for digit 3
#define c4Pin A1 // Common pin for digit 4
#define c5Pin 12
#define c6Pin 13 


int flag1 = 0, flag2 = 0, timer = 0;
int Common = 1; //<Common=1; for Common anode> <Common=0; for Common cathode>
int On, Off, Off_C;
int DTime = 1; // Display timer
unsigned long Counter;
void setup() { // put your setup code here, to run once
  On = HIGH;
  Off = LOW;
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dpPin, OUTPUT);

  pinMode(c1Pin, OUTPUT);
  pinMode(c2Pin, OUTPUT);
  pinMode(c3Pin, OUTPUT);
  pinMode(c4Pin, OUTPUT);
  pinMode(c5Pin, OUTPUT);
  pinMode(c6Pin, OUTPUT);

  digitalWrite(c1Pin, LOW);
  digitalWrite(c2Pin, LOW);
  digitalWrite(c3Pin, LOW);
  digitalWrite(c4Pin, LOW);
  digitalWrite(c5Pin, LOW);
  digitalWrite(c6Pin, LOW);
  Serial.begin(9600);
  Serial.println("1");
  analog.begin();
  analog.setGain(GAIN_TWOTHIRDS);
  Serial.println("2");
}



void minus(bool dt=false) {
  digitalWrite( aPin, Off); //
  digitalWrite( bPin, Off);  //      
  digitalWrite( cPin, Off);  //      
  digitalWrite( dPin, Off); //      
  digitalWrite( ePin, Off); //      
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
  if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void one(bool dt=false) {
  digitalWrite( aPin, Off); //
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, On);  //      |
  digitalWrite( dPin, Off); //      |
  digitalWrite( ePin, Off); //      |
  digitalWrite( fPin, Off);
  digitalWrite( gPin, Off);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void two(bool dt=false) {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, Off); //  ____|
  digitalWrite( dPin, On);  // |
  digitalWrite( ePin, On);  // |____
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void three(bool dt=false) {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, On);  //  ____|
  digitalWrite( dPin, On);  //      |
  digitalWrite( ePin, Off); //  ____|
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void four(bool dt=false) {
  digitalWrite( aPin, Off); //
  digitalWrite( bPin, On);  // |    |
  digitalWrite( cPin, On);  // |____|
  digitalWrite( dPin, Off); //      |
  digitalWrite( ePin, Off); //      |
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void five(bool dt=false) {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, Off); // |
  digitalWrite( cPin, On);  // |____
  digitalWrite( dPin, On);  //      |
  digitalWrite( ePin, Off); //  ____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void six(bool dt=false) {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, Off); // |
  digitalWrite( cPin, On);  // |____
  digitalWrite( dPin, On);  // |    |
  digitalWrite( ePin, On);  // |____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void seven(bool dt=false) {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, On);  //      |
  digitalWrite( dPin, Off); //      |
  digitalWrite( ePin, Off); //      |
  digitalWrite( fPin, Off);
  digitalWrite( gPin, Off);
  if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void eight(bool dt=false) {
  digitalWrite( aPin, On); //  ____
  digitalWrite( bPin, On); // |    |
  digitalWrite( cPin, On); // |____|
  digitalWrite( dPin, On); // |    |
  digitalWrite( ePin, On); // |____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void nine(bool dt=false) {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  // |    |
  digitalWrite( cPin, On);  // |____|
  digitalWrite( dPin, On);  //      |
  digitalWrite( ePin, Off); //  ____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void zero(bool dt=false) {
  digitalWrite( aPin, On); //  ____
  digitalWrite( bPin, On); // |    |
  digitalWrite( cPin, On); // |    |
  digitalWrite( dPin, On); // |    |
  digitalWrite( ePin, On); // |____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, Off);
   if(dt){
    digitalWrite(dpPin, On);
  }
  else{
    digitalWrite(dpPin, Off);
  }
}

void showNumber(int x, bool dt=false) {

  switch (x) {
    case -1: minus(dt); break;
    case 1: one(dt);   break;
    case 2: two(dt);   break;
    case 3: three(dt); break;
    case 4: four(dt);  break;
    case 5: five(dt);  break;
    case 6: six(dt);   break;
    case 7: seven(dt); break;
    case 8: eight(dt); break;
    case 9: nine(dt);  break;
    default: zero(dt); break;
  }
}

void loop(){
int16_t adc0 = analog.readADC_SingleEnded(0);
float distance = (analog.computeVolts(adc0) - referenceValue)*6;
int mapped = distance*100;
//  Serial.print("Nowa wartosc ADC0: ");
//  Serial.println(adc0);
//  Serial.print("Nowa wartosc MAPPED: ");
//  Serial.println(mapped);
//  Serial.print("Nowa wartosc Volts: ");
//  Serial.println(analog.computeVolts(adc0));
//  
 for(uint8_t i = 0; i <10; ++i){
   if(mapped<0){
    showNumber(-1, false);
    digitalWrite(c1Pin, HIGH);
    delay(DTime);
    digitalWrite(c1Pin, LOW);
    delay(DTime);
  }
  showNumber((abs(mapped)/10000)%10, false);
    digitalWrite(c2Pin, HIGH);
    delay(DTime);
    digitalWrite(c2Pin, LOW);
    delay(DTime);
  showNumber((abs(mapped)/1000)%10, false);
    digitalWrite(c3Pin, HIGH);
    delay(DTime);
    digitalWrite(c3Pin, LOW);
    delay(DTime);
  showNumber((abs(mapped)/100)%10, true);
    digitalWrite(c4Pin, HIGH);
    delay(DTime);
    digitalWrite(c4Pin, LOW);
    delay(DTime);
  showNumber((abs(mapped)/10)%10, false);
    digitalWrite(c5Pin, HIGH);
    delay(DTime);
    digitalWrite(c5Pin, LOW);
    delay(DTime);
  showNumber(abs(mapped)%10, false);
    digitalWrite(c6Pin, HIGH);
    delay(DTime);
    digitalWrite(c6Pin, LOW);
    delay(DTime);
 }
  
}
