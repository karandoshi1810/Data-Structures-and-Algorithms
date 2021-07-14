#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next=NULL;
    }
};

void insert(node* &head,int val)
{
    node* n = new node(val);
    node* temp = head;
    if(head==NULL)
    {
        n=head;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
void display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void createIntersection(node* &head,node* &head1, int pos)
{
    node* temp1=head;
    node* temp2=head1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int length(node* &head)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

bool detectIntersection(node* &head,node* &head1)
{
    node* temp1=NULL;
    node* temp2=NULL;
    int d=0;

    int l1=length(head);
    int l2=length(head1);

    if(l1>l2)
    {
        temp1=head;
        temp2=head1;
        d=l1-l2;

        while(d--)
        {
            temp1=temp1->next;
            if(temp1==NULL)
            {
                return 0;
            }
        }
    }
    else
    {
        temp1=head1;
        temp2=head;
        d=l2-l1;

            while(d--)
            {
            temp2=temp2->next;
            if(temp2==NULL)
            {
                return 0;
            }
        }
    }

    while(temp1!=NULL && temp2!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2)
        {
            return 1;
        }
    }
    return 0;
    
    
}
int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);

    node* head1=NULL;
    insert(head1,4);
    insert(head1,5);
    insert(head1,6);
    insert(head1,7);

    display(head);
    display(head1);

    //createIntersection(head,head1,3);
    //cout<<detectIntersection(head,head1)<<endl;



}
