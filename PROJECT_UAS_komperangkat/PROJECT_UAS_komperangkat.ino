#include <WiFi.h>
#include <PubSubClient.h>

// ================= WIFI WOKWI =================
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ================= MQTT =================
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// ================= PIN =================
#define LED_LAMPU  2
#define LED_MESIN  4
#define LED_POMPA  5
#define POT_LAMPU  34

// ================= WIFI =================
void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }
}

// ================= MQTT CALLBACK =================
void callback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  if (String(topic) == "rumah_kos/mesincuci/kontrol") {
    digitalWrite(LED_MESIN, msg == "ON");
  }

  if (String(topic) == "rumah_kos/pompa/kontrol") {
    digitalWrite(LED_POMPA, msg == "ON");
  }
}

// ================= MQTT RECONNECT =================
void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32-WOKWI")) {
      client.subscribe("rumah_kos/mesincuci/kontrol");
      client.subscribe("rumah_kos/pompa/kontrol");
    } else {
      delay(2000);
    }
  }
}

// ================= SETUP =================
void setup() {
  pinMode(LED_LAMPU, OUTPUT);
  pinMode(LED_MESIN, OUTPUT);
  pinMode(LED_POMPA, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  
}

// ================= LOOP =================
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int nilai = analogRead(POT_LAMPU);
  bool lampuOn = nilai > 2000;

  digitalWrite(LED_LAMPU, lampuOn);

  client.publish(
    "rumah_kos/kamar1/lampu/status",
    lampuOn ? "ON" : "OFF"
  );

  delay(3000);
}
