#include <stdio.h>
#include <stdlib.h>


int  main()
{
    unsigned  int  size;
    scanf( " %d " , & size);
     int  var[size];       // 定义变长数组
     if (size  ==   0 )
    {
        printf( " empty array\n " );
         return   0 ;
    }
     else
    {
         /* error: 'for' loop initial declarations are only allowed in C99 mode|
        note: use option -std=c99 or -std=gnu99 to compile your code */
         for ( int  i  =   0 ; i  <  size; i ++ )
        {
            printf( " %d\t " ,var[i]);
        }
    }

     return   0 ;
}
/* ———————————————— */
/* 版权声明：本文为CSDN博主「呵-呵呵」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。 */
/* 原文链接：https://blog.csdn.net/Leon57/article/details/79365167 */

