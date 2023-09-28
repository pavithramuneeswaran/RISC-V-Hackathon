#define echo 14//assinging ardunino pin for echo
#define led 5 //assigning Arduino Pin for LED
#define buzzer 4/*assigning ardunino pin for buzzer
#define trig 11
Arduino Pin for buzzer */
int duration;
void setup(){
  /* assigning pin modes for the components */
pinMode(11, OUTPUT);//assingning pin 11 for trigpin*/
pinMode(14, INPUT);//assigning pin 14 for echopin*/
pinMode(led, OUTPUT);
pinMode(buzzer, OUTPUT);
}
void loop()
{
 long dist; /* defining the variable that will store the distance value*/
  digitalWrite(11, LOW); // assigning LOW state to trigger pin
  delayMicroseconds(2); 
  digitalWrite(11, HIGH);// assigning HIGH state to trigger pin */
  delayMicroseconds(10); /* for 10 microseconds trigger pin will remain in  HIGH*/
  digitalWrite(11, LOW); // assigning the trigger pin the LOW state
  duration = pulseIn(14, HIGH);/*detecting the  pulse in the HIGH state  of sensor */
  dist = (duration / 2) / 29.1; /* formula for calculating the distance in cm*/
  if (dist <= 10) // if hand comes in 10 cm range of sensor
  {
    digitalWrite(led, HIGH);/* turn the LED on */
    digitalWrite(buzzer, HIGH);/* turn in the doorbell*/
    delay(700);/* the doorbell will remain on till 7 milliseconds*/
    digitalWrite(led,LOW);/* turn off the LED*/
    digitalWrite(buzzer, LOW);/* turn off the doorbell*/

    delay(5000);/* the doorbell will remain off till 5 seconds after first ring*/
  }
  else { /* if there is no hand in the 10 cm range*/
    digitalWrite(led, LOW);/* keep the LED off*/
     digitalWrite(buzzer, LOW); /* keep the doorbell off*/
    delay(700);
  }
}