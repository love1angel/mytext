# 编码格式

## MPEG(Moving Picture Experts Group)

MPEG颁布了三个活动图像及声音编码的正式国际标准，分别称为MPEG-1、MPEG-2和MPEG-4

### 1. MPEG-2

MPEG-2系统是将视频、音频及其它数据基本流组合成一个或多个适宜于存储或传输的数据流的规范。将数字视频数据和数字音频数据分别通过图像编码和声音编码之后，生成视频基本流（ES）和音频ES。在视频ES中还要加入一个时间基准，即加入从视频信号中取出的27MHz时钟。然后再分别通过各自的数据包形成器，将相应的ES打包基本流（PES）包，并由PES包构成PES。最后，节目复用器和传输复用器分别将视频PES和音频PES组合成相应的节目流（PS）包和传输流（TS）包，并由PS包构成PS由TS包构成TS。显然，不允许直接传输PES，只允许传输PS和TS；PES只是PS转为TS或TS转为PS的中间步骤或桥梁，是MPEG数据流互换的逻辑结构，本身不能参与交换和互操作，[blog](https://blog.csdn.net/mm792261167/article/details/62218063/)

#### 定义

- 是一组用于视音频压缩编码及其数据流格式的国际标准
- 是MPEG组织制定的视频和音频有损压缩标准之一
- 将视频、音频及其它数据基本流组合成一个或多个适宜于存储或传输的数据流的规范

#### 编码特点

##### 图像分类

编码图像被分为三类，分别称为I帧、P帧和B帧，为了利用<span style="color:red">图像的时间相关性和空间相关性</span>

- I帧图像，或称帧内（intra）图像，参考图像，相当于一个固定图像，且独立于其它的图像类型。每个图像组群由此类型的图像开始。采用帧内压缩编码技术减少空间冗余，不参照其他图像
- P帧图像，或称预测（predicted）图像，通过参照前面靠近它的I或P图像预测得到。P图像减少了空间和时间冗余信息，相比I图像可以有更大的压缩码率
- B帧图像，或称双向预测图像，根据临近的前几帧、本帧、后几帧的I或者P图像预测得到，仅记录本帧与前后帧的不同之处。相比I和P图像可以有更大的压缩码率

#### 传输速率

3Mbit/s ~ 10Mbit/s

#### 用途

MPEG-2标准特别适用于广播质量的数字电视的编码和传送，被用于无线数字电视、DVB（Digital Video Broadcasting，数字视频广播）、数字卫星电视、DVD（Digital Video Disk，数字化视频光盘）等技术中

- 相比MPEG-1，拥有更高的图像质量、更多的图像格式和传输码率的图像压缩标准
- 针对标准数字电视和高清晰电视在各种应用下的压缩方案

### 2. H.264



# 传输流

## TS(transport stream)

参考文档

1. [TS流概述](https://www.sohu.com/a/149138102_781333)
2. [ts流](https://blog.csdn.net/qq_31213433/article/details/50571499)

PAT，PMT，PES

# 流媒体传输协议

## 写的不错的[blog](https://blog.csdn.net/tttyd/article/details/12032357)

## 1. RTP(real-time transport protocol)

## 2. RTCP(real-time transport control protocol)

## 3. RTSP()



