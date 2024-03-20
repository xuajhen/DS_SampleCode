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
    while (*dest != '\0')
    {
        save++;
    } // last position
    for (; *src != '\0'; save++, src++)
    {
        *save = *src;
    }
    *save = '\0';

    return save;
}