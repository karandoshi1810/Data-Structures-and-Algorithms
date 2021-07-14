#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
/*Preorder trversal is like: Root Left Right. 
For any order traversal keep in mind the position of root. Here root is first so we need to print the value as soon
the function starts
*/
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";      //print the value of root node
    preorder(root->left);       //call the function again for traversing left part of tree
    preorder(root->right);      //call the function again for traversing right part of tree
}

/*
Inorder Traversal: Left Root Right
For any order traversal keep in mind the position of root. Here root is at second position so we need to call the function first
for left sub tree then print the node and then call the function again for right subtree
*/
void inorder(struct node* root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);        //call the function again for traversing left part of tree
    cout<<root->data<<" ";      //print the value of root node
    inorder(root->right);       //call the function again for traversing right part of tree
}
int main()
{
    struct node* root= new node(1); //creating a root node
    root->left = new node(2);       //creating a left node and assigning a value
    root->right = new node(3);      //creating a right node and assigning a value
    root->left->left = new node(4); //creating a left node of the left node and assigning a value
    root->left->right = new node(5);//creating a right node of the left node and assigning a value
    root->right->left = new node(6);//creating a left node of the right node and assigning a value
    root->right->right = new node(7);//creating a right node of the right node and assigning a value

    inorder(root);
    cout<<endl;
    preorder(root);


}