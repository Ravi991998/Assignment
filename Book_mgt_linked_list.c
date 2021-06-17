#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int id1=1;

struct Book
{
	int id;
	char name[15];
	char authname[15];
	struct Book* next;
}*head=NULL;

void insert(char bname[15],char aname[15])
{
	struct Book* newnode=(struct Book*)malloc(sizeof(struct Book));
	struct Book* temp=head;
	
	newnode->id=id1++;
	strcpy(newnode->name,bname);
	strcpy(newnode->authname,aname);
	newnode->next=NULL;
	
	if(temp==NULL)
	{
		head=newnode;
		printf("\nBook Entered at the First Position successfully!!!");
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
				
		temp->next=newnode;
		printf("\nBook Entered at the last Position successfully!!!");
	}
}

void search()
{
	int count=0;
	char name[20];
	struct Book* current=head;
	
	printf("\nEnter the Name of the Book: ");
	scanf("%s",&name);
		
	if(current==NULL)
		printf("\nThere are no Books to Search!!!");
		return;
	while(current->next!=NULL)
	{
		count++;
		if(strcmp(current->name,name)==0)
		{
			printf("\nBook Found at %d Position!!!",count);
			return;
		}
		current=current->next;
	}
	printf("\nBook Does not Exist!!!");
}

void removebook()
{
	struct Book* prev;
	struct Book* temp=head;
	
	if(temp==NULL)
	{
		printf("\nThere are no Books to Remove!!!");
	}
	else
	{
		if(temp->next==NULL)
		{
			head=temp->next;    //here head should be made null and not temp
			printf("\nAll the Books have been Removed!!");
			id1--;
			free(temp);
		}
		else
		{
			while(temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
			printf("\nLast Book Removed Succesfully!!");
			id1--;
			free(temp);
		}
	}
}

void display()
{
	struct Book* temp;
	if(head==NULL)
		printf("\nThere are no Books to Display!!!");
	else
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("\n===========================================================");
			printf("\nBook ID: %d\nBook Name: %s\nAuthor Name: %s\n",temp->id,temp->name,temp->authname);
	    }
	}
}

void main()
{
	head=NULL;
	int opt;
	char bname[15],aname[15];
		
	while(1)
	{
		printf("\n\n1.Insert Book\n2.Remove Book\n3.Display Books\n4.Search\n5.Exit\n\nPlease Enter your Choice:  ");
		scanf("%d",&opt);
			
		switch(opt)
		{
			default:printf("\nPlease Enter Appropriate Option!!!");
					break;
				
			case 1: printf("\nEnter the name of the Book: ");
				    scanf("%s",bname);
				    //fgets(bname,15,stdin);
				    printf("\nEnter the name of the Author: ");
				    scanf("%s",aname);
					//gets(aname);
					insert(bname,aname);
					break;
					
			case 2: removebook();
					break;
			
			case 3: display();
					break;
					
			case 4: search();
					break;
			
			case 5:exit(0);
					
		}
    } 
}
