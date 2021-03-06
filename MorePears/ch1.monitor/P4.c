#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int root(int);
int prime(int);
int root(int n)
{
        return (int)sqrt((float)n);
}
int prime(int n)
{
        int i, bound;
        if(n % 2 == 0)
         return 0;
        if(n % 3 == 0)
         return 0;
        if(n % 5 == 0)
         return 0;
        bound = root(n);
        for (i = 7; i <= bound; i += 2)
         if(n % 2 == 0)
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
        for(i = 2; i <= n;i++)
         if(prime(i))
              printf("%d\n", i);
    return 0;
}
