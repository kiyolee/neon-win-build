# neon-win-build

neon Windows build with Visual Studio.

This version is neon-0.32.1.

To build, simply open the required solution file, and
you know how to use Visual Studio, right?
(or perhaps this is the wrong place for you.)

Depends on zlib-win-build and openssl1_1-win-build.
There are hard references assuming both zlib-win-build and openssl1_1-win-build
sit next to neon-win-build.

Basically, in a command prompt:

> \> cd {somewhere}\\  
> \> git clone https://github.com/kiyolee/zlib-win-build.git  
> \> git clone https://github.com/kiyolee/openssl1_1-win-build.git  
> \> git clone https://github.com/kiyolee/neon-win-build.git

Build zlib first and then openssl1_1 and finally neon, with the same corresponding Visual Studio solution of course.

Note: If you prefer to use openssl 1.0 instead, check out branch openssl1_0.
