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
void del_last();
void del_pos();
void traverse_back();
void search();
void multi_digit();
void main()
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
	printf("Press 8 for delete Last\n");
	printf("Press 9 for delete pos\n");
	printf("Press 10 for Traverse Back\n");
	printf("Press 11 for Search\n");
	printf("Press 12 for Multi-Digit\n");
	printf("Press 13 for Exit\n");
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
	else if(ch==8)
		{
		del_last();
		getch();
		}
	else if(ch==9)
		{
		del_pos();
		getch();
		}
	else if(ch==10)
		{
		traverse_back();
		getch();
		}
	else if(ch==11)
		{
		search();
		getch();
		}
	else if(ch==12)
		{
		multi_digit();
		getch();
		}
	else if(ch==13)
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
void del_last()
{
struct singly *tmp,*tmp1;
tmp=start;
while(tmp->next!=NULL)
	{
	tmp1=tmp;
	tmp=tmp->next;
	}
tmp1->next=NULL;
printf("Deleted Data=%d\n",tmp->data);
free(tmp);
}
void del_pos()
{
struct singly *tmp,*tmp1;
int pos,i;
printf("Enter pos\n");
scanf("%d",&pos);
if(pos<=count())
	{
	tmp=start;
	i=1;
	while(i<=pos-1)
		{
		tmp1=tmp;
		tmp=tmp->next;
		i=i+1;
		}
	tmp1->next=tmp->next;
	printf("Deleted Data=%d\n",tmp->data);
	free(tmp);
	}
else
	{
	printf("Invalid Pos\n");
	}
}
void traverse_back()
{
struct singly *tmp;
int i,j;
i=1;
while(i<=count())
	{
	j=1;
	tmp=start;
	while(j<=count()-i)
		{
		tmp=tmp->next;
		j=j+1;
		}
	printf("%d\n",tmp->data);
	i=i+1;
	}
}
void search()
{
struct singly *tmp;
int n,c=0;
printf("Enter data for search\n");
scanf("%d",&n);
tmp=start;
while(tmp!=NULL)
	{
	c=c+1;
	if(n==tmp->data)
		{
		printf("Data found at node no=%d\n",c);
		break;
		}
	else
		{
		tmp=tmp->next;
		}
	}
if(tmp==NULL)
	{
	printf("Data not found\n");
	}
}
void multi_digit()
{
struct singly *tmp,*tmp1;
int num,d;
printf("Enter any multi-digit no\n");
scanf("%d",&num);
if(start!=NULL)
	{
	while(num>0)
		{
		d=num%10;
		tmp1=(struct singly*)malloc(sizeof(struct singly));
		tmp=start;
		while(tmp->next!=NULL)
			{
			tmp=tmp->next;
			}
		tmp->next=tmp1;
		tmp1->next=NULL;
		tmp1->data=d;
		num=num/10;
		}
	}
else
	{
	printf("Plz create your first node\n");
	}

}
