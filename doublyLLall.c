#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
#include<stdlib.h>
struct doubly
{
struct doubly *prev;
int data;
struct doubly *next;
};
struct doubly *start=NULL;
int create();
int traverse_back();
int traverse();
int ins_first();
int ins_last();
int ins_pos();
int del_first();
int del_last();
int del_pos();
int count();
void main()
{
int ch;
while(1)
	{
	system("cls");
	printf("Press 1 for creation:\n");
	printf("Press 2 for traverse Back:\n");
	printf("Press 3 for traverse: \n");	
	printf("Press 4 for count: \n");
	printf("Press 5 for insert First:\n");
	printf("Press 6 for insert last:\n");
	printf("Press 7 for insert pos:\n");
	printf("Press 8 for del First:\n");
	printf("Press 9 for del last:\n");
	printf("Press 10 for del pos:\n");
	printf("Press 11 for exit:\n");
	printf("Select your options:\n");
	scanf("%d",&ch);
	if(ch==1)
		{
		create();
		}
	else if(ch==2)
		{
		traverse_back();
		getch();
		}
	else if(ch==3)
		{
		traverse();
		getch();
		}
	else if(ch==4)
		{
		int r;
		r=count();
		printf("Total no of Node=%d\n",r);
		getch();
		}
	else if(ch==5)
		{
		ins_first();
		}
	else if(ch==6)
		{
		ins_last();
		}
	else if(ch==7)
		{
		ins_pos();
		getch();
		}
	else if(ch==8)
		{
		del_first();
		getch();
		}
	else if(ch==9)
		{
		del_last();
		getch();
		}
	else if(ch==10)
		{
		del_pos();
		getch();
		}	
	else if(ch==11)
		{
		exit(0);
		}
	}
}
int create()
{
struct doubly *tmp,*tmp1;
if(start==NULL)
	{
	tmp=(struct doubly*)malloc(sizeof(struct doubly));
	start=tmp;
	tmp->next=NULL;
	tmp->prev=NULL;
	printf("Enter data\n");
	scanf("%d",&tmp->data);
	}
else
	{
	tmp=start;
	while(tmp->next!=NULL)
		{
		tmp=tmp->next;
		}
	tmp1=(struct doubly*)malloc(sizeof(struct doubly));
	tmp1->next=NULL;
	tmp1->prev=tmp;
	tmp->next=tmp1;
   printf("Enter data\n");
	scanf("%d",&tmp1->data);
	}
}
int traverse_back()
{
struct doubly *tmp;
tmp=start;
while(tmp->next!=NULL)
	{
	tmp=tmp->next;
	}
while(tmp!=NULL)
	{
	printf("%d\n",tmp->data);
	tmp=tmp->prev;
	}
}
int traverse()
{
struct doubly *tmp;
tmp=start;
while(tmp!=NULL)
	{
	printf("%d\n",tmp->data);
	tmp=tmp->next;
	}

}
int count()
{
int c=0;
struct doubly *tmp;
tmp=start;

while(tmp!=NULL)
	{
	c=c+1;
	tmp=tmp->next;
	}
return(c);
}
int del_first()
{
struct doubly *tmp;
tmp=start;
start=tmp->next;
tmp->next->prev=NULL;
printf("Deleted Data=%d\n",tmp->data);
free(tmp);
}
int del_last()
{
struct doubly *tmp;
tmp=start;
while(tmp->next!=NULL)
	{
	tmp=tmp->next;
	}
tmp->prev->next=NULL;
printf("Delete data=%d\n",tmp->data);
free(tmp);
}
int del_pos()
{
struct doubly *tmp;
int pos,i;
printf("Enter pos\n");
scanf("%d",&pos);
if(pos<=count())
	{
	i=1;
	tmp=start;
	while(i<pos)
		{
		tmp=tmp->next;
		i=i+1;
		}
	tmp->prev->next=tmp->next;
	tmp->next->prev=tmp->prev;
	printf("Deleted data=%d\n",tmp->data);
	free(tmp);
	}
else
	{
	printf("Invalid pos\n");
	}
}
int ins_first()
{
struct doubly *n;
n=(struct doubly*)malloc(sizeof(struct doubly));
n->next=start;
start=n;
n->prev=NULL;
n->next->prev=n;
printf("Enter data\n");
scanf("%d",&n->data);
}
int ins_last()
{
struct doubly *tmp,*n;
tmp=start;
while(tmp->next!=NULL)
	{
	tmp=tmp->next;
	}
n=(struct doubly*)malloc(sizeof(struct doubly));
n->next=NULL;
n->prev=tmp;
tmp->next=n;
printf("Enter data\n");
scanf("%d",&n->data);
}
int ins_pos()
{
struct doubly *tmp,*n;
int pos,i;
printf("Enter pos\n");
scanf("%d",&pos);
if(pos<=count())
	{
	tmp=start;
	i=1;
	while(i<pos-1)
		{
		tmp=tmp->next;
		i=i+1;
		}
	n=(struct doubly*)malloc(sizeof(struct doubly));
	n->prev=tmp;
	n->next=tmp->next;
	tmp->next->prev=n;
	tmp->next=n;
	printf("Enter data\n");
	scanf("%d",&n->data);
	}
else
	{
	printf("Invalid Pos\n");
	}
}
