#include <WiFi.h>
#include "Twitter.h"

char WIFI_SSID[] = "Your-WiFi-Router-SSID"; // 無線LANルーターのSSID名称
char WPA_PASSWORD[] = "Your-WiFi-Router-Password"; // 無線LANルーターの接続パスワード

char server[] = "api.twitter.com"; // TwitterのAPI先
char uri[] = "/1.1/statuses/update.json"; // 使用APIのuri
int port = 443; // HTTPS使用
const static char consumer_key[] PROGMEM = ":: your consumer key ::";
const static char consumer_secret[] PROGMEM = ":: your consumer secret ::";
const static char access_token[] PROGMEM = ":: your access token ::";
const static char token_secret[] PROGMEM = ":: your token secret ::";

char buffer[512];
Twitter twitter(buffer, sizeof(buffer));

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
  
  twitter.set_twitter_endpoint(PSTR(server),
                               PSTR(uri),
                               port);
  twitter.set_client_id(consumer_key, consumer_secret);
  twitter.set_account_id(PSTR(access_token), PSTR(token_secret));
  
  delay(500);
  
  if (twitter.is_ready()) {
    twitter.post_status("Hello from CC3200!"); // 任意の呟き
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

}
