// 剑指 Offer 60. n个骰子的点数

// 0501 暴力法
class Solution {
public:
    vector<int> nums;
    void dfs(int size, int sum) {
        for (int i = 1; i <=6; i++) {
            if (size == 1) {
                nums[sum + i] += 1;	// 统计和的个数
            } else {
                dfs(size -1, sum + i);
            }
        }
    }

    vector<double> dicesProbability(int n) {
        nums.resize(n * 6 + 1);
        dfs(n, 0);
        vector<double> ans;
        double p = pow(1/6.0,n);
        for (auto x: nums) {
            if (x != 0) {
                ans.emplace_back(p*x);
            }
        }
        return ans;
    }
};

// 0501 动态规划法
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> counts(6 * n + 1, 0);
        // 第一轮，和1-6出现1次
        for (int i = 1; i <= 6; i++) {
            counts[i] = 1;
        }
		// 再统计n-1轮
        for (int i = 1; i < n; i++) {
            vector<int> temp(6 * n + 1, 0);
            // 遍历上一轮和，每一轮和的范围是（i，6*i），比如一轮是1-6，两轮2-12。
            for (int j = i; j <= i * 6; j++) {
                // 掷骰子6次
                for (int k = 1; k <= 6; k++) {
					// 当前n的次数，等于上一轮（n-k）的次数。
                    temp[j + k] += counts[j];
                }
            }
            counts = temp; // 一轮结束后，交换一下
        }

        vector<double> ans;
        double p = pow(1.0 / 6, n);
        for (int i = n; i < counts.size(); i++) {
            ans.emplace_back(counts[i] * p);
        }
        return ans;
    }
};