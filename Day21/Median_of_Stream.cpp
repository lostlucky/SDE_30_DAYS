class MedianFinder {
    
    struct minHeapComp{
        bool operator()(int a, int b){
            return a > b;
        }
    };
    
    struct maxHeapComp{
        bool operator()(int a, int b){
            return a < b;
        }
    };
    
    priority_queue<int,vector<int>,minHeapComp>minHeap;
    priority_queue<int,vector<int>,maxHeapComp>maxHeap;
    
    int total;
    
public:
    /** initialize your data structure here. */
    
    MedianFinder() {
        total = 0;
    }
    
    void addNum(int num) {
        minHeap.push(num);
        
        if(!maxHeap.empty() and minHeap.top() < maxHeap.top()){
            int maxVal = maxHeap.top(), minVal = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minVal);
            minHeap.push(maxVal);
        }
        
        if(total&1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        total++; 
    }
    
    double findMedian() {
        return total&1 ? minHeap.top() : (double)(maxHeap.top() + minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
