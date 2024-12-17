//STATUS RED, GREEN, O2 HEATING, RUN and TEST LED

int RED =38; 
int GREEN=39;
int O2_HEATING=40;
int RUN=41;
int TEST=42;

void setup()
{
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(O2_HEATING,OUTPUT);
pinMode(RUN,OUTPUT);
pinMode(TEST,OUTPUT);
}

void loop()
{
digitalWrite(RED,HIGH);
delay(100);
digitalWrite(RED,LOW);

digitalWrite(GREEN,HIGH);
delay(100);
digitalWrite(GREEN,LOW);

digitalWrite(O2_HEATING,HIGH);
delay(100);
digitalWrite(O2_HEATING,LOW);



digitalWrite(TEST,HIGH);
delay(100);
digitalWrite(TEST,LOW);

digitalWrite(RUN,HIGH);
delay(100);
digitalWrite(RUN,LOW);
delay(100);

}