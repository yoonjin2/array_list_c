#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define SIZE 1000
int main(int argc, char **argv)
{
    char x[3][6]={"size","top","empty"};
    FILE *f=fopen(argv[1],"wt");
    int i,ii,iii,iiii;
    for(i=0;i<SIZE;i++)
    {
         fprintf(f,"push %d\n",rand());
         switch(i)
         {
             case 0:
                 break;
             default:
                 ii=rand()%i;
                 iii=rand()%i;
                 if (ii!=iii)
                     fprintf(f,"change %d %d\nadd %d %d\n",ii, iii,rand()%i,rand());
                 fprintf(f,"%s\n%s\n",x[rand()%3],x[rand()%3]);
                 break;
         };
    if(rand()%3==1)
        fprintf(f,"pop\n");
    }
    fprintf(f, "where 0\n");
    fprintf(f,"showall\nreturn");
    fclose(f);
    return 0;
}
