cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(ycraft-vita)
include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "ycraft")
set(VITA_TITLEID  "YTI000001")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -std=gnu17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")
FIND_PACKAGE(SDL2)
add_executable(${PROJECT_NAME}
    src/ui.cc
    src/particles.cc
    src/chat.cc
    src/level.cc
    src/app.cc
    src/animation.cc
    src/commands.cc
    src/game.cc
    src/audio.cc
    src/settings.cc
    src/newWorldMenu.cc
    src/text.cc
    src/titleScreen.cc
    src/bits.cc
    src/properties.cc
    src/menuBase.cc
    src/worldMenu.cc
    src/texturePackSelectorMenu.cc
    src/fs.cc
    src/util.cc
    src/collision.cc
    src/blockdefs.cc
    src/pauseMenu.cc
    src/creditsScreen.cc
    src/curl.cc
    src/settingsMenu.cc
    src/inventory.cc
    src/player.cc
    src/image.cc
    src/video.cc
    src/tiles.cc
    src/inventoryScreen.cc
    src/main.cc
)

target_link_libraries(${PROJECT_NAME}
    SDL2_mixer
    SDL2_ttf
    SDL2_image
    SDL2::SDL2
    FLAC
    vorbisfile
    vorbis
    ogg
    mpg123
    mikmod
    modplug
    freetype
    png
    jpeg
    webp
    pthread
    z
    m
    ScePower_stub
    SceAudio_stub
    SceNet_stub
    SceNetCtl_stub
    SceHttp_stub
    SceDisplay_stub
    SceSysmodule_stub
    SceGxm_stub 
    SceHid_stub 
    SceMotion_stub 
    SceTouch_stub
    SceIofilemgr_stub
    SceIme_stub 
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)