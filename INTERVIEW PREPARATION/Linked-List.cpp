#include<bits/stdc++.h>
using namespace std;
//class to create and initialize a node
class node{
    public:
        int data;
        node* next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};
//insertion related functions
void insertAtTail(node* &head, int val) //function to insert a node at end of LL
{
    node* n = new node(val);  //creating a node
    if(head==NULL)
    {
        head = n;
    }
    else
    {
        node* temp = head; //temporary node to traverse the ll
        while(temp->next != NULL)
        {
            temp = temp->next; //jump to next node
        }
        temp->next = n;  //Inserting/Attaching node at end of ll
    }
}
void insertAtHead(node* &head, int val) //function to insert a node at start of LL
{
    node* n = new node(val); //creating a node
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        n->next=head; //new node will point to head
        head=n;       //new node will be head;
    }
}
//searching related function/s
bool searchNode(node* &head,int val)
{
    node* temp = head;

    while(temp!=NULL) //traverse whole ll
    {
        if(temp->data==val) //if node data matches with key then return true
        {
            return true;
        }
        temp=temp->next; //else jump to next node
    }
    return false; //if key is not present then return false
}

//deletion related functions
void deleteHead(node* &head)
{
    node* todelete = head; //save the node that needs to be deleted
    head = head->next; //jump to next node if available else it will be NULL

    delete todelete; //delete the determined node
}
void deleteNode(node* &head, int val)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        deleteHead(head);
    }
    if(head->data == val)
    {
        deleteHead(head);
    }
    else
    {
        node* temp = head; //temporary node to traverse the ll
        while(temp->next->data!=val) //traverse ll till next node with deletion data is not found
        {
            temp=temp->next;
        }
        node* todelete = temp->next; //save the node that needs to be deleted
        temp->next=temp->next->next; //current node will point to next node of node that needs to be deleted
        delete todelete;
    }

}

//display related functions
void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
//reverseing related functions
void reverse(node* head)
{
    if(head==NULL)
    {
        return;
    }
    reverse(head->next);
    cout<<head->data<<"->";
}

node* revserseIter(node* &head)
{
    node* prevPtr=NULL;
    node* currentPtr=head;
    node* nextPtr;

    while(currentPtr!=NULL)
    {
        nextPtr = currentPtr->next;
        currentPtr->next=prevPtr;

        prevPtr = currentPtr;
        currentPtr = nextPtr;
    }

    return prevPtr;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    display(head);
    int ans=searchNode(head,4);
    cout<<ans<<endl;
    deleteNode(head,4);
    display(head);
    insertAtHead(head,4);
    reverse(head);
    cout<<"NULL"<<endl;
    display(head);
    return 0;
}
