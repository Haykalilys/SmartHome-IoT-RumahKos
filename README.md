# SmartHome-IoT-RumahKos
# Proyek Akhir Komunikasi Antar Perangkat – Smart Home IoT

## 1. Judul & Ringkasan Sistem

Smart Home IoT untuk Monitoring dan Kontrol Rumah Kos 3 Kamar Berbasis MQTT

Sistem ini dirancang untuk membantu pemilik rumah kos memantau dan mengontrol penggunaan listrik pada rumah kos 3 kamar secara jarak jauh tanpa menggunakan kamera. Sistem mampu memonitor status lampu di setiap kamar, penggunaan mesin cuci, serta pompa air, dan memungkinkan pengendalian mesin cuci serta pompa air melalui dashboard web berbasis IoT menggunakan protokol MQTT.

---

## 2. Hardware dan Software yang Digunakan

### Hardware

* ESP32 (3 unit)
* Sensor Arus ACS712 / PZEM-004T
* Relay 2 Channel
* Lampu AC
* Mesin Cuci
* Pompa Air
* Router WiFi
* Kabel jumper dan breadboard

### Software / Tools

* Arduino IDE
* MQTT Broker (Mosquitto / HiveMQ)
* Node-RED Dashboard
* GitHub
* Fritzing / Draw.io

---

## 3. Gambar Rangkaian (Wiring Diagram)

**Deskripsi:**

* Sensor arus terhubung ke pin ADC ESP32
* Relay terhubung ke pin digital ESP32
* ESP32 terhubung ke WiFi Router

*(Lampirkan gambar wiring_diagram.png di folder hardware/)*

---

## 4. Arsitektur Aplikasi dan Jaringan

### Diagram Arsitektur

```
[Lampu]     [Mesin Cuci]     [Pompa]
   |             |             |
[Sensor]      [Relay]       [Relay]
      \        |        /
           [ ESP32 ]
                |
              WiFi
                |
          [ MQTT Broker ]
                |
          [ Dashboard Web ]

```

*(Lampirkan gambar architecture.png di folder arsitektur/)*

---

## 5. Topik dan Payload MQTT

### Topic

* rumah_kos/kamar1/lampu/status
* rumah_kos/kamar2/lampu/status
* rumah_kos/kamar3/lampu/status
* rumah_kos/mesincuci/status
* rumah_kos/mesincuci/kontrol
* rumah_kos/pompa/status
* rumah_kos/pompa/kontrol

### Payload Status

```json
{
  "status": "ON",
  "arus": 0.45
}
```

### Payload Kontrol

```json
{
  "perintah": "OFF"
}
```

---

## 6. Cara Instalasi Sistem

1. Install Arduino IDE
2. Tambahkan board ESP32
3. Install library WiFi dan PubSubClient
4. Setup MQTT Broker
5. Upload kode ke ESP32
6. Import flow Node-RED

---

## 7. Cara Pengoperasian dan Pengujian

### Pengoperasian

* Akses dashboard web
* Pantau status perangkat
* Tekan tombol ON/OFF untuk mesin cuci dan pompa

### Pengujian

| No | Pengujian      | Hasil            |
| -- | -------------- | ---------------- |
| 1  | Lampu menyala  | Status ON tampil |
| 2  | Mesin cuci OFF | Relay mati       |
| 3  | Pompa ON       | Relay aktif      |

---

## 8. Contoh Hasil Pengoperasian dan Pengujian

### a. Foto Perangkat

*(Lampirkan foto perangkat di folder testing/)*

### b. Tangkapan Layar Dashboard

*(Lampirkan screenshot dashboard di folder dashboard/)*

---

## 9. Pembagian Tugas Kelompok

* Anggota 1: Hardware & Wiring
* Anggota 2: MQTT & ESP32
* Anggota 3: Dashboard & Dokumentasi

---

## 10. Penutup

Sistem Smart Home IoT ini berhasil memenuhi kebutuhan pemantauan dan pengendalian perangkat listrik rumah kos secara jarak jauh dengan aman dan efisien menggunakan protokol MQTT.

