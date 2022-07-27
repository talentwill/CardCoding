// https://leetcode.cn/problems/z1R5dt/solution/by-talentwill-4r5a/

class MapSum {
public:
    struct TrieNode {
        int val = 0; // 初始化0，题目给定value至少>=1
        map<char, TrieNode*> children;

        // 获取前缀树的单词字母，不存在则新创一个
        TrieNode* get(char c) {
            if (children.find(c) == children.end()) {
                children[c] = new TrieNode();
            }
            return children[c];
        }
        // 判断是否包含字母c
        bool has(char c) {
            return children.find(c) != children.end();
        }
    } root;

    void insert(string key, int val) {
        TrieNode* node = &root;
        for (auto c : key) {
            node = node->get(c);
        }
        node->val = val;
    }

    void dfs(TrieNode* node, int& valueSum) {
        if (node != nullptr) {
            valueSum += node->val;
            for (auto [k, v] : node->children) {
                dfs(v, valueSum);
            }
        }
    }

    int sum(string prefix) {
        TrieNode* node = &root;
        for (auto c : prefix) {
            if (not node->has(c)) {
                return 0;
            }
            node = node->children[c];
        }
        // node 当前为前缀字符串最后一个字母的节点
        int valueSum = 0;
        dfs(node, valueSum); // 将node作为root，累加所有的单词的value
        return valueSum;
    }
};
