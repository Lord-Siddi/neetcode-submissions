class MedianFinder {
public:
    MedianFinder() {}
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>lpq;
    void addNum(int num) {
        pq.push(num);
        lpq.push(pq.top());
        pq.pop();
        if(lpq.size()>pq.size()){
            pq.push(lpq.top());
            lpq.pop();
        }
        
    }
    
    double findMedian() {
        if(pq.size()==lpq.size())return (pq.top()+lpq.top())/2.0;
        return pq.top();
    }
};
