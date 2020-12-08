int previousValue = 0;
int currentValue = 0;
int LEDStatus = 1;
  
void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //Sets the pin to be an output
  pinMode(3, INPUT); //sets pin 3 to input
  pinMode(4, OUTPUT); // sets pin 4 to output

  digitalWrite(13, HIGH); //Sets the third pin to high
  
}

void loop() {
  // put your main code here, to run repeatedly:
  currentValue = digitalRead(3);

  if(previousValue == 0 && currentValue == 1){
    //debounce
    delay(10);

    //change the status of the output
    LEDStatus = (LEDStatus - 1) * -1;
    digitalWrite(4, LEDStatus);
    Serial.print("Value of LED Status: ");
    Serial.println(LEDStatus);
  } else if (previousValue == 1 && currentValue == 0){
    //debounce
    delay(10);
  }

  previousValue = currentValue;

}
