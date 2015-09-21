int dropPin = 1;
int cameraPin = 2;
int buttonPin = 4;

void setup() {
 //establish motor direction toggle pins
 pinMode(12, OUTPUT); //CH A 
 pinMode(13, OUTPUT); //CH B 
 //establish motor brake pins
 pinMode(9, OUTPUT); //brake (disable) CH A
 pinMode(8, OUTPUT); //brake (disable) CH B

 pinMode(cameraPin, OUTPUT);
 pinMode(dropPin, OUTPUT);
 digitalWrite(cameraPin, LOW);
 digitalWrite(dropPin, LOW);

 pinMode(buttonPin, INPUT);
}

void waitForButton() {
  // Loop constantly until button press detected
  while (digitalRead(buttonPin) == LOW) {
    delay(10);
  }
}

void moveMotor(int cycles, boolean forward) {
 int delaylength = 5;

 for(int cyclesCompleted=0; cyclesCompleted<cycles; cyclesCompleted++) {
   digitalWrite(9, LOW);  //ENABLE CH A
   digitalWrite(8, HIGH); //DISABLE CH B
   digitalWrite(12, HIGH);   //Sets direction of CH A
   analogWrite(3, 255);   //Moves CH A
   delay(delaylength);
   digitalWrite(9, HIGH);  //DISABLE CH A
   digitalWrite(8, LOW); //ENABLE CH B
   
   if(forward == true)
     digitalWrite(13, LOW);   //Sets direction of CH B
   else
     digitalWrite(13, HIGH);   //Sets direction of CH B

   analogWrite(11, 255);   //Moves CH B
   delay(delaylength);
   digitalWrite(9, LOW);  //ENABLE CH A
   digitalWrite(8, HIGH); //DISABLE CH B
   digitalWrite(12, LOW);   //Sets direction of CH A
   analogWrite(3, 255);   //Moves CH A
   delay(delaylength);
   digitalWrite(9, HIGH);  //DISABLE CH A
   digitalWrite(8, LOW); //ENABLE CH B
   
   if(forward == true)
     digitalWrite(13, HIGH);   //Sets direction of CH B
   else
     digitalWrite(13, LOW);
   
   analogWrite(11, 255);   //Moves CH B
   delay(delaylength);
 }
}

void pulsePin(int pin) {
 digitalWrite(pin, HIGH);
 delay(10); // leave it on 0.01 seconds just in case
 digitalWrite(pin, LOW);
}

// Anything we want to loop put here
void loop() {
  waitForButton();
  moveMotor(200, true);
  pulsePin(cameraPin);
  moveMotor(100, true);
  pulsePin(dropPin);
  moveMotor(100, true);
  pulsePin(dropPin);
  moveMotor(100, true);
  pulsePin(dropPin);
  moveMotor(100, true);
  // delay(1000);

 // moveMotor(100, false);
}
