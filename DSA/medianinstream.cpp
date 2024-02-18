class Solution
{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxHeap.empty() || maxHeap.top()>x){
            maxHeap.push(x);
        }else minHeap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size()==minHeap.size())
        return (maxHeap.top()+minHeap.top())/2;
        else
        return maxHeap.top();
    }
};