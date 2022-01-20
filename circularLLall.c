#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct circular
{
	int data;
	struct circular *next;
};
struct circular *start=NULL;
void create();
void traverse();
void ins_first();
void del_first();
void main()
{
	int ch;
	while(1)
	{
		system("cls");
		printf("Press 1 for creation\n");
		printf("Press 2 for Traverse\n");
		printf("Press 3 for Insert_first\n");
		printf("Press 4 for del first\n");
		printf("Press 5 for Exit\n");
		printf("select your option\n");
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
			ins_first();
		}
		else if(ch==4)
		{
			del_first();
			getch();
			
		}
		else if(ch==5)
		{
			exit(0);
		}
	}
}
			
void create()
{
	struct circular *tmp,*tmp1;
	if(start==NULL)
	{
		tmp=(struct circular*)malloc(sizeof(struct circular));
		start=tmp;
		tmp->next=start;
		printf("Enter data\n");
		scanf("%d",&tmp->data);
	}
	else
	{
		tmp=start;
		while(tmp->next!=start)
		{
			tmp=tmp->next;
		}
		tmp1=(struct circular*)malloc(sizeof(struct circular));
		tmp1->next=tmp->next;
		tmp->next=tmp1;
		printf("Enter data\n");
		scanf("%d",&tmp1->data);
	}
		
}	
void traverse()
{
	struct circular *tmp;
	tmp=start;
	do
	{
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}while(tmp!=start);
	do
	{
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}while(tmp!=start);
}	
void ins_first()
{
	struct circular *tmp,*tmp1;
	tmp=start;
	while(tmp->next!=start)
		tmp=tmp->next;
	tmp1=(struct circular*)malloc(sizeof(struct circular));
	tmp1->next=start;
	start=tmp1;
	tmp->next=start;
	printf("Enter data\n");
	scanf("%d",&tmp1->data);
	
	
}
void del_first()
{
	struct circular *tmp,*tmp1;
	tmp=start;
	while(tmp->next!=start)
		tmp=tmp->next;
	tmp1=start;
	start=tmp1->next;
	tmp->next=start;
	printf("deleted data=%d\n",tmp1->data);
	free(tmp1);
	
}
