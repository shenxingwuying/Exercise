#include <stdio.h>
#include <string.h>

int main()
{
    char a[80]="AB", b[80]="LMNP";
    int i = 0;
    strcat(a,b);
    while(a[i++] != '\0') b[i] = a[i];
    puts(b);
    return 0;
}
hello
