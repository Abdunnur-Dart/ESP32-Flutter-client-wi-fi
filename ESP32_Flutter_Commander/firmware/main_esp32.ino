/*
 * PROJECT: ESP32 Universal Commander
 * AUTHOR: [Имя Твоего Сына]
 * HARDWARE: ESP32-C3 Super Mini
 */

#include <WiFi.h>
#include <WebServer.h>

// --- НАСТРОЙКИ СЕТИ ---
const char* ssid = "YOUR_WIFI_SSID";      // Имя твоего Wi-Fi
const char* password = "YOUR_WIFI_PASSWORD"; // Пароль Wi-Fi

// --- НАСТРОЙКИ ПИНОВ (Для ESP32-C3 Super Mini) ---
#define LED_PIN 8      // Встроенный светодиод (проверь распиновку своей платы, может быть 2 или 8)
#define SENSOR_PIN 1   // Пример аналогового входа

WebServer server(80);  // Создаем веб-сервер на порту 80

// Переменные состояния
bool ledState = false;
int brightness = 0;

// --- ФУНКЦИИ ОБРАБОТКИ ЗАПРОСОВ ---

// 1. Главная страница (для проверки через браузер)
void handleRoot() {
  server.send(200, "text/plain", "ESP32 Commander is Online! Ready for Flutter connection.");
}

// 2. Переключение светодиода (ON/OFF)
void handleToggle() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? LOW : HIGH); // LOW включает диод на Super Mini (инверсия)
  server.send(200, "application/json", "{\"status\":\"success\", \"led\":" + String(ledState) + "}");
}

// 3. Управление яркостью (Slider)
void handlePWM() {
  if (server.hasArg("val")) {
    brightness = server.arg("val").toInt();
    // Эмуляция PWM (на C3 Super Mini аналоговый вывод ограничен, это пример логики)
    // analogWrite(LED_PIN, brightness); 
    server.send(200, "application/json", "{\"status\":\"success\", \"value\":" + String(brightness) + "}");
  } else {
    server.send(400, "text/plain", "Missing value");
  }
}

// 4. Чтение данных (JSON для Flutter)
void handleStatus() {
  int sensorValue = analogRead(SENSOR_PIN); // Читаем "датчик"
  // Формируем JSON ответ
  String json = "{";
  json += "\"uptime\":" + String(millis()) + ",";
  json += "\"sensor\":" + String(sensorValue) + ",";
  json += "\"led\":" + String(ledState);
  json += "}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); // Выключить (инверсия)

  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); // ЭТОТ IP НУЖНО ВВЕСТИ В ПРИЛОЖЕНИИ

  // Настройка путей (Маршрутов)
  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.on("/pwm", handlePWM);
  server.on("/status", handleStatus);

  server.begin();
}

void loop() {
  server.handleClient();
}
