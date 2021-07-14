#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* lchild;
        node* rchild;
        node(int val)
        {
            data=val;
            lchild=NULL;
            rchild=NULL;
        }
};
int heightOfTree(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=0,rheight=0;
    lheight+=heightOfTree(root->lchild);
    rheight+=heightOfTree(root->rchild);

    return max(lheight,rheight)+1;
}
int main()
{
    node* root = new node(1);
    root->lchild = new node(2);
    root->rchild = new node(3);
    root->lchild->lchild = new node(4);
    root->lchild->rchild = new node(5);
    root->rchild->lchild = new node(6);
    root->rchild->rchild = new node(7);
    cout<<heightOfTree(root)<<endl;

}