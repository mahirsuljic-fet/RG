# Računarska grafika (RG)

### [Prezentacije](./Prezentacije)
Profesorove prezentacije iz predmeta.

### [Vježbe](./Vjezbe)
Kod i primjeri sa vježbi.

### YouTube
#### Playliste
- [Essence of linear algebra](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
- [Linear Algebra for Computer Scientists](https://www.youtube.com/playlist?list=PLTd6ceoshprfZs1VIzGHDt-MYgVewC5tc)
#### Najbitniji videi
- [Transformation Matrices](https://www.youtube.com/watch?v=Cb4aoihvh-o&list=PLTd6ceoshprfZs1VIzGHDt-MYgVewC5tc&index=13)
- [3D Transformation Matrices](https://www.youtube.com/watch?v=G25aT8VFsNI&list=PLTd6ceoshprfZs1VIzGHDt-MYgVewC5tc&index=14)
- [Linear transformations and matrices](https://www.youtube.com/watch?v=kYB8IZa5AuE&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab&index=3)
- [Matrix multiplication as composition](https://www.youtube.com/watch?v=XkY2DOUCWMU&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab&index=4)


### [Skripta osnova/cheatsheet](./Skripta_osnova.pdf)

### Instalacija OpenGL (Linux)
Prvo je potrebno instalirati sljedeće pakete:
``` bash
sudo apt install mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
```
Nakon toga se može koristiti OpenGL.
OpenGL headeri se (po default-u) nalaze u direktoriji `/usr/include/GL/` uključuju pomoću `#include <GL/ime_headera.h>`.

Pri kompajliranju mora se linkati OpenGL koristeći sljedeće kompajler (gcc) argumente: `-lGL -lGLU -lglut`.

Primjer kompajliranja c++ programa *"test"* koji koristi OpenGl:
```bash
g++ test.cpp -o test -lGL -lGLU -lglut
```

### [Java alat](https://github.com/mahirsuljic-fet/RS/tree/main/Random/RacunarskaGrafika)
Ovo je manji alat koji sam napisao u Javi u sklopu predmeta [razvoj softvera](https://github.com/mahirsuljic-fet/RS).
Alat se sastoji od nekoliko klasa od kojih je (za korištenje) najbitnija `CoordinateSystem2D`.
Objekti ove klase predstavljaju 2D koordinatni sistem.
U koordinatni sistem se mogu dodavati tačke, primjenjivati osnovne transformacije (translacija, skaliranje, rotacija i smicanje) i iscrtavati.
Rezolucija iscrta se može povećati smanjivanjem granulacije.
Prikaz naravno nije savršen, budući da se vrši u terminalu, ali je dovoljno pribložan, a za tačne vrijednosti se mogu ispisati tačke u vektorskom obliku.
U [`Main`](https://github.com/mahirsuljic-fet/RS/blob/main/Random/RacunarskaGrafika/Main.java) se nalazi primjer korištenja programa.
Alat ima nedostataka, ali nadam se da koliko toliko može poslužiti.

Ukoliko neko pronađe grešaka ili bug-ova neka mi javi.
