#include <stdio.h>

char *strcat(char *dest, const char *src);

int main(void)
{
    char dest[10] = "hi";
    char src[6] = "~~~~";
    strcat(dest, src);
    printf("%s \n", dest);

    return 0;
}

char *strcat(char *dest, const char *src)
{
    char *save = dest;
    while (*save != 0)
    {
        save++; // 記住s1的最後一個位置
    }
    for (; *src != '\0'; save++, src++)
    {
        *save = *src; // s1最後一個位置的下一個位置開始append s2的值
    }
    *save = '\0'; // save的第1個為null的空間 = '\0' 在這空間之後還是null

    return (save);
}