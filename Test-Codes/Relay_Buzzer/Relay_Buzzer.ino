//STATUS RED, GREEN, O2 HEATING, RUN and TEST LED

int relay =4; 
int buzz=5;


void setup()
{
pinMode(relay,OUTPUT);
pinMode(buzz,OUTPUT);

}

void loop()
{
digitalWrite(relay,HIGH);
delay(500);
digitalWrite(relay,LOW);
delay(500);

digitalWrite(buzz,HIGH);
delay(500);
digitalWrite(buzz,LOW);
delay(500);



}