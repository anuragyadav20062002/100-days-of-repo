//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
   long long trappingWater(int arr[], int n){
        // code here
         if(n<3) return 0;
       long long water = 0;
       int left = 0;
       int right = n-1;
       int leftwall = arr[0];
       int rightwall = arr[n-1];
       while(left<right)
       {
           if(leftwall > rightwall)
           {
               water += rightwall - arr[right];
               right--;
               rightwall = max(rightwall, arr[right]);
           }
           else
           {
               water += leftwall - arr[left];
               left++;
               leftwall = max(leftwall, arr[left]);
           }
       }
       return water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends