#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct singly
{
int data;
struct singly *next;
};
struct singly *start=NULL;
void create();
void traverse();
int count();
void ins_first();
void ins_last();
void ins_pos();
void del_first();
int main()
{
int ch;
while(1)
	{
	printf("Press 1 for creation\n");
	printf("Press 2 for Traverse\n");
	printf("Press 3 for count\n");
	printf("Press 4 for insert first\n");
	printf("Press 5 for insert last\n");
	printf("Press 6 for insert pos\n");
	printf("Press 7 for delete first\n");
	printf("Press 11 for Exit\n");
	printf("Select Your option\n");
	scanf("%d",&ch);
	if(ch==1)
		{
		create();
		}
	else if(ch==2)
		{
		traverse();
		getch();
		}
	else if(ch==3)
		{
		int x;
		x=count();
		printf("Total no of Node=%d\n",x);
		getch();
		}
	else if(ch==4)
		{
		ins_first();
		}
	else if(ch==5)
		{
		ins_last();
		}
	else if(ch==6)
		{
		ins_pos();
		}
	else if(ch==7)
		{
		del_first();
		getch();
		}
	else if(ch==11)
		{
		exit(0);
		}
	}
}
void create()
{
struct singly *tmp;
if(start==NULL)
	{
	tmp=(struct singly*)malloc(sizeof(struct singly));
	start=tmp;
	tmp->next=NULL;
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
	tmp->next=(struct singly*)malloc(sizeof(struct singly));
	tmp->next->next=NULL;
	printf("Enter data\n");
	scanf("%d",&tmp->next->data);
	}
}
void traverse()
{
struct singly *tmp;
tmp=start;
while(tmp!=NULL)
	{
	printf("%d\n",tmp->data);
	tmp=tmp->next;
	}
}
int count()
{
struct singly *tmp;
int c=0;
tmp=start;
while(tmp!=NULL)
	{
	c=c+1;
	tmp=tmp->next;
	}
return c;
}
void ins_first()
{
struct singly *tmp;
tmp=(struct singly*)malloc(sizeof(struct singly));
tmp->next=start;
start=tmp;
printf("Enter data\n");
scanf("%d",&tmp->data);
}
void ins_last()
{
struct singly *tmp,*tmp1;
tmp1=(struct singly*)malloc(sizeof(struct singly));
tmp=start;
while(tmp->next!=NULL)
	{
	tmp=tmp->next;
	}
tmp->next=tmp1;
tmp1->next=NULL;
printf("Enter data\n");
scanf("%d",&tmp1->data);
}
void ins_pos()
{
struct singly *tmp,*tmp1;
int pos,i;
printf("Enter pos for insert\n");
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
	tmp1=(struct singly*)malloc(sizeof(struct singly));
	tmp1->next=tmp->next;
	tmp->next=tmp1;
	printf("Enter data\n");
	scanf("%d",&tmp1->data);
	}
else
	{
	printf("Invalid pos\n");
	}
}
void del_first()
{
struct singly *tmp;
tmp=start;
start=tmp->next;
printf("Deleted data=%d\n",tmp->data);
free(tmp);
}