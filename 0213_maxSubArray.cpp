// 42.最大子列和

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int sum = 0;
        int neg = -100;

        for (auto& n : nums)
        {
            if (n < 0) {
                if (n > neg)
                    neg = n;
            }else {
                neg = 0;
            }

            cur = cur <= 0 ? n: cur + n;

            if (cur > sum) {
                sum = cur;
            }
        }
        
        return neg == 0 ? sum: neg;
    }
};
