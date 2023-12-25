//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int minIdx=N-1;
        int i=N-2;
        for(;i>=0;i--){
            if(arr[i]<arr[i+1]){
                while(arr[minIdx]<=arr[i]){
                    minIdx--;
                }
                swap(arr[i], arr[minIdx]);
                int l=i+1;
                int r=N-1;
                while(l<r){
                    swap(arr[l++], arr[r--]);
                }
                break;
            }
            else{
                if(arr[i]<arr[minIdx]){
                    minIdx=i;
                }
            }
        }

        if(i<0){
            int l=0;
            int r=N-1;
            while(l<r){
                swap(arr[l++], arr[r--]);
            }
        }

        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends