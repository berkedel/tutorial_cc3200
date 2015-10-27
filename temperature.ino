// ref: http://www.geocities.jp/zattouka/GarageHouse/micon/Arduino/Temp/Temp.htm

int sensorPin = A2; // センサーはアナログの２番ピン
int sensorValue = 0; // 
int tempVoltage = 0;
int temperature = 0;

void setup()
{
  Serial.begin(115200); // パソコンとシリアル通信の準備を行う
}

void loop()
{
  sensorValue = analogRead(sensorPin); // アナログ２番ピンからセンサー値を読み込む
  tempVoltage = map(sensorValue, 0, 4095, 0, 1450); // センサー値を電圧に変換する
  temperature = map(tempVoltage, 300, 1600, -30, 100); // 電圧から温度に変換する
  Serial.println(temperature); // 値をパソコンに送信
  delay(1000); // １秒ごとに繰り返す
}
