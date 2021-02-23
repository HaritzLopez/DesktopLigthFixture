/*
 *  Desktop Light Fixture 
 *  By Haritz López (haritz@haritzlopez.es)
 *  
 *  This is the code for the Desktop Light Fixture project. The wiring is very simple.
 *  Each of the pots controls the PWM signal that drives each of the MOSFETs.
 */

int blue_pot = A0;    // Input pins for the pots. Each por must provide a 0 to 5 vsignal
int cold_pot = A1;    //   0v: LEDs of that particular color are off
int warm_pot = A2;    //   5v: LEDs of that particular color are at full brigthness

int pwm_blue = 9;     // Pins where PWM signals came out to drive the MOSFETs
int pwm_cold = 5;
int pwm_warm = 6;

int blue_value = 0;  // This variables are used to store the value to be
int cold_value = 0; 
int warm_value = 0;

void setup() {
  pinMode(pwm_blue, OUTPUT);  // Set each of the output pins
  pinMode(pwm_cold, OUTPUT);
  pinMode(pwm_warm, OUTPUT);
}


void loop() {

  blue_value = analogRead(blue_pot);  // Read analog values of the pots
  cold_value = analogRead(cold_pot);
  warm_value = analogRead(warm_pot);

  // The analogWrite function, outputs an PWM encoded analog value in the selected pin. The 
  // Function inputs the output pin number and a value that goes from 0 to 255 corresponding to a
  // 0% duty cycle to a 100% duty cycle. 
  // The reading from the pots gives a value from 0 to 1023, being 0 when 0v are read
  // and 1023 when 5v are read. 
  // Since the input of the pots and the PWM output duty cycle functions range do not match
  // the map function is used to map input pots' value range to output PWM's value range. 
  // An offset of 5 is set to avoid low frequency flikering in the LEDs due to noise. 
   
  analogWrite(pwm_blue,map(blue_value, 5, 1023, 0, 255));
  analogWrite(pwm_cold,map(cold_value, 5, 1023, 0, 255));
  analogWrite(pwm_warm,map(warm_value, 5, 1023, 0, 255));
  
  delay(200);  // This delay kills pot response, but filters fliker in the pots readings. 
               // If instant response is needed, this delay might be removed and some other
               // filtering technique be used in the analogReads.
}
