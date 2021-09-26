## download

[link to cmake.org/download/](https://cmake.org/download/)

## install

install gcc/g++ or clang

in UBuntu

``` shell
$ sudo apt-get update
$ sudo apt-get install make
$ tar -zxvf cmake-3.21.3.tar.gz
$ sudo apt-get install openssl
$ sudo apt-get install libssl-dev
$ ./bootstrap
$ make
$ sudo ln -s /home/xiepeng/software/cmake-3.21.3/bin/cmake /usr/bin/
$ cmake --version
```

## use

1. extract SDK
2. set compile environment

``` shell
$ . {your install path}/oecore-x86_64/environment-setup-aarch64-oe-linux
```

3. compile

``` shell
$ mkdir build
$ cd build/
$ cmake ../
$ make
```



