FROM debian:stable-slim

WORKDIR /root

COPY . /root

RUN apt-get update
RUN apt-get install -y --no-install-recommends binutils-dev tclsh wput cmake make
RUN dpkg -i /root/packages/$(dpkg --print-architecture)/*.deb /root/packages/all/*.deb
RUN rm -rf /root/packages

#Fix toolchain bug dropping includes from call to compiler
RUN sed -i "s/_COMPILER> <DEFINES>/_COMPILER> <INCLUDES> <DEFINES>/" /usr/powerpc-wrs-vxworks/share/cmake/toolchain.cmake

#Fix warning about deprecated CMake command
RUN sed -ri "s/CMAKE_FORCE_(.*)_COMPILER\((.*) GNU\)/set\(CMAKE_\1_COMPILER \2\)/" /usr/powerpc-wrs-vxworks/share/cmake/toolchain.cmake

ENTRYPOINT /bin/bash
