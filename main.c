#include"list.h"
int main(int argc, char **argv)
{
    FILE *f=fopen(argv[1],"rt");
    list_int intlist=listgen();
    intlist=listinter(f,intlist);
    free(intlist.list);
    fclose(f);
    return 0;
}
