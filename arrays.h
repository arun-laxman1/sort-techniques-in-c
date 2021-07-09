#include<stdio.h>
#include<stdlib.h>

typedef int ele;
typedef struct
{
	ele* array;
	int max_size;
	int size;
}myarray;

int creating(myarray *p);
int inserting(myarray *p,int pos,ele x);
int display(myarray *p);
int deleting(myarray *p,ele x);
int searching(myarray *p,ele x);
int update(myarray *p,int pos,ele x);
int sorting(myarray *p);
int destroy(myarray *p);
int remove_duplicates(myarray *p);


