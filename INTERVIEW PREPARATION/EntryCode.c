/*
Expected time to Complete - 110 Min.
Total Marks: 20
"	Create Circular Queue with given structure. [2 Marks]
"	 Persons in Queue will be arrange based on priority. Here priority will be managed by count of consonent in the Person Name. [5 Marks]
"	eg . "Kapil" = 3 (k,p,l)
"	Add at least 10 Persons in a Queue [3 Marks]
"	Now Dequeue (Delete) Person from Both the end One by one. [4 Marks]
"	Push Deleted Person in Stack. (PUSH()) [ 3 Marks ]
"	Display Person Name by calling POP() on screen [3 Marks]

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Person
{
	char *name;
	int priority; //count of consonent
	struct Person *next;
};

// Function to create a new node
struct Person* newNode(char *name,int priority)
{
    struct Person* temp = (struct Person*)malloc(sizeof(struct Person));
    temp->name = name;
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

struct Person *FIRST=NULL, *LAST=NULL;
struct Person *stack=NULL;

void Enqueue(int);
struct Person * Dequeue();
void Push(struct Person *);
char * Pop();
int definePriority(char* nam);

int main()
{
	Enqueue(10); //At Least 10 Nodes
	/*while(queue is not Empty)
	{
		Push(Dequeue());
	}
	While(Stack is not Empty)
	{
		Pop();
	}*/
	return 0;
}

int definePriority(char* nam)
{
	int consonants=0,i;
	for(i=0;i<strlen(nam);i++)
	{
		if(nam[i]!='a' && nam[i]!='A' && nam[i]!='e' && nam[i]!='E' && nam[i]!='i' && nam[i]!='I' && nam[i]!='o' && nam[i]!='O' && nam[i]!='u' && nam[i]!='U')
		{
			consonants++;
		}
	}
	return consonants;
}

void Enqueue(int n) //add n person in queue
{
	while(n--)
	{
		char name[15];
		printf("Enter name:  ");
		scanf("%s",name);
		//printf("%s",name);

		int value = definePriority(name);
		printf("%d\n",value);
		struct Person* nd = newNode(name,value);


		if(FIRST==NULL && LAST==NULL)
		{
			FIRST=LAST=nd;
		}
		else
		{
		    struct Person* head = FIRST;
			if(head->priority > nd->priority)
			{
				nd->next=head;
				head=nd;
			}
			else
			{
				while(head->next != NULL && head->next->priority <= nd->priority)
				{
					head=head->next;
				}
				nd->next=head->next;
				head->next=nd;
			}
		}
	}
	struct Person* head = FIRST;
	while(head->next!=NULL)
    {
        printf("%d\t",head->priority);
        head=head->next;
    }
}

struct Person * Dequeue()
{
    static int flag=1;
    if(flag==1)
    {
       struct Person *p=NULL;
        struct Person *head = FIRST;
        FIRST=FIRST->next;
        flag=0;
        return head;
    }
    else
    {

    }



	return p;
}
void Push(struct Person *p)
{

}
char *Pop()
{

	//return *char;
}
