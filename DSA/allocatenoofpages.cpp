//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
     bool isPosiible(int A[], int N, int M, int mid){
        int studcount =1;
        int pages = 0;
        
        for(int i=0;i<N;i++){
            if(pages+A[i]<=mid){
                pages=pages+A[i];
            }
            else{
                studcount++;
                
                if(studcount>M || A[i]>mid){
                    return false;
                }
                
                pages = A[i];
            }
        }
        
        return true;
    }
    
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int s=0;
        int sum = 0;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        
        int e = sum;
        
        int mid = s+(e-s)/2;
        
        int ans =-1;
        
         if(M > N)
          return -1;
        
        while(s<=e){
            
            mid = s+(e-s)/2;
            if(isPosiible(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends