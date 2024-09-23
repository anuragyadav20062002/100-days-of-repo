//User function template for C++

class Solution{   
public:
    double getPairsCount(double arr[], double n, double k) {
        // code here
        double count=0;
        unordered_map<double,double> map;
        for(double i=0;i<n;i++){
            if(map.find(k-arr[i])!=map.end()){
                count+=map[k-arr[i]];
            }
            map[arr[i]]++;
        }
        return count;
    }
};
