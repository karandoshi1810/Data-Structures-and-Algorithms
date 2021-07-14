#include<bits/stdc++.h>
using namespace std;
int count_sort(int arr[],int n);
int main()
{
    int arr[] = {1,4,5,8,1,2,6,5,8,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    count_sort(arr,len);
}

int count_sort(int arr[],int n)
{
    int m = arr[0];  //Initialize a variable max to find max variable because size of arrays willl be equal to max
    
    for(int i=0;i<n;i++)  //Finding max
    {
        m = max(m,arr[i]);
    }
    int count[10];        
    for(int i=0;i<n;i++)  //Count array will store the frequency of elements in original array
    {
        count[arr[i]++];
    }

    for(int i=i;i<n;i++)  //Update count by adding the frequency of previous element with frequency current element for whole array
    {
        count[i] += count[i-1];
    }

    int output[10];
    for(int i=0;i<n;i++) //Decrement the count of the value(arr[i]) and place arr[i] at that index in output array
    {
        output[--count[arr[i]]] = arr[i];
    }
 
    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<endl;
        //arr[i] = output[i];
    }
    
    return 0;
}