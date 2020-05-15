#include <stdio.h>
#include <assert.h>

int factorial(int);
int valore = 6;
int factorial(int n)
{
    assert(n>=0);
    if(n>0)
    {
        return n*factorial(n-1);
    }
    else 
    return 1;
}

int main(void)
{
    printf("FATTORIALE DI %d : %d\n",valore,factorial(valore));
}