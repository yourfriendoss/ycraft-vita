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
and you will get a file called `ycraft-vita.vpk`, move it to `ux0:VPK/` with vitashell FTP, and run it from vitashell. also create a folder called `ux0:data/ycraft`

## todo / known bugs (psvita) 
1. write better testing (currently i move the file manually to my psvita and it is a fucking pain)
2. figure out joysticks properly (they still don't work!! fuck sdl api)  
**2.1.** i probably need to use the `SDL_GameControllerOpen/SDL_GameControllerName` api instead of `SDL_JoystickOpen`  
**2.2.** need access to controller to check if this works properly  
3. stop using `__vita__` everywhere and switch to a `#if defined(VITA)` version
4. use HTTPS in curl.cc for psvita (a pain and also requries itls for most of the time)

## dependencies
SDL2, SDL2_ttf, SDL2_image, SDL2_mixer, libcurl

vitasdk for the vita build

### deps for debian
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
none rn
