#include <DHT.h>

#define DHTPIN 4      // Chân kết nối DHT22
#define DHTTYPE DHT22 // Loại cảm biến
#define LEDPIN 2      // Chân kết nối LED

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature(); // Đọc nhiệt độ
  if (isnan(temp)) {
    Serial.println("Lỗi đọc cảm biến!");
    return;
  }

  Serial.print("Nhiệt độ: ");
  Serial.print(temp);
  Serial.println("°C");

  int delayTime = map(temp, 20, 40, 1000, 100); // Điều chỉnh tốc độ LED
  delayTime = constrain(delayTime, 100, 1000);

  digitalWrite(LEDPIN, HIGH);
  delay(delayTime);
  digitalWrite(LEDPIN, LOW);
  delay(delayTime);
}
