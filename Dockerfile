FROM ubuntu:latest
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get -y install git && apt-get -y install cmake && apt-get -y install g++
RUN cd ~ && git clone https://github.com/Itseez/opencv.git
RUN cd ~ && git clone https://github.com/Itseez/opencv_contrib.git && cd opencv_contrib
RUN cd ~/opencv && mkdir -p build && cd build && cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D OPENCV_EXTRA_MOUDLES_PATH=~/opencv_contrib/modules -D BUILD_EXAMPLES=OFF ~/opencv
RUN cd ~/opencv/build && make -j1 
RUN cd ~/opencv/build && make install && ldconfig
RUN mkdir -p source
RUN apt-get -y install libopencv-*

WORKDIR /source
CMD ["bash"]