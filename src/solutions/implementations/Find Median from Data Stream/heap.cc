class MedianFinder {
    priority_queue<int, vector<int>, less<int>> max_queue;
    priority_queue<int, vector<int>, greater<int>> min_queue;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (max_queue.empty()) {
            max_queue.push(num);
            return;
        }
        if (min_queue.empty()) {
            max_queue.push(num);
            return;
        }
        if (num <= max_queue.top()) {
            max_queue.push(num);
        } else {
            min_queue.push(num);
        }
    }
    
    double findMedian() {
        while (max_queue.size() > min_queue.size()) {
            min_queue.push(max_queue.top());
            max_queue.pop();
        }
        while (min_queue.size() > max_queue.size()) {
            max_queue.push(min_queue.top());
            min_queue.pop();
        }
        int total = min_queue.size() + max_queue.size();
        if (total % 2 == 1) {
            return max_queue.top();
        } else {
            return (min_queue.top() + max_queue.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */