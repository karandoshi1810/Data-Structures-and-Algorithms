#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data=0;
        node* left;
        node* right;

        node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
        }
};
void inOrderTraversal(node * root)
{
    queue<node*> q; //A queue of node type (it will hold pointers)
    q.push(root);   //insering root in queue
    q.push(NULL);   //inserting a null to identify that first level is traversed

    while(!q.empty()) //while there is/are elements present in queue
    {
        node* node = q.front(); //create a node of front of the queue
        q.pop();  //remove the front of the queue as its value is already stored in node
        if(node!=NULL)  //if the node(front node of queue) is not null
        {
            cout<<node->data<<" ";  //output the value of node
            if(node->left)  //if it has left subtree
            {
                q.push(node->left);  //then add it to the queue
            }
            if(node->right)  //if it has right subtree
            {
                q.push(node->right);  //add it to queue
            }
        }
        else if(!q.empty()) //if queue is not empty and the node at front is null 
        {
            q.push(NULL);  //then add a null at end because it signifies that traversal of a level completed and next level will
                           //begin after this iteration
        }
    }
}
int main()
{
    node* root = new node(1); //Creating a tree

    root->left = new node(2);
    root->right = new node(3);

    root->left->left=new node(4);
    root->left->right=new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    inOrderTraversal(root);
}