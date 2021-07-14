#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* right;
    node* left;

    node(int val)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};
int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
node* buildTree(int postorder[],int inorder[],int start,int end)
{
    static int idx=end;
    if(start>end)
    {
        return NULL;
    }
    
    int curr=postorder[idx];
    idx--;
    node* n = new node(curr);

    int pos = search(inorder,start,end,curr);
    if(start==end)
    {
        return n;
    }
    n->right=buildTree(postorder,inorder,pos+1,end);
    n->left=buildTree(postorder,inorder,start,pos-1);

    return n;
    
}
void printInorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<endl;
    printInorder(root->right);
}
int main()
{
    int postorder[] ={4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(postorder,inorder,0,4);
    printInorder(root);
}