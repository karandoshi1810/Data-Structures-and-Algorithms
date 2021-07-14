/*
Question: Find unique element in an array:
Description:There is an array containing elements in which there is exactly one element which appears only once and rest all 
appears two times. Find that unique element

Solution: XORing each and every element by iterating over the array gives the number which is unique in the array, as XOR gives 1
if two bits at same position are different. The numbers which are repeated will result zero and in the end we will get the unique
number.

Note: No need to sort the array, the will automatically return the unique element after XORing the whole array.
*/
#include<bits/stdc++.h>
using namespace std;

int unique(int a[],int n)
{
    int xorSum=0;
    for(int i=0;i<n;i++) //iterating over whole array
    {
        xorSum=xorSum^a[i]; //XORing every element 
    }
    return xorSum; //return the unique element
}

int main()
{
    int arr[]={57,61,21,57,61},result=0;
    result = unique(arr,6); //passing value to the function
    cout<<result<<endl;
    return 0;
}