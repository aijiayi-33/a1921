#include<stdio.h>
#include<stdlib.h>


int main ()
{
        int i;
        int n;
        int *ptr_arr;
        printf ("输入字符串的长度：");
        scanf ("%d", &i);
        printf ("输入: ");
        scanf ("%d", &n);
        ptr_arr = (int*)malloc(i);
        *ptr_arr = n;
        if( ptr_arr== NULL) exit(1);

        ptr_arr = (int*)calloc(i,sizeof(int));
        printf("%d\n", *ptr_arr);
        printf("%d\n", ptr_arr);
}
