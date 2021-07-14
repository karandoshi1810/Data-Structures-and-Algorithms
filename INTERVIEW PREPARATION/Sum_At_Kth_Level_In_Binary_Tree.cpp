#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int sumAtK(node* root, int k)
{
    if(root==NULL) //if root is null then return
    {
        return -1;
    }
    int level=0,sum=0; 
    queue<node*> q; //creating a queue with node type(it will hold pointers)
    q.push(root);  //inserting root in queue
    q.push(NULL);  //inserting null, because it signifies that first level is traversed
    while(!q.empty()) //while queue is not empty perform following operations
    {
        node * n = q.front(); //create a node which will hold value of front of queue
        q.pop();  //pop the front of the queue
        if(n!=NULL) //check if the node is null or not
        {
            if(level==k) //if not we have reached teh desired level
            {
                sum+=n->data; //if yes then add its value to sum variable
            }
            if(n->left)  //if the node has left subtree
                {q.push(n->left);} //push it to the queue
            if(n->right)  //if the node has right subtree
                {q.push(n->right);}  //push it to the queue
        }
        else if(!q.empty()) //if node is null then check if the queue is empty or not
        {
            q.push(NULL); //if not then add a null at end of queue. It signifies that traversal of one level is done and in
                          //next iteration traversal of next level will begin.
        }
    }

    return sum;
}

int main()
{
    //creating a tree
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left=new node(4);
    root->left->right=new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<sumAtK(root,2)<<endl;
}