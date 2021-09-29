#include <stdio.h>
#include "add.h"
#include "minus.h"


int main(int argc, char const *argv[])
{
    int a = 5, b = 4;
    int c = add(a, b);
    printf("add = %d, minus = %d\n", c, minus(a, b));
    return 0;
}