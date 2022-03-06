// 剑指 Offer 09. 用两个栈实现队列

// 03/06 倒腾s2当删除s1时，T=O1，S=On
class CQueue {
    std::stack<int> s1,s2;
public:
    void appendTail(int x) {
        s1.push(x);
    }
    
    int deleteHead() {
        if (s2.empty()) {
            while (not s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()){
            return -1;
        } else {
            int x = s2.top();
            s2.pop();
            return x;
        };
    }
};