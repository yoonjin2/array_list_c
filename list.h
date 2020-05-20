#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list_int
{
int *list;
int list_size;
};
typedef struct list_int list_int;
/*get space for add function*/
list_int getspace(list_int X, int a)
{
    int i;
    if(X.list_size!=0)
    {
        X.list=(int *)realloc(X.list,sizeof(int)*(X.list_size+1));
        for(i=X.list_size;i>a;i--)
            X.list[i]=X.list[i-1];
        X.list_size++;
    }
    return X;
}
/*add function*/
list_int list_add(FILE *f,list_int X)
{
    int a,b;
    fscanf(f,"%d %d", &a, &b);
    if(X.list_size<a)
        ;
    else
    {
        X=getspace(X,a);
        X.list[a]=b;
    }
    return X;
}
/*copy X to Y*/
list_int listcpy(list_int Y, list_int X)
{
    int i;
    Y.list_size=X.list_size;
    Y.list=malloc(sizeof(int)*X.list_size);
    for(i=0;i<X.list_size;i++)
        memcpy(Y.list+i,X.list+i,sizeof(int));
    return Y;
}
/*make initial data*/
list_int listgen()
{
    list_int X;
    X.list=malloc(sizeof(int));
    X.list_size=0;
    return X;
}
/*push data*/
list_int push(FILE *f, list_int X)
{
    X.list=(int *)realloc(X.list,(X.list_size+1)*sizeof(int));
    fscanf(f,"%d",X.list+X.list_size);
    X.list_size++;
    return X;
}
/*pop data*/
list_int pop(FILE *f,list_int X)
{
    if(X.list_size==0)
        puts("-1");
    else
    {
        printf("%d\n",X.list[X.list_size-1]);
        X.list_size--;
        X.list=(int *)realloc(X.list,X.list_size*sizeof(int));
    }
    return X;
}
/*print size*/
void size(list_int X)
{
    if(X.list_size>0)
        printf("%d\n",X.list_size);
    else
        puts("0");
}
/*if it is empty, it will return 1, or it will return 0.*/
void empty(list_int X)
{
    if(X.list_size==0)
        puts("1");
    else
        puts("0");
}
/*shows top*/
void top(list_int X)
{
    if(X.list_size>0)
        printf("%d\n",X.list[X.list_size-1]);
    else
        puts("-1");
}
/*switch X and Y*/
list_int change(FILE *f,list_int X)
{
    int x,y,sv;
    fscanf(f,"%d %d", &x, &y);
    sv=X.list[x];
    X.list[x]=X.list[y];
    X.list[y]=sv;
    return X;
}
/*print specific number's location*/
void where(FILE *f,list_int X)
{
    int x,i;
    fscanf(f,"%d",&x);
    for(i=X.list_size-1;i>=0;i--)
    {
        if(x==X.list[i])
            printf("%d\n",i);
    }

}
/*print all*/
void list_show_all(list_int X)
{
    int i;
    for(i=X.list_size-1;i>=0;i--)
         printf("%d\n",X.list[i]);
}
/*remove number*/
list_int list_remove(FILE *f,list_int X)
{
    int Y;
    fscanf(f,"%d",&Y);
    for(;Y<X.list_size-1;Y++)
         X.list[Y]=X.list[Y+1];
    X.list_size--;
    X.list=(int *)realloc(X.list,sizeof(int)*X.list_size);
    return X;
}
/*gets command*/
list_int listinter(FILE *f,list_int X)
{
    int i;
    char command[6];
    list_int Y=listcpy(Y,X);
    while(!feof(f))
    {
        fscanf(f,"%s",command);
        if(strcmp(command,"push")==0)
            Y=push(f,Y);
        else if(strcmp(command,"pop")==0)
            Y=pop(f,Y);
        else if (strcmp(command,"size")==0)
            size(Y);
        else if (strcmp(command,"empty")==0)
            empty(Y);
        else if(strcmp(command,"top")==0)
            top(Y);
        else if(strcmp(command,"change")==0)
            Y=change(f,Y);
        else if(strcmp(command,"where")==0)
            where(f,Y);
        else if(strcmp(command,"return")==0)
            break;
        else if(strcmp(command,"showall")==0)
            list_show_all(Y);
        else if(strcmp(command,"remove")==0)
            Y=list_remove(f,Y);
        else if(strcmp(command,"add")==0)
            Y=list_add(f,Y);
        else if(strcmp(command,"clear")==0)
        {
            for(i=0;i<Y.list_size;i++)
                Y.list[i]=0;
            Y.list_size=0;
            Y.list=(int *)malloc(sizeof(int));
        }
        else
            puts("ERROR");
    }
    X.list=(int *)realloc(X.list,sizeof(int)*Y.list_size);
    return Y;
}


