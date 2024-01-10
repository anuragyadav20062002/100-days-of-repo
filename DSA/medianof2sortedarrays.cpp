//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
double func(vector<int>& arr1, vector<int>& arr2){
        int m=arr1.size(), n=arr2.size();
        int s=0, e=m; //no of elements to be picked from arr1
        int target=ceil((m+n)/2.0);
        int mid = s+(e-s)/2;
        while(s<=e){
            int l1=0, r1=0, l2=1e9, r2=1e9;
            if(mid-1>=0) l1=arr1[mid-1];
            if(mid<m) l2=arr1[mid];
            int rmid = target-mid;
            if(rmid-1>=0) r1=arr2[rmid-1];
            if(rmid<n) r2=arr2[rmid];
            
            if(r1 > l2){
                s=mid+1;
            }
            else if(l1 > r2){
                e=mid-1;
            }
            else{
                if((m+n)%2 == 0){
                    return (min(l2, r2) + max(r1, l1))/2.0;
                }else{
                    return max(r1, l1);
                }
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // binary search approach
        if(array1.size() > array2.size()){
            return func(array2, array1);
        }else{
            return func(array1, array2);
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends