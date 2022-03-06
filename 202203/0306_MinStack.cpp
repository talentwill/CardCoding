// 剑指 Offer 30. 包含min函数的栈

// 03/06 利用辅助空间tuple<top,min> 保存冗余数据。
class MinStack {
    std::stack<std::tuple<int, int>> s;
public:
    void push(int x) {
        if (s.empty() or x <= min()) {
            s.push({x, x});
        }else {
            s.push({x, min()});
        }
    }
    
    void pop() { s.pop(); }
    int top() { return std::get<0>(s.top()); }
    int min() { return std::get<1>(s.top()); }
};

