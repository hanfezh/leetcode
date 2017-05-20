/*
 * =====================================================================================
 *
 *       Filename:  zigzag_conversion.c
 *
 *    Description:  ZigZag Conversion 
 *
 *        Version:  1.0
 *        Created:  05/19/2017 11:57:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng <xianfeng.zhu@gmail.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * rows: 6
 *  
 * 0      10       20
 * 1    9 11    19 21
 * 2   8  12   18  22
 * 3  7   13  17   23
 * 4 6    14 16    24
 * 5      15       15
 * 
 * n: ((6 - 1) * 2) = 10
 * 
 * 0  +10             10
 * 1  +8     9 +(2*1) 11
 * 2  +6    8  +(2*2) 12
 * 3  +4   7   +(2*3) 13
 * 4  +2  6    +(2*4) 14
 * 5           +(2*5) 15
 */

char *convert(char *s, int rows)
{
    int len = strlen(s);
    char *buf = NULL;
    char *ptr = NULL;
    int n = (rows - 1) * 2;
    int i = 0;
    int j = 0;

    // Alloca buffer
    buf = (char *)malloc(len + 1);
    ptr = buf;

    if (rows == 1)
    {
        strncpy(buf, s, len + 1);
        return buf;
    }

    for ( ; i < rows; i++)
    {
        if ((i == 0) || (i == (rows - 1)))
        {
            for (j = i; j < len; j += n)
            {
                *ptr = *(s + j);
                ptr++;
            }
        }
        else
        {
            int k = n - (i * 2);

            for (j = i; j < len; )
            {
                *ptr = *(s + j);
                ptr++;

                j += k;
                k = n - k;
            }
        }
    }

    buf[len] = '\0';
    return buf;
}

int main(int argc, char *argv[])
{
    // char *str = "PAYPALISHIRING";
    // char *ptr = convert(str, 3);
    char *str = "A";
    char *ptr = convert(str, 1);

    printf("%s\n", ptr);

    free(ptr);
    return 0;
}
