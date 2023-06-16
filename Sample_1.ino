#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const int menuButtonPin = A0;
const int relayPin = 3;

float temperature;
float humidity;
int moisture;

const int moistureThreshold = 500; // Adjust this value to your desired moisture threshold

// Watering duration
const int wateringDuration = 3000;     // Adjust this value to set the watering duration in milliseconds

int currentOption = -1;
const int numOptions = 3;
const char* menuOptions[] = {"Temperature", "Humidity", "Soil Moisture"};

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  pinMode(menuButtonPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Menu");
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  moisture = analogRead(A1);
  
  int buttonState = digitalRead(menuButtonPin);
  
  if (buttonState == LOW) {
    currentOption++;
    if (currentOption >= numOptions) {
      currentOption = 0;
    }
    
    delay(200); // Debounce delay
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(menuOptions[currentOption]);
  }
  
  switch (currentOption) {
    case 0: // Temperature
      {
        temperature = dht.readTemperature();
        lcd.setCursor(0, 1);
        lcd.print("Temp: ");
        lcd.print(temperature);
        lcd.print(" C");
        
        
        break;
      }
    case 1: // Humidity
      {
        humidity = dht.readHumidity();
        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print(" %");
        
        break;
      }
    case 2: // Soil Moisture
      {
        moisture = analogRead(A1);
        lcd.setCursor(0, 1);
        lcd.print("Moisture: ");
        lcd.print(moisture);
        
        
        
        break;
      }
    default: // Menu
      {
        // Display menu title only
        lcd.setCursor(0, 1);
        lcd.print("                ");
        break;
      }
  }
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  
    Serial.print("Soil Moisture: ");
    Serial.println(moisture);
    
    if (moisture < moistureThreshold) {
      digitalWrite(relayPin, HIGH); // Activate the relay (turn on the pump)
      delay(wateringDuration);  
      digitalWrite(relayPin, LOW); // Deactivate the relay (turn off the pump)
    }
  
     // Send data to Raspberry Pi
    Serial.print("Raspberry Pi: ");
    Serial.print(temperature);
    Serial.print(",");
    Serial.print(humidity);
    Serial.print(",");
    Serial.println(moisture);
          
          
    delay(1000); // Delay between readings
}
