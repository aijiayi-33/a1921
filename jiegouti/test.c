
#include "jiegouti.h"

int main(void)
{
    Linklist *phead;
    int value,num;
    phead=creat();

    head_insert(phead,5);
    print(phead);

    printf("请输入你想插入的数字:\n");
    scanf("%d",&value);
    tail_insert(phead,value);
    print(phead);

    printf("请输入你想删除的数字:\n");
    scanf("%d",&num);
    delete(phead,num);
    print(phead);
}
