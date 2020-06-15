#include"list.h"
int main(int argc, char **argv)
{
    FILE *f=fopen(argv[1],"rt");
    list_int intlist=listgen(),i=listgen();
    intlist=listinter(f,intlist);
    i=listcpy(i,intlist);
    free(intlist.list);
    i=listinter(stdin,i);
    free(i.list);
    fclose(f);
    return 0;
}
