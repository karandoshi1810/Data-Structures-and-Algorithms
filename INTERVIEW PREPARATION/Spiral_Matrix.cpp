/*Spiral Matrix
01 02 03 04
14 15 16 05
13 20 17 06
12 19 18 07
11 10 09 08
---------------------------------------
Logic: Four variables are required. row_start=0,row_end=total_rows-1,col_start=0,col_end=total_col-1
While row_start<row_end && col_start<col_end perform below mentioned code
    Print elements from col_start to col_end using row_start because of 0th row being printed and make row_start++(Printed first row:01,02,03,04)
    Print elements from row_start to row_end using col_end because of last col being printed and make col_end--(Printed last column:05,06,07,08)
    Print elements from col_end to row_end using row_end because of last row being printed and make row_end--(Printed last row:09,10,11)
    Print elements from row_end to row_start using col_start because of 0th col being printed and make col_start--(Printed first column:12,13,14) 
*/

#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    cin>>rows>>cols;
    int arr[rows][cols];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>arr[i][j];
        }
    }

    int row_start = 0,row_end=rows-1,col_start=0,col_end=cols-1;

    while(row_start<row_end && col_start<col_end)
    {
        for(int row=col_start;row<=col_end;row++)
        {
            cout<<arr[row_start][row]<<" ";
        }
        row_start++;


        for(int col=row_start;col<=row_end;col++)
        {
            cout<<arr[col][col_end]<<" ";
        }
        col_end--;
 

        for(int row=col_end;row>=col_start;row--)
        {
            cout<<arr[row_end][row]<<" ";
        }
        row_end--;
  

        for(int col=row_end;col>=row_start;col--)
        {
            cout<<arr[col][col_start]<<" ";
        }
        col_start++;
    }

}