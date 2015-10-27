#include <WiFi.h>

char WIFI_SSID[] = "Your-WiFi-SSID"; // 無線LANルーターのSSID名称
char WPA_PASSWORD[] = "Your-WPA-Password"; // 無線LANルーターの接続パスワード

WiFiClient client;

void setup()
{
  Serial.begin(115200);
  
  int wifiStatus = WiFi.status(); // 接続状況を取得
  
  if (wifiStatus == WL_NO_SHIELD) { // 無線アダプターのシールドがなかった場合
    Serial.println("Error: WiFi adapter is not available.");
    
    while (true);
  }
  
  Serial.println("WiFi adapter is available.");
  
  while (wifiStatus != WL_CONNECTED) { // 無線LANルーターと接続ができるまでループ
    Serial.print("WiFi: ");
    wifiStatus = WiFi.begin(WIFI_SSID, WPA_PASSWORD); // 接続を開始
    
    if (wifiStatus == WL_CONNECTED) { // 接続済み
      Serial.println("Ok");
    }
    else {
      Serial.println("Fail");
    }
    
    delay(2000); // 2秒待つ
  }
  
  Serial.println("Setup complete.\n");
}

void loop()
{
  
}
