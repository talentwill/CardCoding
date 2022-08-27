// 061. 和最小的 k 个数对
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    // 1. prepare min heap, whose top is the smallest sum of pairs
    using Ids = pair<int, int>; // indice of nums1 and nums2.
    auto cmp = [&](const Ids& lhs, const Ids& rhs) {
        auto sum = [&](const Ids& ids) {
            return nums1[ids.first] + nums2[ids.second];
        };
        return sum(lhs) > sum(rhs);
    };
    priority_queue<Ids, vector<Ids>, decltype(cmp)> pq{ cmp };

    // 2. add k items of the nums, pairing with nums2[0]
    for (int i = 0; i < k && i < nums1.size(); i++) {
        pq.emplace(i, 0);
    }

    vector<vector<int>> res;
    // 3. add ! pq.empty can adapt to m*n < k. if m*n < k, then pop all the heap
    for (int i = 0; i < k && !pq.empty(); i++) {
        auto ids = pq.top(); pq.pop();
        res.push_back({ nums1[ids.first], nums2[ids.second] });
        // 3.1 add one more pair to minheap.
        if (ids.second + 1 < nums2.size()) { // key step, add next id of nums2.
            pq.emplace(ids.first, ids.second + 1);
        }
    }
    return res;
}
