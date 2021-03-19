// constant variables
const int inputPin = 14; // input pin for the voltage probe
const int outputPin = 1; // output pin connected to the LED
const int buzzerPin = 2; // output pin connected to the buzzer

// other variables:
int voltage; // generated now to later be used for the voltage deteced
// set varialbes for the upper and lower voltage threshold which have been calcualted
int lowerThreshold = 3.07;
int upperThreshold = 3.31;
// these can be changed to 2.56 and 2.76 for the beding


void setup() {
  // need to be set to use the same speed serial connection in order to get any sort of intelligible data
  Serial.begin(9600);
  pinMode(inputPin, INPUT); // set the arduino pin for the probe to input mode
  pinMode(outputPin, OUTPUT); // set the arduino pin for the LED to output mode
  pinMode(buzzerPin, OUTPUT); // set the arduino pin for the buzzer to output mode
}

void loop() {
  voltage = digitalRead(inputPin); // save the probe value deteced
  //check if the voltage value recorded is between the thresholds values created
  if(voltage > lowerThreshold && voltage < upperThreshold) {
    digitalWrite(outputPin, HIGH); // change the LED state to HIGH
    // alternate the buzzer bettween on and off
    for(i=1; i<=10; i=i+1){
      digitalWrite(buzzerPin, HIGH);
      delay(1)
      digitalWrite(buzzerPin, LOW);
    }
  else{
    digitalWrite(outputPin, LOW); // change the LED state to LOW
  }
  }
}
