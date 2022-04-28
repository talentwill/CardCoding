// 剑指 Offer 59 - II. 队列的最大值

// 0428 利用单调队列特性
class MaxQueue {
public:

    deque<int> data_queue;
    deque<int> max_queue;

    int pop_front() {
        if (data_queue.empty()) {
            return -1;
        }

        int front = data_queue.front();
        data_queue.pop_front();

        if (front == max_queue.front()) {
            max_queue.pop_front();
        }

        return front;
    }

    void push_back(int value) {
        data_queue.push_back(value);

        // 移除比value小的元素
        while (not max_queue.empty() and max_queue.back() < value) {
            max_queue.pop_back();
        }
        max_queue.push_back(value);
    }

    int max_value() {
        if (max_queue.empty()) {
            return -1;
        }
        return max_queue.front();
    }
};