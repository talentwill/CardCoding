// https://leetcode.cn/problems/ms70jA/solution/by-talentwill-bgnc/

class Solution {
public:
    struct TrieNode {
        TrieNode* children[2] = { nullptr };
    }root;

    void buildTrie(vector<int>& nums) {
        for (auto num : nums) {
            TrieNode* node = &root;
            for (int i = 31; i >= 0; i--) { // 把每个元素按照二进制位拆成32位。
                auto bit = num >> i & 1;
                if (node->children[bit] == nullptr) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        buildTrie(nums);
        int maxXor = 0;
        for (auto num : nums) {
            int thisXor = 0;
            TrieNode* node = &root;
            for (int i = 31; i >= 0; i--) {
                int bit = num >> i & 1;
                // 反向查找，二进制不同的节点
                if (node->children[1 - bit] != nullptr) {
                    node = node->children[1 - bit];
                    thisXor += 1 << i;
                }
                else {
                    node = node->children[bit];
                }
            }
            maxXor = max(maxXor, thisXor);
        }
        return maxXor;
    }
};