// https://leetcode.cn/problems/UhWRSj/

// 0709 前缀树查询
class Solution {
public:
    struct Trie {
        struct TrieNode {
            bool isWord;
            map<char, TrieNode> children;
        } root;

        void insert(string word) {
            TrieNode* node = &root;
            for (auto ch : word) {
                if (node->children.find(ch) == node->children.end()) {
                    node->children.insert({ ch, {} });
                }
                node = &node->children[ch];
            }
            node->isWord = true;
        }

        string queryPrefix(string word) {
            string result;
            TrieNode* node = &root;
            for (const char ch : word) {
                auto it = node->children.find(ch);
                if (it == node->children.end()) {
                    return {};
                }
                result.push_back(ch);
                if (it->second.isWord) {
                    return result;
                }
                node = &it->second;
            }
            return {};
        }
    } trie;

    string replaceWords(vector<string>& dictionary, string sentence) {
        if (dictionary.empty() or sentence.empty()) {
            return sentence;
        }

        // 构造前缀树
        for (auto word : dictionary) {
            trie.insert(word);
        }

        // 分割字符串
        istringstream iss(sentence);
        vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>());

        // 替换单词前缀
        for (auto& w : words) {
            auto prefix = trie.queryPrefix(w); // 查询包含前缀
            if (not prefix.empty()) {
                w = prefix; // 替换
            }
        }

        // 拼接字符串
        string result = words[0];
        for (int i = 1; i < words.size(); i++) {
            result += " " + words[i];
        }

        return result;
    }
};