#include "DHT.h"          // Brings in the Adafruit DHT library so we can talk to the sensor

#define DHTPIN 2          // The Arduino pin the sensor's data (SDA) wire is connected to
#define DHTTYPE DHT22     // Tells the library which sensor model we are using

DHT dht(DHTPIN, DHTTYPE); // Create a sensor object named "dht" using the pin and type above

void setup() {
  Serial.begin(9600);     // Open serial communication at 9600 baud (speed) so we can print to the Serial Monitor
  Serial.println("DHT22 test!"); // Print a start-up message, only once
  dht.begin();            // Wake up the sensor and get the library ready to use it
}

void loop() {
  delay(2000);            // Wait 2 seconds between readings (the DHT22 is a slow sensor)

  float h = dht.readHumidity();      // Read humidity in percent (%)
  float t = dht.readTemperature();   // Read temperature in degrees Celsius (°C)

  if (isnan(h) || isnan(t)) {        // isnan() checks for "Not a Number", which means the read failed
    Serial.println("Failed to read from DHT sensor!"); // Tell the user something went wrong
    return;                          // Leave loop() early and skip the printing below for this cycle
  }

  Serial.print("Humidity: ");        // Print the label for humidity
  Serial.print(h);                   // Print the value (Arduino shows 2 decimals by default, e.g. 43.00)
  Serial.print(" % Temperature: ");  // Print the unit, then the label for temperature
  Serial.print(t);                   // Print the temperature value (e.g. 26.00)
  Serial.println(" °C");             // Print the unit and move to a new line
}
