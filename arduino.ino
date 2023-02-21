int inch = 0;
int cm = 0;
int led
double readDistance(int triggerP, int echoP)
{
  pinMode(triggerP, OUTPUT); 
  digitalWrite(triggerP, LOW);
  delay(2000);
  digitalWrite(triggerP, HIGH);
  delay(1000);
  digitalWrite(triggerP, LOW);
  pinMode(echoP, INPUT);
  return pulseIn(echoP, HIGH);
}
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  cm = 0.01723 * readDistance(7, 7);
  inch = (cm / 2.54);
  if (cm>10cm)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
  }
  Serial.print(inch);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); 
}
