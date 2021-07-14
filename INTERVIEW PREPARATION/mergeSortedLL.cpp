/*
Merge Two Sorted Linked List
Theroy: The aim is to merge two linked list which are sorted increasingly.
Algorithm:The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the 
last node in the result list, so appending new nodes is easy. The dummy node gives the tail something to point to initially when 
the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop 
proceeds, removing one node from either ‘a’ or ‘b’, and adding it to the tail.
*/
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data=0;
        node* next;
        node(int val)
        {
            data = val;
            next=NULL;
        }
};

void insert(node* &head, int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}

void display(node* & head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* merge(node* &h1, node* &h2)
{
    node* temp1 = h1;
    node* temp2 = h2;
    node* dummyNode=new node(-1);
    node* ptr3=dummyNode;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            ptr3->next=temp1;
            temp1=temp1->next;
        }
        else
        {
            ptr3->next=temp2;
            temp2=temp2->next;
        }
        ptr3=ptr3->next;
    }

    while(temp1!=NULL)
    {
        ptr3->next=temp1;
        temp1=temp1->next;
        ptr3=ptr3->next;
    }

    while(temp2!=NULL)
    {
        ptr3->next=temp2;
        temp2=temp2->next;
        ptr3=ptr3->next;
    }

    return dummyNode->next;
}

node* mergeRecursive(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* result=NULL;
    if(head1->data<head2->data)
    {
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else
    {
        result = head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}

int main()
{
    int ll1[]={1,4,5,7};
    int ll2[]={2,3,6};
    node* head1=NULL;
    node* head2=NULL;
    for(int i=0;i<4;i++)
    {
        insert(head1,ll1[i]);
    }
    for(int i=0;i<3;i++)
    {
        insert(head2,ll2[i]);
    }
    display(head1);
    display(head2);
    node* newHead=merge(head1,head2);
    display(newHead);
    node* newHead=mergeRecursive(head1,head2);
    display(newHead);

    return 0;

}