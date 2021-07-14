/*
Problem: Given a matrix search the target value,given that:
    Values are sorted in ascending order from left-right and
    Values are sorted in ascending order from top-bottom
Solution-1(Brute-Force Approach): Loop over the matrix and check the values and give the output
Solution-2(Optimised Approach): 
As the matrix is sorted rows and cols wise in ascending order we can start with right most element of first row.Then we can use 
approach of binary search if the target value is bigger than the current value then we can move to left side of matrix else if the 
value is smaller than the target value then we can move at bottom by making the col variable ++
Example:
1 2 3 4
5 6 7 8
9 10 11 12


*/
#include<iostream>
using namespace std;

int main()
{
    int n,m,target=0;
    cin>>n>>m;
    int matrix[10][10];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cin>>target;
    int row=0,col=m-1;
    bool found=false;
    while(row<n && col>=0)
    {
        if(matrix[row][col]==target)
        {
            found=true;
            break;
        }
        if(matrix[row][col]>target)
        {
            col--;
        }
        else
        {
            row++;
        }
        
    }
    if(found)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not-Found"<<endl;
    }
    
}