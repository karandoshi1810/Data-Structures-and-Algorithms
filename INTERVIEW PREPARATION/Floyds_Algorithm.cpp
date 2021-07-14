/*
Theory: 
Floyd's Algorithm is used ot detect a cycle in any linked List. Cycle is a situation in which two nodes point to one
same node. ANd due to this there is no ending of the data structure i.e. algorithm does not encounter NULL which specifies the 
end.
---------------------------------------------------------------------------------------------------------------------------------
Algorithm/s:
Approach-1(Floyd's Algorithm): This is the fastest method and has been described below:  
Step-1)Traverse linked list using two pointers.
Step-2)Move one pointer(slow_p) by one and another pointer(fast_p) by two.
Step-3)If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
---------------------------------------------------------------------------------------------------------------------------------
Remove Cycle: To remove cycle point anyone of the pointers to head again and then keep moving forward bith pointers by 1 step.
During this check if 'next'of both pointers point to same element or not, if yes then point slow pointer to NULL if fast was 
reiterated to head, else point fast to NULL. If 'next' of both pointers is not pointing to same element then again move 1 step
till condition is satisfied.
---------------------------------------------------------------------------------------------------------------------------------
Solution 2: This problem can be solved without hashmap by modifying the linked list data-structure. 
Approach: This solution requires modifications to the basic linked list data structure. 
Step-1)Have a visited flag with each node.
Step-2)Traverse the linked list and keep marking visited nodes.
Step-3)If you see a visited node again then there is a loop. This solution works in O(n) but requires additional information with 
each node.
Step-4)A variation of this solution that doesn’t require modification to basic data structure can be implemented using a hash, 
just store the addresses of visited nodes in a hash and if you see an address that already exists in hash then there is a loop.
*/
#include<bits/stdc++.h>
using namespace std;
//Class to create and initialize node
class node{
    public:
        int data; //data of node
        node* next; //next, where adddress of next node will ne stored
        node(int val) //constructor to initialize data and val;
        {
            data = val;
            next=NULL;
        }

};

//function to insert node
void insert(node* &head, int val)
{
    node* n = new node(val); //create a new node
    if(head==NULL) //if head is null then new node will be the head
    {
        head=n;
        return;
    }

    node* temp =head; //temporary variable to traverse linked list
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;  //node inserted at end of LL
}

//display the linked list
void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}


//function to create a cycle
void createCycle(node* &head, int pos) //pos will signify where the cycle will begin. Means last node will poin to node
                                       //at this position, hence like 1->2->3->4. if pos=2 then 1->2->3->4->2
{
    if(head==NULL) //if ll is null then cycle cannot be formed
    {
        cout<<"Create a Linked List First";
        return;
    }

    node* temp = head; //temporary variable to traverse LL
    node* triggerNode; //from this node cycle can be formed. Last node will point to this node
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos) //if pointer has reached the position then assign it as trigger node
        {
            triggerNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=triggerNode; //assign next of last to triggerNode, hence cycle is formed
}

//function to detect a cycle
bool detectCycle(node* &head)
{
    node* slowPtr=head;
    node* fastPtr=head;

    while(fastPtr!=NULL && fastPtr->next!=NULL)//if fast or fast->next is null then no cycle.Another condition can be
                                               //while(slowPtr && fastPtr && fastPtr->next!=NULL) 
    {
        fastPtr = fastPtr->next->next; //fast will move 2 steps
        slowPtr = slowPtr->next; //slow will move 1 step. By this if there will be a cycle then both ptrs will meet at 
                                 //one common node.
        if(fastPtr==slowPtr)
        {
            return true;
        }
    }
    return false;
}

//function to remove cycle
void removeCycle(node* &head)
{
    node* slowPtr=head;
    node* fastPtr=head;
    do{                         //detecting cycle
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
    }while(slowPtr!=fastPtr);

    fastPtr=head; //sending fastPtr to start. slowPtr can also be sent, any one can be sent
    while(fastPtr->next != slowPtr->next) //move 1 step till next of both ptrs point to same node
    {
        fastPtr=fastPtr->next;
        slowPtr = slowPtr->next;
    }
    slowPtr->next = NULL; //make slow point to NULL, if fast was reiterated to head else bice versa
}
int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    display(head);
    createCycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    return 0;

}