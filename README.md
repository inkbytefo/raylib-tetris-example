# Tetris (Raylib / C++)

Raylib öğreneyim diye başladım, sonunda elimde çalışan bir Tetris oldu. Harici bağımlılık yok, library'i CMake kendisi indiriyor, derleniyor, çalışıyor. Hepsi bu.

## Ekran Görüntüleri

| Başlarken | Biraz sonra |
|-----------|-------------|
| ![Başlarken](screenshots/gameplay-start.png) | ![Biraz sonra](screenshots/gameplay-mid.png) |

## Nasıl Derlenir

CMake 3.20+ ve bir C++17 derleyicisi yeterli. Raylib'i ayrıca kurmana gerek yok, CMake ilk derlemede kendi indiriyor.

```bash
git clone https://github.com/inkbytefo/raylib-tetris-example.git
cd raylib-tetris-example
cmake -B build
cmake --build build
```

İlk derleme biraz uzun sürebilir çünkü Raylib'i de derliyor. Sonraki derlemeler hızlı.

## Kontroller

| Tuş | Ne yapar |
|-----|----------|
| ← → | Sağa / sola hareket |
| ↑ | Döndür |
| ↓ | Yavaşça aşağı |
| Boşluk | Anında düşür |

## Puanlama

Klasik Tetris sistemi, seviyeyle çarpılıyor:

- 1 satır → 100 × seviye
- 2 satır → 300 × seviye
- 3 satır → 500 × seviye
- 4 satır (Tetris!) → 800 × seviye

Her 1000 puanda seviye artıyor ve parçalar biraz daha hızlı düşmeye başlıyor. En hızlı noktada fark ediyorsun.

## Yapı

```
MyGame/
├── main.cpp        — pencere aç, döngüyü çalıştır
├── Game.cpp/h      — oyun mantığı, input, skor/seviye
├── Board.cpp/h     — 10×20 ızgara, satır temizleme
├── Tetromino.cpp/h — 7 parça, 4 yönlü rotasyon
└── Renderer.cpp/h  — çizim
```

## Kullanılan Şeyler

- C++17
- [Raylib 5.5](https://github.com/raysan5/raylib)
- CMake (FetchContent ile Raylib)
