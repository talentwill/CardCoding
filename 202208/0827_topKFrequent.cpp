// 060. 出现频率最高的 k 个数字
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. calculate nums' frequencies
        unordered_map<int, int> numToCount;
        for (auto x : nums) {
            numToCount[x] += 1;
        }
        // 2. prepare the min heap
        using NumCountPair = pair<int, int>; // <num, count>
        auto cmp = [](const NumCountPair& lhs, const NumCountPair rhs) {
            return lhs.second > rhs.second; // compare by num's frequency
        };
        priority_queue<NumCountPair, vector<NumCountPair>, decltype(cmp)> minHeap{ cmp };

        // 3. add item of hashmap to the minheap of K size 
        for (const auto& [value, count] : numToCount) {
            if (minHeap.size() < k) {
                minHeap.emplace(value, count);
            }
            else if (count > minHeap.top().second) {
                // add only if new num's count is larger than the top of the minheap.
                minHeap.pop();
                minHeap.emplace(value, count);
            }
        }
        // 4. print the minheap.
        vector<int> res;
        for (; not minHeap.empty(); minHeap.pop()) {
            res.emplace_back(minHeap.top().first);
        }
        return res;
    }
};