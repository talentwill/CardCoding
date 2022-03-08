// 剑指 Offer 41. 数据流中的中位数

// 03/08 使用2个优先队列，一大，一小排序。
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    priority_queue<int, vector<int>, greater<int> > cs; // 小堆 [7(堆顶),8,9]
    priority_queue<int, vector<int>, less<int> > cb; // 大堆 [1,3,5(堆顶)]

    void addNum(int num) {
        if (!cs.empty() and num >= cs.top()) {
            cs.push(num);
        }
        else if (!cb.empty() and num <= cb.top()) {
            cb.push(num);
        }
        else { // 2个堆顶之间的数据，平衡插入
            if (cs.size() > cb.size()) {
                cb.push(num);
            }
            else {
                cs.push(num);
            }
        }
    }

    double findMedian() {
        while (int(cb.size() - cs.size()) > 1) {
            cs.push(cb.top());
            cb.pop();
        }

        while (int(cs.size() - cb.size()) > 1) {
            cb.push(cs.top());
            cs.pop();
        }

        if (cb.size() == cs.size()) {
            return (cb.top() + cs.top()) / 2.0;
        }
        else if (cb.size() > cs.size()) {
            return cb.top();
        }
        else {
            return cs.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */