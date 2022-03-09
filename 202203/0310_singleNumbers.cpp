// 剑指 Offer 56 - I. 数组中数字出现的次数

// 03/10 划分成2组，分别异或
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xorResult = 0;
        for (auto& x: nums) {
            xorResult ^= x;
        }
        
        int bitIndex = 0;
        for (; bitIndex < sizeof(int) * 8; bitIndex++) {
            if ((xorResult & 1) == 1) {
                break;
            }
            xorResult = xorResult >> 1;
        }

        auto isBit1 = [bitIndex](int n)->bool {
            return ((n >> bitIndex) & 1) == 1;
        };

        vector<int> res(2);
        for (auto& x: nums) {
            if (isBit1(x)) {
                res[0] ^= x;
            }else {
                res[1] ^= x;
            }
        }
        return res;
    }
};
