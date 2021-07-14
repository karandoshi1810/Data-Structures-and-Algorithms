/*
a[1..Lo-1] zeroes red
a[Lo..Mid-1] ones (white)
a[Mid..Hi] unknown
a[Hi+1..N] twos (blue)
If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
If the element is 2 then swap it with an element in high range.

Algorithm:
Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
Traverse the array from start to end and mid is less than high. (Loop counter is i)
If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
If the element is 1 then update mid = mid + 1
If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
Print the output array.
*/
#include<bits/stdc++.h>
using namespace std;

void dnf_sort(int arr[],int n);
int main()
{
    int arr[] = {1,0,2,1,0,1,2,1,2};
    dnf_sort(arr,9);

    /*for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }*/
    return 0;
}

void dnf_sort(int arr[],int n)
{
    int low = 0; //will to starting of array
    int mid = 0;//will pont to starting of array
    int high = n-1; //will point to end of array
    int temp=0;
    while(mid<=high)
    {
        switch(arr[mid])
        {
            case 0:
                temp=0;
                temp = arr[mid];
                arr[mid] = arr[low];
                arr[low]=temp;
                mid++;
                low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                temp = 0;
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
            default:
                cout<<"Please enter three different numbers only"<<endl;

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}