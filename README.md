# neon-win-build

neon Windows build with Visual Studio.

This version is neon-0.36.0.

To build, simply open the required solution file, and
you know how to use Visual Studio, right?
(or perhaps this is the wrong place for you.)

Depends on:
* zlib-win-build
* openssl-win-build:main (openssl 4 for VS2015 or later)  
* openssl-win-build:openssl-3.6 (openssl 3.6 for VS2013)  
* openssl1_1-win-build (openssl 1.1 for VS2010)  
* expat-win-build

There are hard references assuming all these sit next to neon-win-build.

Basically, in a command prompt:

> \> cd {somewhere}\\  
> \> git clone https://github.com/kiyolee/zlib-win-build.git  
> \> git clone https://github.com/kiyolee/openssl-win-build.git (openssl 4 for VS2015 or later)  
> \> git clone -b openssl-3.6 https://github.com/kiyolee/openssl-win-build.git openssl3-win-build (openssl 3.6 for VS2013)  
> \> git clone https://github.com/kiyolee/openssl1_1-win-build.git (openssl 1.1 for VS2010)  
> \> git clone https://github.com/kiyolee/expat-win-build.git  
> \> git clone https://github.com/kiyolee/neon-win-build.git

Build all these dependencies in the suggested order as shown above and finally neon, with the same corresponding Visual Studio solution of course.

Note:
If you prefer to use openssl 1.1 instead, check out branch openssl1_1.
If you prefer to use openssl 1.0 instead, check out branch openssl1_0.
