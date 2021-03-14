// constant variables
const int inputPin = 12; // input pin for the voltage probe
const int outputPin = 13; // output pin for LED
const int buzzerPin = 8; //needs to be changed to the correct value

// other variables:
int ledState = LOW; // set the ledState
int voltage; // just to save the value detected
int lowerThreshold = 3.07; // these can be changed to 2.56 and 2.76 for the beding
int upperThreshold = 3.31;


void setup() {
  // need to be set to use the same speed serial connection in order to get any sort of intelligible data
  Serial.begin(9600);
  pinMode(inputPin, INPUT); // set arduino pin to input mode
  pinMode(outputPin, OUTPUT); // set arduino pin to output mode
  pinMode(buzzerPin, OUTPUT); // set arduino pin to output mode
}

void loop() {
  voltage = digitalRead(inputPin); // check the voltage detected
  if(voltage > lowerThreshold && voltage < upperThreshold) {
    digitalWrite(outputPin, HIGH); // change the LED state to HIGH
    for(i=1; i<=10; i=i+1){
      digitalWrite(buzzerPin, HIGH); // turn buzzer on
      delay(1)
      digitalWrite(buzzerPin, LOW); // turn buzzer off
    }
  else{
    digitalWrite(outputPin, LOW); // change the LED state to LOW
  }
  }
}
