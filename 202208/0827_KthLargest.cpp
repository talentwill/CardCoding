// 059. 数据流的第 K 大数值
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int capacity = 0;

    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for (auto x : nums) {
            add(x);
        }
    }

    int add(int val) {
        if (minHeap.size() < capacity) {
            minHeap.push(val);
        }
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};