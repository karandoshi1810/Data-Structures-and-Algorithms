/*
Theory:Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end. A 
circular linked list can be a singly circular linked list or doubly circular linked list.
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
            data = val;
            next=NULL;
        }
};
/*Insertion related function*/
void insertAtHead(node* &head, int val) //node needs to be inserted at head
{
    node* n = new node(val); //creating a new node
    if(head==NULL)           //if head is null 
    {
        n->next=n;
        head=n;              //make new node the head
    }
    else
    {
        node* temp=head;     //temporary node to traverse LL
        while(temp->next!=head) //while next node is head keep moving one step
        {
            temp=temp->next;
        }
        temp->next=n;        //change links, next of tem will be n
        n->next=head;        //next of n will point to
    }
}
void insertAtTail(node* &head, int val) //node needs to be inserted at head
{
    node* n = new node(val);  //creating a new node
    if(head==NULL)   //if head is null 
    {
        insertAtHead(head, val);  //call the function insertAtHead
    }
    else
    {
        node* temp=head;  //temporary node to traverse the LL
        while(temp->next!=head)  //while next of temp does not contain head
        {
            temp=temp->next;  //move aheaad by one step
        }
        temp->next=n;  //change links, next of temp will point to new node
        n->next=head;  //next of n will point to head
    }
}

//function to display LL
void display(node* head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//function related to deletion of nodes
void deletion(node* head, int pos)
{
    node* temp=head;
    int count=1;
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,5);
    display(head);
}