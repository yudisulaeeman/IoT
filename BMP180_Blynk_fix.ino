#define BLYNK_TEMPLATE_ID "TMPLHcaAXer4"
#define BLYNK_DEVICE_NAME "Anti Kebakaran"
#define BLYNK_AUTH_TOKEN "XrJgQ8k0Y_5gtb9GoFstT5rEuXaQN-y6"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
float suhu;

char ssid[] = "Juctice";  // type your wifi name
char pass[] = "jjjjgggg";  // type your wifi password
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;


void sendSensor()
{
  float suhu = bmp.readTemperature();
  Serial.print("Suhu=");  //kirim serial "Suhu"
  Serial.println(suhu);     //kirim serial nilai suhu
  Blynk.virtualWrite(V2, suhu);
}

void setup()
{
  Serial.begin(115200);
  if (!bmp.begin()) {
  Serial.println("Sensor suhu belum terkoneksi");
  while (1) {}
  }
  
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
