# OOP_indie_studio_2019
![Pull Request](https://github.com/Madfish5415/OOP_indie_studio_2019/workflows/Pull%20Request/badge.svg?branch=master)
![Push](https://github.com/Madfish5415/OOP_indie_studio_2019/workflows/Push/badge.svg?branch=master)

##Epitech Year End Project created by:
- [@Madfish5415](https://github.com/Madfish5415)
- [@Mihobsine](https://github.com/Mihobsine)
- [@LucasFab](https://github.com/LucasFab)
- [@Alkeon](https://github.com/Alkeon)
- [@Juunie](https://github.com/Juunie)
- [@Mattox](https://github.com/matteofauchon)

## On Linux
### Requirements
To compile on Linux, make sure you have the `SFML 2.5 or more` installed. See commands below:  
#### Fedora
```
sudo dnf install SFML-devel
``` 
#### Ubuntu
```
sudo apt install libsfml-dev
``` 
You can find the last version [SFML 2.5.1](https://www.sfml-dev.org/download/sfml/2.5.1/index.php) here.

You also need the `Irrlicht` library installed. See commands below:  
#### Fedora
```
sudo dnf install libirrlicht-devel
```
#### Ubuntu
```
sudo dnf install libirrlicht-dev
```
Here a link to download [Irrlicht packages](http://irrlicht.sourceforge.net/?page_id=10).  
  
To build the project, you must install [CMake](https://cmake.org/download/).

--------
### Build
Run this command at the root of the project:
```
cmake -B build && make -C build
```
---
### Execute
Run this command at the root of the project:
```
./bomberman
```

---
## On Windows
### Requirements
You must download and extract the archive ([windows-dll.rar](https://mega.nz/file/rzQH2CqR#ZcenPwFPjuso1ZWwy9E3Y5ID2pxZ9V8LRyiOg7O_-Ec)) to the root of the project.  
  
To build the project, you must install [CMake](https://cmake.org/download/).

---
### Build
Run this command at the root of the project:
```
cmake -B build && cmake --build build
```

---
### Execute
Run this command at the root of the project:
```
.\bomberman.exe
```
