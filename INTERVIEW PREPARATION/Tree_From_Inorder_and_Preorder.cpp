#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int val)
        {
            val=data;
            left=NULL;
            right=NULL;
        }
};
int search(int inorder[], int start, int end,int pos)
{
    for(int i=start;i<end;i++)
    {
        if(inorder[i]==pos)
        {
            return i;
        }
    }
    return -1;
}
node* buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node* n = new node(curr);
    int pos=search(inorder,start,end,curr);
    if(start==end)
    {
        return n;
    }
    n->left = buildTree(preorder,inorder,start,pos-1);
    n->right = buildTree(preorder,inorder,pos+1,end);

    return n;

}

void inOrderPrint(node* root)
{
    
    if(root==NULL)
    {
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}
int main()
{
    int preorder[]={1,2,4,3,5}; //Root Left Right
    int inorder[]={4,2,1,5,3};  //Left Root Right

    node* root = buildTree(preorder,inorder,0,4);
    inOrderPrint(root);
    
}


