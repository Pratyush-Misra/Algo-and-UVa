#include <iostream>
#include<vector>

using namespace std;

    
int partition(vector<int>& nums, int l,int h)
{
    int pivot=nums[l];
    
    int i=l,j=h;
    
    while(i<j)
    {
        while(nums[i]<=pivot) i++;
        while(nums[j]>pivot) j--;
        
        if(i<j) { swap(nums[i++],nums[j--]); }
    }
    
    swap(nums[l],nums[j]);
    return j;
}

int solve(vector<int>& nums, int l,int h,int k)
{
     while(l<h)
    {
        int p=partition(nums,l,h);
        
        if(p==nums.size()-k) return nums[p];
        
        else if(nums.size()-k < p) h=p-1;
        
        else l=p+1;
    }
    
    return nums[l];
}
    
    
    
int findKthLargest(vector<int>& nums, int k) 
{
    return solve(nums,0,nums.size()-1,k);    
}

int main(){
    vector<int> v;
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << findKthLargest(v,n-k) << endl;
}