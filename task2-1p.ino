int ledPin = D7; // LED D7 is used to bink the first name

int buttonPin = D3; // pin D3 is used to control the push button

void setup() 
{
   // Sets the ledPin as output pin.
   
   pinMode( ledPin, OUTPUT);
   
   //Sets the buttonPin as input_pullup which means to use internal pull up resistor.
   
   pinMode( buttonPin, INPUT_PULLUP);
}

void loop() 
{
    
 // Tells the state of the button i.e. whether it is pressed or not.
    
 int buttonState = digitalRead(buttonPin);
    
 // If the button is pressed, the led will start blinking the first name in morse code.
    
 if( buttonState == LOW)
 {
     digitalWrite(ledPin, HIGH);
     delay(3s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(3s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(3s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(3s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(3s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(1s);
     digitalWrite(ledPin, LOW);
     delay(1s);
     
     digitalWrite(ledPin, HIGH);
     delay(3s);
     digitalWrite(ledPin, LOW);
     delay(1s);
 }   
 // When the button is not pressed, the led will be turned off.
     
 else 
 {
    digitalWrite(ledPin, LOW);
 }
     
     
 
}