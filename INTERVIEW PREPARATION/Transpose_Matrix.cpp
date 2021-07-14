/*Transpose of a matrix
Input:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output:
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

Two possible logic:
1) Loop over whole matrix and set transpose matrix's[i][j] = original matrix's[j][i] or transpose matrix's[j][i] = original matrix's[i][j]
2) Observe that we need to swap only those values which are above principal matrix with the values below principal matrix i.e 2 with 5
   9 with 3 and so on
   outer loop will loop till end of rows:
    inner loop from current row i till end of rows
        temp = arr[i][j]
        arr[i][j] = arr[j][i]
        arr[i][j] = temp
    In our case
        temp = arr[j][i]
        tran[j][i] = arr[i][j]
        tran[i][j] = temp

*/

#include<iostream>
using namespace std;

void transpose(int arr[4][4],int tran[4][4]);

int main()
{
    int rows=4,cols=4;
    int arr[4][4],tran[4][4];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>arr[i][j];
        }
    }
    transpose(arr,tran);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<tran[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

void transpose(int arr[4][4],int tran[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)//int j=i;j<4;j++
        {
            /*int temp=0;
            temp = arr[j][i];
            tran[j][i] = arr[i][j];
            tran[i][j] = temp;*/

            tran[j][i] = arr[i][j];
        }
    }
}