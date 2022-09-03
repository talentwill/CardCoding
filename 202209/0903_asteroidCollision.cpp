// 037. 小行星碰撞
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        // 碰撞发生的条件判断
        auto canMeet = [&](int asteroid) {
            if (s.empty()) {
                return false;
            }
            else {
                return s.top() > 0 && asteroid < 0;
            }
        };

        // 碰撞后的结果
        auto collision = [](int a, int b) {
            if (abs(a) == abs(b)) return 0;
            return abs(a) > abs(b) ? a : b;
        };

        for (auto next : asteroids) {
            while (canMeet(next)) {
                int prev = s.top(); s.pop();
                next = collision(prev, next);
            }
            if (next != 0) {
                s.push(next);
            }
        }
        // 拷贝stack，土办法拷贝
        vector<int> res(s.size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = s.top(); s.pop();
        }
        return res;
    }
};