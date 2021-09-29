<!--
 * @Author: peng.xie
 * @Email: helianthus547@gmail.com
 * @Date: 2021-08-20 23:04:39
 * @LastEditTime: 2021-08-24 16:57:55
 * @Description: learn **C Primer Plus** book text
-->
# 导言

## 语言学习过程

一门计算机语言广义上来说主要包括两部分：一部分是语言的语法，另外一部分是将语言翻译成机器语言的工具（编译器或者解释器）。一门语言的语法学习不仅要学习原生的语法，还有用语法实现的库。C语言是编译语言，C语言编译器中不仅包含了编译器，还包括了链接器。

## 这本书的组织结构

1. 第一章和第二章讲了C语言编程的预备知识

第一章：C语言起源和编译C语言

第二章：一个C语言程序示例

2. 第三章到第十五章讲了C语言的语法知识

第三章和第四章：讲了数据类型，第四章讲的字符串和格式化输入输出

第五章：运算符、表达式和语句

第六章和第七章：循环与分支

第八章：字符输入输出验证，前面的总结和例子

**第九章和第十章：函数、数组和指针**

第十一章：字符串，字符串函数

**第十二章：存储类别、链接和内存管理**

第十三章：文件输入输出

第十四章：结构

第十五章：位操作

3. 第十六章和第十七章讲了C预处理器、C库和一些数据结构

# 第一章：初识C语言

## 内容梗概

- C语言的历史和特性
- C标准和C程序编写步骤
- C语言编译过程
- 在常见的系统中运行C程序

## C语言起源

1972年Ken Thompson, Dennis Ritchie在开发UNIX操作系统时设计了C语言，从B语言(Thompson发明)发展而来。语言设计的目标是专门为程序员设计开发使用

强类型、弱检查、静态、编译性语言

## C语言特点

- 设计特性：自顶向下的规划、结构化编程和模块化设计
- 运行速度快：具有汇编语言才具有的微调控制能力（汇编语言是为特殊的中央处理单元设计的一系列内部指令，使用助记符表示；不同的CPU系列使用不同的汇编语言）
- 有**较好**的可移植性，但是程序中针对特殊硬件设备或操作系统特殊功能编写的部分，通常是不可移植的
- 可以访问硬件、操作内存中的位，C实现都有一个大型的库，包含众多有用的C函数，用于处理程序员经常需要解决的问题
- 自由编程，但易错，必须承担更多的责任，想拥有自由必须时刻保持警惕
- IOCCC：the international obfuscated C code contest国际C语言混乱代码大赛
- 1980~90年代，C++在C语言的基础上嫁接了面向对象编程工具（面向对象编程是一门哲学，它通过对语言建模来适应问题，而不是对问题建模以适应语言）

小型机UNIX服务器minicomputer, midrangecomputer

微型机Microcomputer

大型机

## 计算机、高级计算机语言与编译器

### 计算机组成部件

1. CPU：中央处理单元，控制，运算，处理程序
2. RAM：随机存取内存，存储程序和文件的工作区
3. 永久内存存储设备：机械硬盘、固态硬盘，关机也不会丢失存储的程序和文件
4. 各种外围设备(键盘、鼠标、触摸屏、监视器)来提供人机交互

### CPU负责处理程序

1. CPU反复从内存中取指令执行，更新指令
2. 有自己的小工作区：若干个寄存器，其中一个寄存器存储下一条指令的内存地址，在一个寄存器中储存指令，更新存储指令地址寄存器的值
3. CPU理解的指令的集合叫做指令集
4. **存储在计算机中所有的内容都是数字，以数字的形式存储数字和字符，指令集中的每条指令都有一个数字码，计算机程序最终必须以数字指令码（机器语言）来表示，程序就是指令列表task list**
5. 数据需要从内存拷贝到寄存器中进行运算

### 高级语言与编译器

1. **编译器是将C语言翻译成为机器语言指令集的程序，桥梁作用**

2. 使用高级编程语言，以更抽象的方式描述行为，不局限于特定CPU或指令集，可以在更抽象的层面表达你的想法
3. 编译器封装了系统架构特性CPU和指令集

## C语言标准

|   时间    |                        C语言标准名称                         |
| :-------: | :----------------------------------------------------------: |
|   1978    | K&R C: Brian Kernighan, Dennis Ritchie合著的The C Programming Language |
| 1989/1990 |                    ISO/ANSI C 或者叫 C89                     |
|   1999    |                           C9X C99                            |
|           |                         C1X草案标准                          |
|   2011    |                         ISO/IEC C11                          |

The C Programming Language中只有C实现，没有定义C库，UNIX实现提供的C库成为了标准库

ANSI C

定义了C语言和C库

1. 信任程序员
2. 保持语言精炼简单
3. 只提供一种方法执行一项操作
4. 让程序运行更快，即使不能保持其可移植性：作为实现，应该针对目标计算机来定义最合适的某特定操作，而不是强加一个抽象，统一的定义

## 编写程序7大步骤

1. 定义程序的目标
2. 设计程序
3. 编写代码
4. 编译

编译的细节取决于编程的环境

编译器是把源代码转换成可执行代码的程序。可执行代码是用计算机的机器语言表示的代码，这种语言由数字码表示的指令组成，不同的计算机使用不同的机器语言方案，C语言编译器负责把C代码翻译成特定的机器语言。在大多数系统中，编译器运行链接器，用来链接源代码和库代码

5. 运行程序
6. 测试和调试程序
7. 维护和修改程序

磨刀不误砍柴工，定义和设计程序的环节非常重要

## C语言编译过程

C source code file：源代码文件，以.c结尾，.之前的称为基本名base name，后面的称为扩展名extension，两者的组合就是文件名

预处理、编译、汇编、链接

### 目标代码文件、可执行文件和库

编译器把源代码转换成中间代码，链接器把中间代码和其它代码合并，生成可执行文件

C使用这种分而治之的方法方便对程序进行模块化，可以独立编译单独的模块，稍后再用链接器合并已编译的模块。通过这种方式，如果只更改某个模块，不必重新编译其它模块

链接器将编写的程序的目标代码、系统启动代码和预编译的库代码合并。库代码中，链接器只会把程序中要用到的库函数代码提取出来

启动代码（start up code）：启动代码充当着程序和操作系统之间的接口

目标文件和可执行文件都由机器语言指令组成的

|              | GNU/Linux | Windows |
| :----------: | :-------: | :-----: |
| 目标代码文件 |    .o     |  .obj   |
|  静态库文件  |    .a     |  .lib   |
|  动态库文件  |    .so    |  .dll   |
|  可执行文件  |   a.out   |  .exe   |

## 在常见的系统中运行C程序

1. 类UNIX操作系统

cc：C语言编译器的别名，具体情况下对应不同的编译器

cc -v

- GNU(GNU is Not UNIX): GCC编译器

gcc -std=c99 helloworld.c

GCC调用C11之前的草案标准

gcc -std=c1x helloworld.c

GCC调用C11标准

gcc -std=c11 helloworld.c

- LLVM项目: Clang编译器

2. Windows

不要用字处理文件，保存为纯文本文件

IDE

DLL

3. Mac

Xcode

# 第二章：C语言概述

## 内容梗概

- 简单的C程序
- 调试程序的方法

## C程序结构

- C语言通过定义关键字、标识符、运算符、数据构成了语句

- 语句构成了函数，一共有6种语句，标号语句、符合语句、表达式语句、选择语句、迭代语句、跳转语句

- 函数是C程序的构造块

- main()是第一个被调用的函数

## 示例程序分析

``` c
#include <stdio.h>
```

这行代码是一条C预处理指令（preprocessor directive），C编译器在编译前会对源代码做一些准备工作，即预处理（preprocessing），#表明，C预处理器会在编译器接手之前处理这条指令

这行代码的作用相当于把stdio.h文件中的所有内容拷贝粘贴到此处，通过include文件提供了一种共享许多程序共有信息的途径，stdio.h在C编译器软件包中

在程序顶部的信息集合被称为头文件（header），包含了编译器创建最终可执行程序要用到的信息。头文件可以定义一些变量、指明函数名

不在语言中内置功能，通过库给出，轻装上阵是C语言的哲学

``` c
int main(void)
```

()表明是一个函数名，C程序一定从main函数开始执行，必须有main函数，int是main函数返回的类型，返回给操作系统，void表示该程序不接受程序输入参数

``` c
/* 多行注释，不能嵌套*/
// 单行注释
int main(void) {

}
```

左花括号表示函数定义的开始，右花括号表示函数定义结束

``` c
int num;// 声明declaration
```

<span style="color:red;">定义声明和引用声明的区别</span>

该声明：一个名为num的变量variable，int表明num是一个整数类型，编译器使用这些信息为num变量在内存中分配存储空间，num是一个标识符identifier，也就是一个变量、函数或其它实体的名称，声明把特定标识符与计算机内存中的特定位置联系起来，同时也确定了存储在某位置的信息类型或数据类型

变量必须先声明才能使用

C语言数据类型如整数、字符、浮点数，只有把变量声明为某种类型，计算机才能正确的存储、读取和解释数据，分而治之

标识符：小写字母、大写字母、数字、下划线组成，数字不能第一个，不能用关键字keyword，避免使用__开头，可能会与底层代码名称冲突

``` c
num = 1;
```

赋值表达式语句，在执行int num;声明时，编译器在计算机内存中为变量num预留了空间，把值储存在之前预留的位置，把右值赋给左值

``` c
printf("I am a simple ");
```

调用函数，""的字符串称为实际参数actual argument，printf执行完成后，返回主调函数calling function

转义序列escape sequence如\n表示一个换行符newline character，\t代表制表符，\b表示Backspace退格键，每个转义序列以反斜杠\开始

printf中的%d：%表示要打印变量，d表示以十进制整数打印

return 0;返回值为0，可以echo $?打印程序运行返回值，是一种跳转语句

## 编码规范

1. 多写注释
2. 用有意义的变量名
3. 多用空行
4. 每个语句独占一行
5. 程序说明，文件头部描述

## 多函数

``` c
void butler(void);// 函数原型：prototype, function declaration
main {
    butler();// 函数调用：function call
}
// 函数定义：function definition
void butler(void) {

}
```

建议为程序中用到的所有函数提供函数原型

## 调试程序

bug与debug

语法错误和语义错误

- 编译器编译报错，修改几条错误就重新编译，报错的位置比真实位置滞后

- 语义错误：单步调试，查看程序状态program state；添加printf；使用调试器debugger(gdb)

保留标识符reserved identifier比如_开头的标识符和标准库函数名printf

<span style="color:red;">在符合C标准的编译器框架中，表达你希望程序应该如何完成任务的想法</span>

# 第三章：数据与C





# 第十三章：存储类别、链接和内存管理
