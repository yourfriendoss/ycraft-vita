# ycraft
my top down sandbox game

## compile
```
$ make
```

a binary will be placed in the `bin` folder

## compile psvita
```
mkdir vita
cd vita
cmake ..
make
```
and you will get a file called `ycraft-vita.vpk`, move it to `ux0:VPK/` with vitashell FTP, and run it from vitashell.

## dependencies
SDL2, SDL2_ttf, SDL2_image, SDL2_mixer, libcurl

vitasdk for the vita build

### sdl2 autobuild (manual)
run `sdlautoinstall.sh` inside the repo

basically use this if you get issues about traingle rendering, means that your apt-get / package manager sdl version is a couple years old lmfao

### deps for ubuntu based systems
**i really reccomend the manual build above!! this will most likely have issues**

```
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-mixer-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libcurl4-openssl-dev
```

## controls
WASD - move player

left click - delete block

right click - place block

t - open chat

e - open/close inventory

## screenshots
<img src="/img/screenshot.png">

## known bugs
1. (PC & XBOX CONTROLLER ONLY) moving the joystick for mouse is kind of broken, idk wtf's wrong with it, it seems to be missing whole 3 axis from the 2nd joystick, it launches onto LT on the xbox one controller instead also is recognized as "8BitDo FC30 Pro".. so fucking weird idk
