#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); // ch�n du lieu, loai DHT

void setup() {
  Serial.begin(115200);
  delay(1000);

  dht.begin();
  Serial.println("Dang ket noi voi ESP32");
}

void loop() {
  float NhietDo = dht.readTemperature(); //goi ham con
  float DoAm    = dht.readHumidity();    

  if (isnan(NhietDo) || isnan(DoAm)) {
    Serial.println("Loi doc cam bien!");
  } else {
    Serial.print("Nhiet do: ");
    Serial.print(NhietDo);
    Serial.print(" °C | Do am: ");
    Serial.print(DoAm);
    Serial.println(" %");
  }

  delay(2000);
}
