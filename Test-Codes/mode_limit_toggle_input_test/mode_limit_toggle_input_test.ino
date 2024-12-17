/*mode switch input.
 Check and report working of the limit switch input.
 Check and report working of the toggle switch input.
*/

int mode =6;
int limit =47;
int toggle =48;

int mode1=0;
int limit1=0;
int toggle1=0;


void setup() {
Serial.begin(9600);
  pinMode(mode,INPUT);
  pinMode(limit,INPUT);
  pinMode(toggle,INPUT);
  // put your setup code here, to run once:

}

void loop()
 {
  // put your main code here, to run repeatedly:

mode1= digitalRead(mode);
Serial.print ("mode = ");
Serial.print (mode1);
Serial.print("\t");

limit1 =digitalRead(limit);
Serial.print("Limit = ");
Serial.print(limit1);
Serial.print("\t");

toggle1=digitalRead(toggle);
Serial.print("toggle = ");
Serial.println(toggle1);
delay(200);
}
