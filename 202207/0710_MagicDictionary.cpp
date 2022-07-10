// https://leetcode.cn/problems/US1pGT/

class MagicDictionary {
public:
    struct TrieNode {
        TrieNode() { children.resize(26); }

        bool isEnd = false;

        TrieNode *child(char ch) { return children[ch - 'a']; }

        vector<TrieNode *> children;
    } root;

    // 1. 构建单词前缀树
    void buildDict(vector<string> dictionary) {
        for (auto word: dictionary) {
            TrieNode *node = &root;
            for (auto ch: word) {
                if (node->child(ch) == nullptr) {
                    node->children[ch - 'a'] = new TrieNode();
                }
                node = node->child(ch);
            }
            node->isEnd = true;
        }
    }

    // 2. 是否能够改变一个字母，是否匹配
    bool search(string searchWord) {
        TrieNode *node = &root;
        for (int i = 0; i < searchWord.size(); i++) {
            // 1. 改变单词的一个字母，去匹配当前节点的所有子字母
            for (int j = 0; j < 26; j++) {
                // 如果节点的子字母和当前单词的字母相同，则需要排除
                if (node->children[j] != nullptr and searchWord[i] - 'a' != j) {
                    if (searchInternally(node->children[j], searchWord, i + 1)) {
                        return true;
                    }
                }
            }

            // 2. 当前字典树存在单词的字母，迭代下一个节点
            if (node->child(searchWord[i]) != nullptr) {
                node = node->child(searchWord[i]);
            } else {
                return false;
            }
        }
        return false;
    }

    // 辅助的dfs，用缀树的任意子树作为起点，进行单词匹配
    bool searchInternally(TrieNode *node, const string &searchWord, int wordIndex) {
        // 除了单词的起点不同，代码和正常的search逻辑完全一样
        for (int i = wordIndex; i < searchWord.size(); i++) {
            if (node->child(searchWord[i]) == nullptr) {
                return false;
            }
            node = node->child(searchWord[i]);
        }
        return node->isEnd;
    }
};
