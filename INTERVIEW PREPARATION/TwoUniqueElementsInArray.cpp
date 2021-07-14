/*
Problem: Given an array find two unique elements present in that array rest all elements are present in pair.

Description:There is an array containing elements in which there are exactly two element which appears only once and rest all 
appears two times. Find that unique element.

Solution: On XORing the whole array as done in previous question we get an result which is XOR of whole array.
->Now we can conculde that teh answer received is the XOR of the two unique elements.
->In that answer we need to find the right most set bit which tells us that this is the unique bit in both the numbers, so we need
to find that unique bit which is '1' in the answer, it can be done using a "while" loop
->Now once we get that bit which is unique we will find the elements which has "1" at that particular placevalue and XOR all those
values. We know if a number contains 1 at a particular place then and it is not unique then it will be cancelled out, so at the end
we will get the 1st unique element.
->On XORing the element received in above step with the answer received in 1st step we will get the second unique element in an 
array

Eg: {1,2,3,4,2,1}
    {001,010,011,100,010,001}
->Xoring all values will return : 111(XOR of 011-3 &100-4)
->Find rightmost 1 in the result which is at position 0(111)
->Find all the elememnts in array with 0th bit=1 in array(1,3,1)
->Xoring them will return 3 as answer because the pair of 1s will be zero]
->Xoring the result of above step with the result in step-1 we will get second number: 011^111=100(4)
*/

void unique(int a[],int n);
int setBit(int sum,int p);

#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,2,1};
    unique(arr,6);
    return 0;
}

void unique(int a[],int n)
{
    int xorSum=0;
    for(int i=0;i<n;i++) //Xor of whole array
    {
        xorSum=xorSum^a[i]; // The anser will be XOR of two different elements presrnt in array
    }
    int setbit=0; 
    int pos=0,tempXor=xorSum;
    while(setbit!=0) //Iterate till we find the set bit in 'xorSum'
    {
        setbit = xorSum & 1; //& with the xorSum to and set the answer in setbit which will be checked every time in while loop
        pos++; //the postion is updated which at end of loop will tell which bit is set
        xorSum=xorSum>>1; //right shift the number so that we can check for all the values in the number
                          //Eg: 010-> Element at 0th index is not set do on right shift->001
                          // In this we have 1 at 0th index so the condition will be true and we will get postion as 1
    }
    int num1=0; 
    for(int i=0;i<n;i++) //Iterate over whole array 
    {
        if(setBit(a[i],pos)){ //Check if the ith element have a bit set at the same place defined by the "pos" variable
            num1= num1^a[i]; //if yes then XOR that value, at the end we will get only the unique value in the array rest will 
                             //occur in pair so will be filtered
        }
    }
    cout<<num1<<endl;
    cout<<(tempXor^num1)<<endl; //XOR the result with the value returned in first step i.e. tempXor
}

int setBit(int sum,int p)
{
    return ((sum & (1<<p))!=0);
}