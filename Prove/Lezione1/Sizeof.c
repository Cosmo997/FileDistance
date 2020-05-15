#include <stdio.h>

int main(void)
{
    printf("void\tchar\tshort\tint\tlong\tfloat\tdouble\n");
    printf("%3ld\t%3ld\t%3ld\t%3ld\t%3ld\t%3ld\t%3ld\n",
           sizeof(void), sizeof(char), sizeof(short),
           sizeof(int), sizeof(long), sizeof(float),
           sizeof(double));
}