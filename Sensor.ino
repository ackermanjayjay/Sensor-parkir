// Door Alarm Using Arduino UNO and Ultrasonic Sensor
// Code to be used in the Text sub-window of tinkercad.com circuit page

int trigger_pin = 5;
int echo_pin = 6;
int buzzer_pin = 10;
int buzzer_pin2=9;
int time;
int distance; 
void setup() 
{
        Serial.begin (9600); 
        pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
        pinMode (buzzer_pin, OUTPUT);
            pinMode (  buzzer_pin2, OUTPUT);

}
void loop() 
{
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

  if (distance <= 10) 
        {
        Serial.println (" Door Open ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, HIGH);
           digitalWrite (buzzer_pin2, HIGH);

        delay (500);
        }
  else {
        Serial.println (" Door closed ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, LOW);
               digitalWrite (buzzer_pin2, LOW);

        delay (500);        
       } 
}
