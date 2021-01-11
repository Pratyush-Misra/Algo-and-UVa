#include <iostream>
#include <algorithm>
using namespace std;
int firstOccurance(int a[],int n,int key)
{
    int s=0;
    int e=(n-1);
    int resIdx=(-1);
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]<key)
            s=mid+1;
        else if(a[mid]>key)
            e=mid-1;
        else
        {
            resIdx=mid;
            e=mid-1;            //since first occurance so it must be on left side of where a[mid]=key
        }
    }
    return resIdx;
}

int lastOccurance(int a[],int n,int key)
{
    int s=0;
    int e=(n-1);
    int resIdx=(-1);
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]<key)
            s=mid+1;
        else if(a[mid]>key)
            e=mid-1;
        else
        {
            resIdx=mid;
            s=mid+1;            //since last occurance so it must be on right side of where a[mid]=key
        }
    }
    return resIdx;
}

int main() {
    int a[]={1,2,5,8,8,8,8,10,12,15,20};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    cout<<"first: "<<firstOccurance(a,n,key)<<endl;
    cout<<"last: "<<lastOccurance(a,n,key)<<endl;

	return 0;
}
