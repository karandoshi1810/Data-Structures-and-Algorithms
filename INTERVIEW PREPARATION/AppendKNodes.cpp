/*
theory: Append last k nodes at beginning
A linked list with n nodes needs to be splitted from kth node and append at the end of linked list. For this the LL needs to
be splitted from kth node and that linked list is appended at the end of remaining part of linked list.
-----------------------------------------------------------------------------------------------------------------------------------
Algorithm:
Find the first node of the last M nodes in the list, this node will be the new head node so make the next pointer of the previous 
node as NULL and point the last node of the original list to the head of the original list. Finally, print the updated list.

*/
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int val)
        {
            data=val;
            next=NULL;
        }
};

void insert(node* &head,int val)
{
    node* n = new node(val);
    node* temp = head;
    if(head==NULL)
    {
        head=n;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        n->next=NULL;
        temp->next=n;
    }
    
}
int length(node* head)
{
    int l=0;
    while(head!=NULL)
    {
        l++;
        head=head->next;
    }
    return l;

}
node* kappend(node* &head, int k)
{
    node* newHead;
    node* newTail;
    node* tail=head;

    int l = length(head);
    int count=1;
    k=k%l;
    while(tail->next!=NULL)
    {
        if(count==l-k)
        {
            newTail = tail;
        }
        else if(count==l-k+1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail=NULL;
    tail->next=head;
}
int main()
{
    node* head=NULL;
    int k=3;
    for(int i=1;i<7;i++)
    {
        insert(head,i);
    }
    kappend(head,k);
    return 0;
}