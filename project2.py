import serial
import requests
import time

# Serial port configuration
port = '/dev/ttyACM0'
baudrate = 9600

# IFTTT webhook URLs
webhook_url_watered = 'https://maker.ifttt.com/trigger/plant_has_watered/with/key/dgxMYg5LwlEefwYkd82DQl'
webhook_url_temperature = 'https://maker.ifttt.com/trigger/temperature_not_optimum/with/key/dgxMYg5LwlEefwYkd82DQl'

# Connect to Arduino
ser = serial.Serial(port, baudrate)

# Constants
moistureThreshold = 500
minTemperature = 18
maxTemperature = 30

while True:
    # Read data from Arduino
    data = ser.readline().decode().strip()
    print("Received data:", data)

    # Check if the line starts with the expected prefix
    if data.startswith("Raspberry Pi:"):
        # Extract numerical values from the line
        values = data.split(":")[1].split(",")
        print("Extracted values:", values)
        if len(values) == 3:
            try:
                temperature = float(values[0])
                humidity = float(values[1])
                moisture = int(values[2])

            

                # Check if plant needs watering
                if moisture < moistureThreshold:
                    # Perform watering action here
                    print("Watering the plant...")

                    # Trigger IFTTT event for plant has been watered
                    response = requests.get(webhook_url_watered)
                    if response.status_code == 200:
                        print("Notification sent for plant has been watered.")
                    else:
                        print("Failed to send notification for plant has been watered.")

                # Check if temperature is not within the desired range
                if temperature < minTemperature or temperature > maxTemperature:
                    # Perform action for temperature not optimum
                    print("Temperature is not optimum for the plant.")

                    # Trigger IFTTT event for temperature not optimum
                    response = requests.get(webhook_url_temperature)
                    if response.status_code == 200:
                        print("Notification sent for temperature not optimum.")
                    else:
                        print("Failed to send notification for temperature not optimum.")

            except ValueError:
                print("Invalid numerical value. Skipping this reading.")
        else:
            print("Invalid data format. Skipping this reading.")
    else:
        print("Invalid data format. Skipping this reading.")

    # Add a delay between readings
    time.sleep(5)  # Adjust the delay as needed

  
