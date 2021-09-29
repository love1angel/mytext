#include <minus.h>
#include <add.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5, b = 4;
    printf("= %d, = %d\n", add(a, b), minus(a, b));
    return 0;
}
