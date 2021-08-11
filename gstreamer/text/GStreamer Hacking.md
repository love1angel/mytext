# GStreamer Hacking

## 安装

### - Ubuntu安装

``` shell
$ sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
```

安装gcc

添加库到gcc命令中去字符串

``` shell
pkg-config --cflags --libs gstreamer-1.0
```

## 编译

``` shell
$ gcc basic-tutorial-1.c -o basic-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`
```

GStreamer函数、结构体和类型使用gst_前缀，而GLib和GObject使用g\_



## code核心

- 通过元素构建pipeline，pipeline最终也会作为一个元素



![img](https://gstreamer.freedesktop.org/documentation/tutorials/basic/images/figure-1.png)

## 构件

1. 简单的播放器：playbin，其中包含了source和sink
2. element：GstElement

- element框架上的分类

  有source、sink和filter

- element属性

  state（playing和）

- 创建

```c
source = gst_element_factory_make("videotestsrc", "source");
sink = gst_element_factory_make ("autovideosink", "sink");
```

第一个参数是元素类型，第二个是自定义元素名字

1. bus：GstBus
2. message：GstMessage
3. GstStateChangeReturn

## 框架

source element -> sink element

