/**
 *  This program needs Arduino IRremote Library to work which you
 *  can find in here: https://github.com/z3t0/Arduino-IRremote
 * 
 *  Note: IRremote Library defines IR LED output pin named "IR_SEND_PIN" statically in IRremote.h
 *  If you want to use another pin you should change it manually from IRremote.h
 */
#include <IRremote.h>   
                                          
IRsend IrSender;

/**
 * IR Codes that your tv reacts
 */
#define DOWN 0x205D40BF
#define UP 0x205DC03F
#define LEFT 0x205D708F
#define RIGHT 0x205D58A7
#define OK 0x205DE01F

/**
 * Joystick's pins
 */
#define SW_PIN 8 // should be digital
#define X_PIN 0  // should be analog
#define Y_PIN 1  // should be analog

void setup() {
  pinMode(SW_PIN, INPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);

}  
                               
void loop()  
{  
  int x_val = analogRead(X_pin);
  int y_val = analogRead(Y_pin);
  int b_val = digitalRead(SW_PIN);

  if(b_val == 0){
    IrSender.sendNEC(OK, 32);
  }else if(x_val < 10){
    IrSender.sendNEC(UP, 32);
  }else if(x_val > 1000){
    IrSender.sendNEC(DOWN, 32);
  }else if(y_val > 1000){
    IrSender.sendNEC(LEFT, 32);
  }else if(y_val < 10){
    IrSender.sendNEC(RIGHT, 32);
  }

  for (unsigned int i = 0; i < 3; i++){
    digitalWrite(LED_BUILTIN, HIGH)
    delay(50);
    digitalWrite(LED_BUILTIN, LOW)
  }
  
  delay(100);
}  
