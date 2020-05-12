#include"list.h"
int main()
{
    list_int intlist=listgen(1);
    intlist=listinter(intlist);
    free(intlist.list);
    return 0;
}
