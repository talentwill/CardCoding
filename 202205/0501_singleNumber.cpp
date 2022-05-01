// 剑指 Offer 56 - II. 数组中数字出现的次数 II

// 0501 遍历统计二进制3的次数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32); // 代表二进制数，每一位1的个数
        for (auto x : nums) {
            int i = 0;
            while (x > 0) {
                bits[i++] += x & 1; // 按位累加
                x = x >> 1;
            }
        }

        int ans = 0;
        for (int i = bits.size() - 1; i >= 0; i--) {
            ans = ans << 1;
            ans |= bits[i] % 3; // 还原成int
        }

        return ans;
    }
};

// 0501 自动机，直接计算模3的结果
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};