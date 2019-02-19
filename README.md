FRC-cRIO-Build
==============

A lightweight containerized build system for the National Instruments cRIO-FRC and cRIO-FRC II.

Usage
-----
To build the container, run `docker build -t frc-crio-build .` from a local clone of this repository. To start it, run `docker run -it frc-crio-build:latest`.

To build the sample project, simply `cd` to the `sample` directory within the container, run `frcmake` to generate an updated Makefile, and run `make` to compile the code.

To deploy the compiled binary, ensure that the Docker container is capable of connecting to the cRIO and that your team number is set correctly in `CMakeLists.txt`, then run `make deploy`. You can also use [frcupload](https://github.com/Techwolfy/frcupload/) to deploy the output binary from a different host after building it in the container. Note that the host must be connected to Ethernet Port 1 if using the 8-slot cRIO, either directly via an Ethernet cable or over the robot's wireless network.

Resources
---------
Toolchain project homepage:
http://firstforge.wpi.edu/sf/projects/c--11_toochain
https://bitbucket.org/frc-cpp11

Project wiki (contains all related information):
http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/HomePage

Setup instructions:
http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/BinaryInstall

Build instructions:
http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/UsingCMake
http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/Compiling

Alternate toolchain info:
http://www.chiefdelphi.com/forums/showthread.php?t=109385
