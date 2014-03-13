#include "random.h"

int random_intnum(int MaxNum)
{
    timeval *t = (timeval *)malloc(sizeof(timeval));
    gettimeofday(t, NULL);
    srand(t->tv_usec);
    free(t);

    int s = rand()%MaxNum;
    return s;
}
char* random_charnum(int MaxNum)
{
    timeval *t = (timeval *)malloc(sizeof(timeval));
    gettimeofday(t, NULL);
    srand(t->tv_usec);
    free(t);

        int num;
        num = rand()%MaxNum;
        char *buf = (char *)malloc(sizeof(char) * 100);
        for(int i = 0; ; i++)
        {
                if(i != 0 && num <= 0)
                {
                        buf[i] = 0;
                        break;
                }
                int yushu = num % 10;
                buf[i] = (char)(yushu+48);
                num = num / 10;
        }
        for(int i = 0; i < strlen(buf)/2; i++)
        {
                char tmp;
                tmp = buf[i];
                buf[i] = buf[strlen(buf) - i - 1];
                buf[strlen(buf) - i - 1] = tmp;
        }
        return buf;
}
char* random_character(int MaxLength)
{
    timeval *t = (timeval *)malloc(sizeof(timeval));
    gettimeofday(t, NULL);
    srand(t->tv_usec);
    free(t);

    char c[1];
    int changce, len;
    char *s;

    len = rand()%MaxLength+1;
    s = (char *)malloc(sizeof(char)*(len+1));
    memset(s, '\0', strlen(s));
    for(int i = 0; i < len; i++)
    {
        changce = rand()%2;
        if(0 == changce)
            sprintf(c, "%c", rand()%26+97);
        else
            sprintf(c, "%c", rand()%26+65);
        strcat(s, c);
    }
    return s;
}
