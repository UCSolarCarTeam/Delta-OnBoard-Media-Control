#!/bin/bash

echo "This script will download and install all dependencies for the Raspberry Pi running Raspbian (Debian)"

USER=`whoami`
if [ $USER = "root" ]
    then
    echo "Running as ROOT"
else
    echo "***********YOU ARE NOT ROOT************"
    exit 0
fi

apt-get update --yes
#OpenCV (grabbing camera frames)
#ao.h   (playing music)
#mpg123 (loading music)
#g++    (compiling)
apt-get install libopencv-dev --yes
apt-get install libao-dev --yes
apt-get install g++ --yes
apt-get install libmpg123-dev --yes
apt-get install libasound2-dev --yes
apt-get install libpulse-dev --yes

apt-get install libdbus-1-dev --yes
apt-get install libudev-dev --yes

#SDL stuff

#removes all old folders of SDL2
ls | grep SDL2 | sudo xargs rm -r

#SDL2.0
wget https://www.libsdl.org/release/SDL2-2.0.3.tar.gz
tar -xzvf SDL2-2.0.3.tar.gz
cd SDL2-2.0.3
./configure --host=armv71-raspberry-linux-gnueabihf --target=arm-raspberry-linux-gnueabihf --disable-video-opengl --disable-video-x11
make -j4
make install -j4
cd ..

#SDL2_ttf
wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.tar.gz
tar -xzvf SDL2_ttf-2.0.12.tar.gz
cd SDL2_ttf-2.0.12
./configure
make -j4
make install -j4
cd ..

#SDL2_image
wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
tar -xzvf SDL2_image-2.0.0.tar.gz
cd SDL2_image-2.0.0
./configure
make -j4
make install -j4
cd ..

#SDL2_mixer
wget https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.0.tar.gz
tar -xzvf SDL2_mixer-2.0.0.tar.gz
cd SDL2_mixer-2.0.0
#SMPEG
cd external/smpeg2-2.0.0
./configure
make -j4
make install -j4
cd ../..
./configure
make -j4
make install -j4

