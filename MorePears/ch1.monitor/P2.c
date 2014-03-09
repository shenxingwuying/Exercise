#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int root(double);
int prime(int);


int root(double n)
{
        return (int)sqrt(n);
}

int prime(int n)
{
        int i;
        for (i = 2; i <= root(n); i++)
         if (n%i == 0)
              return 0;
        return 1;
}

int main(int argc, char* argv[])
{
        int i, n;
        if(argc > 1)
         n = atoi(argv[1]);
        else
         n = 100000;
        for (i = 2; i <= n; i++)
         if(prime(i))
              printf("%d\n", i);
    return 0;
}
