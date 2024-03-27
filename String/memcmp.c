#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 int memcmp ( const void * ptr1, const void * ptr2, size_t num );

 Return value :
  < 0 : the first byte that does not match in both memory blocks has a lower value
        in ptr1 than in ptr2 (if evaluated as unsigned char values)

  = 0 : the contents of both memory blocks are equal

  > 0 : the first byte that does not match in both memory blocks has a greater value
        in ptr1 than in ptr2 (if evaluated as unsigned char values)

*/
int main()
{
    char *s1 = "asdas";
    char *s2 = "asdat";
    int value = memcmp(s1, s2, 5);
    if (!value)
    {
        printf("s1 is equal to s2. \n");
    }
    else if (value < 0)
    {
        printf("s1 is less than s2. \n");
    }
    else if (value > 0)
    {
        printf("s1 is greater than s2. \n");
    }

    return 0;
}