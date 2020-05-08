#include<stdio.h>
#include"list.h"
#define SIZE 1000
int main()
{
    list_int intlist=listgen(1000);
    int i;
    for(i=1;i<SIZE;i++)
        intlist.list[i]=i;
    intlist=listinter(intlist);
    list_show_all(intlist);
    free(intlist.list);
    return 0;
}
