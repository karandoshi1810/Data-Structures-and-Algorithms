#include<iostream>
using namespace std;

int kadane(int arr[]);

int main()
{
    int values=0;
    cout<<"Enter total values"<<endl;
    cin>>values;
    int arr[values];
    for(int i=0;i<values;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<values;i++)
    {
        int currSum=0;
        for(int j=i;j<values;j++)
        {
            currSum+=arr[j];
            cout<<currSum<<endl;
        }
    }
    return 0;
}