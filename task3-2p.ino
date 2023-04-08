SYSTEM_THREAD(ENABLED);

int SENSOR_PIN = A0;

int analogvalue;

void setup() 
{
  Particle.variable("analogvalue", analogvalue);
}

void loop() 
{
   
  analogvalue = analogRead(SENSOR_PIN);
  
  if(analogvalue > 0)
  {
     String message = "Sunlight is falling on the terrarium";
     Particle.publish("sunlight_hit_terrarium", message, PRIVATE);
     delay(3000ms);
  }
  else
  {
     String message = "Sunlight has stopped falling on the terrarium";
     Particle.publish("sunlight_hit_terrarium", message, PRIVATE); 
     delay(3000ms);
  }
}