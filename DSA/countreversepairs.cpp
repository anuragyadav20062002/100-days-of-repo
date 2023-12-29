//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            int res = obj.countRevPairs(N, arr);
            System.out.println(res);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

using ll = long long;
class Solution {
    private:
    void mergeArr(vector<int>& arr,int low,int mid,int high) {
        int i=low;
        int j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=high) {
            if (arr[i]<arr[j]) {
                temp.push_back(arr[i]);
                ++i;
            }
            else {
                temp.push_back(arr[j]);
                ++j;
            }
        }
        while (i<=mid) {
            temp.push_back(arr[i]);
            ++i;
        }
        while(j<=high) {
            temp.push_back(arr[j]);
            ++j;
        }
        for(int i=low;i<=high;++i) {
            arr[i] = temp[i-low];
        }
    }
    
    int pairCount(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int j=mid+1;
        for (int i=low;i<=mid;++i) {
            while(j<= high && (ll)arr[i]>2*(ll)arr[j]) ++j;
            count+=j-(mid+1);
        }
        return count;
    }
    
    int mergeSort(vector<int>& arr, int low, int high) {
        if (low==high) return 0;
        int count =0 ;
        int mid=(low+high)/2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=pairCount(arr,low,mid,high);
        mergeArr(arr,low,mid,high);
        return count;
    }
    
  public:
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        mergeSort(arr,0,n-1);
    }