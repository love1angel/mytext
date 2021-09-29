[参考文档](https://blog.csdn.net/daidaihema/article/details/80902012)

compile
├── include
│   ├── add.h
│   └── minus.h
├── learning.md
├── lib
│   ├── libTest.a
│   └── libTest.so
├── main.c
├── main.i
└── src
    ├── add.c
    ├── add.o
    ├── minus.c
    └── minus.o

3 directories, 11 files

# 静态库编写

## 编译目标文件

``` shell
# 在当前目录
$ gcc *.c -c -I ../include

# 将所有目标文件打包成静态库文件，r将文件插入静态库中，c创建静态库，不管库是否存在，s写入一个目标文件索引到库中，或者更新一个存在的目标文件索引
$ ar rcs libMyTest.a *.o
$ mv libMyTest.a ../lib
## 查看库中包含的函数等信息
$ nm ./lib/libMyTest.a

# 运行
$ gcc main.c -L lib/ -l MyTest -I include/ -o main
## 错误，不指定静态库名 
$ gcc main.c -L lib/ -I include/ -o main
## 正确
$ gcc main.c src/minus.o src/add.o -I include/ -o main
## 错误 main函数中的头文件没有指定路径 
$ gcc main.c src/minus.o src/add.o -o main

# 或者 写在前面的依赖于后面的，
$ gcc main.c lib/libMyTest.a  -I include/ -o main
## 错误
$ gcc -o main lib/libMyTest.a  main.c -I include

# 对于static library链接，链接器只加载库的符号表，模块间需要查找符号表，定位符号的过程。定义找不到就是有某块的导入符号没有模块来给导入表赋地址。而.o链接，是链接器全盘知道的，不依赖符号表，即不需要通过导入导出符号表定位符号的过程。
```

# 动态库文件编写

```  shell
$ gcc -fPIC -shared src/add.c src/minus.c -o lib/libTest.so -I include
```

[fPIC参数](https://blog.csdn.net/derkampf/article/details/69660050)

和静态库同名的时候优先链接动态库

``` shell
$ gcc main.c -o main -I include -L lib -l Test
$ git:(main) ./main                                      
./main: error while loading shared libraries: libTest.so: cannot open shared object file: No such file or directory
$ ldd main
        linux-vdso.so.1 (0x00007ffcf0f5b000)
        libTest.so => not found
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6438f01000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f6439118000)
```

``` shell
$ gcc -I include main.c lib/libTest.so -o main
$ ./main                                      
= 9, = 1
$ ldd main
        linux-vdso.so.1 (0x00007ffd819c3000)
        lib/libTest.so (0x00007f87e5326000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f87e5116000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f87e5332000)
```

1. export LD_LIBRARY_PATH
2. 写入相应的shellrc
3. 放入usr/lib usr/local/lib
4. 将libTest.so的绝对路径追加到/etc/ld.so.conf文件，用sudo ldconfig -v更新
